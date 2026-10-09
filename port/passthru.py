"""For every call site argscan.py flags, decide from the caller's original MIPS code whether the
missing argument registers still held the caller's own incoming arguments at the jal.

If a register in a0..a3 is read by the callee but the C caller does not pass it, the N64 passed
whatever the register held.  When nothing in the caller wrote that register before the jal (no
instruction targets it and no earlier call clobbered it), that was the caller's own argument -
the original source passed it through explicitly and the compiler had nothing to emit.  The x86
build must forward it (extend the caller's parameter list and the call); passthru_fix.py writes
those overrides.  When the register was written, the original did not pass it and the callee
tolerates garbage on both machines.

Usage: python port/passthru.py            # pass-through sites only
       python port/passthru.py --all      # every flagged site with its verdict
"""
import glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'port'))
import argscan, mips2c  # noqa: E402

AREG = ('a0', 'a1', 'a2', 'a3')
REG_RE = re.compile(r'\$(zero|at|v[01]|a[0-3]|t[0-9]|s[0-8]|k[01]|gp|sp|fp|ra)(?![\w])')


def asm_files():
    out = {}
    for p in glob.glob(os.path.join(ROOT, 'port', 'build', 'asm_func', '*.s')):
        out[os.path.basename(p)[:-2]] = p
    return out


def regs_written_by(m, ops):
    regs = [REG_RE.findall(o) for o in ops]
    if m in ('jal', 'jalr'):
        return set(AREG) | {'v0', 'v1', 'ra'}
    if m in mips2c._DEST_FIRST and ops:
        return set(regs[0])
    return set()


def jal_targets(items):
    """Yield (callee, registers written before the call) for each jal in the function, in order."""
    written = set()
    ins = [it for it in items if it[0] == 'ins']
    for n, it in enumerate(ins):
        m, ops = it[1], it[2]
        if m == 'jal' and ops:
            w = set(written)
            if n + 1 < len(ins):   # the delay slot runs before the call
                w |= regs_written_by(ins[n + 1][1], ins[n + 1][2])
            yield ops[0].lstrip('$'), w
        written |= regs_written_by(m, ops)


def analyse(maybe=False):
    """One dict per flagged call site: file, line, callee, passed, need, verdict ('PASS'/'garbage'/'no asm'/
    'no jal'), live (pass-through registers as indices), caller."""
    rows, recomp, cdefs, objs = argscan.collect(show_maybe=maybe)
    asm = asm_files()
    out = []
    for rel, line, callee, n_c, need, soft, kind in rows:
        caller = os.path.basename(rel)[:-2].split('__')[0]
        need = min(soft if maybe else need, 4)
        d = dict(file=rel, line=line, callee=callee, passed=n_c, need=need, caller=caller, live=[], verdict='')
        out.append(d)
        p = asm.get(caller) or asm.get(caller.replace('func_00', 'func_'))
        if not p:
            d['verdict'] = 'no asm'; continue
        items = mips2c.parse(open(p, encoding='utf-8').read(), caller)
        missing = [k for k in range(n_c, need)]
        live = set()
        found = False
        for tgt, written in jal_targets(items):
            if re.match(r'func_[0-9A-F]{6}$', tgt):
                tgt = 'func_00' + tgt[5:]
            if tgt != callee:
                continue
            found = True
            live.update(k for k in missing if AREG[k] not in written)
        if not found:
            d['verdict'] = 'no jal'; continue
        d['live'] = sorted(live)
        d['verdict'] = 'PASS' if live else 'garbage'
    return out, cdefs


def main():
    show_all = '--all' in sys.argv
    out, cdefs = analyse('--maybe' in sys.argv)
    for d in out:
        if d['verdict'] == 'PASS' or show_all:
            print('%s:%d %s C=%d reads=%d  %s %s  caller has %s params' % (
                d['file'], d['line'], d['callee'], d['passed'], d['need'], d['verdict'],
                ' '.join(AREG[k] for k in d['live']), cdefs.get(d['caller'])))
    print('%d sites, %d pass-through' % (len(out), sum(1 for d in out if d['verdict'] == 'PASS')))


if __name__ == '__main__':
    main()
