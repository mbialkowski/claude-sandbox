# Ghidra (Jython) headless post-script: seed functions in the flat LAZARUS image,
# apply known symbol names, re-analyse and decompile every function to C.
#
# Script arguments: <seeds.txt> <symbols.txt> <out.c>
#
# The flat image is produced by tools/make_flat_image.py: code object @0x10000,
# data object @0x50000, everything loaded with fixups applied.
# @category Lazarus

from ghidra.app.decompiler import DecompInterface, DecompileOptions
from ghidra.program.model.symbol import SourceType
from ghidra.app.cmd.disassemble import DisassembleCommand
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
seeds_path, syms_path, out_path = args[0], args[1], args[2]
af = currentProgram.getAddressFactory()
fm = currentProgram.getFunctionManager()
st = currentProgram.getSymbolTable()
mon = ConsoleTaskMonitor()


def A(x):
    return af.getDefaultAddressSpace().getAddress(x)


seeds = [int(l.strip(), 16) for l in open(seeds_path) if l.strip()]
syms = {}
for line in open(syms_path):
    line = line.split('#', 1)[0].strip()
    if not line:
        continue
    a, n = line.split(None, 1)
    syms[int(a, 16)] = n.strip()

# 1. disassemble + create functions at every seed (code object only)
for s in sorted(set(seeds) | set(k for k in syms if k < 0x50000)):
    addr = A(s)
    DisassembleCommand(addr, None, True).applyTo(currentProgram, mon)
for s in sorted(set(seeds) | set(k for k in syms if k < 0x50000)):
    addr = A(s)
    if fm.getFunctionAt(addr) is None:
        CreateFunctionCmd(addr).applyTo(currentProgram, mon)

analyzeAll(currentProgram)

# 2. names
for a, n in syms.items():
    addr = A(a)
    f = fm.getFunctionAt(addr)
    try:
        if f is not None:
            f.setName(n, SourceType.USER_DEFINED)
        else:
            st.createLabel(addr, n, SourceType.USER_DEFINED)
    except Exception as e:
        print("name failed %x %s: %s" % (a, n, e))

# 3. decompile everything
di = DecompInterface()
opts = DecompileOptions()
di.setOptions(opts)
di.openProgram(currentProgram)
out = open(out_path, 'w')
count = 0
for f in fm.getFunctions(True):
    res = di.decompileFunction(f, 120, mon)
    out.write("\n/* ======== %s @ %s ======== */\n" % (f.getName(), f.getEntryPoint()))
    if res and res.decompileCompleted():
        out.write(res.getDecompiledFunction().getC())
    else:
        out.write("/* decompilation failed */\n")
    count += 1
out.close()
print("decompiled %d functions -> %s" % (count, out_path))
