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

def drop_stale_twins():
    keep = set(open('port/recomp.txt').read().split())
    for p in glob.glob('port/native/recomp/func_*.c'):
        n = os.path.basename(p)[:-2]
        if re.fullmatch(r'func_[0-9A-F]{8}', n) and n not in keep:
            for q in (p, f'port/build/obj_c/ar_{n}.obj'):
                try: os.remove(q)
                except OSError: pass

def sync_overrides():
    """port/overrides/<name>.c is compiled from port/nonmatching/<name>__ovr.c (collect_nonmatching.py copies it); an override added or edited later would otherwise
    never be built, and an old draft of the same function (port/nonmatching/<name>__N.c, no longer superseded once the function is overridden) would be linked instead.
    Conversely, an override DELETED from port/overrides/ must have its stale port/nonmatching/<name>__ovr.c removed too, or the deleted override keeps getting
    built from that leftover copy forever (bit us once: a diagnostic-only override was deleted but its __ovr.c sync copy silently kept building)."""
    import shutil
    live = set()
    for f in glob.glob('port/overrides/*.c'):
        n = os.path.basename(f)[:-2]; dst = f'port/nonmatching/{n}__ovr.c'; live.add(n)
        if not os.path.exists(dst) or open(dst, 'rb').read() != open(f, 'rb').read():
            shutil.copy(f, dst); print('  override synced:', n)
        for d in glob.glob(f'port/nonmatching/{n}__[0-9]*.c') + glob.glob(f'port/nonmatching/{n}__m2c.c'):
            defs = set(re.findall(r'^[A-Za-z_][^;{}()=]*[ *](\w+)\s*\([^;{}]*\)\s*\{', open(d, errors='replace').read(), re.M))
            if defs <= {n}: os.remove(d); print('  stale draft removed:', os.path.basename(d))     # a draft that also defines other functions stays
    for d in glob.glob('port/nonmatching/*__ovr.c'):
        n = os.path.basename(d)[:-len('__ovr.c')]
        if n not in live: os.remove(d); print('  orphaned override sync removed:', os.path.basename(d))

def main():
    asm = '--asm' in sys.argv
    env = {} if asm else {'PORT_NO_ASM_REGEN': '1'}
    py = sys.executable
    for f in ('port/c_skip.txt', 'port/recomp_base.txt'):
        if os.path.exists(f): os.remove(f)
    print('overrides'); sync_overrides()
    print('recomp_select'); run([py, 'port/recomp_select.py'], env)
    print('recomp_prune'); run([py, 'port/recomp_prune.py'])
    print('gen_recomp'); run([py, 'port/gen_recomp.py'], {'PORT_NO_ASM_REGEN': '1'})
    print('pass_through'); pt = [l.strip() for l in run([py, 'port/pass_through.py'], quiet=True).split('\n') if re.fullmatch(r'func_[0-9A-F]{8}', l.strip())]
    if os.path.exists('port/twin_prefer.txt'):                     # hand-maintained: C that behaves wrongly although it matches
        pt += [l.split('#')[0].strip() for l in open('port/twin_prefer.txt') if l.split('#')[0].strip()]
    pt = sorted(set(pt))
    print('  ', len(pt), 'sources run as recompiled twins')
    print('bisect_c set'); run([py, 'port/bisect_c.py', 'set'] + pt, {'PORT_NO_ASM_REGEN': '1'})
    drop_stale_twins()
    print('build_clang'); out = run([py, 'port/build_clang.py'] + (['--all'] if '--all' in sys.argv else []), quiet=True)
    print('   ' + out.split(chr(10))[-1][:200])
    bad = sorted(set(re.findall(r'FAIL src[/\\](?:game|ovl_a)[/\\](func_[0-9A-F]{8})\.c', out)) - set(pt))
    if bad:                                          # matched C the host compiler rejects (MIPS inline asm, register-class constraints): the recompiled twin takes over
        print('   rejected by the host compiler, run as recompiled twins:', ' '.join(bad))
        pt = sorted(set(pt) | set(bad))
        run([py, 'port/bisect_c.py', 'set'] + pt, {'PORT_NO_ASM_REGEN': '1'})
        drop_stale_twins()
        print('build_clang (twins)'); run([py, 'port/build_clang.py'])
    if '--no-link' in sys.argv: return
    print('relink')
    r = subprocess.run(['powershell', '-NoProfile', '-File', 'port\\relink.ps1'], capture_output=True, text=True)
    print('   ' + '\n   '.join((r.stdout + r.stderr).strip().split('\n')[-3:]))

if __name__ == '__main__':
    main()
