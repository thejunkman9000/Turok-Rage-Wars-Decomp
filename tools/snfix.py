#!/usr/bin/env python3
"""Post-processors for the cc1 -S output in the SN pipeline (called by lu_match.py before n64link asn64).
usage: snfix.py <file.s> [@EPI] [@L] [@K] [@Z] [@M]
  @EPI  unfilled return slot of the low code region (`.set noreorder; j $31; addu $sp,$sp,N` -> `addu $sp,$sp,N; j $31`; asn64 adds the nop)
  @L    gcc 2.7.2-style delay-slot policy for `if (x == 0) return v;` (branch-likely with a copy of the return block's first insn in the slot)
  @K    gcc 2.7.2-style loop back edge: branch-likely to the loop top with a copy of the loop-top `li` in the slot
  @Z    dead epilogue after an endless loop (gcc 2.7.2 keeps it, 2.8.1 drops it)
  @M    mult/div never in a branch delay slot (not needed with real asn64 path; kept for completeness)
(code derived from the multfix.py / epifix.py of workspaces r01/s401, which proved these shapes EXACT for the ROM's low region)"""
import re, sys
sys.path.insert(0, __import__('os').path.dirname(__import__('os').path.abspath(__file__)))

_PAT = re.compile(r'(\t\.set\tnoreorder\n\t\.set\tnomacro\n)(\t(?:beq|bne|beqz|bnez|blez|bgtz|bltz|bgez|bc1t|bc1f|j)\t[^\n]*\n)(\t(?:mult|multu|div|divu)\t[^\n]*\n)(\t\.set\tmacro\n\t\.set\treorder\n)')
def mult_unslot(s):
    return _PAT.sub(lambda m: m.group(3) + m.group(1) + m.group(2) + '\tnop\n' + m.group(4), s)

_FRAME = re.compile(r'\t\.frame\t\$sp,(\d+),\$31')
def dead_epilogue(s):
    out = []
    for m in re.finditer(r'\t\.ent\t(\w+)\n(.*?)\t\.end\t\1\n', s, re.S):
        body = m.group(2)
        fm = _FRAME.search(body)
        tail = body.rstrip()
        lines = [l for l in tail.split('\n') if l.strip() and not l.strip().startswith('.set')]
        if not fm or not lines: continue
        if len(lines) >= 2 and re.match(r'\t(j)\t[$.]L\d+', lines[-2]) or (lines and re.match(r'\t(j)\t[$.]L\d+', lines[-1])):
            frame = int(fm.group(1))
            saves = re.findall(r'\tsw\t\$(\d+),(\d+)\(\$sp\)', body[:body.find('\n\n') if '\n\n' in body else 2000])
            saves = sorted(set((int(o), int(r)) for r, o in saves), reverse=True)
            epi = ''.join('\tlw\t$%d,%d($sp)\n' % (r, o) for o, r in saves)
            epi += '\t.set\tnoreorder\n\t.set\tnomacro\n\tj\t$31\n\taddu\t$sp,$sp,%d\n\t.set\tmacro\n\t.set\treorder\n' % frame
            out.append((m.start(0), m.end(0), m.group(0).replace('\t.end\t' + m.group(1) + '\n', epi + '\t.end\t' + m.group(1) + '\n')))
    for a, b, rep in reversed(out):
        s = s[:a] + rep + s[b:]
    return s

def likely_return(s):
    pat = re.compile(r'\t\.set\tnoreorder\n\t\.set\tnomacro\n\t(beq|bne)\t(\$\d+),\$0,([$.]L\d+)\n(\t[^\n]*\n)\t\.set\tmacro\n\t\.set\treorder\n')
    n = [0]
    def repl(m):
        op, reg, lab, slot = m.groups()
        if slot.startswith('	li	'): return m.group(0)
        tm = re.search(re.escape(lab) + r':\n(\t[^\n]*\n)([$.]L\d+):\n\tlw\t\$31,', s)
        if not tm or tm.start() < m.end(): return m.group(0)
        n[0] += 1
        new = '.LR%d' % n[0]
        first = tm.group(1)
        likely = 'beql' if op == 'beq' else 'bnel'
        repl.fix.append((lab, first, new))
        return ('\t.set\tnoreorder\n\t.set\tnomacro\n\t%s\t%s,$0,%s\n%s\t.set\tmacro\n\t.set\treorder\n%s' % (likely, reg, new, first, slot))
    repl.fix = []
    s2 = pat.sub(repl, s)
    for lab, first, new in repl.fix:
        s2 = s2.replace(lab + ':\n' + first, lab + ':\n' + first + new + ':\n', 1)
    return s2

def loop_likely(s):
    m = re.search(r'\tli\t(\$\d+),(-?\d+)[^\n]*\n([$.]L\d+):\n((?:[$.]L\d+:\n)*)(\t[^\n]*\n)((?:[$.]L\d+:\n)*)', s)
    if not m: return s
    Y, imm, top = m.group(1), m.group(2), m.group(3)
    lis = m.group(0).split(chr(10))[0] + chr(10)
    nxt = re.findall(r'[$.]L\d+', m.group(6))
    pat1 = re.compile(r'\t\.set\tnoreorder\n\t\.set\tnomacro\n\t(bne|beq)\t(\$\d+),\$0,%s\n%s\t\.set\tmacro\n\t\.set\treorder\n' % (re.escape(top), re.escape(lis)))
    s = pat1.sub(lambda mm: '\t.set\tnoreorder\n\t.set\tnomacro\n\t%s\t%s,$0,%s\n%s\t.set\tmacro\n\t.set\treorder\n' % ({'bne': 'bnel', 'beq': 'beql'}[mm.group(1)], mm.group(2), top, lis), s)
    for lb in nxt:
        pat2 = re.compile(r'\t\.set\tnoreorder\n\t\.set\tnomacro\n\t(bne|beq)\t(\$\d+),\$0,%s\n(\t[^\n]*\n)\t\.set\tmacro\n\t\.set\treorder\n' % re.escape(lb))
        s = pat2.sub(lambda mm: '\t.set\tnoreorder\n\t.set\tnomacro\n\t%s\t%s,$0,%s\n%s\t.set\tmacro\n\t.set\treorder\n%s' % ({'bne': 'bnel', 'beq': 'beql'}[mm.group(1)], mm.group(2), top, lis, mm.group(3)), s)
    return s

def epi(s):
    return re.sub(r'(?:\t\.set\tnoreorder\n\t\.set\tnomacro\n)?\tj\t\$31\n\taddu\t(\$sp,\$sp,\d+)\n(?:\t\.set\tmacro\n\t\.set\treorder\n)?',
                  r'\taddu\t\1\n\tj\t$31\n', s)

if __name__ == '__main__':
    p = sys.argv[1]
    toks = sys.argv[2:]
    s = open(p).read()
    if '@L' in toks: s = likely_return(s)
    if '@K' in toks: s = loop_likely(s)
    if '@Z' in toks: s = dead_epilogue(s)
    if '@M' in toks: s = mult_unslot(s)
    if '@EPI' in toks: s = epi(s)
    open(p, 'w').write(s)
