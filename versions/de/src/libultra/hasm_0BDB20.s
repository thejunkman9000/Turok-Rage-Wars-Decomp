.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDB20-0xBDB2C (VRAM 0x002BCF20) */
.globl __osGetSR
__osGetSR:
    /* BDB20 002BCF20 40026000 */  mfc0       $v0, $12 /* handwritten instruction */
    /* BDB24 002BCF24 03E00008 */  jr         $ra
    /* BDB28 002BCF28 00000000 */  nop
