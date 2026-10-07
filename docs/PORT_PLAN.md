# Native Windows port plan (Turok: Rage Wars)

## Goal
A native Windows build that runs at 4K (and any resolution/aspect), that the project owner can **modify** and whose
**source is readable**. Matching the N64's original rendering style is explicitly *not* a goal; fidelity of game logic is.

Consequences:
- Readability and moddability beat byte-matching. Matched C stays as is; everything still asm only has to be
  *functionally* equivalent C (no byte match needed), written to be read.
- The renderer does not emulate the RDP/RSP. Display lists are translated into a modern GPU renderer
  (own D3D11/OpenGL/Vulkan backend or a reused open-source N64 gfx layer used only as a display-list front end).
- Game logic gets a clean platform layer instead of libultra emulation wherever possible.

## Facts about the ROM (see docs/layout.md)
- Standard libultra plus Acclaim engine code; audio uses the N64 audio library (alSynth / sequence player).
- Graphics microcode: F3DEX (string at ROM 0xE0D96) -> standard N64 gbi display lists.
- ~2050 chunks tagged `RNC\x01` (Rob Northen compression); `0x240000-0x790000` is mostly compressed assets.
- Code in TLB-mapped space (0x002xxxxx), one overlay (A) at 0x400000, custom boot stub.
- Status of the decompilation: see funcs.txt / funcs_a.txt; `tools/cycle.ps1` must end in "OK: byte-identical".

## Phases
1. **Every function as C.** Leftover (unmatched) functions: produce clean, behaviour-equivalent C (m2c output cleaned up,
   structs recovered, names proposed). Track them in a manifest separate from the matching one (e.g. `src/nonmatching/`),
   keep `#ifdef` NON_MATCHING so the byte-matching build still works.
2. **Platform layer (`port/`)**: libultra shim (threads, message queues, timers, PI/DMA -> file reads, SI/controller ->
   gamepad/keyboard, VI, AI -> audio device), 32-bit<->64-bit memory model, big-endian data loading.
3. **Memory model**: the game uses 32-bit addresses and structs with embedded pointers. Decide: (a) compile for 32-bit x86 (simplest,
   limits modding libs), or (b) keep a 32-bit guest address space for game data and map it into the 64-bit host (pointer
   macros / handle table). Prototype (b) early; it decides how much source has to change.
4. **Assets**: RNC decompressor (rncUnpack), level/model/texture loaders reading from extracted files (not the ROM) so assets
   can be replaced by modders; byte-swap on load.
5. **Renderer**: translate F3DEX display lists (the game builds them in C: `D_80110634` display-list pointer macros) into draw
   calls. Start with a straightforward translator (textured triangles, combiner modes -> shaders, z-buffer, fog), render at
   arbitrary resolution with real filtering/anti-aliasing; widescreen via projection changes. Do not emulate RDP edge cases.
6. **Audio**: reuse the matched audio library with a software synth backend (or replace with a modern mixer later).
7. **Tooling for modding**: CMake/MSBuild project, hot-reloadable asset folder, readable names (apply the proposed names from
   results.txt), documentation of structs.
8. **Bring-up order**: boot -> first menu with stub audio and a basic renderer -> level load -> gameplay -> audio -> polish
   (4K, input rebinding, options).

## Open decisions
- Memory model (item 3).
- Renderer backend choice and whether to reuse an existing open-source gfx front end.
- Whether unmatched functions are completed before or in parallel with bring-up (parallel is fine: stub them while testing).
