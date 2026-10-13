.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBBAF0-0xBBAF8 (VRAM 0x002BAEF0) */
.globl __assert
__assert:
    /* BBAF0 002BAEF0 03E00008 */  jr         $ra
    /* BBAF4 002BAEF4 00000000 */  nop
