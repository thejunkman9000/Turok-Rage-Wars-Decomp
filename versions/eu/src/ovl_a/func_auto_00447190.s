.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly (watchpoint setter), ROM 0x1BD190-0x1BD1D4 (VRAM 0x00447190); same words as v1.1 func_00446B80 */
glabel func_auto_00447190
    /* 1BD190 00447190 00042100 */  sll        $a0, $a0, 4
    /* 1BD194 00447194 00042102 */  srl        $a0, $a0, 4
    /* 1BD198 00447198 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* 1BD19C 0044719C 00442024 */  and        $a0, $v0, $a0
    /* 1BD1A0 004471A0 30A50003 */  andi       $a1, $a1, 0x3
    /* 1BD1A4 004471A4 00A42025 */  or         $a0, $a1, $a0
    /* 1BD1A8 004471A8 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* 1BD1AC 004471AC 00000000 */  nop
    /* 1BD1B0 004471B0 00000000 */  nop
    /* 1BD1B4 004471B4 00000000 */  nop
    /* 1BD1B8 004471B8 00000000 */  nop
    /* 1BD1BC 004471BC 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* 1BD1C0 004471C0 00000000 */  nop
    /* 1BD1C4 004471C4 00000000 */  nop
    /* 1BD1C8 004471C8 00000000 */  nop
    /* 1BD1CC 004471CC 03E00008 */  jr         $ra
    /* 1BD1D0 004471D0 00000000 */   nop
endlabel func_auto_00447190
