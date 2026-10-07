# Windows port: status and how it works (32-bit x86, Direct3D 11)

## Build / run (PowerShell, from the project root; needs Visual Studio Build Tools and `pip install ziglang`)
```
python port\collect_nonmatching.py     # gather behaviour-level C for functions that are not matching C yet -> port\nonmatching
python port\build_clang.py [--all]     # game C -> clang -> LLVM IR -> big-endian rewrite (port\be_ir.py) -> port\build\obj_c
powershell port\relink.ps1             # link (generates port\gen\syms.asm / stubs.c / fnptrs.c from the unresolved list)
powershell port\run.ps1 -Seconds 10    # run the newest build, print the log and a symbolized crash/trace
powershell port\screenshot.ps1         # capture the window
```
The ROM is read from `baserom.us.v11.z64` in the working directory (never committed).

## Design
- **Addresses.** Game globals are absolute symbols (`port\gen\syms.asm`) at their original addresses, so guest address == host
  address.  8 MB at 0x80000000 is the guest RAM; overlay A's data tail is at 0x400000; low code space 0x200000 is reserved.
  If the host already uses one of those ranges the exe relaunches itself (new ASLR layout).
- **Byte order.** The ROM and all its data are big-endian.  `port/be_ir.py` rewrites every 16/32/64-bit integer, pointer, float and
  double load/store in the compiled game code into a byte-swapped access, so the C source needs no changes and data/assets are
  kept exactly as in the ROM.  Objects defined inside a module (private tables) stay native.  `va_arg` is special-cased in
  `port\compat_clang.h`; the OS shim uses `LD32/ST32...` for every guest field it touches.
- **Code pointers** stored in data tables are relocated at load time (`port\gen\fnptrs.c`: guest address -> host function).
- **libultra** is replaced by `port\os_shim.c`: baton-scheduled threads (one runs at a time, priority based), message queues in
  the game's own OSMesgQueue structures, timers, VI/SP/DP/PI events, PI DMA from the ROM, a keyboard controller.
- **TLB demand paging.** The game pages assets in through TLB misses.  Asset space is moved to 0x30000000+ (overrides of
  `func_0023CDC4` / `func_0023CCC4`) and an access-violation handler loads the faulting 4 KB page from the ROM (`page_in`).
- **Drafts.** Functions without matching C use the workers' best drafts (`port\nonmatching`, hand fixes in `port\overrides`).
  They are behaviour-level only and are the main source of bring-up bugs.
- **Debugging.** `-finstrument-functions` feeds a ring buffer of function entries; a crash prints the last calls
  (`python port\where.py` turns RVAs into names).

## Status (latest)
The port boots, runs the game's own boot sequence and renders it: the Acclaim Studios logo and the legal/copyright screens appear
correctly through the D3D11 F3DEX2 renderer (`port/renderer.cpp`).  The state machine advances through the splash states into the
main-menu state; the menu's 3D background still crashes on half-initialised objects.

How the missing code is covered
- **Exact static recompilation** (`port/mips2c.py`, `gen_recomp.py`): every function without matching C is recompiled from the ROM's
  MIPS code (integer + FPU subset, jump tables, o32 float ABI via `fpsig.py`, 64-bit helper adapters, odd-register 64-bit FPU
  saves).  ~800 functions; validated against the matching C by differential tests (`gen_difftest.py`, 1221/1226 agree).
  Drafts in `port/nonmatching` are only the fallback when recompilation fails.
- **Entry points inside functions** (`port/forced_entries.txt`, `port/game_glue.c` aliases): some code pointers land a few bytes
  into a function or on a bare `jr $ra`; those are handled by alias stubs / an exec-fault redirect.

Debug switches (environment variables): `TUROK_SKIPMENU=1` (leave the controller-pak screen), `TUROK_AUTOPRESS=1`,
`TUROK_TRACE=func_x,bt,dump`, `TUROK_WATCH=<guest word>`, `TUROK_SAMPLE=1`, `TUROK_DLFRAME=n` (dump display lists),
`TUROK_VTXLOG=1`, `TUROK_NOTRI`, `TUROK_NORECT`, `TUROK_DUMPTICK=1`.

Known problems
- Menu background objects: slots in the object array are visited before they are initialised (null `def`), guarded in
  `port/overrides/func_0024795C.c` / `func_0024B2C0.c` for now.
- The controller-pak screen (screen 19) is not completed by the port's pak stubs; `TUROK_SKIPMENU` is a workaround.
- Audio (alAudio*, alSndp*, alCSP*) is stubbed; no sound.
- libm: the game's `sinf/cosf` double tables are word-swapped on the little-endian host (`DU()` macro in `src/libultra/cosf.c`).
- The rewriter pitfalls found so far: volatile accesses (atomic in clang's MSVC mode), align-1 loads, `memcpy` pointer attributes,
  byte loads/stores, stack objects.
