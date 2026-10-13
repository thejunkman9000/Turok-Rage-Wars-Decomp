.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly (watchpoint setter), ROM 0x1ABF30-0x1ABF74 (VRAM 0x00445F30); same words as the Europe func_auto_00447190; the word before it (0x1ABF2C jr $ra) is linker pad */
glabel func_auto_00445F30
    /* 1ABF30 00445F30 00042100 */  sll        $a0, $a0, 4
    /* 1ABF34 00445F34 00042102 */  srl        $a0, $a0, 4
    /* 1ABF38 00445F38 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* 1ABF3C 00445F3C 00442024 */  and        $a0, $v0, $a0
    /* 1ABF40 00445F40 30A50003 */  andi       $a1, $a1, 0x3
    /* 1ABF44 00445F44 00A42025 */  or         $a0, $a1, $a0
    /* 1ABF48 00445F48 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* 1ABF4C 00445F4C 00000000 */  nop
    /* 1ABF50 00445F50 00000000 */  nop
    /* 1ABF54 00445F54 00000000 */  nop
    /* 1ABF58 00445F58 00000000 */  nop
    /* 1ABF5C 00445F5C 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* 1ABF60 00445F60 00000000 */  nop
    /* 1ABF64 00445F64 00000000 */  nop
    /* 1ABF68 00445F68 00000000 */  nop
    /* 1ABF6C 00445F6C 03E00008 */  jr         $ra
    /* 1ABF70 00445F70 00000000 */   nop
endlabel func_auto_00445F30
