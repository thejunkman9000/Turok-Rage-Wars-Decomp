.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly (watchpoint setter), US v1.0 ROM 0x1AA0A0-0x1AA0E4 (VRAM 0x004460A0) */
glabel func_auto_004460A0
    /* 1AA0A0 004460A0 00042100 */  sll        $a0, $a0, 4
    /* 1AA0A4 004460A4 00042102 */  srl        $a0, $a0, 4
    /* 1AA0A8 004460A8 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* 1AA0AC 004460AC 00442024 */  and        $a0, $v0, $a0
    /* 1AA0B0 004460B0 30A50003 */  andi       $a1, $a1, 0x3
    /* 1AA0B4 004460B4 00A42025 */  or         $a0, $a1, $a0
    /* 1AA0B8 004460B8 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* 1AA0BC 004460BC 00000000 */  nop
    /* 1AA0C0 004460C0 00000000 */  nop
    /* 1AA0C4 004460C4 00000000 */  nop
    /* 1AA0C8 004460C8 00000000 */  nop
    /* 1AA0CC 004460CC 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* 1AA0D0 004460D0 00000000 */  nop
    /* 1AA0D4 004460D4 00000000 */  nop
    /* 1AA0D8 004460D8 00000000 */  nop
    /* 1AA0DC 004460DC 03E00008 */  jr         $ra
    /* 1AA0E0 004460E0 00000000 */   nop
endlabel func_auto_004460A0
