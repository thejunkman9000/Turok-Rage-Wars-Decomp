.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9208-0xB9210 (VRAM 0x002B8608) */
glabel func_002B8608
    /* B9208 002B8608 24070001 */  addiu      $a3, $zero, 0x1
    /* B920C 002B860C 00002021 */  addu       $a0, $zero, $zero
endlabel func_002B8608
