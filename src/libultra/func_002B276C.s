.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB336C-0xB3410 (VRAM 0x002B276C) */
glabel func_002B276C
    /* B336C 002B276C 96080000 */  lhu        $t0, 0x0($s0)
    /* B3370 002B2770 22100002 */  addi       $s0, $s0, 0x2 /* handwritten instruction */
    /* B3374 002B2774 010E4024 */  and        $t0, $t0, $t6
    /* B3378 002B2778 96010000 */  lhu        $at, 0x0($s0)
    /* B337C 002B277C 22100002 */  addi       $s0, $s0, 0x2 /* handwritten instruction */
    /* B3380 002B2780 01014022 */  sub        $t0, $t0, $at /* handwritten instruction */
    /* B3384 002B2784 1500FFF9 */  bnez       $t0, func_002B276C
    /* B3388 002B2788 00000000 */   nop
    /* B338C 002B278C 9209003C */  lbu        $t1, 0x3C($s0)
    /* B3390 002B2790 00000000 */  nop
    /* B3394 002B2794 01E97822 */  sub        $t7, $t7, $t1 /* handwritten instruction */
    /* B3398 002B2798 05E10005 */  bgez       $t7, .L002B27B0
    /* B339C 002B279C 00000000 */   nop
    /* B33A0 002B27A0 03E0C821 */  addu       $t9, $ra, $zero
    /* B33A4 002B27A4 0C0ACA0E */  jal        func_002B2838
    /* B33A8 002B27A8 00000000 */   nop
    /* B33AC 002B27AC 0320F821 */  addu       $ra, $t9, $zero
  .L002B27B0:
    /* B33B0 002B27B0 012E7006 */  srlv       $t6, $t6, $t1
    /* B33B4 002B27B4 9208003D */  lbu        $t0, 0x3D($s0)
    /* B33B8 002B27B8 00000000 */  nop
    /* B33BC 002B27BC 2101FFFE */  addi       $at, $t0, -0x2 /* handwritten instruction */
    /* B33C0 002B27C0 04200011 */  bltz       $at, .L002B2808
    /* B33C4 002B27C4 00000000 */   nop
    /* B33C8 002B27C8 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B33CC 002B27CC 01004821 */  addu       $t1, $t0, $zero
    /* B33D0 002B27D0 01005021 */  addu       $t2, $t0, $zero
    /* B33D4 002B27D4 9608003E */  lhu        $t0, 0x3E($s0)
    /* B33D8 002B27D8 01E97822 */  sub        $t7, $t7, $t1 /* handwritten instruction */
    /* B33DC 002B27DC 010E4024 */  and        $t0, $t0, $t6
    /* B33E0 002B27E0 05E10005 */  bgez       $t7, .L002B27F8
    /* B33E4 002B27E4 00000000 */   nop
    /* B33E8 002B27E8 03E0C821 */  addu       $t9, $ra, $zero
    /* B33EC 002B27EC 0C0ACA0E */  jal        func_002B2838
    /* B33F0 002B27F0 00000000 */   nop
    /* B33F4 002B27F4 0320F821 */  addu       $ra, $t9, $zero
  .L002B27F8:
    /* B33F8 002B27F8 012E7006 */  srlv       $t6, $t6, $t1
    /* B33FC 002B27FC 20010001 */  addi       $at, $zero, 0x1 /* handwritten instruction */
    /* B3400 002B2800 01410804 */  sllv       $at, $at, $t2
    /* B3404 002B2804 00284025 */  or         $t0, $at, $t0
  .L002B2808:
    /* B3408 002B2808 03E00008 */  jr         $ra
    /* B340C 002B280C 00000000 */   nop
endlabel func_002B276C
