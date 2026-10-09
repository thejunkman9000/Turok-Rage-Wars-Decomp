"""Write overrides that forward pass-through argument registers (see passthru.py).

For every C function with a flagged call whose missing argument register was live (the caller's
own incoming register, untouched since entry), this
  - maps the caller's parameters to MIPS argument registers (a hidden struct-return pointer takes
    a0, by-value Vec3f/Quat4 take 3/4 slots, leading floats sit in f12/f14 instead),
  - extends the caller's parameter list so every needed register has a name (`u32 pt_aK`),
  - appends the missing arguments at the call (the caller's parameter for a live register, 0 for
    one the N64 code had already clobbered - garbage on both machines),
  - widens the callee's local prototype to match,
and writes the result to port/overrides/<caller>.c plus its port/nonmatching copy.  Callers whose
register mapping cannot be expressed (a needed register holds float bits or part of a by-value
struct) are listed for a manual override.

Usage: python port/passthru_fix.py          # dry run: show the planned edits
       python port/passthru_fix.py --write  # write the overrides
"""
import glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'port'))
import argscan, passthru  # noqa: E402

TYPE_SET = {'void', 'u8', 's8', 'u16', 's16', 'u32', 's32', 'f32', 'f64', 'float', 'double', 'int', 'char',
            'unsigned', 'signed', 'short', 'long', 'const', 'volatile', 'struct', 'enum', 'static', 'extern'}
STRUCT_SLOTS = {'Vec3f': 3, 'Vec3': 3, 'Vec3s': 2, 'Quat4': 4, 'Quat': 4, 'Vec4f': 4}


def split_params(s):
    parts, depth, cur = [], 0, ''
    for ch in s:
        if ch in '([':
            depth += 1
        elif ch in ')]':
            depth -= 1
        if ch == ',' and depth == 0:
            parts.append(cur); cur = ''
        else:
            cur += ch
    parts.append(cur)
    parts = [p.strip() for p in parts]
    return [] if parts in ([''], ['void']) else parts


def param_name(p):
    m = re.search(r'\(\s*\*\s*(\w+)\s*\)', p)   # function pointer
    if m:
        return m.group(1)
    words = re.findall(r'\w+', p)
    m = re.search(r'(\w+)\s*(\[[^\]]*\])*\s*$', p)
    if not m or len(words) < 2 or m.group(1) in TYPE_SET:
        return None
    return m.group(1)


def reg_map(params, sret):
    """Return (slot -> expression or None, new param texts, next free slot) or None when a parameter's
    size is unknown.  None expressions mark registers that hold float bits or struct words."""
    regs, texts = {}, []
    slot = 1 if sret else 0
    prev_int = sret
    for p in params:
        n = param_name(p)
        ptr = '*' in p
        is_float = bool(re.search(r'\b(f32|f64|float|double)\b', p)) and not ptr
        words = [w for w in re.findall(r'\w+', p) if w not in TYPE_SET]
        type_word = next((w for w in re.findall(r'\w+', p) if w not in {'static', 'extern', 'const', 'volatile', 'struct', 'enum'}), '')
        if is_float:
            size = 2 if re.search(r'\b(f64|double)\b', p) else 1
            if size == 2 and slot % 2:
                slot += 1
            for j in range(size):
                regs[slot + j] = None     # f12/f14, or float bits in an integer register
            slot += size
            texts.append(p)
            continue
        if not ptr and '(*' not in p and type_word not in TYPE_SET:
            size = STRUCT_SLOTS.get(type_word)
            if size is None:
                return None
            for j in range(size):
                regs[slot + j] = None
            slot += size
            texts.append(p)
            continue
        if n is None:
            n = 'pt_a%d' % slot
            p = (p.rstrip() + n) if p.rstrip().endswith('*') else (p.rstrip() + ' ' + n)
        regs[slot] = n
        texts.append(p)
        prev_int = True
        slot += 1
    return regs, texts, slot


def plan(sites, cdefs):
    """Group the pass-through sites per caller file and build the edited text for each."""
    by_file = {}
    for d in sites:
        if d['verdict'] == 'PASS':
            by_file.setdefault(d['file'], []).append(d)
    results = []
    for rel, rows in sorted(by_file.items()):
        caller = rows[0]['caller']
        src = os.path.join(ROOT, rel)
        text = open(src, encoding='utf-8').read()
        dm = next((m for m in argscan.C_DEF_RE.finditer(text) if m.group(1) == caller), None)
        if not dm:
            results.append((rel, caller, None, 'definition not found')); continue
        rtype = text[dm.start():dm.start(1)].strip()
        rword = next((w for w in re.findall(r'\w+', rtype) if w not in {'static', 'extern', 'const'}), 'void')
        sret = '*' not in rtype and rword not in TYPE_SET
        params = split_params(dm.group(2))
        rm = reg_map(params, sret)
        if rm is None:
            results.append((rel, caller, None, 'parameter of unknown size: (%s)' % dm.group(2).strip())); continue
        regs, texts, free = rm
        need = max(d['need'] for d in rows)
        for k in range(free, need):
            regs[k] = 'pt_a%d' % k; texts.append('u32 pt_a%d' % k)
        bad = [k for d in rows for k in d['live'] if regs.get(k) is None]
        if bad:
            results.append((rel, caller, None, 'needed register %s holds float/struct bits: %s(%s)%s' % (
                ' '.join('a%d' % k for k in sorted(set(bad))), rtype, dm.group(2).strip(), ' [struct return]' if sret else ''))); continue
        edits = []
        if texts != params:
            edits.append((dm.start(2), dm.end(2), ', '.join(texts)))
        callees, ok = {}, True
        lines = text.split('\n')
        for d in sorted(rows, key=lambda d: -d['line']):
            line_start = sum(len(l) + 1 for l in lines[:d['line'] - 1])
            line_end = text.find('\n', line_start)
            if line_end < 0:
                line_end = len(text)
            pat = r'\b(' + re.escape(d['callee']) + (r'|func_' + d['callee'][7:] if d['callee'].startswith('func_00') else '') + r')\s*\('
            hit = None
            for cm in re.finditer(pat, text[line_start:line_end]):
                args, end = argscan.balanced_args(text, line_start + cm.end())
                if len(args) == d['passed']:
                    hit = (args, end); break
            if not hit:
                results.append((rel, caller, None, 'call of %s with %d args not found on line %d' % (d['callee'], d['passed'], d['line'])))
                ok = False; break
            args, end = hit
            extra = [regs[k] if k in d['live'] else '0' for k in range(d['passed'], d['need'])]
            edits.append((end, end, (', ' if args else '') + ', '.join(extra)))
            callees[d['callee']] = max(callees.get(d['callee'], 0), d['need'])
        if not ok:
            continue
        for callee, need_c in callees.items():   # widen the local prototypes of the callees
            pat = r'\b(' + re.escape(callee) + (r'|func_' + callee[7:] if callee.startswith('func_00') else '') + r')\s*\(([^;{}]*?)\)\s*;'
            for pm in re.finditer(pat, text):
                prefix = text[text.rfind('\n', 0, pm.start()) + 1:pm.start()]
                if not re.match(r'\s*(static\s+|extern\s+|const\s+)*[A-Za-z_]\w*[\s\*]+$', prefix) or re.match(r'\s*return\b', prefix):
                    continue   # a call statement, not a declaration
                ps = split_params(pm.group(2))
                if pm.group(2).strip() == '' or len(ps) >= need_c:
                    continue   # K&R declaration, or already wide enough
                edits.append((pm.start(2), pm.end(2), ', '.join(ps + ['u32'] * (need_c - len(ps)))))
        for s, e, r in sorted(edits, key=lambda t: -t[0]):
            text = text[:s] + r + text[e:]
        note = '/* port (passthru_fix.py): %s - the MIPS code passed this function\'s own incoming registers on to the callee; the C decomp dropped them. */\n' % ', '.join(
            '%s needs %s' % (d['callee'], ' '.join(passthru.AREG[k] for k in d['live'])) for d in rows)
        results.append((rel, caller, note + text, 'ok'))
    return results


def main():
    write = '--write' in sys.argv
    sites, cdefs = passthru.analyse('--maybe' in sys.argv)
    results = plan(sites, cdefs)
    written = []
    for rel, caller, text, status in results:
        print('%s: %s' % (rel, status))
        if text is None:
            continue
        if write:
            ovr = os.path.join(ROOT, 'port', 'overrides', caller + '.c')
            open(ovr, 'w', encoding='utf-8', newline='\n').write(text)
            drafts = glob.glob(os.path.join(ROOT, 'port', 'nonmatching', caller + '__*.c'))
            dst = drafts[0] if drafts else os.path.join(ROOT, 'port', 'nonmatching', caller + '__ovr.c')
            open(dst, 'w', encoding='utf-8', newline='\n').write(text)
            written.append(caller)
        elif '--diff' in sys.argv:
            import difflib
            orig = open(os.path.join(ROOT, rel), encoding='utf-8').read().split('\n')
            for l in difflib.unified_diff(orig, text.split('\n')[1:], lineterm='', n=0):
                if l.startswith(('+', '-')) and not l.startswith(('+++', '---')):
                    print('    ' + l[:170])
        else:
            for l in text.split('\n')[1:]:
                if 'pt_a' in l or re.search(r'\b(func_\w+)\s*\(.*\b(pt_a|, 0\))', l):
                    print('    ' + l.strip()[:150])
    if write:
        print('written %d overrides: %s' % (len(written), ' '.join(written)))
        print('next: rm port/build/obj_c/{%s}.obj; python port/build_clang.py --only %s; relink' % (','.join(written), ','.join(written)))


if __name__ == '__main__':
    main()
