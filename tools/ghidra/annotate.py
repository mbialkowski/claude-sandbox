#!/usr/bin/env python3
"""Post-process the Ghidra output of lazarus_decompile.py for reading.

    python3 tools/ghidra/annotate.py LAZARUS.EXE lazarus.c > lazarus_annotated.c

* Dialogue calls such as Dlg_Say(&PTR_DAT_00054154,7) become
  Dlg_Say(MSG_259) /* "Bezpiecznik." */ using the message table of the EXE.
* Dlg_Menu(0,0,&PTR...,n) shows the base message number.
* Every function header gets a comment listing the script ids / item ids
  whose handler it is (from the script and item tables).
"""
import os
import re
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from lazarus_exe import ADDR, LazarusExe  # noqa: E402

TAG = re.compile(r"\{[xyc]:\d{3}\}")


def main():
    exe = LazarusExe(sys.argv[1])
    text = open(sys.argv[2], encoding="utf-8").read()
    msgs = [TAG.sub("", m).replace("\n", " / ").replace("*/", "* /") for m in exe.messages()]
    base0 = ADDR["messages"]

    def msg_no(tbl_hex, idx):
        return (int(tbl_hex, 16) - base0) // 4 + int(idx, 0)

    def say(m):
        fn, tbl, idx = m.group(1), m.group(2), m.group(3)
        try:
            n = msg_no(tbl, idx)
        except ValueError:
            return m.group(0)
        if not 0 <= n < len(msgs):
            return m.group(0)
        return f'{fn}(MSG_{n}) /* "{msgs[n][:100]}" */'

    def say_range(m):
        a, b = msg_no(m.group(2), m.group(3)), msg_no(m.group(2), m.group(4))
        return f'{m.group(1)}(MSG_{a}..MSG_{b}) /* "{msgs[a][:60]}" ... "{msgs[b][:60]}" */'

    text = re.sub(r"(Dlg_SayRange)\(&PTR_DAT_000([0-9a-f]+),(\w+),(\w+)\)", say_range, text)
    text = re.sub(r"(Dlg_\w+)\(&PTR_DAT_000([0-9a-f]+),(\w+)\)", say, text)
    text = re.sub(r"(Dlg_\w+)\(&g_messages,(\w+)\)",
                  lambda m: f'{m.group(1)}(MSG_{int(m.group(2), 0)}) /* "{msgs[int(m.group(2), 0)][:100]}" */',
                  text)
    text = re.sub(r"Dlg_Menu\(0,0,&PTR_DAT_000([0-9a-f]+),(\w+)\)",
                  lambda m: f"Dlg_Menu(/*options = MSG_{(int(m.group(1), 16) - base0) // 4} + g_menuOpt[i]*/ "
                            f"{m.group(2)})", text)

    roles = {}
    for s in exe.scripts():
        if s["on_trigger_fn"] != "1b2b0":
            roles.setdefault(int(s["on_trigger_fn"], 16), []).append(f"script {s['id']} on_trigger")
        if s["on_missing_item_fn"] != "1b2b0":
            roles.setdefault(int(s["on_missing_item_fn"], 16), []).append(f"item {s['id']} missing-item reply")
    for it in exe.items():
        roles.setdefault(int(it["use_fn"], 16), []).append(f"item {it['id']} use")

    def header(m):
        addr = int(m.group(2), 16)
        r = roles.get(addr)
        extra = f"\n/* role: {', '.join(r)} */" if r else ""
        return m.group(0) + extra

    text = re.sub(r"/\* ======== (\S+) @ (\w+) ======== \*/", header, text)
    sys.stdout.write(text)


if __name__ == "__main__":
    main()
