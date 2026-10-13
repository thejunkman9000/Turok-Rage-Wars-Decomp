.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDDC0-0xBDDCC (VRAM 0x002BD1C0) */
.globl __osGetSR
__osGetSR:
    /* BDDC0 002BD1C0 40026000 */  mfc0       $v0, $12 /* handwritten instruction */
    /* BDDC4 002BD1C4 03E00008 */  jr         $ra
    /* BDDC8 002BD1C8 00000000 */  nop
