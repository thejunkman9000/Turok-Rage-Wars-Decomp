.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDDB0-0xBDDBC (VRAM 0x002BD1B0) */
.globl __osGetFpcCsr
__osGetFpcCsr:
    /* BDDB0 002BD1B0 4442F800 */  cfc1       $v0, $31
    /* BDDB4 002BD1B4 03E00008 */  jr         $ra
    /* BDDB8 002BD1B8 00000000 */  nop
