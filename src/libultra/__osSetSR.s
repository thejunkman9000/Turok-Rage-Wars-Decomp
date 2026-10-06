.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2F10-0xC2F20 (VRAM 0x002C2310) */
glabel __osSetSR
    /* C2F10 002C2310 40846000 */  mtc0       $a0, $12 /* handwritten instruction */
    /* C2F14 002C2314 00000000 */  nop
    /* C2F18 002C2318 03E00008 */  jr         $ra
    /* C2F1C 002C231C 00000000 */   nop
endlabel __osSetSR
