.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB7EB0-0xB7EBC (VRAM 0x002B72B0) */
.globl sqrtf
sqrtf:
    /* B7EB0 002B72B0 46006004 */  sqrt.s     $fv0, $fa0
    /* B7EB4 002B72B4 03E00008 */  jr         $ra
    /* B7EB8 002B72B8 00000000 */  nop
