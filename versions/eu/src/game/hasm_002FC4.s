.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0x2FC4-0x2FDC (VRAM 0x002023C4) */
.globl func_002023C4
func_002023C4:
    /* 2FC4 002023C4 40026000 */  mfc0       $v0, $12 /* handwritten instruction */
    /* 2FC8 002023C8 03E00008 */  jr         $ra
    /* 2FCC 002023CC 00000000 */  nop
.globl func_002023D0
func_002023D0:
    /* 2FD0 002023D0 40846000 */  mtc0       $a0, $12 /* handwritten instruction */
    /* 2FD4 002023D4 03E00008 */  jr         $ra
    /* 2FD8 002023D8 00000000 */  nop
