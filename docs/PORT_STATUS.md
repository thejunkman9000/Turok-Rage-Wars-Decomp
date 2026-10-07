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

## Status
Boot thread runs: heap, allocator, overlay load, sound manager setup, resource loading with demand paging.
Nothing is drawn yet (the renderer hook `port_present_hook` is empty; the game's display list is captured in `g_gfx_task`).
