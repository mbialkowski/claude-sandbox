# Ghidra decompilation of LAZARUS.EXE

`lazarus_decompile.py` is a Ghidra (Jython) post-script that seeds functions in the flat image produced by
`tools/make_flat_image.py`, applies the names from `tools/symbols.txt`, re-runs auto-analysis and writes
pseudo-C for every function to one file.

## Watcom register calling convention

Watcom C passes the first four integer arguments in `EAX, EDX, EBX, ECX`, returns in `EAX`, preserves all
other registers and the callee pops stack arguments. Ghidra (tested with 11.1.2) has no such prototype, so
without help the output is full of `unaff_EDX` / `in_EAX`. Add this as the **default prototype** in
`Ghidra/Processors/x86/data/languages/x86win.cspec` (replace the opening of `<default_proto>` and keep
`__stdcall` as an ordinary `<prototype>`):

```xml
<default_proto>
  <prototype name="__watcall" extrapop="unknown" stackshift="4">
    <input>
      <pentry minsize="1" maxsize="4"><register name="EAX"/></pentry>
      <pentry minsize="1" maxsize="4"><register name="EDX"/></pentry>
      <pentry minsize="1" maxsize="4"><register name="EBX"/></pentry>
      <pentry minsize="1" maxsize="4"><register name="ECX"/></pentry>
      <pentry minsize="1" maxsize="500" align="4"><addr offset="4" space="stack"/></pentry>
    </input>
    <output killedbycall="true">
      <pentry minsize="4" maxsize="10" metatype="float" extension="float"><register name="ST0"/></pentry>
      <pentry minsize="1" maxsize="4"><register name="EAX"/></pentry>
      <pentry minsize="5" maxsize="8"><addr space="join" piece1="EDX" piece2="EAX"/></pentry>
    </output>
    <unaffected>
      <varnode space="ram" offset="0" size="4"/>
      <register name="ESP"/><register name="EBP"/><register name="ESI"/><register name="EDI"/>
      <register name="EBX"/><register name="ECX"/><register name="EDX"/>
      <register name="DF"/><register name="FS_OFFSET"/>
    </unaffected>
  </prototype>
</default_proto>
```

## Run

```bash
python3 tools/make_flat_image.py original/LAZARUS.EXE out/
$GHIDRA/support/analyzeHeadless out/proj laz -import out/flat.bin \
    -processor x86:LE:32:default -cspec windows \
    -loader BinaryLoader -loader-baseAddr 0x10000 \
    -scriptPath tools/ghidra -postScript lazarus_decompile.py \
    out/seeds.txt tools/symbols.txt out/lazarus.c
```

About two minutes; ~1000 functions. Add names to `tools/symbols.txt` and re-run to improve the output.
Then annotate dialogue calls with their text and mark script/item handlers:

```bash
python3 tools/ghidra/annotate.py original/LAZARUS.EXE out/lazarus.c > reference/lazarus.c
```
