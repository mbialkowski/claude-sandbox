#!/usr/bin/env python3
"""Linear-sweep disassembly of LAZARUS.EXE with string/xref annotations.

Produces a text listing where each instruction is shown at its run-time
address (code object at 0x10000, data object at 0x50000).  Immediate or
displacement values that point into the data object are annotated with the
Mazovia-decoded C string found there (if it looks like text), and every
function start (call target) is labelled `sub_XXXXXXXX`, optionally replaced
by a human name from a symbol file (`ADDR NAME` per line).

Usage:
    python3 tools/disasm.py LAZARUS.EXE -o lazarus.asm [-s symbols.txt]
"""
import argparse
import os
import re
import sys

import capstone

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le_loader import LEFile  # noqa: E402
import mazovia  # noqa: E402


def load_symbols(path):
    syms = {}
    if path and os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            line = line.split("#", 1)[0].strip()
            if not line:
                continue
            addr, name = line.split(None, 1)
            syms[int(addr, 16)] = name.strip()
    return syms


def looks_like_text(b):
    if not b or len(b) < 3:
        return False
    good = sum(1 for c in b if 32 <= c < 127 or c >= 0x80 or c in (9, 10, 13))
    return good / len(b) > 0.9


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("exe")
    ap.add_argument("-o", "--out", required=True)
    ap.add_argument("-s", "--symbols")
    a = ap.parse_args()

    le = LEFile(a.exe)
    syms = load_symbols(a.symbols)
    code = le.objects[0]
    data = le.objects[2]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.skipdata = True

    insns = list(md.disasm(bytes(code.data), code.base))
    # pass 1: collect call/jump targets
    calls, jumps = {}, {}
    for i in insns:
        if i.mnemonic == "call" and i.op_str.startswith("0x"):
            t = int(i.op_str, 16)
            calls.setdefault(t, []).append(i.address)
        elif i.mnemonic.startswith("j") and i.op_str.startswith("0x"):
            t = int(i.op_str, 16)
            jumps.setdefault(t, []).append(i.address)

    def name(addr):
        if addr in syms:
            return syms[addr]
        if addr in calls:
            return f"sub_{addr:08x}"
        return None

    hexre = re.compile(r"0x[0-9a-f]+")
    with open(a.out, "w", encoding="utf-8") as out:
        for i in insns:
            if i.address in calls or i.address in syms:
                xr = ", ".join(f"{c:x}" for c in calls.get(i.address, [])[:8])
                more = len(calls.get(i.address, [])) - 8
                if more > 0:
                    xr += f" (+{more})"
                out.write(f"\n; ---------------- {name(i.address)}   ; called from: {xr}\n")
            elif i.address in jumps:
                out.write(f"loc_{i.address:08x}:\n")
            ops = i.op_str
            notes = []
            for m in hexre.finditer(ops):
                v = int(m.group(), 16)
                if code.base <= v < code.base + code.vsize:
                    n = name(v)
                    if n:
                        notes.append(n)
                elif data.base <= v < data.base + data.vsize:
                    n = syms.get(v)
                    if n:
                        notes.append(n)
                    s = le.cstr(v, 80)
                    if s and looks_like_text(s):
                        notes.append('"' + mazovia.decode(s).replace("\n", "\\n") + '"')
            if i.mnemonic in ("call", "jmp") and ops.startswith("0x"):
                n = name(int(ops, 16))
                if n:
                    ops = n
                    notes = [x for x in notes if x != n]
            line = f"{i.address:08x}  {i.bytes.hex():<20} {i.mnemonic:<7} {ops}"
            if notes:
                line = f"{line:<70} ; " + " | ".join(notes)
            out.write(line + "\n")
    print(f"{len(insns)} instructions, {len(calls)} call targets -> {a.out}")


if __name__ == "__main__":
    main()
