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
byte-identical to the base ROM. Compilers: decompals/old-gcc (GCC 2.8.1 -O2 is the current best guess, see docs/layout.md).

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
