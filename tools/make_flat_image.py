#!/usr/bin/env python3
"""Build inputs for the Ghidra headless decompilation of LAZARUS.EXE.

    python3 tools/make_flat_image.py LAZARUS.EXE out_dir/

Writes:
    flat.bin   - all LE objects (fixups applied) laid out from 0x10000, so the
                 raw image can be imported with -loader BinaryLoader
                 -loader-baseAddr 0x10000
    seeds.txt  - function entry points: call targets, code pointers found in
                 the data object (vtables, script/item tables) and immediates
                 that point at function prologues (hero state handlers etc.)
"""
import os
import re
import struct
import sys

import capstone

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le_loader import LEFile  # noqa: E402

PROLOGUE = {0x50, 0x51, 0x52, 0x53, 0x55, 0x56, 0x57}   # push reg
BOUNDARY = {0xC3, 0x90, 0x00, 0xC0, 0xC9}               # ret / padding before a function


def main():
    exe, out = sys.argv[1], sys.argv[2]
    os.makedirs(out, exist_ok=True)
    le = LEFile(exe)
    end = max(o.base + o.vsize for o in le.objects)
    img = bytearray(end - 0x10000)
    for o in le.objects:
        img[o.base - 0x10000:o.base - 0x10000 + o.vsize] = o.data
    open(os.path.join(out, "flat.bin"), "wb").write(img)

    code = le.objects[0]
    lo, hi = code.base, code.base + code.vsize
    seeds = {le.entry}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.skipdata = True
    hexre = re.compile(r"0x([0-9a-f]+)")
    for ins in md.disasm(bytes(code.data), code.base):
        if ins.mnemonic == "call" and ins.op_str.startswith("0x"):
            seeds.add(int(ins.op_str, 16))
            continue
        for m in hexre.finditer(ins.op_str):
            v = int(m.group(1), 16)
            if lo <= v < hi and img[v - 0x10000] in PROLOGUE and img[v - 0x10001] in BOUNDARY:
                seeds.add(v)
    data = le.objects[2]
    for i in range(0, 0x16000, 4):
        v = struct.unpack_from("<I", data.data, i)[0]
        if lo <= v < hi:
            seeds.add(v)
    with open(os.path.join(out, "seeds.txt"), "w") as f:
        f.write("\n".join("%x" % s for s in sorted(seeds)))
    print(f"flat.bin: {len(img)} bytes, {len(seeds)} function seeds")


if __name__ == "__main__":
    main()
