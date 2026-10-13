.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBB850-0xBB858 (VRAM 0x002BAC50) */
.globl __assert
__assert:
    /* BB850 002BAC50 03E00008 */  jr         $ra
    /* BB854 002BAC54 00000000 */  nop
