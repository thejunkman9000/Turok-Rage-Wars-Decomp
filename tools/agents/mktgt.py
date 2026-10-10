#!/usr/bin/env python3
"""mktgt.py <fn> : permuter target .s (glabel/alabel function body from asm/*.s) on stdout"""
import re, sys, glob
fn = sys.argv[1]
print('.include "macro.inc"\n.set noat\n.set noreorder\n.set gp=64\n.section .text, "ax"\n')
for p in sorted(glob.glob('asm/*.s')):
    on = False
    for l in open(p, encoding='utf-8'):
        m = re.match(r'\s*([ga])label (\S+)', l)
        if m:
            if on: break
            if m.group(2) == fn:
                on = True
                print('glabel ' + fn)
            continue
        if on:
            if l.startswith('endlabel'): break
            print(l.rstrip())
    if on:
        print('endlabel ' + fn)
        sys.exit(0)
