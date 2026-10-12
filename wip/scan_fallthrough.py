"""Functions whose code runs on into the next symbol (splat cut a function in the middle): the last two instructions of the file contain no
return / jump (jr, j, b, beq $zero,$zero).  A recompiled twin of such a function returns where the real code continues (func_00449E38 lost
its tail func_0044A100: the trial respawn key was never set).  Lists them, marking the ones that run as twins (port/recomp.txt)."""
import glob, os, re
rec = set(open('port/recomp.txt').read().split())
cskip = set(open('port/c_skip.txt').read().split())
srcs = {os.path.basename(p)[:-2] for p in glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c') + glob.glob('src/libultra/*.c')}
for f in sorted(glob.glob('port/build/asm_func/*.s')):
    ins = [l.split('*/', 1)[1].strip() for l in open(f, errors='ignore') if re.match(r'\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/', l)]
    if not ins: continue
    tail = ins[-2:]
    ends = any(re.match(r'(jr|j|b|eret)\b', t) or re.match(r'beq\s+\$zero,\s*\$zero', t) for t in tail)
    if ends: continue
    name = os.path.basename(f)[:-2]
    twin = name in rec
    csrc = name in srcs and name not in cskip
    print('%-16s %-5s %-12s last: %s' % (name, 'TWIN' if twin else '', 'C' if csrc else ('C-skipped' if name in srcs else ''), ' | '.join(tail)))
