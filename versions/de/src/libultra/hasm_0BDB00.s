.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDB00-0xBDB0C (VRAM 0x002BCF00) */
.globl osGetCount
osGetCount:
    /* BDB00 002BCF00 40024800 */  mfc0       $v0, $9 /* handwritten instruction */
    /* BDB04 002BCF04 03E00008 */  jr         $ra
    /* BDB08 002BCF08 00000000 */  nop
