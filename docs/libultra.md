# libultra in Turok: Rage Wars

## Toolchain (established by matching real functions byte-for-byte)
- Compiler: **GCC 2.8.1** (decompals/old-gcc build), flags
  `-meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic -O2 -fforce-addr -fno-builtin -mcpu=r4300 -mips3 -mgp32`.
  - `-fforce-addr`: changes address-calculation scheduling (osSetEventMesg).
  - `-fno-builtin`: the ROM *calls* `memcpy` (in `_VirtualToPhysicalTask`) instead of inlining it.
  - `-mcpu=r4300`: VR4300 scheduling (no load-delay hoisting); fixed osStartThread/osSetThreadPri/osGetTime etc.
  - Other versions (2.7.2, 2.7.2.3, egcs 2.91.66, 2.95.2) match far fewer functions; `-fno-delayed-branch` is worse.
- Assembler: the original `as` is reproduced on top of modern gas by `tools/gas_compat.py` + `tools/as.sh`:
  - `move rd,rs` -> `addu rd,rs,$0`
  - 3-operand `div/rem/divu/remu` -> `div; bnez; nop; break 7; ...; mfhi/mflo` (modern gas moves the div into the slot)
  - Only a **return's** delay slot may be filled by the assembler, and never with a load; every other call/branch
    GCC left to the assembler keeps a `nop` slot. (GCC fills the slots it can itself in `.set noreorder` blocks.)
  - Each piece is assembled into a section with alignment 1 (`.text.piece`, renamed back to `.text`) so gas does
    not pad objects to 16 bytes.
- Acclaim's *own* code was assembled the same way except that even `j $31` keeps a `nop` (see `mode=game` in
  `tools/gas_compat.py`; the game compiler/flags are not settled yet).
- Nintendo's linker padded libultra objects to 16 bytes with *garbage* (copies of other code). The padding stays in
  the asm chunks between C files; `tools/fix_asm.py` turns padding "branches" that point outside their file into `.word`.

## Layout (ROM offsets; VA = ROM + 0x1FF400)
libultra occupies roughly ROM 0xBC000-0xC4800 (VA 0x2BB400-...), followed by string/printf code.
`docs/libultra_locations.txt` lists libreultra functions with their best structural match in the ROM (similarity
>= 0.80); `funcs.txt` lists everything already converted to C (`src/libultra`).

## Done (byte-identical C)
osCreateMesgQueue, osSendMesg, osRecvMesg, osJamMesg, osSetEventMesg, osCreateThread, osDestroyThread,
osStartThread, osSetThreadPri, osGetThreadId, osGetThreadPri, osGetTime, __osInsertTimer, osVirtualToPhysical,
_VirtualToPhysicalTask, osSpTaskLoad, osSpTaskStartGo, osSpTaskYield, osSpTaskYielded, osViBlack, osViSetEvent,
osViSetMode, osViSwapBuffer, osViSetSpecialFeatures, osContGetReadData, osPiGetCmdQueue, osPiStartDma,
osPiRawStartDma, __osAiDeviceBusy, __osSiDeviceBusy, __osSpGetStatus, memcpy, strchr, strlen, __osPiRelAccess,
__osTimerInterrupt, __osTimerServicesInit, __osSetTimerIntr, __osPackReadData, __osPackRequestData,
__osContGetInitData, __osSpDeviceBusy, osSetEventMesg, __osDequeueThread, guMtxIdent, guMtxIdentF, guMtxF2L,
guMtxL2F, __osViSwapContext, osAiSetFrequency.

## Float literal pools (solved)
The original `as` expanded `li.s`/`li.d` into a **per-object literal pool** in `.rodata` (first-use order, duplicates
shared, doubles 8-aligned) loaded with `lui $at,%hi(pool); lwc1/ldc1 $fN,%lo(pool)($at)`.
- `tools/gas_compat.py` does the expansion; in the real build the pool address is absolute (`rodata_map.txt` gives the
  object's rodata ROM offset, `VA = 0x80000000 + ROM - 0xC00`), so the instruction bytes match the ROM.
- `funcs.txt` lines carry `ro=<rom offset>:<bytes>`; `tools/gen_yaml.py` splits the data blob around those pieces so the
  object's `.rodata` is linked exactly there (splat `linker_section_order: .rodata` keeps ROM order).
- `tools/as.sh` assembles `.rodata` in an alignment-1 section too (no padding).
- To find a function's pool: run it through `tools/try_many.ps1`; the `symbols:` line shows `.rodata=0x800C....`
  (ROM = VA - 0x80000000 + 0xC00); the number of distinct addresses/entries gives the size.
- Float ISA: libultra uses **`-mips3 -mgp32`** (packed `$f0-$f3`; the ROM saves odd FP registers in thread contexts).
- Old gas also kept a `nop` between an FP compare (`c.le.s`) and the `bc1t/bc1tl` that follows.

## Close but not matching yet (see docs/libultra_locations.txt)
- `__osPiCreateAccessQueue`/`__osPiGetAccess` (0xBF640): the ROM's first function looks like GetAccess with the
  queue creation inlined; sources in `wip/`.
- `osSetTimer` 0xC13B0, `osContInit`, `osContStartReadData` (not found at the libreultra position; sources in `wip/`)
- `osCreateViManager`, `osAiSetNextBuffer`, `osAiGetLength`, `guPerspectiveF`, `osInitialize` (115 insns @0xC0B2C), `osCreatePiManager`
- printf family (`_Printf`, `_Ldtob`, `_Litob`, `sprintf`): libreultra's headers use `__builtin_va_list`, which
  GCC 2.8.1 lacks - needs a `stdarg`-style rewrite.

## Lessons
- Matches of fewer than ~8 instructions are unreliable (the "osSetTime" match at 0xA2E4C was an unrelated game function).
- When a function is a near-match, check the *assembler/delay-slot* behaviour before changing the C.
- The libreultra sources are SM64's libultra (2.0D); this ROM's libultra differs in places (e.g. `osPiStartDma` stores
  `piHandle = NULL`, `osDestroyThread` walks to the `priority == -1` sentinel, `osCreateThread` status register
  is 0x0400FF03).
