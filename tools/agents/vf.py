#!/usr/bin/env python3
"""vf.py (WSL) <fn> <rom> <n> [xflags|-] file1 file2 ...   score whole files (rel to ~/trw_s704) with structural (VM=struct) or full metric"""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import evalsn, vrun_metrics
fn, rom, n, xf = sys.argv[1:5]; files = sys.argv[5:]
xf = '' if xf == '-' else xf
from multiprocessing import Pool
rom_i = evalsn.disasm_rom(int(rom, 16), int(n))
with Pool(int(os.environ.get('VJ', '4'))) as p:
    for arg, ours in p.imap(evalsn.compile_ours, [(f, fn, xf) for f in files]):
        if ours is None: print('FAIL', arg); continue
        print(f'{vrun_metrics.struct(ours, rom_i):4d} {evalsn.metric(ours, rom_i):4d} insns={len(ours)} {arg}')
