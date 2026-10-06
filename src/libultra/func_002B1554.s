.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2154-0xB215C (VRAM 0x002B1554) */
glabel func_002B1554
    /* B2154 002B1554 03E00008 */  jr         $ra
    /* B2158 002B1558 00000000 */   nop
endlabel func_002B1554
