# Turok: Rage Wars (N64, US v1.1) - decompilation

Goal: a matching decompilation (C that compiles to the original bytes), then a native PC port.
Base ROM: `baserom.us.v11.z64`, SHA1 `037fb397cee2669048ed6b762a64698de4a4d88a` (not included; never commit it).

## Playing the PC port (Windows)
The port (`port/`, see docs/PORT_STATUS.md) runs the game natively: Direct3D 11 renderer, keyboard / mouse / gamepad input (`turok_controls.exe` edits the mapping), virtual Controller Pak memory cards (Project64-compatible `.mpk` files in `saves\`).
On the first start it asks for your own ROM of Turok: Rage Wars (USA, version 1.1; `.z64`, `.n64` or `.v64`), checks it and keeps a copy in `%LOCALAPPDATA%\TurokRageWars`; nothing of the original game is shipped.
**Ctrl+Enter** (or Alt+Enter) switches between window and full screen; F1 captures / releases the mouse, F2 reloads `controls.ini`, Esc twice quits.

## Workflow
Windows side (needs the venv: `python -m venv .venv; .venv\Scripts\pip install splat64[mips]`):
```
.venv\Scripts\python -m splat split turok_ragewars.yaml
.venv\Scripts\python tools\fix_asm.py
```
WSL side (Ubuntu-24.04; `bash tools/get_gcc.sh` once to fetch compilers into tools/gcc):
```
wsl -d Ubuntu-24.04 -- bash /mnt/d/Projects/TurokRageWars/tools/wsl_build.sh
```
`wsl_build.sh` syncs to `~/trw` (old gcc cannot read files on /mnt/d), runs `make`, and verifies the result is
byte-identical to the base ROM. Compilers: decompals/old-gcc; libultra is GCC 2.8.1 `-O2 -fforce-addr -fno-builtin -mcpu=r4300` (docs/libultra.md).

## Layout
- `src/` C sources (matched); `src/libultra/` libultra functions.
- `asm/` splat's disassembly of everything not yet decompiled (generated; gitignored). `asm/nonmatchings/` for INCLUDE_ASM.
- `symbol_addrs.txt` names and addresses recovered from the ROM. `docs/` notes and the libultra match table.
- `tools/` analysis and build helpers. `tools/as.sh`: assembles pieces without gas's 16-byte section padding.
- `tools/cc.sh`: compiler wrapper (post-processes `move` -> `addu`; libultra vs game code differ in delay-slot handling).

## Converting a function to C
1. Add a `[start, c, path/name]` subsegment (ROM offsets, function boundaries) to `turok_ragewars.yaml` and a source file.
2. Name its symbols in `symbol_addrs.txt`; re-run splat + fix_asm.py; build. It must stay byte-identical.

Notes: libultra objects are padded to 16 bytes with *garbage* (copies of other code); splat keeps those words in asm and
`tools/fix_asm.py` turns any padding "branch" that points outside its file into a raw `.word`.

## Status (2026-10-11)
- **Matching build**: `powershell tools/cycle.ps1` rebuilds the ROM byte-identical. About 99.1% of all game-code instructions are matched C (one function, func_00418224, is left)
  (`src/game/` main image, `src/ovl_a/` overlay A; libultra/libaudio in `src/libultra/`, `-O3 -fforce-addr -fno-builtin`); the rest is
  still splat asm, including hand-written exception/cache/TLB/RNC stubs that no C reproduces.
- **Toolchain** (the big finding): the other public decompilation of this game, [melalawi/ragewars-decomp](https://github.com/melalawi/ragewars-decomp)
  (CC0), builds everything with the pmret gcc 2.8.1 `cc1` (`-O2 -mgas -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300`), the SN64
  assembler normaliser `n64link asn64` and GNU as (gcc 2.7.2 for a few low-region units).  Our older decompals-gcc + `tools/gas_compat.py`
  emulation is an approximation; functions can now be built in `mode=sn` (`tools/cc.sh`; tokens `+sa +r4k +epi +nb ...` or `sn272`
  in `funcs.txt`).  `tools/sn_setup.sh` installs the three programs (download + sha256 from their pinned releases); the checker takes the
  token `@SN` / `@SN272`.  `include/their` and `their_syms.ld` are their headers and symbol table (CC0); `tools/port_their.py`,
  `tools/port_sn.py`, `tools/dropfix.py` integrate matched functions and keep the build byte-identical.
- **Assets / maps**: `docs/ROM_MAPS.md` documents the resource directory (36 map records, 347-mesh library, 507 texture banks, RNC
  compression); `tools/rnc.py`, `tools/extract_assets.py`, `tools/dump_maps.py` produce the raw dumps (output gitignored).
- **Windows port** (`port/`, `docs/PORT_STATUS.md`): runs the game natively (32-bit x86, Direct3D 11 F3DEX2 renderer, libultra audio with an
  ABI1 audio HLE, scripted input) through the menus into 1-4 player matches; functions without matching C are exact static recompilations
  of the ROM code (`port/mips2c.py`).  `TUROK_MAPDUMP=1` captures the static world geometry the renderer draws to OBJ.
- Parallel matching workflow: `tools/mkws.py` / `tools/mkround.py` (isolated workspaces), `tools/fchk.ps1`, `docs/AGENT_GUIDE.md`,
  `docs/GAME_GUIDE.md`, `docs/FINDINGS_all.txt` (combined lessons). `tools/chk.py` compares code AND the literal pool with the ROM (`tools/rodoc.py` diffs a whole rodata piece). C/H/TXT files must keep LF line endings (`.gitattributes`).
