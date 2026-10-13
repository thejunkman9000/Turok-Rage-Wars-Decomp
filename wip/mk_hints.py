"""usage: mk_hints.py <target ver> <sibling ver> <ws>...   (generalised from mk_de_hints.py)
Add the Europe starting points to the Germany worker workspaces: wip/sib_src (matched Europe sources), wip/sib_manifest.txt, wip/baserom.{SIB}.z64,
wip/vpairs.txt (the closest matched Europe unit per target) and a hint section in docs/BATCH_PROMPT.txt."""
import os, shutil, sys
T, SIB = sys.argv[1], sys.argv[2]
NAME = {'eu': 'Europe', 'de': 'Germany', 'us': 'US v1.0'}
ROOT = r'D:\Projects\TurokRageWars'
pairs = {}
for l in open(rf'{ROOT}\wip\vpairs_{T}_{SIB}.txt'):
    f = l.split()
    if f: pairs[f[0]] = l.strip()
HINT = """

=====================================================================================================================
SIBLING-RELEASE HINTS (added for this round: the sibling release is ALREADY MATCHED, use it)
 - wip/sib_src/<game|ovl_a|libultra>/*.c are the matched Europe sources (EXACT against baserom.{SIB}.z64 = wip/baserom.{SIB}.z64); wip/sib_manifest.txt has their
   ROM offsets / flags (`mode=sn`, `ro=` pieces); wip/vpairs.txt lists, for your targets, the Europe unit with the most similar instruction stream
   (`<target> <insns> <europe unit> <its insns> <similarity> <source file>`).  Germany's functions are usually the Europe function with other constants,
   other table indices or a few moved statements: START FROM THE EUROPE SOURCE (copy it, rename the function, run tools\chk.ps1) before the 1.1 source.
 - What the Europe workers found (Germany is the same family): the release difference is localisation - 1.1 string/id globals became per-language tables
   indexed by the language byte (D_auto_80152789 / byte 0x581 of D_801462C8 / D_80145088[0x17C1]); read the byte as a struct field, not a plain u8 global
   (the load is scheduled differently).  Where the ROM keeps a table base in a register, assign a pointer local right before the first use.
 - The upstream decompilation (D:\Projects\ext\ragewars-decomp, versions/de/symbol_addrs.txt maps our DE address to its name) compiles EXACT for several
   functions with `#define VERSION_DE 1` as the first line; try it for functions whose names it has.
 - Some targets are not functions: 1-3 stray linker-pad words (`pad_<ROM hex>`, NOT +0x1000 copies in this release), out-of-line `return N` switch arms of a
   neighbour, hand-written asm blobs (deliver as `wip\out\<name>.s`).  Their names: the real entry VRAM; a stray word before the entry is its own pad line.
 - Known traps: their_alias.ld carries wrong PROVIDE lines for release-only names (D_auto_800E1664 ...): use a release-only name in your source and put it
   in wip\out\syms.ld; tools/ccchk.py cannot relocate jump tables (chk with ro= pieces is the proof there); a piece's real size may be smaller than the
   object's padded .rodata (`ro=0xROM:64:60`: the last 4 bytes belong to the next piece).
 - Do not spend more than ~1 hour on one function: deliver it as PARTIAL (wip/hard/) and go on.
"""
for ws in sys.argv[3:]:
    d = rf'D:\Projects\ws\{ws}'
    if not os.path.isdir(d): print('missing', ws); continue
    shutil.rmtree(rf'{d}\wip\sib_src', ignore_errors=True)
    shutil.copytree(rf'{ROOT}\versions\{SIB}\src', rf'{d}\wip\sib_src')
    shutil.copy(rf'{ROOT}\versions\{SIB}\manifest.txt', rf'{d}\wip\sib_manifest.txt')
    shutil.copy(rf'{ROOT}\baserom.{SIB}.z64', rf'{d}\wip\baserom.{SIB}.z64')
    mine = [pairs[l.split()[0]] for l in open(rf'{d}\wip\targets.txt') if l.split() and l.split()[0] in pairs]
    open(rf'{d}\wip\vpairs.txt', 'w').write('\n'.join(mine) + '\n')
    with open(rf'{d}\docs\BATCH_PROMPT.txt', 'a', newline='\n') as f: f.write(HINT.replace('{SIB}', SIB).replace('Europe', NAME[SIB]).replace('EU ', NAME[SIB] + ' '))
    print(ws, len(mine), 'pairs')
