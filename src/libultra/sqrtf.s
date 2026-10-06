.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBCF80-0xBCF90 (VRAM 0x002BC380) */
glabel sqrtf
    /* BCF80 002BC380 46006004 */  sqrt.s     $fv0, $fa0
    /* BCF84 002BC384 03E00008 */  jr         $ra
    /* BCF88 002BC388 00000000 */   nop


    /* BCF8C 002BC38C ACCA0008 */  .word      0xACCA0008 /* linker padding */
endlabel sqrtf
