"""Game tables that live inside LAZARUS.EXE (not in the DATAxx.RES files).

All addresses are run-time addresses of the LE data object (base 0x50000) as
loaded by tools/le_loader.py.  They are valid for the Polish release
(LAZARUS.EXE, 358 841 bytes).
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le_loader import LEFile  # noqa: E402
import mazovia  # noqa: E402

ADDR = {
    "tile_anim_seqs": 0x50004,   # 76 x (u16 hdr, i16 tiles..., -1)
    "sound_table": 0x51360,      # 54 x 32-byte sound descriptors
    "item_table": 0x53434,       # 38 x {u32 hud_icon, u32 use_fn}
    "script_table": 0x53564,     # 256 x {u32 on_trigger_fn, u32 on_missing_item_fn}
    "messages": 0x53d64,         # 293 x char* (Mazovia)
    "weapon_table": 0x5427c,     # 12 x 0x24 bytes (weapon*2 + facing)
    "sock_spots": 0x5442c,       # 11 x (i32 col, i32 row)
    "hurt_sounds": 0x559cc,      # i16 list, -1 terminated
}

NUM_MESSAGES = 293


class LazarusExe:
    def __init__(self, path):
        self.le = LEFile(path)

    def _i16_list(self, addr, limit=64):
        out = []
        for k in range(limit):
            v = struct.unpack("<h", self.le.read(addr + 2 * k, 2))[0]
            if v == -1:
                break
            out.append(v)
        return out

    # -- text ---------------------------------------------------------------
    def messages(self):
        """List of decoded dialogue strings.  Control codes are kept as
        {x:NNN} {y:NNN} {c:NNN} (0xE0/0xE1/0xE2 + 3 decimal digits)."""
        res = []
        for i in range(NUM_MESSAGES):
            raw = self.le.cstr(self.le.u32(ADDR["messages"] + i * 4), 1000)
            res.append(decode_text(raw))
        return res

    # -- sounds -------------------------------------------------------------
    def sounds(self):
        out = []
        for sid in range(54):
            b = self.le.read(ADDR["sound_table"] + sid * 0x20, 0x28)
            off, = struct.unpack_from("<I", b, 0x14)
            length, rate = struct.unpack_from("<HH", b, 0x18)
            loop_start, = struct.unpack_from("<I", b, 0x1E)
            loop, = struct.unpack_from("<h", b, 0x26)
            out.append({"id": sid, "offset": off, "length": length, "rate": rate,
                        "loop": loop == 2, "loop_start": loop_start})
        return out

    # -- weapons ------------------------------------------------------------
    def weapons(self):
        out = []
        for i in range(12):
            b = self.le.read(ADDR["weapon_table"] + i * 0x24, 0x24)
            ox, oy = struct.unpack_from("<hh", b, 0)
            v, a, frame, impact = struct.unpack_from("<iiii", b, 4)
            auto, = struct.unpack_from("<H", b, 0x16)
            cooldown, damage = b[0x18], b[0x19]
            lifetime, = struct.unpack_from("<H", b, 0x1A)
            cost, snd_ptr = struct.unpack_from("<iI", b, 0x1C)
            out.append({
                "weapon": i // 2, "facing": "left" if i % 2 == 0 else "right",
                "spawn_offset": [ox, oy], "speed_px": v / 65536.0, "accel_px": a / 65536.0,
                "bob_frame": frame, "impact_bob_frame": impact, "auto_fire": bool(auto),
                "cooldown_ticks": cooldown, "damage": damage, "lifetime_ticks": lifetime,
                "ammo_cost": cost, "ammo_cost_fraction": cost / 0x2F0000,
                "sounds": self._i16_list(snd_ptr) if snd_ptr else [],
            })
        return out

    # -- items / scripts ----------------------------------------------------
    def items(self):
        return [{"id": i,
                 "hud_icon": self.le.u32(ADDR["item_table"] + i * 8),
                 "use_fn": "%05x" % self.le.u32(ADDR["item_table"] + i * 8 + 4)}
                for i in range(38)]

    def scripts(self):
        res = []
        for i in range(256):
            a = self.le.u32(ADDR["script_table"] + i * 8)
            b = self.le.u32(ADDR["script_table"] + i * 8 + 4)
            res.append({"id": i, "on_trigger_fn": "%05x" % a, "on_missing_item_fn": "%05x" % b})
        return res

    def tile_anim_sequences(self):
        p, seqs = ADDR["tile_anim_seqs"], []
        for _ in range(76):
            p += 2
            s = []
            while True:
                v = struct.unpack("<h", self.le.read(p, 2))[0]
                p += 2
                if v == -1:
                    break
                s.append(v)
            seqs.append(s)
        return seqs

    def sock_spots(self):
        return [list(struct.unpack("<ii", self.le.read(ADDR["sock_spots"] + i * 8, 8)))
                for i in range(11)]

    def hurt_sounds(self):
        return self._i16_list(ADDR["hurt_sounds"])


def decode_text(raw):
    """Mazovia bytes -> str with explicit control-code tags."""
    out, i = [], 0
    while i < len(raw):
        b = raw[i]
        if b in (0xE0, 0xE1, 0xE2) and i + 3 < len(raw) + 1:
            tag = {0xE0: "x", 0xE1: "y", 0xE2: "c"}[b]
            out.append("{%s:%s}" % (tag, raw[i + 1:i + 4].decode("ascii", "replace")))
            i += 4
            continue
        out.append(mazovia.decode(bytes([b])))
        i += 1
    return "".join(out)
