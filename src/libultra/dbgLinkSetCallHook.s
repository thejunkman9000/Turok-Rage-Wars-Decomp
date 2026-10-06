.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB215C-0xB216C (VRAM 0x002B155C) */
glabel dbgLinkSetCallHook
    /* B215C 002B155C 3C01800D */  lui        $at, %hi(D_800D364C)
    /* B2160 002B1560 AC24364C */  sw         $a0, %lo(D_800D364C)($at)
    /* B2164 002B1564 03E00008 */  jr         $ra
    /* B2168 002B1568 00000000 */   nop
endlabel dbgLinkSetCallHook
