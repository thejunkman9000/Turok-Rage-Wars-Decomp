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
`TUROK_FTRACE=func_x,bt,dump (function arg trace; TUROK_TRACE is the oracle frame trace)`, `TUROK_WATCH=<guest word>`, `TUROK_SAMPLE=1`, `TUROK_DLFRAME=n` (dump display lists),
`TUROK_VTXLOG=1`, `TUROK_NOTRI`, `TUROK_NORECT`, `TUROK_DUMPTICK=1`.

Known problems
- Menu background objects: slots in the object array are visited before they are initialised (null `def`), guarded in
  `port/overrides/func_0024795C.c` / `func_0024B2C0.c` for now.
- The controller-pak screen (screen 19) is not completed by the port's pak stubs; `TUROK_SKIPMENU` is a workaround.
- Audio (alAudio*, alSndp*, alCSP*) is stubbed; no sound.
- libm: the game's `sinf/cosf` double tables are word-swapped on the little-endian host (`DU()` macro in `src/libultra/cosf.c`).
- The rewriter pitfalls found so far: volatile accesses (atomic in clang's MSVC mode), align-1 loads, `memcpy` pointer attributes,
  byte loads/stores, stack objects.

### Debug switches added later
- `TUROK_LIGHTLOG=1`: log the light slots the display lists load (colour, direction, count). In the gameplay frames seen so far the light is white with grey ambient, so the red cast of the first match scene does not come from lighting.
- `recomp_skip.txt` / `recomp_nullguard.txt` / `forced_entries.txt`: functions not recompiled (usable C exists, asm head mis-split), recompiled functions that return early on a NULL first argument, extra function entries for code reached only through data tables.

### State after the menu bring-up

- Boot screens, title, main menu (MULTIPLAYER / TRIALS / CONTROLLER PAK / OPTIONS), HOW MANY PLAYERS, the loadout screen and matches all run; a 2-minute autopress soak does not crash.
- Input for scripted tests: `port\pressfile.ps1` writes `port_input.txt` (hex buttons, stick x, stick y), which `osContGetReadData` merges; OS key injection (`keybd_event`) proved unreliable. `port\shots.ps1`, `port\menushots.ps1`, `port\dumpwhen.ps1` take timed screenshots / display-list dumps.
- Debug switches: TUROK_TREE (UI node tree + handler slot table per screen), TUROK_EVT (screen event table), TUROK_LIGHTLOG, TUROK_TEXDUMP / TEXDUMP8 / TEXDUMPBIG (decoded textures to port/build/tex_N.ppm), port_dumpnow.txt (trigger a 3-frame display-list dump + RAM image).
- Renderer: the screen size follows SETCIMG (284 wide in menus, 480 in matches).
- Recompiler lessons: stack words of a by-value struct are a big-endian memory image on the native side (`port/recomp_structargs.txt` lists the functions that get them swapped at entry/calls); float prototypes typed `s32` hide float arguments (`port/fpsig_override.txt`, and fpsig prefers the prototype with most floats); the address of the incoming argument area being taken forces 7 stack args; printf-family variadics go through `port_vararg_block` (compat_clang.h `__builtin_next_arg`).
- Known open: garbled 3D previews on the loadout screen (portrait/weapon), audio stubbed, a handful of recompile failures (`be_ir` duplicate-name errors in a few functions; `func_0029BBA0`).

### Lead on the garbled loadout models
- The 32x64 CI8 model textures (display list: `FD500000 801D4050` image, `FD100000 801D4070` palette) decode as noise because the image address overlaps the palette: RAM at 0x801D4040.. shows chunk headers (`00000001 00000010 ...`) where the image should be. The model resource is not laid out the way the display list builder assumes, so suspect the loader/unpacker of that resource type (pointer fix-up or chunk unpack in recompiled code). Dump the area with `port_dumpnow.txt` (writes port_mem.bin / port_mem2.bin).
- `TUROK_TEXDUMPWH=32x64` dumps decoded textures of one size to port/build/tex_N.ppm.
- Allocation trail for that resource: `alloc size=3360 -> 801D0C90` (flags=0) is followed by a run of `alloc size=70 -> 801D4010, 801D40A0, ...` (0x90 apart), each next to an RNC1 asset (header `RNC 01`, unpacked size 0xA40) that unpacks into a temporary buffer at 80474320. The display list's image pointer 801D4050 lands just past the 0x3360 block, i.e. inside one of the 0x70 blocks - the unpacked size / allocation size used for these model blocks looks wrong (or the unpacker writes more than was allocated). Start with the function that issues the `alloc size=3360` (see the log lines before it) and the RNC unpack call that follows.

### Resolved: garbled loadout models
- Cause: matching C declared `func_0028FDD8` as `void` although the original leaves the piece size in v0 and recompiled callers (`func_00295B90`, ...) use it; models were allocated 0x70 bytes instead of 0xA40. Fixed by `port/overrides/func_0028FDD8.c` returning the size.
- Same class of bug may exist elsewhere: matching-C functions typed `void` whose result lingers in v0. Symptom: a recompiled caller computes with garbage after the call. Fix by overriding the function with a returning prototype.

### Scripted play (pressfile.ps1)
- Main menu -> 1 PLAYER TRIALS -> NEW GAME -> level: `stick:0:-80:0.25 wait:1 C:0.3 wait:5` (select 1P trials, pak screen: NO CONTROLLER PAK FOUND), `stick:80:0:0.25 wait:1 C:0.3 wait:5` (DONE), `stick:-80:0:0.25 wait:1 C:0.3 wait:5` (OK), then `C:0.3 wait:6` x5 (NEW GAME and the following screens) until the level (about 40 s after the main menu).
- In the level: stick = turn/pitch, `CUp:3` walks, `Z` fires. Controller pak is always reported absent (osPfsInitPak/osPfsIsPlug overrides).

### Audio (2026-10-09)
- The real libultra audio library runs (alInit/alSynNew/alAudioFrame, sequence player, sound player, reverb). Its ABI1 command lists are executed by `port/audio_hle.c`; `port/audio_out.c` plays the pushed AI buffers through waveOut. Music and the menu play cleanly; `TUROK_WAVDUMP=file.wav` records the stream for offline analysis (python: discontinuities, clipping, per-channel smoothness), which found every bug below.
- Semantics verified against the game's own command streams: ADPCM writes its 16-sample history in front of the decoded frames (RESAMPLE reads at out+32); RESAMPLE uses the 64-phase microcode table on the 4 samples before the position; INTERLEAVE's count is one channel's byte length; ENVMIXER keeps an 80-byte state with exponential ramps; POLEF is the reverb's two-pole filter. Debug: `TUROK_HLELOG=start;count` (command lists), `TUROK_HLEDUMP=list` (DMEM after each stage), `TUROK_VOLOPT=mmss` (option bytes; a blank EEPROM leaves the music volume at 0, so 0x80/0x80 are defaulted), `TUROK_RS`, `TUROK_NOPOLEF`, `TUROK_NOWET`.
- Recompiler: the game sets Status.FR (osCreateThread: SR=0x0400FF03), i.e. 32 separate 64-bit FPU registers; doubles appear in odd registers (`_getRate`). `g_fpr` is 32 x 2 words, `gd/sd/ldc1/sdc1` move whole registers (4-byte accesses only - `be_ir` would swap an 8-byte access as one unit).
- Pitfall: removing a `port/overrides/X.c` whose original lives in `src/` leaves X as an UNIMPLEMENTED stub until the src file is rebuilt (touch it); `alCSPSetVol` went missing that way and the music played at the library default volume 0x7FFF (clipping).
- Fast-forward: `TUROK_FF=1` runs the game at full host speed (10 frames per presented frame, audio muted) until the main menu (screen 3); `TUROK_FF=<n>` until screen n; holding Tab fast-forwards at any time. `pressfile.ps1 -Boot <s>` is the wait before the Start taps (2 s automatically under TUROK_FF).
