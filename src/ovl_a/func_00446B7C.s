.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B4B7C-0x1B4BD0 (VRAM 0x00446B7C) */
glabel func_00446B7C
    /* 1B4B7C 00446B7C 304200C0 */  andi       $v0, $v0, 0xC0
    /* 1B4B80 00446B80 00042100 */  sll        $a0, $a0, 4
    /* 1B4B84 00446B84 00042102 */  srl        $a0, $a0, 4
    /* 1B4B88 00446B88 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* 1B4B8C 00446B8C 00442024 */  and        $a0, $v0, $a0
    /* 1B4B90 00446B90 30A50003 */  andi       $a1, $a1, 0x3
    /* 1B4B94 00446B94 00A42025 */  or         $a0, $a1, $a0
    /* 1B4B98 00446B98 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* 1B4B9C 00446B9C 00000000 */  nop
    /* 1B4BA0 00446BA0 00000000 */  nop
    /* 1B4BA4 00446BA4 00000000 */  nop
    /* 1B4BA8 00446BA8 00000000 */  nop
    /* 1B4BAC 00446BAC 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* 1B4BB0 00446BB0 00000000 */  nop
    /* 1B4BB4 00446BB4 00000000 */  nop
    /* 1B4BB8 00446BB8 00000000 */  nop
    /* 1B4BBC 00446BBC 03E00008 */  jr         $ra
    /* 1B4BC0 00446BC0 00000000 */   nop


    /* 1B4BC4 00446BC4 AFB30064 */  .word      0xAFB30064 /* linker padding */
    /* 1B4BC8 00446BC8 00C09821 */  .word      0x00C09821 /* linker padding */
    /* 1B4BCC 00446BCC AFBF0068 */  .word      0xAFBF0068 /* linker padding */
endlabel func_00446B7C
