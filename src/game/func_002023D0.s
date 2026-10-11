.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x2FD0-0x2FDC (VRAM 0x002023D0) */
glabel func_002023D0
    /* 2FD0 002023D0 40846000 */  mtc0       $a0, $12 /* handwritten instruction */
    /* 2FD4 002023D4 03E00008 */  jr         $ra
    /* 2FD8 002023D8 00000000 */   nop
endlabel func_002023D0
