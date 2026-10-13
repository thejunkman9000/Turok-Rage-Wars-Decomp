.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB8150-0xB815C (VRAM 0x002B7550) */
.globl sqrtf
sqrtf:
    /* B8150 002B7550 46006004 */  sqrt.s     $fv0, $fa0
    /* B8154 002B7554 03E00008 */  jr         $ra
    /* B8158 002B7558 00000000 */  nop
