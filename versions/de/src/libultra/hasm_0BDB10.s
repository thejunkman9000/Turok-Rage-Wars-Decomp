.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDB10-0xBDB1C (VRAM 0x002BCF10) */
.globl __osGetFpcCsr
__osGetFpcCsr:
    /* BDB10 002BCF10 4442F800 */  cfc1       $v0, $31
    /* BDB14 002BCF14 03E00008 */  jr         $ra
    /* BDB18 002BCF18 00000000 */  nop
