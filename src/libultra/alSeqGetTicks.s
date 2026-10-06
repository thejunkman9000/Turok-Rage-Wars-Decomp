.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7D98-0xB7DA4 (VRAM 0x002B7198) */
glabel alSeqGetTicks
    /* B7D98 002B7198 8C82000C */  lw         $v0, 0xC($a0)
    /* B7D9C 002B719C 03E00008 */  jr         $ra
    /* B7DA0 002B71A0 00000000 */   nop
endlabel alSeqGetTicks
