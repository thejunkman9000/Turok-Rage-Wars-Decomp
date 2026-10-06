.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8F6C-0xB8F70 (VRAM 0x002B836C) */
glabel func_002B836C
    /* B8F6C 002B836C 24050007 */  addiu      $a1, $zero, 0x7
endlabel func_002B836C
