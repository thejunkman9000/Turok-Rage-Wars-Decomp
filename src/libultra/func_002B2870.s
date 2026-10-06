.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3470-0xB35C4 (VRAM 0x002B2870) */
glabel func_002B2870
    /* B3470 002B2870 2008001F */  addi       $t0, $zero, 0x1F /* handwritten instruction */
    /* B3474 002B2874 03E0C021 */  addu       $t8, $ra, $zero
    /* B3478 002B2878 0C0ACA04 */  jal        func_002B2810
    /* B347C 002B287C 20090005 */   addi      $t1, $zero, 0x5 /* handwritten instruction */
    /* B3480 002B2880 0300F821 */  addu       $ra, $t8, $zero
    /* B3484 002B2884 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B3488 002B2888 0500004C */  bltz       $t0, .L002B29BC
    /* B348C 002B288C 00000000 */   nop
    /* B3490 002B2890 01005021 */  addu       $t2, $t0, $zero
    /* B3494 002B2894 01005821 */  addu       $t3, $t0, $zero
    /* B3498 002B2898 23BDFFF0 */  addi       $sp, $sp, -0x10 /* handwritten instruction */
    /* B349C 002B289C 03A08821 */  addu       $s1, $sp, $zero
  .L002B28A0:
    /* B34A0 002B28A0 2008000F */  addi       $t0, $zero, 0xF /* handwritten instruction */
    /* B34A4 002B28A4 03E0C021 */  addu       $t8, $ra, $zero
    /* B34A8 002B28A8 0C0ACA04 */  jal        func_002B2810
    /* B34AC 002B28AC 20090004 */   addi      $t1, $zero, 0x4 /* handwritten instruction */
    /* B34B0 002B28B0 0300F821 */  addu       $ra, $t8, $zero
    /* B34B4 002B28B4 A2280000 */  sb         $t0, 0x0($s1)
    /* B34B8 002B28B8 22310001 */  addi       $s1, $s1, 0x1 /* handwritten instruction */
    /* B34BC 002B28BC 1540FFF8 */  bnez       $t2, .L002B28A0
    /* B34C0 002B28C0 214AFFFF */   addi      $t2, $t2, -0x1 /* handwritten instruction */
    /* B34C4 002B28C4 00A04021 */  addu       $t0, $a1, $zero
    /* B34C8 002B28C8 20090001 */  addi       $t1, $zero, 0x1 /* handwritten instruction */
    /* B34CC 002B28CC 00005021 */  addu       $t2, $zero, $zero
    /* B34D0 002B28D0 23BDFFF0 */  addi       $sp, $sp, -0x10 /* handwritten instruction */
    /* B34D4 002B28D4 AFAD0000 */  sw         $t5, 0x0($sp)
    /* B34D8 002B28D8 AFAE0004 */  sw         $t6, 0x4($sp)
    /* B34DC 002B28DC AFAF0008 */  sw         $t7, 0x8($sp)
  .L002B28E0:
    /* B34E0 002B28E0 01606021 */  addu       $t4, $t3, $zero
    /* B34E4 002B28E4 23B10010 */  addi       $s1, $sp, 0x10 /* handwritten instruction */
  .L002B28E8:
    /* B34E8 002B28E8 92210000 */  lbu        $at, 0x0($s1)
    /* B34EC 002B28EC 22310001 */  addi       $s1, $s1, 0x1 /* handwritten instruction */
    /* B34F0 002B28F0 15210026 */  bne        $t1, $at, .L002B298C
    /* B34F4 002B28F4 00000000 */   nop
    /* B34F8 002B28F8 200D0001 */  addi       $t5, $zero, 0x1 /* handwritten instruction */
    /* B34FC 002B28FC 012D6804 */  sllv       $t5, $t5, $t1
    /* B3500 002B2900 21ADFFFF */  addi       $t5, $t5, -0x1 /* handwritten instruction */
    /* B3504 002B2904 A60D0000 */  sh         $t5, 0x0($s0)
    /* B3508 002B2908 22100002 */  addi       $s0, $s0, 0x2 /* handwritten instruction */
    /* B350C 002B290C 01406821 */  addu       $t5, $t2, $zero
    /* B3510 002B2910 000D0C00 */  sll        $at, $t5, 16
    /* B3514 002B2914 000D6C02 */  srl        $t5, $t5, 16
    /* B3518 002B2918 01A16825 */  or         $t5, $t5, $at
    /* B351C 002B291C 01207821 */  addu       $t7, $t1, $zero
    /* B3520 002B2920 21EFFFFF */  addi       $t7, $t7, -0x1 /* handwritten instruction */
  .L002B2924:
    /* B3524 002B2924 2001FFFF */  addi       $at, $zero, -0x1 /* handwritten instruction */
    /* B3528 002B2928 00010C02 */  srl        $at, $at, 16
    /* B352C 002B292C 002E7024 */  and        $t6, $at, $t6
    /* B3530 002B2930 01A70824 */  and        $at, $t5, $a3
    /* B3534 002B2934 000D6840 */  sll        $t5, $t5, 1
    /* B3538 002B2938 000E7042 */  srl        $t6, $t6, 1
    /* B353C 002B293C 10200002 */  beqz       $at, .L002B2948
    /* B3540 002B2940 00000000 */   nop
    /* B3544 002B2944 01C77025 */  or         $t6, $t6, $a3
  .L002B2948:
    /* B3548 002B2948 15E0FFF6 */  bnez       $t7, .L002B2924
    /* B354C 002B294C 21EFFFFF */   addi      $t7, $t7, -0x1 /* handwritten instruction */
    /* B3550 002B2950 200D0010 */  addi       $t5, $zero, 0x10 /* handwritten instruction */
    /* B3554 002B2954 01A96822 */  sub        $t5, $t5, $t1 /* handwritten instruction */
    /* B3558 002B2958 01AE7006 */  srlv       $t6, $t6, $t5
    /* B355C 002B295C A60E0000 */  sh         $t6, 0x0($s0)
    /* B3560 002B2960 22100002 */  addi       $s0, $s0, 0x2 /* handwritten instruction */
    /* B3564 002B2964 A209003C */  sb         $t1, 0x3C($s0)
    /* B3568 002B2968 01606821 */  addu       $t5, $t3, $zero
    /* B356C 002B296C 01AC6823 */  subu       $t5, $t5, $t4
    /* B3570 002B2970 A20D003D */  sb         $t5, 0x3D($s0)
    /* B3574 002B2974 200E0001 */  addi       $t6, $zero, 0x1 /* handwritten instruction */
    /* B3578 002B2978 25ADFFFF */  addiu      $t5, $t5, -0x1
    /* B357C 002B297C 01AE7004 */  sllv       $t6, $t6, $t5
    /* B3580 002B2980 25CEFFFF */  addiu      $t6, $t6, -0x1
    /* B3584 002B2984 A60E003E */  sh         $t6, 0x3E($s0)
    /* B3588 002B2988 01485021 */  addu       $t2, $t2, $t0
  .L002B298C:
    /* B358C 002B298C 1580FFD6 */  bnez       $t4, .L002B28E8
    /* B3590 002B2990 218CFFFF */   addi      $t4, $t4, -0x1 /* handwritten instruction */
    /* B3594 002B2994 00084042 */  srl        $t0, $t0, 1
    /* B3598 002B2998 21290001 */  addi       $t1, $t1, 0x1 /* handwritten instruction */
    /* B359C 002B299C 20010011 */  addi       $at, $zero, 0x11 /* handwritten instruction */
    /* B35A0 002B29A0 1521FFCF */  bne        $t1, $at, .L002B28E0
    /* B35A4 002B29A4 00000000 */   nop
    /* B35A8 002B29A8 8FAD0000 */  lw         $t5, 0x0($sp)
    /* B35AC 002B29AC 8FAE0004 */  lw         $t6, 0x4($sp)
    /* B35B0 002B29B0 8FAF0008 */  lw         $t7, 0x8($sp)
    /* B35B4 002B29B4 23BD0010 */  addi       $sp, $sp, 0x10 /* handwritten instruction */
    /* B35B8 002B29B8 23BD0010 */  addi       $sp, $sp, 0x10 /* handwritten instruction */
  .L002B29BC:
    /* B35BC 002B29BC 03E00008 */  jr         $ra
    /* B35C0 002B29C0 00000000 */   nop
endlabel func_002B2870
