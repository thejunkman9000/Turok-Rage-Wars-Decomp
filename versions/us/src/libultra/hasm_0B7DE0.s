.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB7DE0-0xB7DF0 (VRAM 0x002B71E0) */
.globl sqrtf
sqrtf:
    /* B7DE0 002B71E0 46006004 */  sqrt.s     $fv0, $fa0
    /* B7DE4 002B71E4 03E00008 */  jr         $ra
    /* B7DE8 002B71E8 00000000 */  nop
.globl func_auto_002B71EC
func_auto_002B71EC:
    /* B7DEC 002B71EC 90000000 */  lbu        $zero, 0x0($zero)
