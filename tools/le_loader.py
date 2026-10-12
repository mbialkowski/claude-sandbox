#!/usr/bin/env python3
"""Minimal loader for DOS/4GW Linear Executable (LE) files.

Parses the MZ stub + LE header, loads every object at its preferred
relocation base, applies internal fixups and returns a flat memory image
that can be fed to a disassembler with real (as-run) addresses.

Usage as a script:
    python3 tools/le_loader.py LAZARUS.EXE            # print header/object info
    python3 tools/le_loader.py LAZARUS.EXE -o out.bin # also dump objects
"""
import argparse
import struct
import sys


class LEObject:
    def __init__(self, idx, vsize, base, flags, page_idx, page_cnt):
        self.idx = idx
        self.vsize = vsize
        self.base = base
        self.flags = flags
        self.page_idx = page_idx
        self.page_cnt = page_cnt
        self.data = bytearray(vsize)

    @property
    def kind(self):
        if self.flags & 0x4:
            return "CODE"
        return "DATA"

    def __repr__(self):
        return (f"<obj {self.idx} {self.kind} base=0x{self.base:08x} "
                f"size=0x{self.vsize:x} flags=0x{self.flags:x} "
                f"pages={self.page_idx}+{self.page_cnt}>")


class LEFile:
    def __init__(self, path):
        self.raw = open(path, "rb").read()
        d = self.raw
        if d[:2] != b"MZ":
            raise ValueError("not an MZ executable")
        self.le_off = struct.unpack_from("<I", d, 0x3C)[0]
        h = self.le_off
        if d[h:h + 2] not in (b"LE", b"LX"):
            raise ValueError("no LE header")
        u32 = lambda o: struct.unpack_from("<I", d, h + o)[0]
        self.num_pages = u32(0x14)
        self.eip_obj = u32(0x18)
        self.eip = u32(0x1C)
        self.esp_obj = u32(0x20)
        self.esp = u32(0x24)
        self.page_size = u32(0x28)
        self.last_page_size = u32(0x2C)
        self.obj_tab = h + u32(0x40)
        self.num_objs = u32(0x44)
        self.page_map = h + u32(0x48)
        self.fixup_page_tab = h + u32(0x68)
        self.fixup_rec_tab = h + u32(0x6C)
        self.data_pages = u32(0x80)  # absolute file offset
        self.auto_ds_obj = u32(0x94)

        self.objects = []
        for i in range(self.num_objs):
            vs, base, fl, pi, pc, _ = struct.unpack_from(
                "<6I", d, self.obj_tab + i * 24)
            self.objects.append(LEObject(i + 1, vs, base, fl, pi, pc))

        # page map: LE uses 3-byte big-endian page number + flags byte
        self.pages = []
        for i in range(self.num_pages):
            b = d[self.page_map + i * 4:self.page_map + i * 4 + 4]
            num = (b[0] << 16) | (b[1] << 8) | b[2]
            self.pages.append((num, b[3]))

        self._load_pages()
        self.fixups = []
        self._apply_fixups()

    def _page_bytes(self, logical_page):
        num, flags = self.pages[logical_page - 1]
        off = self.data_pages + (num - 1) * self.page_size
        size = self.page_size
        if num == self.num_pages:
            size = self.last_page_size
        return self.raw[off:off + size]

    def _load_pages(self):
        for o in self.objects:
            for j in range(o.page_cnt):
                pg = self._page_bytes(o.page_idx + j)
                start = j * self.page_size
                end = min(start + len(pg), o.vsize)
                if end > start:
                    o.data[start:end] = pg[:end - start]

    def obj_for_page(self, logical_page):
        for o in self.objects:
            if o.page_idx <= logical_page < o.page_idx + o.page_cnt:
                return o, (logical_page - o.page_idx) * self.page_size
        return None, 0

    def _apply_fixups(self):
        d = self.raw
        for p in range(1, self.num_pages + 1):
            start = struct.unpack_from("<I", d, self.fixup_page_tab + (p - 1) * 4)[0]
            end = struct.unpack_from("<I", d, self.fixup_page_tab + p * 4)[0]
            pos = self.fixup_rec_tab + start
            stop = self.fixup_rec_tab + end
            obj, page_base = self.obj_for_page(p)
            while pos < stop:
                src = d[pos]
                flg = d[pos + 1]
                pos += 2
                stype = src & 0x0F
                if src & 0x20:
                    cnt = d[pos]
                    pos += 1
                    srcoffs = None
                else:
                    srcoffs = [struct.unpack_from("<h", d, pos)[0]]
                    pos += 2
                ttype = flg & 0x03
                if ttype != 0:
                    raise NotImplementedError(f"fixup target type {ttype}")
                if flg & 0x40:
                    tobj = struct.unpack_from("<H", d, pos)[0]
                    pos += 2
                else:
                    tobj = d[pos]
                    pos += 1
                toff = 0
                if stype != 0x02:
                    if flg & 0x10:
                        toff = struct.unpack_from("<I", d, pos)[0]
                        pos += 4
                    else:
                        toff = struct.unpack_from("<H", d, pos)[0]
                        pos += 2
                if srcoffs is None:
                    srcoffs = [struct.unpack_from("<h", d, pos + 2 * k)[0]
                               for k in range(cnt)]
                    pos += 2 * cnt
                target = self.objects[tobj - 1].base + toff
                for so in srcoffs:
                    off = page_base + so
                    self.fixups.append((obj.base + off, stype, target))
                    if off < 0 or obj is None:
                        continue
                    if stype == 0x07:  # 32-bit offset
                        if off + 4 <= obj.vsize:
                            struct.pack_into("<I", obj.data, off, target & 0xFFFFFFFF)
                        else:  # fixup straddles page/object end
                            b = struct.pack("<I", target & 0xFFFFFFFF)
                            for k in range(4):
                                if off + k < obj.vsize:
                                    obj.data[off + k] = b[k]
                    elif stype == 0x08:  # 32-bit self relative
                        rel = target - (obj.base + off + 4)
                        if off + 4 <= obj.vsize:
                            struct.pack_into("<i", obj.data, off, rel)
                    elif stype == 0x05:  # 16-bit offset
                        if off + 2 <= obj.vsize:
                            struct.pack_into("<H", obj.data, off, target & 0xFFFF)
                    elif stype == 0x02:  # 16-bit selector: leave as obj number
                        if off + 2 <= obj.vsize:
                            struct.pack_into("<H", obj.data, off, tobj)
                    elif stype == 0x06:  # 16:32 pointer
                        if off + 6 <= obj.vsize:
                            struct.pack_into("<IH", obj.data, off, target, tobj)
                    elif stype == 0x00:  # byte
                        if 0 <= off < obj.vsize:
                            obj.data[off] = target & 0xFF

    # convenience accessors -------------------------------------------------
    def obj_at(self, addr):
        for o in self.objects:
            if o.base <= addr < o.base + o.vsize:
                return o
        return None

    def read(self, addr, n):
        o = self.obj_at(addr)
        if o is None:
            return None
        off = addr - o.base
        return bytes(o.data[off:off + n])

    def u32(self, addr):
        b = self.read(addr, 4)
        return struct.unpack("<I", b)[0] if b and len(b) == 4 else None

    def cstr(self, addr, maxlen=512):
        o = self.obj_at(addr)
        if o is None:
            return None
        off = addr - o.base
        end = o.data.find(b"\0", off, off + maxlen)
        if end < 0:
            end = off + maxlen
        return bytes(o.data[off:end])

    @property
    def entry(self):
        return self.objects[self.eip_obj - 1].base + self.eip


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("exe")
    ap.add_argument("-o", "--out-prefix", help="dump each object to PREFIX.objN.bin")
    a = ap.parse_args()
    le = LEFile(a.exe)
    print(f"LE header at 0x{le.le_off:x}, pages={le.num_pages}, "
          f"page_size=0x{le.page_size:x}, data_pages@0x{le.data_pages:x}")
    print(f"entry = {le.eip_obj}:0x{le.eip:x} -> 0x{le.entry:08x}")
    print(f"stack = {le.esp_obj}:0x{le.esp:x}, auto DS obj = {le.auto_ds_obj}")
    for o in le.objects:
        print(" ", o)
    print(f"fixups applied: {len(le.fixups)}")
    if a.out_prefix:
        for o in le.objects:
            fn = f"{a.out_prefix}.obj{o.idx}.bin"
            with open(fn, "wb") as f:
                f.write(o.data)
            print("wrote", fn)


if __name__ == "__main__":
    sys.exit(main())
