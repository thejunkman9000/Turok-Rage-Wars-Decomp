# Other versions of the game

**Status (2026-10-11): US v1.1 is done (every game-code function is matched C), the other releases are in progress, US v1.0 first.**  Before that only the
analysis below existed (`tools/ver_diff.py`, `tools/ver_cover.py`, the "other releases" panel of `tools/progress_chart.py`).  The prompt for the
per-release workers is `docs/VERSION_PROMPT.txt`.

ROMs (project root, gitignored, never commit them):

| file | game | sha1 | melalawi name |
|---|---|---|---|
| baserom.us.v11.z64 | Turok: Rage Wars (US v1.1) - the version this repo matches | 037fb397... | us-rev1 |
| baserom.us.v10.z64 | Turok: Rage Wars (US v1.0) | 9f8cb190... | us |
| baserom.eu.z64 | Turok: Rage Wars (Europe) | 46b474fa... | eu |
| baserom.de.z64 | Turok: Legenden des Verlorenen Landes (Germany, censored) | a6daacbd... | de |
| baserom.us.v10.palfix1.z64 / palfix2.z64 | US v1.0 patched to run on PAL consoles (232 / 15 words differ from v1.0) | e8f68992... / 9941a0d2... | (not in their list) |

(their eu-x = PAL multi-language release: not available here.)

## How much code is shared with us-rev1 (`python tools/ver_diff.py`)
Per version about 2,800 functions (~160k instructions) are byte-identical or identical up to relocations (j/jal targets, symbol
addresses), 165-190 functions (~30k instructions) exist only in us-rev1 / have no counterpart, and only a few dozen differ in length or
code (eu: 52 functions with another size, de: 12 plus 5 real code differences, us v1.0: 8).  So a version build = our matched C compiled with
that version's addresses + the version-specific functions.

Data for the other versions' addresses: melalawi/ragewars-decomp `versions/<ver>/{slices.mk,symbol_addrs.txt,symbols.ld,RageWars.yaml,report.json}`
(CC0; clone in D:\Projects\ext\ragewars-decomp).  Unit names are shared across versions, so a function of ours has a counterpart in version v
iff its unit name appears in `versions/v/slices.mk`.

## Content-based analysis (2026-10-11, analysis only: `tools/ver_symmap.py`, `tools/ver_funcmap.py`)
`python tools/ver_funcmap.py us|eu|de` looks every function of `docs/game_funcs.txt` up in the other ROM by normalised code (j/jal targets and lui/addiu/load/store
immediates ignored, so it needs no symbol tables) and writes `wip/funcmap_<ver>.txt` (`name rom11 insns status rom_other`):

| release | same (found, normalised) | shifted layout | no counterpart = needs version-specific code |
|---|---|---|---|
| US v1.0 | 3,640 functions (234,901 insns) | 44 (1,779) | **200 functions, 13.7k insns** (largest: func_0043C4F4 1046, func_00295FB4 903, func_0020DDD4 552, func_0042F12C 535) |
| Europe | 3,466 (214,084) | 125 (7,686) | **293 functions, 28.6k insns** (largest: func_004308B8 1695) |
| Germany | 3,537 (218,158) | 67 (3,548) | **280 functions, 28.6k insns** (same largest) |

`python tools/ver_symmap.py us` pairs the code of every unit present in both ROMs (`lui`+`addiu/lw/sw`, `jal`) and recovers the address map v1.1 -> v1.0: 7,977 game addresses,
0 conflicts, 37 runs of constant delta (main image data 0x800C6AB0..0x800E5E74 shifts by -20,928..-21,408, 0x80110160.. by -24,768, code 0x80200500..0x802AE254 by 0 .. -296 and
-4,288, overlay A 0x80400000.. by 0 / -2,784).  So the data and code layout differences between the releases are piecewise-constant shifts: a version build is the same C with the
version's symbol addresses (an address-map ld script generated from this table) plus the few hundred functions that really differ.  EU and DE share most of their changed
functions (the PAL/localisation paths), so those get matched once and reused.

## Build pipeline for another release (2026-10-11, work in progress; US v1.0 first)
Design: the release is built in a WORKSPACE COPY of the tree (`python tools/mkws.py v10`, then `python tools/mkver.py us --out D:/Projects/ws/v10`) so the US v1.1 build cannot be disturbed; the generalised tools
move into the main tree once a release builds byte-identical.  Our C keeps its IDENTITY names (func_XXXXXXXX / D_XXXXXXXX = the 1.1 address); only the addresses change:
1. `tools/ver_funcmap.py <ver>` finds every function of the 1.1 tree in the other ROM by normalised code (monotonic anchor assignment: unique matches define the order, ambiguous tiny functions are placed between the neighbouring anchors).
2. `tools/ver_symmap.py <ver>` pairs the instruction streams of the common units (lui+addiu/lw/sw, jal) into an address map; `tools/ver_sweep.py <ver>` compiles every unit of the 1.1 tree UNCHANGED against the other ROM (`CHK_ROM`, `CHK_SYMS`), checks every function of a unit and the unit layout, and with `CHK_INFER` collects the address the other ROM encodes for each symbol relocation (`wip/ver/<ver>/syms_inferred.ld`, majority vote, conflicts reported): the units that come out EXACT are the C that builds the release as is.
3. `tools/mkver.py` writes the workspace inputs: funcs.txt / funcs_a.txt (EXACT units at the release's ROM offsets, `ro=` pieces found in its ROM), symbol_addrs.txt (our names at the release's addresses, so splat names asm and C links by name; auto names are `auto_<vram>` so they cannot collide with identity names), c_syms.ld / their_alias.ld / their_syms.ld (versions/<ver>/symbols.ld), the yaml with the release's segment starts and sha1 (`VER_LAYOUT` for tools/gen_yaml.py: MAIN_CODE_END, DATA_END, OVL_START, OVL_END from upstream's RageWars.yaml), Makefile BASEROM; units that are not EXACT stay asm (splat) and their sources are removed from the workspace (the Makefile compiles everything under src/).
4. `powershell tools\cycle.ps1` in the workspace (splat on the release's ROM, fix_asm, WSL build, compare) and `tools/dropfix.py` for the culprit-dropping loop.
Layouts (ROM offsets): US v1.0 main code ends 0xC24F0 (1.1: 0xC76B0), overlay A 0x164000..0x1B20D0 (1.1: 0x16E000..0x1BCDA0), no 14-page copy region; EU 0xC2860 / 0x176000..0x1C5230; DE 0xC25C0 / 0x166000..0x1B3F60.


## US v1.0 builds byte-identical (2026-10-11)
`D:\Projects\ws\v10` (tools/mkws.py + tools/mkver.py us, then `tools\cycle.ps1`) reproduces `baserom.us.v10.z64` **byte for byte**: 3,408 units of the unchanged 1.1 C (2,358 main image + 1,050 overlay A, the sweep's EXACT verdicts) at the release's addresses, everything else as splat asm of the v1.0 ROM.  The 200 functions (13.7k insns) that really differ stay asm until they are matched.
Traps found on the way (all fixed in the tools, the 1.1 build stays byte-identical):
- splat names a call target that lies in a C unit (no asm definition) `func_auto_<address>` (the workspace uses `symbol_name_format: auto_$VRAM` so that auto names cannot collide with our identity names): mkver adds `PROVIDE(func_auto_<addr> = <addr>)` for every game function.
- The 1.1 sources also use short splat names (`func_402FB4`, `D_800CE040`, `D_451700`: undefined_funcs_auto.txt / undefined_syms_auto.txt) and names of melalawi's 1.1 table that the release's table lacks: translated through the address map and the inferred symbols (`CHK_INFER`), written to extra_syms.ld / their_alias.ld.  c_syms.ld takes function addresses from the function map (the instruction-pair map has gaps: one stale 1.1 address silently overrides the right asm label).
- Linker padding between libultra objects is garbage that spimdisasm decodes as code: `tools/fix_asm.py` turns every j/jal whose target is outside the code (< 0x200000 or >= 0x500000), every branch to a data symbol, every `.word` that names a hardware register / an address outside the code, and every MIPS IV+ instruction into the identical raw `.word`.
- A literal pool the sweep finds must keep its `ro=` piece (a unit that has a pool in 1.1 but none found in the release is dropped), and a piece is a whole number of words: `ro=off:size` with an odd size (a 7-byte string pool) becomes `ro=off:size_rounded:real` (the alignment tail comes from the ROM), else the next piece shifts by 4.
- `tools/cc.sh` and `tools/gas_compat.py` read the layout (`ver_layout.txt`: OVL_START) and the ROM (`BASEROM` of the Makefile) of the workspace instead of the 1.1 constants (the pool tail bytes were taken from the 1.1 ROM).
- `tools/romdiff.py <ws>` (WSL) attributes every cluster of differing bytes of a workspace build to the owning unit (`unit:` / `ro:` piece / `asm:` file) and `--objs` compares object sizes with the manifest ranges: the first stage of the culprit loop takes seconds instead of a 6-minute cycle.
Next: match the 200 version-specific functions (agents), then the same for Europe and Germany (`ver_sweep.py eu|de`, mkws veu / vde), then move the generalised pipeline into the main tree (`versions/<ver>/` manifests + a Makefile target).

## Europe and Germany build byte-identical (2026-10-11)
`D:\Projects\ws\veu` and `D:\Projects\ws\vde` (`tools/mkws.py`, `tools/ver_funcmap.py eu|de`, `tools/ver_sweep.py eu|de`, `tools/mkver.py eu|de --out <ws>`, then `tools\cycle.ps1`) reproduce `baserom.eu.z64` and `baserom.de.z64` **byte for byte**:
Europe from 3,575 units of the unchanged 1.1 C (2,548 main image + 1,027 overlay A), Germany from 3,496 (2,560 + 936); everything else is splat asm of the release's ROM.  What the EU/DE ports needed beyond the US v1.0 pipeline:
- A release can hold the same code twice: the Europe overlay area carries a second copy of library code at 0xF9000 that an unconstrained content search finds first.  `tools/ver_funcmap.py` is region aware (a function of 1.1's overlay A can only be in the release's overlay A, a main image function in its main image) and includes the libultra units of funcs.txt; `tools/mkver.py` additionally keeps only the longest increasing run of the function map per region (a mapping must preserve the 1.1 order) and drops units that land in the wrong region.
- `tools/ver_sweep.py` seeds `syms.ld` with the function-map address of EVERY function (authoritative) before the instruction-pair map and the inferred addresses fill in the data symbols: without it a unit that calls a function of a shifted neighbour came out as RELOC-MISMATCH although its code was right.
- Two symbols at one address (translated names that collide in a release) make splat reject the symbol file: `mkver` keeps the first and comments out the rest; libultra units are named by the SDK, not by an identity name, so asm that calls them uses the auto name: `PROVIDE(func_auto_<addr>)` aliases for them as well.
- Rerunning `mkver` on an existing workspace restores the sources of the units that are kept now from the project (a unit that was dropped in an earlier run had its source removed and splat wrote an `INCLUDE_ASM` stub that then shadowed the real C).
Work list per release: `tools/mkvtargets.py` (units that differ, libultra units, release-only functions); the function-matching agents use `docs/VERSION_MATCH_PROMPT.txt`.

## US v1.0: first integration of the matching workers (2026-10-11)
`versions/us/manifest.txt` holds 165 release-specific units (workers u10d01..09, u10l01..07, u10n04: game, overlay A and libultra units whose 1.1 C
needed a change or only other flags, the new functions, linker-pad units); `tools/mkver.py` merges them and the workspace still rebuilds `baserom.us.v10.z64`
byte-identical.  Lessons of the integration:
- Symbols only the release's sources use (`D_auto_<vram>`, or identity names the address map leaves at the 1.1 address, e.g. `D_00450830` of overlay A) go
  into `versions/<ver>/syms.ld` (release addresses): mkver appends it to the workspace's extra_syms.ld AND lets it override c_syms.ld (a worker that fixed such
  a symbol only in its own workspace's .ld files gets a match that the regenerated workspace does not reproduce).
- A release function that references ANOTHER object than its 1.1 counterpart (func_00446A54 reads the table at 0x800E0D5C in v1.0, not the one D_800E20AC
  maps to) must name that object in its own source (`D_auto_800E0D5C`), never by moving the shared identity name.
- A literal piece must not be widened past the next piece: __osViSwapContext keeps `ro=0xC84F0:12` (a worker's 16 overwrote the first word of the next piece).
- The v1.0 matches of __osContAddressCrc / __osContDataCrc are byte-identical code in 1.1: they replaced the asm placeholders of the 1.1 tree.
