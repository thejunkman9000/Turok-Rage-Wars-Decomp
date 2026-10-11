# Matching a libultra / libaudio function (worker guide)

You work in an isolated copy of the project (your cwd, e.g. `D:\Projects\ws\<name>`), never in `D:\Projects\TurokRageWars`.
Everything below is relative to your workspace root; run commands from there (`cd` first, use absolute paths).

## What you are doing
The original ROM was built with GCC 2.8.1. The goal is C source that compiles (with the project's compiler setup) to
**exactly** the ROM bytes of a function that is still a hand-written asm stub `src/libultra/<fn>.s`. The N64 SDK's own
libaudio/libultra sources (what these functions are) are the best template: you know them from memory; adapt them.

## Reading the target
- `bash tools/asmv.sh fnA fnB ...` prints compact asm of the stubs (reloc symbols as `%hi(sym)`).  `m2c_out/<ROMHEX>_<name>.c`
  has an m2c skeleton (unreliable control flow, good for field offsets).  `funcs.txt` lists `name rom insns subdir [ro=..]`.
  Offsets like `lw $v0, 0x14($s0)` tell you struct layouts: put them in a new header `include/<topic>_types.h`
  (it may `#include "libaudio.h"`, which holds the types recovered so far; do NOT edit libaudio.h or common.h, you may
  read them).  Define structs with explicit padding arrays when a field is not known.
- A function entry is the glabel; extra stray words before/after a function are linker padding (ignore them).

## Checking a candidate  (this is the loop)
1. Write `src/libultra/<fn>.c` (or `wip/c/<fn>.c`).  `#include "libaudio.h"` (or common.h).  Declare prototypes of callees
   in the .c (not in headers: GCC 2.8 emits functions in the order their names are first declared, so declaration order matters).
2. Make a list file, one line per function:  `<path rel. to src/libultra or project-relative like wip/c/x.c> <function> <rom hex> [gcc flags]`
   e.g. `wip/c/alLink.c alLink 0xB8150`.  Default flags are `-O3 -fforce-addr -fno-builtin -mcpu=r4300` (mode "lu").
   Run: `powershell -NoProfile -File tools/chk.ps1 <listfile>`.  Output per function: `EXACT`, or `N words differ` + the first
   differing words (ours vs rom) and a `score` (lower is better, ignores register-only differences partially).
   An EXACT result may print `ro=0xROM:bytes`: the function has a literal pool / string data; note it, it goes into funcs.txt.
3. `powershell -NoProfile -File tools/try.ps1 <file rel. to src/libultra> <fn> <rom hex> -Side` prints a side-by-side asm diff
   (left ours, right ROM; for files outside src/libultra pass `../../wip/c/x.c`).
4. Variant search: write `spec.json` = `{"header": "#include \"libaudio.h\"\n<protos>", "name": "<fn>", "rom": "0x..", "sig": "<signature>",
   "bodies": ["<body variant 1>", "<variant 2>", ...]}` and run `python tools/vq.py spec.json` (set env `VTRY_FLAGS="-O2 -mcpu=r4300"`
   to pass other flags).  For more placeholders see tools/vtry.py (template with `@@name@@`, variants json).
   Use it to try statement orders, `if/else` shapes, local-variable declaration styles, types (s16 vs s32, u8 casts), pointer
   arithmetic vs indexing, `ptr->a` caching in locals.  Most mismatches are register allocation or instruction order and
   are cured by such source-level variations.  Typical tells: a value loaded once vs reloaded after a store/call
   (aliasing => no CSE across calls/stores), whether a temp is a local variable (callee-saved reg across a call), the order
   of struct-field stores, `x = y = 0` order, compare direction (`<` vs `>=` with swapped branches), ternary vs if.
5. Give up on a function after ~6 distinct attempts and report it as "not matched" with your best attempt kept in `wip/hard/<fn>.c`.

## Compiler modes
- default "lu": `-O3 -fforce-addr -fno-builtin -mcpu=r4300` (libaudio, libultra).  "lu2": `-O2 -fforce-addr ...`.
- "lu3": `-O2 -mcpu=r4300` (no force-addr): used by the debug-link code (`dbgPort*`, `dbgLink*`, `dbgHost*`); pass these flags in the chk line.
- Functions are not emitted in source order and `-O3` inlines static functions: make helpers non-static.
- Float constants: pass floats as `f32` literals like `1000000.0f`; literals are never shared inside the assembler we emulate.
- Hardware/globals: `extern` them with the exact names used in the asm (`D_8014D3E8`, `alGlobalsp`, ...), type = access width.

## Multi-function objects / rodata
The original objects are not visible, and the literal pool is part of the match: the real ROM build puts every object's `.rodata` at the `ro=` piece you report, so the pool must equal the ROM
bytes there (values, order, alignment pads, jump tables).  `chk` verifies it: it prints plain `EXACT` only when the code matches AND every pool slot the ROM code reads sits at the same offset and
holds the same bytes (`CODE-EXACT, POOL-ORDER(...)` / `CODE-EXACT, POOL-VALUE(...)` mean not done).  Rules: define only the target function(s) in the file (helpers for inlining are
`static inline`, a plain `inline` helper is emitted as an extra out-of-line function); keep float/double constants the original has in the function's own pool as literals (not `extern f32 D_...`);
the order of `case` bodies decides jump-table and pool order; the alignment pad before a double depends on the absolute address of the piece (chk finds it).  If two of your functions' `ro=`
ranges overlap, or their `ro=` starts are not 8-aligned relative to each other, they may come from ONE object: put them in a single .c file in ROM order and verify each with its own chk line
(same path, different function/rom).  Report this.  `python3 tools/rodoc.py <src.c> sn <ro offset hex> <size>` diffs the whole pool and lists the functions the object defines.

## When only registers differ (the allocator rules, from gcc 2.8.1 global.c)
`D:\Projects\ext\gcc281src` (also `wip/w/*281.c` in some workspaces) is the real source of our compiler.  Allocation = pseudos sorted by
`floor_log2(refs)*refs/live_length` (refs weighted by loop depth); each takes the lowest free hard reg (pass 0: only regs already used by someone and not preferred by a
lower-priority CONFLICTING pseudo), then copy preferences (moves to/from hard regs) and `expand_preferences` (a pseudo that dies in an insn that sets another
non-conflicting pseudo inherits that pseudo's preferences, e.g. a divisor temp inherits the result's $a3) may override the choice.  A user variable is ONE pseudo for all its uses
(priority and conflicts are the union), pseudos live across call-argument setup conflict with the arg regs, and jump2's cross-jumping merges identical arm tails only when the
registers are identical.  Zero-code levers: `register T v __asm__("$N")` pin; copy preference = `register s32 p5 __asm__("$5"); p5 = tmp; __asm__ volatile ("" : : "r"(p5));`
after tmp's last use; conflicts = `__asm__ volatile ("" : : "r"(x) : "$3", "$4");` inside x's live range; `__asm__ volatile ("" : "=f"(f))` cuts a preference chain; an empty
volatile asm is a scheduling barrier.  Tools: `tools/dumpl.sh <src> <dir under ~>` (all RTL dumps) + `tools/regdump.py <dir> <pseudo..>` (order, reg, conflicts, preferences),
`tools/sdiff.py` (alignment-aware diff when the insn counts differ), `tools/vscore.py` (scores many variants per process: build the variants from a template, score, then confirm with chk).
Never keep dumps in /tmp (WSL wipes it when idle) or under ~/trw (rebuilt by dropfix).  func_00269A80 (five words, solved with a pinned copy to $5) is the worked example.

## Deliverable
For each function that is EXACT: the final C at `wip/out/<fn>.c` (self-contained: includes + prototypes; it must compile as is
from `include/`), plus your new header(s) `include/<topic>_types.h`.  Write `wip/out/results.txt` with one line per function:
`<fn> <rom hex> <c insn count from chk> EXACT|PARTIAL|NONE [ro=0xROM:bytes] [flags: ...] [# note]`.
The `c insn count` must be copied from chk (it may be smaller than the stub's count; the rest is padding I handle).
Do not touch files outside your workspace; do not run cycle/splat/make.

## Speed tip
`tools/chk.ps1` rsyncs the whole project (~40 s per call).  Use `powershell -NoProfile -File tools/fchk.ps1 <listfile>` instead:
it refreshes only include/, src/ and wip/ and runs chk directly (~1 s).  Put the candidate .c files under wip/ or src/.
`tools/vtry.py` / `tools/vq.py` already run many variants in one chk call; they use chk.ps1 for that one call.
