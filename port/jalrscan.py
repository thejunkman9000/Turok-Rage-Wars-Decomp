"""Survey indirect calls (jalr) in C-compiled game functions: which argument registers were still the
function's own incoming arguments at the jalr, versus how many arguments the C function-pointer call
passes.  A C call `state->cb()` passes nothing on x86, while the N64 handed the callee whatever a0..a3
held - the enclosing function's own arguments when nothing wrote them (func_002171FC -> fn110 ->
func_00219A40 crashed the attract demo that way).  Pointer-call targets are unknown statically, so
this only lists candidates for a manual override; the asm/C matching is by order of appearance.

Usage: python port/jalrscan.py
"""
import glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'port'))
import argscan, mips2c, passthru  # noqa: E402

PTR_CALL_RE = re.compile(r'(?:->|\.)\s*(\w+)\s*\(|\(\s*\*\s*(\w+)\s*\)\s*\(|(?<![\w.>])([a-z]\w*)\s*\(')


def c_pointer_calls(text, cdefs):
    """Yield (name, line, nargs) for calls through pointers in a C source (member calls, (*p)(), local/global
    pointer variables that are not known functions)."""
    for m in PTR_CALL_RE.finditer(text):
        name = m.group(1) or m.group(2) or m.group(3)
        if m.group(3) and (name in cdefs or name.startswith(('func_', 'os', 'al', 'gu', 'sqrt', 'sin', 'cos', 'memcpy', 'bzero', 'bcopy', 'strlen', 'if', 'while', 'for', 'return', 'sizeof', 'switch'))):
            continue
        if m.group(3) and not re.search(r'\b(\(\s*\*\s*%s\s*\)|\*\s*%s\b|%s\s*=)' % (name, name, name), text):
            continue   # a plain call of something not declared as a pointer here
        line_start = text.rfind('\n', 0, m.start()) + 1
        if re.search(r'(^|\s|\*)' + argscan.TYPE_WORDS.replace('\\b', '') + r'\s*\**\s*$', text[line_start:m.start()]):
            continue
        args, _ = argscan.balanced_args(text, m.end())
        yield name, text.count('\n', 0, m.start()) + 1, len(args)


def main():
    rows, recomp, cdefs, objs = argscan.collect(show_all=True)
    asm = passthru.asm_files()
    n = 0
    for d in [os.path.join(ROOT, 'src'), os.path.join(ROOT, 'port', 'overrides')]:
        for path in sorted(glob.glob(os.path.join(d, '**', '*.c'), recursive=True)):
            name = os.path.basename(path)[:-2]
            if not name.startswith('func_') or objs.get(name, '').startswith('ar_'):
                continue
            if d.endswith('src') and os.path.exists(os.path.join(ROOT, 'port', 'overrides', name + '.c')):
                continue
            p = asm.get(name)
            if not p:
                continue
            items = mips2c.parse(open(p, encoding='utf-8').read(), name)
            written, jalrs = set(), []
            ins = [it for it in items if it[0] == 'ins']
            for k, it in enumerate(ins):
                m, ops = it[1], it[2]
                if m == 'jalr':
                    w = set(written)
                    if k + 1 < len(ins):
                        w |= passthru.regs_written_by(ins[k + 1][1], ins[k + 1][2])
                    jalrs.append([r for r in passthru.AREG if r not in w])
                written |= passthru.regs_written_by(m, ops)
            if not jalrs:
                continue
            text = open(path, encoding='utf-8', errors='replace').read()
            calls = list(c_pointer_calls(text, cdefs))
            for i, live in enumerate(jalrs):
                c = calls[i] if i < len(calls) else None
                if c is None:
                    print('%s: jalr #%d live %s, no matching C pointer call found' % (os.path.relpath(path, ROOT), i, ' '.join(live) or '-'))
                    n += 1
                elif len(live) > c[2] and any(int(r[1]) >= c[2] for r in live):
                    print('%s:%d %s(...%d args) live at jalr: %s' % (os.path.relpath(path, ROOT), c[1], c[0], c[2], ' '.join(live)))
                    n += 1
    print('%d candidates' % n)


if __name__ == '__main__':
    main()
