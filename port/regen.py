#!/usr/bin/env python3
"""Regenerate everything the Windows port derives from the matched C and rebuild it.  Run after every integration of matched functions.

usage: python port/regen.py [--asm] [--all] [--no-link]
  --asm     rebuild the per-function asm index from the ROM first (slow, ~10 min; needed only after port/forced_entries.txt changed)
  --all     recompile every source (after changes of port/be_ir.py, compiler flags or source filters in port/build_clang.py)
  --no-link stop after the object files

Steps: recomp_select (functions without matching C -> port/recomp.txt) -> recomp_prune (not what matched C already defines under the other
decompilation's names) -> gen_recomp (statically recompiled twins, port/build/rc_argc.txt) -> pass_through (C sources whose calls rely on
MIPS argument registers: run as twins) -> bisect_c set (port/c_skip.txt + the twins of those sources) -> delete stale twins -> build_clang
-> relink (symbols, aliases, stubs; mid-function entry points found by the linker are appended to port/forced_entries.txt: run again
with --asm then)."""
import glob, os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

def run(args, env=None, quiet=False):
    e = dict(os.environ); e.update(env or {})
    r = subprocess.run(args, capture_output=True, text=True, env=e)
    out = (r.stdout + r.stderr).strip()
    if not quiet and out: print('   ' + out.split('\n')[-1][:200])
    return out

def main():
    asm = '--asm' in sys.argv
    env = {} if asm else {'PORT_NO_ASM_REGEN': '1'}
    py = sys.executable
    for f in ('port/c_skip.txt', 'port/recomp_base.txt'):
        if os.path.exists(f): os.remove(f)
    print('recomp_select'); run([py, 'port/recomp_select.py'], env)
    print('recomp_prune'); run([py, 'port/recomp_prune.py'])
    print('gen_recomp'); run([py, 'port/gen_recomp.py'], {'PORT_NO_ASM_REGEN': '1'})
    print('pass_through'); pt = [l.strip() for l in run([py, 'port/pass_through.py'], quiet=True).split('\n') if re.fullmatch(r'func_[0-9A-F]{8}', l.strip())]
    print('  ', len(pt), 'sources run as recompiled twins')
    print('bisect_c set'); run([py, 'port/bisect_c.py', 'set'] + pt, {'PORT_NO_ASM_REGEN': '1'})
    keep = set(open('port/recomp.txt').read().split())
    for p in glob.glob('port/native/recomp/func_*.c'):
        n = os.path.basename(p)[:-2]
        if re.fullmatch(r'func_[0-9A-F]{8}', n) and n not in keep:
            for q in (p, f'port/build/obj_c/ar_{n}.obj'):
                try: os.remove(q)
                except OSError: pass
    print('build_clang'); run([py, 'port/build_clang.py'] + (['--all'] if '--all' in sys.argv else []))
    if '--no-link' in sys.argv: return
    print('relink')
    r = subprocess.run(['powershell', '-NoProfile', '-File', 'port\\relink.ps1'], capture_output=True, text=True)
    print('   ' + '\n   '.join((r.stdout + r.stderr).strip().split('\n')[-3:]))

if __name__ == '__main__':
    main()
