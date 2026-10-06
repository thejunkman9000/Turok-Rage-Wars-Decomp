"""Run m2c on every not-yet-decompiled function in a ROM range; write m2c_out/<rom>_<name>.c.
usage: python tools/m2c_dump.py <lo> <hi>      (needs tools/m2c, asm/ from splat; run from the project root)"""
import sys, re, glob, os, subprocess
from concurrent.futures import ThreadPoolExecutor

lo, hi = int(sys.argv[1], 0), int(sys.argv[2], 0)
done = set()      # ROM offsets that already have C source (hand-written asm in src/*.s still gets dumped)
for l in open('funcs.txt'):
    f = l.split('#')[0].split()
    if len(f) >= 4 and os.path.exists(f'src/{f[3]}/{f[0]}.c'): done.add(int(f[1], 16))

funcs = {}   # rom -> (name, file)
for p in glob.glob('asm/*.s') + glob.glob('asm/nonmatchings/**/*.s', recursive=True) + glob.glob('src/**/*.s', recursive=True):
    t = open(p, encoding='utf-8').read()
    for m in re.finditer(r'glabel (\S+)\n\s+/\* ([0-9A-F]+) ', t):
        funcs[int(m.group(2), 16)] = (m.group(1), p)

os.makedirs('m2c_out', exist_ok=True)
jobs = [(rom, n, p) for rom, (n, p) in sorted(funcs.items()) if lo <= rom < hi and rom not in done]

def run(job):
    rom, name, path = job
    try:
        r = subprocess.run([sys.executable, 'tools/m2c/m2c.py', '--target', 'mips-gcc-c', '-f', name, path],
                           capture_output=True, text=True, timeout=120)
        out = r.stdout if r.stdout.strip() else r.stderr
    except subprocess.TimeoutExpired:
        out = '/* timeout */'
    open(f'm2c_out/{rom:06X}_{name}.c', 'w', encoding='utf-8').write(f'/* ROM 0x{rom:X} */\n' + out)
    return rom

with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as ex:
    n = sum(1 for _ in ex.map(run, jobs))
print(n, 'functions dumped to m2c_out/')
