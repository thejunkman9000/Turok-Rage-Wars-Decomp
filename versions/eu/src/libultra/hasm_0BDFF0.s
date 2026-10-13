.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDFF0-0xBDFFC (VRAM 0x002BD3F0) */
.globl __osSetCompare
__osSetCompare:
    /* BDFF0 002BD3F0 40845800 */  mtc0       $a0, $11 /* handwritten instruction */
    /* BDFF4 002BD3F4 03E00008 */  jr         $ra
    /* BDFF8 002BD3F8 00000000 */  nop
