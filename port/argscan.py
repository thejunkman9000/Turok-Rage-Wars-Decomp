"""Find C call sites that pass fewer register arguments than the recompiled callee reads.

A recompiled function (port/native/recomp/<name>.c) starts with
    r[4] = a0; r[5] = a1; r[6] = a2; r[7] = a3;
and then reads whichever of r[4..7] the MIPS code used as incoming
arguments - directly, or by passing the still-untouched register on to a
callee (`func_Y(r[4], r[5], r[6], r[7])`) that reads it.  A matching C decomp
may declare fewer parameters (the MIPS code is identical whether the extra
registers were "passed" or just left alone), so a C caller pushes fewer words
and the x86 callee reads stack garbage where the N64 saw a live register.
func_0041CE88 -> func_0041C680 and func_002171FC -> fn110 -> func_00219A40
were two instances.

Usage: python port/argscan.py [--all] [--maybe]
  default : C call sites whose callee is linked from the recompiler and
            certainly reads more incoming registers than the call passes
  --maybe : also list callees that pass the register to an indirect call
  --all   : every C call of a recompiled function with its counts
"""
import glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RECOMP = os.path.join(ROOT, 'port', 'native', 'recomp')
MAP = os.path.join(ROOT, 'port', 'build', 'turok.map')
SRC = [os.path.join(ROOT, 'src'), os.path.join(ROOT, 'port', 'overrides'),
       os.path.join(ROOT, 'port', 'nonmatching')]

REG_RE = re.compile(r'(?<![\w\[])r\[(\d+)\]')
WRITE_RE = re.compile(r'^\s*r\[(\d+)\]\s*=[^=]')
CALL_RE = re.compile(r'\)\s*(func_[0-9A-F]{8}|[A-Za-z_]\w*)\)\(|port_resolve\([^;]*?\)\)\(')
C_CALL_RE = re.compile(r'(?<![\w.>])(func_[0-9A-F]{8}|[a-z_][\w]*)\s*\(')
C_DEF_RE = re.compile(r'^(?:static\s+)?(?:const\s+)?(?:unsigned\s+|signed\s+)?[A-Za-z_]\w*[\s\*]+(func_[0-9A-F]{8}|[A-Za-z_]\w*)\s*\(([^;{}]*?)\)\s*\{', re.M)
TYPE_WORDS = r'(const\s+)?(void|u32|s32|u8|s8|u16|s16|f32|f64|float|double|int|char|unsigned|short|long|[A-Z]\w*)\b'


def balanced_args(text, i):
    """Split the argument list starting at text[i] (just after '(') at depth 0; return (args, end)."""
    depth, args, cur = 0, [], ''
    while i < len(text):
        c = text[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            if depth == 0:
                break
            depth -= 1
        if c == ',' and depth == 0:
            args.append(cur); cur = ''
        else:
            cur += c
        i += 1
    args.append(cur)
    if len(args) == 1 and not args[0].strip():
        args = []
    return args, i


def analyse_recomp(path):
    """Return (direct_uses, deps): direct = set of incoming arg indices (0..3) read before any write;
    deps = set of (callee or '*', k) meaning 'arg k is used iff callee uses its arg k'."""
    body = open(path, encoding='utf-8', errors='replace').read()
    m = re.search(r'r\[4\] = a0; r\[5\] = a1; r\[6\] = a2; r\[7\] = a3;', body)
    if not m:
        return None
    body = body[m.end():]
    nxt = re.search(r'\n\}\n', body)
    if nxt:
        body = body[:nxt.end()]
    written = set()
    direct, deps = set(), set()
    for stmt in re.split(r'[;{}]', body):
        calls = []
        for cm in CALL_RE.finditer(stmt):
            callee = cm.group(1) or '*'
            args, _ = balanced_args(stmt, cm.end())
            calls.append((callee, args, cm.end()))
        passthrough_spans = []
        for callee, args, start in calls:
            pos = start
            for k, a in enumerate(args[:4]):
                reg = 4 + k
                if a.strip() == 'r[%d]' % reg and reg not in written:
                    deps.add((callee, k))
                    passthrough_spans.append((pos, pos + len(a) + 1))
                pos += len(a) + 1
        for rm in REG_RE.finditer(stmt):
            reg = int(rm.group(1))
            if reg < 4 or reg > 7 or reg in written:
                continue
            if any(s <= rm.start() < e for s, e in passthrough_spans):
                continue
            wm = WRITE_RE.match(stmt)
            if wm and int(wm.group(1)) == reg and rm.start() == wm.start(1) - 2:
                continue  # the write itself
            direct.add(reg - 4)
        wm = WRITE_RE.match(stmt)
        if wm:
            written.add(int(wm.group(1)))
    return direct, deps


def scan_c_calls(text):
    """Yield (name, line, nargs) for every direct call in a C source (prototypes/definitions skipped)."""
    for m in C_CALL_RE.finditer(text):
        name = m.group(1)
        if re.match(r'func_[0-9A-F]{6}$', name):
            name = 'func_00' + name[5:]   # build_clang.py expands the short names the same way
        line_start = text.rfind('\n', 0, m.start()) + 1
        prefix = text[line_start:m.start()]
        if re.search(r'(^|\s|\*)' + TYPE_WORDS.replace('\\b', '') + r'\s*\**\s*$', prefix) and \
                not re.search(r'[=(,?:]\s*$', prefix):
            continue
        args, _ = balanced_args(text, m.end())
        if args and re.match(r'\s*' + TYPE_WORDS + r'[\s*]*\w*\s*$', args[0]) and not re.search(r'[=(,?:]\s*$', prefix):
            continue
        yield name, text.count('\n', 0, m.start()) + 1, len(args)


def c_param_count(params):
    params = params.strip()
    if not params or params == 'void':
        return 0
    return params.count(',') + 1


def read_map():
    """symbol -> object basename from the MSVC map, or {} when there is no map."""
    out = {}
    if not os.path.exists(MAP):
        return out
    for line in open(MAP, encoding='utf-8', errors='replace'):
        parts = line.split()
        if len(parts) >= 4 and re.match(r'[0-9a-f]{4}:[0-9a-f]{8}$', parts[0], re.I):
            sym = parts[1].lstrip('_')
            if sym not in out:
                out[sym] = parts[-1]
    return out


def main():
    show_all, show_maybe = '--all' in sys.argv, '--maybe' in sys.argv
    rows, recomp, cdefs, objs = collect(show_all, show_maybe)
    for rel, line, name, n, hard, soft, kind in rows:
        print('%s:%d %s(%s) C=%d reads=%d maybe=%d%s' % (rel, line, name, kind, n, hard, soft, '' if n < hard else ' (indirect only)'))
    print('%d call sites listed; %d recompiled functions, %d C definitions, map %s' % (
        len(rows), len(recomp), len(cdefs), 'used' if objs else 'absent'))


def collect(show_all=False, show_maybe=False):
    """Return (rows, recomp, cdefs, objs); rows = (file, line, callee, passed, reads, maybe, kind)."""
    objs = read_map()
    recomp = {}
    asmargs = {}   # hand-written libultra assembly (src/**/*.s): registers read before written, so __osDisableInt() etc. do not count as 'uses everything'
    try:
        import mips2c
        for path in glob.glob(os.path.join(ROOT, 'src', '**', '*.s'), recursive=True):
            text = open(path, encoding='utf-8', errors='replace').read()
            for name in re.findall(r'glabel (\S+)', text):
                try:
                    asmargs[name] = mips2c.int_arg_count(mips2c.parse(text, name))
                except Exception:
                    pass
    except ImportError:
        pass
    for path in sorted(glob.glob(os.path.join(RECOMP, '*.c'))):
        name = os.path.basename(path)[:-2]
        r = analyse_recomp(path)
        if r is not None:
            recomp[name] = r
    cdefs, csites = {}, []
    overrides = {os.path.basename(p)[:-2] for p in glob.glob(os.path.join(ROOT, 'port', 'overrides', '*.c'))}
    for d in SRC:
        for path in sorted(glob.glob(os.path.join(d, '**', '*.c'), recursive=True)):
            base = os.path.basename(path)[:-2]
            if base.split('__')[0] in overrides and not path.startswith(os.path.join(ROOT, 'port', 'overrides')):
                continue   # the override replaces this file (src copy or nonmatching copy)
            text = open(path, encoding='utf-8', errors='replace').read()
            rel = os.path.relpath(path, ROOT)
            for dm in C_DEF_RE.finditer(text):
                cdefs.setdefault(dm.group(1), c_param_count(dm.group(2)))
            for name, line, n in scan_c_calls(text):
                csites.append((rel, line, name, n))

    def linked_from_recomp(name):
        if objs:
            o = objs.get(name, '')
            return o.startswith('ar_')  # recompiled objects link as ar_<name>.obj
        return name in recomp and not glob.glob(os.path.join(ROOT, 'port', 'nonmatching', name + '__ovr.c'))

    # fixed point: used[name] = set of certainly-read incoming args; maybe[name] adds indirect-call pass-through
    used = {n: set(d) for n, (d, _) in recomp.items()}
    maybe = {n: set(d) for n, (d, _) in recomp.items()}
    for n in recomp:
        if not linked_from_recomp(n) and n in cdefs:
            used[n] = maybe[n] = set(range(cdefs[n]))
    changed = True
    while changed:
        changed = False
        for n, (d, deps) in recomp.items():
            if not linked_from_recomp(n) and n in cdefs:
                continue
            for callee, k in deps:
                if callee == '*':
                    tgt_used, tgt_maybe = set(), set(range(4))
                elif callee in used:
                    tgt_used, tgt_maybe = used[callee], maybe[callee]
                elif callee in cdefs:
                    tgt_used = tgt_maybe = set(range(cdefs[callee]))
                elif callee in asmargs:
                    tgt_used = tgt_maybe = set(range(asmargs[callee]))
                else:
                    tgt_used, tgt_maybe = set(), set(range(4))  # unknown callee (libultra etc.)
                if k in tgt_used and k not in used[n]:
                    used[n].add(k); changed = True
                if k in tgt_maybe and k not in maybe[n]:
                    maybe[n].add(k); changed = True

    def need(s):
        return max(s) + 1 if s else 0

    def caller_linked(rel):
        """Is this source file the one the map links for its function (drafts lose to ar_/ovr objects)?"""
        if not objs:
            return True
        base = os.path.basename(rel)[:-2]
        o = objs.get(base.split('__')[0], '')
        if not o:
            return os.path.basename(os.path.dirname(rel)) != 'nonmatching'
        return re.sub(r'^(ar|nm|ov|lu|nt)_(?=func_)', '', o[:-4]) == base

    rows = []
    for rel, line, name, n in csites:
        if not caller_linked(rel):
            continue
        if name in recomp and linked_from_recomp(name):
            hard, soft = need(used[name]), need(maybe[name])
        elif name in cdefs and name.startswith('func_'):
            hard = soft = cdefs[name]   # C callee: every declared parameter counts (unprototyped callers pass fewer)
        else:
            continue
        if n < hard or (show_maybe and n < soft) or show_all:
            kind = 'recomp' if name in recomp and linked_from_recomp(name) else 'C'
            rows.append((rel, line, name, n, hard, soft, kind))
    return rows, recomp, cdefs, objs


if __name__ == '__main__':
    main()
