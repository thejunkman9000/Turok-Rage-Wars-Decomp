.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB92A4-0xB92AC (VRAM 0x002B86A4) */
glabel func_002B86A4
    /* B92A4 002B86A4 03E00008 */  jr         $ra
    /* B92A8 002B86A8 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B86A4
