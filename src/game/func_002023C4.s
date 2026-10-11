.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x2FC4-0x2FD0 (VRAM 0x002023C4) */
glabel func_002023C4
    /* 2FC4 002023C4 40026000 */  mfc0       $v0, $12 /* handwritten instruction */
    /* 2FC8 002023C8 03E00008 */  jr         $ra
    /* 2FCC 002023CC 00000000 */   nop
endlabel func_002023C4
