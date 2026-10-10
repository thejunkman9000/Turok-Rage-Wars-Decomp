#!/usr/bin/env python3
"""One-screen summary of a port run log: the CRASH report (symbolized with port/build/turok.map), the first stack frames, the tail of the
call trace ring and the last game states.   usage: python port/crashsum.py [run.log]    (exit code 1 when the log holds a crash)"""
import bisect, re, sys
syms = []; base = None
for l in open('port/build/turok.map', errors='replace'):
    m = re.match(r'\s*Preferred load address is ([0-9a-f]+)', l)
    if m: base = int(m.group(1), 16)
    m = re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
    if m and base is not None and int(m.group(2), 16) >= base: syms.append((int(m.group(2), 16) - base, m.group(1)))
syms.sort(); keys = [s[0] for s in syms]
def where(rva):
    i = bisect.bisect_right(keys, rva) - 1
    return '%s+0x%X' % (syms[i][1].lstrip('_'), rva - syms[i][0]) if i >= 0 else '?'
log = open(sys.argv[1] if len(sys.argv) > 1 else 'port/build/run.log', errors='replace').read().split('\n')
crash = [i for i, l in enumerate(log) if 'CRASH(raw' in l or l.startswith('game thread exception')]
states = [re.search(r'game state: g=\w+ st=(\d+)', l).group(1) for l in log if 'game state: g=' in l]
print('last states:', ' '.join(states[-8:]) or '-', '| distinct:', ' '.join(sorted(set(states), key=int)))
soft = [i for i, l in enumerate(log) if l.startswith('SOFTFAULT')]
for i in soft[:8]:                              # null-page accesses the port recovered from (port/softfault.c): site and callers
    m = re.search(r'SOFTFAULT (\w+) acc=(\d) addr=([0-9A-F]+) rva=([0-9A-F]+)', log[i])
    fr = []
    if i + 1 < len(log) and 'stack rvas:' in log[i + 1]:
        for r in [t for t in log[i + 1].split(':', 1)[1].split() if re.fullmatch(r'[0-9A-F]{1,8}', t)][:6]:
            w = where(int(r, 16))
            if not fr or fr[-1] != w: fr.append(w)
    if m: print('SOFTFAULT %s addr=%s at %s < %s' % (m.group(1), m.group(3), where(int(m.group(4), 16)), ' < '.join(fr)))
if len(soft) > 8: print('  ... %d softfault sites in total' % len(soft))
if not crash:
    print('no crash'); sys.exit(0)
l = log[crash[0]]
m = re.search(r'rva=([0-9A-F]+) acc=(\d) addr=([0-9A-F]+)', l)
print('CRASH', l.strip()[:200])
if m: print('  at', where(int(m.group(1), 16)), '| access', m.group(2), 'addr', m.group(3))
for l in log[crash[0]:crash[0] + 8]:
    m = re.search(r'stack rvas:(.*)', l)
    if m:
        fr = []
        for r in [t for t in m.group(1).split() if re.fullmatch(r'[0-9A-F]{1,8}', t)][:24]:
            w = where(int(r, 16))
            if not fr or fr[-1] != w: fr.append(w)
        print('  stack:', ' < '.join(fr[:12]))
        break
for l in log[crash[0]:crash[0] + 12]:
    if l.strip().startswith('trace (oldest first):'):
        out = []
        for it in l.split(':', 1)[1].split():
            t, r = it.split(':'); nm = where(int(r, 16) - 1).split('+')[0]
            if out and out[-1][0] == nm: out[-1][1] += 1
            else: out.append([nm, 1])
        print('  trace:', ' > '.join(nm + ('' if n == 1 else '(x%d)' % n) for nm, n in out[-14:]))
        break
sys.exit(1)
