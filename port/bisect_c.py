#!/usr/bin/env python3
"""Behaviour bisect for the port: run chosen matched-C functions as statically recompiled MIPS instead.
usage: python port/bisect_c.py set func_00226DAC func_... | reset | regen
  set    port/c_skip.txt := the manifest sources that cover the names (build_clang.py does not compile them); every asm-index
         function inside those sources' ROM ranges is added to port/recomp.txt (port/recomp_base.txt keeps the original list);
         then gen_recomp.py runs (PORT_NO_ASM_REGEN=1) - build_clang.py and port\\relink.ps1 are up to you
  reset  c_skip.txt removed, recomp.txt restored
  regen  only regenerate port/native/recomp from the current recomp.txt"""
import os, re, shutil, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

def entries():
    out = []
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(fn):
            f = l.split('#')[0].split()
            if len(f) >= 4 and not f[0].startswith('pad_') and f[3] in ('game', 'ovl_a'): out.append((f[0], int(f[1], 16), int(f[2]), f[3]))
    return out

def va_of_rom(rom):
    return rom - 0x16E000 + 0x400000 if rom >= 0x16E000 else rom - 0x1000 + 0x200400

def regen():
    env = dict(os.environ, PORT_NO_ASM_REGEN='1')
    r = subprocess.run([sys.executable, 'port/gen_recomp.py'], env=env, capture_output=True, text=True)
    print((r.stdout.strip().split('\n') or [''])[-1][:100]); sys.stdout.flush()
    for l in (r.stdout + r.stderr).split('\n'):
        if l.startswith(('FAILED', 'no asm')): print(l[:160])

def main():
    cmd = sys.argv[1]
    if cmd == 'reset':
        if os.path.exists('port/c_skip.txt'): os.remove('port/c_skip.txt')
        if os.path.exists('port/recomp_base.txt'): shutil.copy('port/recomp_base.txt', 'port/recomp.txt')
        regen(); return
    if cmd == 'regen': regen(); return
    names = sys.argv[2:]
    if not os.path.exists('port/recomp_base.txt'): shutil.copy('port/recomp.txt', 'port/recomp_base.txt')
    base = [l.strip() for l in open('port/recomp_base.txt') if l.strip()]
    idx = sorted(int(re.fullmatch(r'func_([0-9A-F]{8})\.s', f).group(1), 16) for f in os.listdir('port/build/asm_func') if re.fullmatch(r'func_[0-9A-F]{8}\.s', f))
    ents = entries()
    skip, force, per = set(), set(), {}
    for n in names:
        if not re.fullmatch(r'func_[0-9A-F]{8}', n): continue
        va = int(n[5:], 16)
        hit = [e for e in ents if e[0] == n] or [e for e in ents if va_of_rom(e[1]) <= va < va_of_rom(e[1]) + 4 * e[2]]      # an entry may start after its (stray head words) name
        if not hit: print('no manifest entry covers', n); continue
        e = hit[0]; skip.add(e[0]); lo = va_of_rom(e[1]); hi = lo + 4 * e[2]
        member = {'func_%08X' % a for a in idx if lo <= a < hi}
        force.update(member); per.setdefault(e[0], set()).update(member)
    open('port/c_skip.txt', 'w', newline='\n').write('\n'.join(sorted(skip)) + '\n')
    open('port/recomp.txt', 'w', newline='\n').write('\n'.join(base + sorted(force - set(base))) + '\n')
    print(len(skip), 'sources skipped,', len(force), 'functions recompiled'); sys.stdout.flush()
    regen()
    # a twin that could not be generated (unsupported instruction / float signature) leaves the function missing: keep that source as C
    bad = sorted(st for st, ns in per.items() if any(not os.path.exists('port/native/recomp/%s.c' % n) for n in ns))
    if bad:
        skip -= set(bad)
        drop = set().union(*(per[st] for st in bad)) - set(base)
        open('port/c_skip.txt', 'w', newline=chr(10)).write(chr(10).join(sorted(skip)) + chr(10))
        open('port/recomp.txt', 'w', newline=chr(10)).write(chr(10).join(base + sorted(force - drop - set(base))) + chr(10))
        print('kept as C (no twin possible):', ' '.join(bad)[:300])

if __name__ == "__main__":
    main()
