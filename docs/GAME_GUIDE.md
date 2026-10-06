# Matching Turok: Rage Wars game code (worker guide, extends AGENT_GUIDE.md)

Read docs/AGENT_GUIDE.md first (tools, loop, deliverable).  Differences for game code:

## Compiler
Acclaim's game code is GCC 2.8.1 **`-O2 -mcpu=r4300`** (no -fforce-addr, no -fno-builtin, not -O3).
Every chk line for game functions must carry those flags:
`wip/c/foo.c func_00245840 0x46440 -O2 -mcpu=r4300`   (the rom offset = VRAM - 0x1FF400 for the main image;
overlay A functions: rom = VRAM - 0x400000 + 0x16E000).  Same assembler behaviour as libultra (return delay slot
filled by the assembler only when safe; `move` -> `addu`).  For vq.py use `VTRY_FLAGS="-O2 -mcpu=r4300"`.
Proven: 3/5 random tiny game functions matched at first try with these flags; mismatches were source shape only.

## Getting the target
- `docs/game_funcs.txt`: all 3884 functions (rom, name, insns, callees, callers, flags).
- asm: `python tools/asmfn.py func_00245840 [...]` prints a function's asm (from asm/entry.s or asm/16E000.s).
- m2c skeletons: `m2c_out/<ROMHEX>_<name>.c` (m2c output for the function; may be missing for some: run
  `python tools/m2c/m2c.py --target mips-gcc-c -f <name> asm/entry.s`).  m2c is a starting point only: it mis-structures loops,
  invents temps.  Write idiomatic C that looks like what a 1990s game programmer wrote (structs, small helpers, `for`/`while`).
- Callee/caller context: grep the other functions' asm/m2c; named libultra functions have real names (symbol_addrs.txt).
- Globals appear as `D_XXXXXXXX` (symbols for VRAM 0x800.....): declare them `extern <type> D_XXXXXXXX;` in your .c or your own
  header with the type/array/struct you infer (keep the symbol name; renaming comes later).  Data is in .data/.bss: you cannot
  see it in the function; infer structure from access patterns.  Never define the globals in the C file.
- Functions: keep calling them by their current symbol names (func_XXXXXXXX); declare prototypes in the .c.  Put the real,
  inferred signatures in the prototypes (return types and args matter for the generated code: s32/u8/s16 conversions, f32 args).
  If you recognise what a function is, record a proposed name in results.txt (`name=<proposal>`); do not rename in C.

## Types / headers
include/common.h and include/libaudio.h hold shared libultra types: read-only for you.  Game structs go into your OWN header
`include/<yourname>_types.h` (include "common.h").  If you need a type another worker may also define (e.g. a vector/matrix
or a common object struct), name it neutrally (`Vec3f`, `Mtx4f`), and put it in `include/game_common.h` ONLY if that file
exists in your workspace (it is maintained by the lead): otherwise define it in your own header under a unique name.

## What counts as done
chk says EXACT for the function with the flags above.  If a function is far from matching after ~8 variants, skip it, keep
your best attempt in wip/hard/ and note why in results.txt.  Prefer breadth: do the easy functions of your list first.
Functions that share a literal pool/jump table/strings in the original object may show overlapping or adjacent `ro=` pieces
(see AGENT_GUIDE); record all `ro=` pieces chk prints for the function.
