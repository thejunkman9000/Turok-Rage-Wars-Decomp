.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC3DB0-0xC3DB8 (VRAM 0x002C31B0) */
glabel _Ldtob
    /* C3DB0 002C31B0 03E00008 */  jr         $ra
    /* C3DB4 002C31B4 00000000 */   nop
endlabel _Ldtob
