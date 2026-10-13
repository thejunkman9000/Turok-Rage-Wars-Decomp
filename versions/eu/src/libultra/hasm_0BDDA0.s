.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDDA0-0xBDDAC (VRAM 0x002BD1A0) */
.globl osGetCount
osGetCount:
    /* BDDA0 002BD1A0 40024800 */  mfc0       $v0, $9 /* handwritten instruction */
    /* BDDA4 002BD1A4 03E00008 */  jr         $ra
    /* BDDA8 002BD1A8 00000000 */  nop
