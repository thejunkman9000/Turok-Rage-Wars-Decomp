# Turok: Rage Wars (N64, US v1.1) - decompilation

Goal: a matching decompilation (C that compiles to the original bytes), then a native PC port.
Base ROM: `baserom.us.v11.z64`, SHA1 `037fb397cee2669048ed6b762a64698de4a4d88a` (not included; never commit it).

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

## Status (2026-10-09)
- **Matching build**: `powershell tools/cycle.ps1` rebuilds the ROM byte-identical. Game code (GCC 2.8.1 `-O2 -mcpu=r4300`, per-function
  overrides in `funcs.txt`) is C in `src/game/` (main image) and `src/ovl_a/` (overlay A); libultra/libaudio in `src/libultra/`
  (`-O3 -fforce-addr -fno-builtin`). About half of all game instructions (2167 of 2701 main-image functions, 982 of 1183 overlay-A
  functions; the large ones are the remaining tail) are matched C; the rest is still splat asm, plus ~120 hand-written libultra/libaudio
  asm stubs (`src/libultra/*.s`) - the RNC decompressor and CPU/TLB/exception code are real hand-written assembly.
- **Windows port** (`port/`, `docs/PORT_STATUS.md`): runs the game natively (32-bit x86, Direct3D 11 F3DEX2 renderer, libultra audio with an
  ABI1 audio HLE, scripted input) through the menus into 1-4 player matches; functions without matching C are exact static recompilations
  of the ROM code (`port/mips2c.py`).
- Tooling for parallel matching work: `tools/mkws.py` (isolated workspaces), `tools/fchk.ps1` (fast checker with relocation verification),
  `tools/apply_results.py` / `tools/integrate.py` (bring results back; keep the build byte-identical), `docs/AGENT_GUIDE.md`,
  `docs/GAME_GUIDE.md`, `docs/FINDINGS_all.txt` (combined lessons). C/H/TXT files must keep LF line endings (`.gitattributes`).
