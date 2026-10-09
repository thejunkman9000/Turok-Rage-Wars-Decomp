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

## Status (latest, 2026-10-09)
The port boots through the game's own boot sequence, menus, loadout and match options into 1-player trials and 2-player split-screen
matches with music and sound effects (libultra audio library + `port/audio_hle.c`), renders them through the D3D11 F3DEX2 renderer
(`port/renderer.cpp`) and runs the attract mode indefinitely (seven demo screens, then recorded gameplay demos).  Scripted runs
(`port/pressfile.ps1`, fast-forward `TUROK_FF`) cover boot -> level and 2-player matches; the sections below are the chronological log
of how each piece was brought up and which traps were found.  Older paragraphs describe the state at their date, not today.

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

Known problems (as of the first bring-up; see the dated sections for what was resolved since)
- Menu background objects: slots in the object array are visited before they are initialised (null `def`), guarded in
  `port/overrides/func_0024795C.c` / `func_0024B2C0.c` for now.  (Resolved 2026-10-09: the "null" objects were dropped argument
  registers, see "Dropped argument registers"; the guards are now dormant.)
- The controller-pak screen (screen 19) is not completed by the port's pak stubs; `TUROK_SKIPMENU` is a workaround.
- Audio (alAudio*, alSndp*, alCSP*) is stubbed; no sound.  (Resolved 2026-10-09: see "Audio".)
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
- Fast-forward: `TUROK_FF=1` runs the game at full host speed (10 frames per presented frame, audio muted) until the title screen (29); `TUROK_FF=a;b;c` alternates: fast until screen a, normal until b, fast until c (an even count ends fast for good, e.g. `29;10` = normal through the menus, 10x inside a level); holding Tab fast-forwards at any time. `pressfile.ps1 -Boot <s>` is the wait before the Start taps (2 s automatically under TUROK_FF).

### Loadout portraits, main-menu outline (2026-10-09)
- The loadout screen's portrait actors are created from the character table `D_800E3A50` (ROM 0xE4650, one 0x70 row per character: key, index, then per-player-slot scale / yaw / position / pitch). Each player slot has its own default character key in `D_800E42D4` (P1 146 -> row 0, P2 134 -> row 1, P3 141 -> row 7, P4 140 -> row 5), so different characters with different framing per side is the game's own behaviour. The "same model on both sides, framed differently" symptom came from `func_0041CE88`: the matching C dropped the three arguments it forwards to `func_0041C680` (model/pose selection), so every portrait got the default model; `port/overrides/func_0041CE88.c` forwards them.
- The thin outline in the lower left of the main menu was a 72x73 CI8 copy of the rock backdrop that the game redraws there (invisible on hardware). Bilinear sampling of the upscaled render target bled its black padding column and garbage rows into a visible edge; 1:1 texrects are now point-sampled.
- Build pitfall: `build_clang.py --only` compiles only the named objects - an edited override whose object is stale stays stale (the screen-id hook did not fire until `--only func_0029A958__ovr`). An override for a function that has a nonmatching draft (`name__N.c`) is written into that draft's slot by `collect_nonmatching.py`; check `port/build/obj_c` timestamps when a print does not appear.

### 2-player match: intro camera (2026-10-09)
- After START GAME and the rumble-pak prompt the match shows a static arena camera without HUD or weapon until a player presses A; only then do the split views and HUDs appear. Scripted runs need that extra `C:0.3` after the prompt (the morning run had it, the evening ones did not - two hours of "regression" bisecting later). Nothing was broken: audio HLE, option bytes, the recompiler's spill rule and the FR=1 model were all ruled out along the way. Bisect aids kept: `MIPS2C_OLD_SAVED=1`, `RECOMP_OUT=<dir>` for gen_recomp.py, `TUROK_NOAUDIO=1` (skips the audio HLE; the alAudioFrame switch spins the audio thread, do not use), `TUROK_SNDSTATE0=1` (sound/sequence players report stopped), the `port_dumpnow.txt` trigger also dumps thread states and the recent-call trace.
- Logging: the per-frame trace prints (PI DMA, allocations, UI node walks) are off by default; `TUROK_VERBOSE=1` turns them back on. A boot-to-level run is ~3.5k log lines instead of ~16k.
- Soak (2 players, random sticks/fire for 3 minutes under FF): no crash, no scheduler hang. One libultra assertion fires once per match (`assert(EX) failed at audio/csplayer.c:304`, the sequence player's event handler; the port's `__assert` reports and continues).
- Attract demo under permanent fast-forward (TUROK_FF=99, about 15 game-minutes of demo) crashed once in `func_00219A40` (+0x320 of the recompiled body, garbage object pointer 0xECE7A811; callers func_002171FC / func_00266830 / func_00245788). Later reproduced at normal speed as well (run_demo1.log, 2nd demo cycle); fixed - see "Dropped argument registers" below.
- 1-player trial under 10x for 15 game-minutes: no end-of-match transition (the trial has no time limit without objectives being met); no crash.

### Dropped argument registers (2026-10-09)
- Root cause of the attract-demo crash and of a whole class of garbage-pointer faults: a matching C decomp can declare fewer parameters than the function really takes, because the MIPS code is identical whether a register was "passed" or just left alone. `func_002171FC(actor, state)` calls `state->fn110()` with no arguments, but its callers (func_0028CCB8, the recompiled func_00266830) pass a third one - a scratch buffer - which the MIPS code leaves in a2 for the handler `func_00219A40(Plr *, u8 *, f32 *)`. On x86 the handler read a stack word instead and dereferenced it. The same pattern (`func_0024795C(&qo)` instead of `func_0024795C(&qo, o)`, `func_00442158()` instead of `func_00442158(item)`, trampolines like `func_002A1E8C(void)` that pass a0..a3 and v0 straight through) was behind the level crash after firing and several of the earlier null guards.
- Tools: `python port/argscan.py` lists C call sites that pass fewer register arguments than the callee reads (recompiled callees: registers read before written in `port/native/recomp`, transitively through pass-through calls; C callees: declared parameters; uses `port/build/turok.map` to know which object is linked). `python port/passthru.py` checks each flagged site against the caller's MIPS code (`port/build/asm_func`): if the missing register was never written before the jal (and no earlier call clobbered it) the N64 passed the caller's own incoming argument, i.e. the original source forwarded it. `python port/passthru_fix.py --diff|--write` generates overrides for those: it maps the caller's parameters to argument registers (hidden struct-return pointer in a0, by-value Vec3f/Quat4, leading floats in f12/f14), widens the parameter list with `u32 pt_aK`, appends the arguments at the call and widens the callee's local prototype. `python port/jalrscan.py` does the same survey for C function-pointer calls (targets unknown, so those are hand-written overrides that forward the live registers through a cast).
- Result: 72 generated plus 28 hand-written overrides (`port/overrides`, headers say which tool). Iterating scan -> fix -> scan reaches a fixed point with 0 pass-through sites left; the remaining ~140 flagged sites are "garbage on both machines" (the register was clobbered before the call on the N64 too, so the callee cannot depend on it). Not modelled: float arguments in f12/f14 for C callees (one manual case, func_00284844 -> func_002745D4(x)) and by-value structs of unknown size.
- Verification: attract demo 7 cycles under 10x without a crash (it used to fault in the 2nd cycle at normal speed, run_demo1.log, and after 6-11 cycles under FF); 1-player level with firing and walking clean (lv6_*.png); the earlier "crash after firing" in lv5 was `func_0024795C(&qo)` reading a stack word as its object pointer - the new overrides had merely changed which garbage was there.

### Crash reporting, post-demo renderer fault (2026-10-09)
- Every demo soak "ended" quietly after the 7th attract cycle: run.log stopped at `screen id -> 2` / `game state st=20` and the process was gone. It was a crash on the main thread (renderer) that no handler reported: the game-thread `__except` only covers the game thread, and the one-shot vectored report had already been consumed by a first-chance fault (an `IsBadReadPtr` probe inside the handler itself). `crash_filter2` now writes a raw report first (`CRASH(raw): code rva acc addr tid registers` plus up to 160 return addresses into the module, via WriteFile on the log handle - `_get_osfhandle(_fileno(stderr))`, a GUI process has no fd 2) for the first 6 access violations, then the old fprintf report once. `port_early.txt` keeps the same raw line for every exception, including first-chance ones. Symbolise rvas against `port/build/turok.map` (Rva+Base column minus 0x20000000; lowercase hex). `TUROK_CRASHTEST=1` faults on purpose at frame 300 to check the path.
- The fault: `loadTile` with lrs < uls (a LoadTile command the game issues while tearing the demo down) gave a negative row size, which memcpy took as ~4 GB and wrote past the heap. The RDP loads nothing for an empty rectangle; loadTile now returns for w <= 0 / h <= 0 and loadBlock clamps to the 4 KB TMEM.
- After that fix the soak still froze at the same point, this time with every thread alive: a stall watchdog thread (`stall_watch` in game_glue.c, dumps `STALL: ... g_lock owner/recursion, every game thread's state/queue/eip/stack, the platform thread`, through WriteFile only) showed all eight game threads waiting on their queues and the platform thread inside `runDL` twelve levels deep: a self-referencing display list (the game re-initialising while the renderer still reads the previous task's list) ran the 200000-command guard at every nesting level, i.e. forever. `runDL` now has a per-frame budget of 4M commands (`renderer: display list runaway, frame abandoned` once it trips); the per-vertex `getenv("TUROK_VTXLOG")` it was spinning in is cached.

### Reference: game state machine, screen ids (2026-10-09)
- Main loop `func_00291404` waits on the queue `D_80146980` and calls the state dispatcher `func_0029382C` (overridden to log `game state: st=N fn_rva`), which runs `D_800D29DC[st].fn(g)`; the table at `D_800D29D8` (ROM 0xD35D8; RAM = ROM + 0x7FFFF400 for the main segment) has 26 entries of {init, update, x}. Seen states: 0 boot, 1 title (`func_00293EAC/F38`), 4 (`func_002941AC/1D0`), 8 recorded gameplay demo (`func_002943B8/00294404`, screen 24 pushed), 13 title/attract loop (`func_002946A8/7BC`), 20 transition (`func_00294AC4`: waits for the fade counter `D_80146D68 == 2` and `g->f26DD0 == 0`, then switches to `g->f26DBC` and calls its init).
- Attract sequence from the title: seven cycles of state 13 with the demo screen (ids `-1, 2, 24`), then `13 -> 20 -> 1 -> 20 -> 4 -> 20 -> 8/24 -> 20 -> 13 ...` repeating with recorded gameplay demos in the arenas.
- UI screen ids (`screen id -> N (top=K)` from `func_0029A958`): 29 title, 24 attract demo, 3 main menu, 19 controller-pak screen, 9 ?, 26 how many players, 7 join page, 8 loadout, 20/21 match options (21 = options page), 25 rumble prompt / in-level overlay, 10 in-level overlay, `2 (top=0)` = UI stack empty (in a level or between screens), -1 = stack cleared.
- `TUROK_FF` stages key off those ids (`port_ff_screen`); `pressfile.ps1 -Gate` defaults to `-> 3 ` (main menu).
- Renderer input is now a snapshot: at normal speed `osSpTaskStartGo` copies RDRAM (8 MB, ~1 ms) into `g_gfx_snap` while the submitting thread still holds the scheduler baton, and `renderer.cpp` reads the task's lists, vertices and textures from the copy (`res()`), under `g_snap_lock` so the next capture waits for the walk. Fast-forward skips the copy (ten tasks per presented frame) and reads live memory as before; the per-frame command budget still covers it. This removes the transition race (loader threads overwriting the previous state's display list while it is drawn) from normal play.
