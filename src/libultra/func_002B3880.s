.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4480-0xB448C (VRAM 0x002B3880) */
glabel func_002B3880
    /* B4480 002B3880 8C82000C */  lw         $v0, 0xC($a0)
    /* B4484 002B3884 03E00008 */  jr         $ra
    /* B4488 002B3888 00000000 */   nop
endlabel func_002B3880
