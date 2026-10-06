.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8BD0-0xB8BE0 (VRAM 0x002B7FD0) */
glabel func_002B7FD0
    /* B8BD0 002B7FD0 00052C00 */  sll        $a1, $a1, 16
    /* B8BD4 002B7FD4 00052C03 */  sra        $a1, $a1, 16
    /* B8BD8 002B7FD8 03E00008 */  jr         $ra
    /* B8BDC 002B7FDC AC85003C */   sw        $a1, 0x3C($a0)
endlabel func_002B7FD0
