.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3200-0xB336C (VRAM 0x002B2600) */
glabel rncUnpackMethod1Body
    /* B3200 002B2600 2003FFFF */  addi       $v1, $zero, -0x1 /* handwritten instruction */
    /* B3204 002B2604 306300FF */  andi       $v1, $v1, 0xFF
    /* B3208 002B2608 00032600 */  sll        $a0, $v1, 24
    /* B320C 002B260C 00032FC0 */  sll        $a1, $v1, 31
    /* B3210 002B2610 00053C02 */  srl        $a3, $a1, 16
    /* B3214 002B2614 00033027 */  nor        $a2, $zero, $v1
    /* B3218 002B2618 0233A820 */  add        $s5, $s1, $s3 /* handwritten instruction */
    /* B321C 002B261C 0212B020 */  add        $s6, $s0, $s2 /* handwritten instruction */
    /* B3220 002B2620 02009821 */  addu       $s3, $s0, $zero
    /* B3224 002B2624 0220A021 */  addu       $s4, $s1, $zero
    /* B3228 002B2628 23BDFE80 */  addi       $sp, $sp, -0x180 /* handwritten instruction */
    /* B322C 002B262C 03A09021 */  addu       $s2, $sp, $zero
    /* B3230 002B2630 926E0001 */  lbu        $t6, 0x1($s3)
    /* B3234 002B2634 92610000 */  lbu        $at, 0x0($s3)
    /* B3238 002B2638 00007821 */  addu       $t7, $zero, $zero
    /* B323C 002B263C 000E7200 */  sll        $t6, $t6, 8
    /* B3240 002B2640 01C17025 */  or         $t6, $t6, $at
    /* B3244 002B2644 20080002 */  addi       $t0, $zero, 0x2 /* handwritten instruction */
    /* B3248 002B2648 03E0C021 */  addu       $t8, $ra, $zero
    /* B324C 002B264C 0C0ACA04 */  jal        rncInputBits
    /* B3250 002B2650 20090002 */   addi      $t1, $zero, 0x2 /* handwritten instruction */
    /* B3254 002B2654 0300F821 */  addu       $ra, $t8, $zero
  .L002B2658:
    /* B3258 002B2658 23BDFFF8 */  addi       $sp, $sp, -0x8 /* handwritten instruction */
    /* B325C 002B265C AFBF0000 */  sw         $ra, 0x0($sp)
    /* B3260 002B2660 0C0ACA1C */  jal        rncMakeHuffTable
    /* B3264 002B2664 02408021 */   addu      $s0, $s2, $zero
    /* B3268 002B2668 0C0ACA1C */  jal        rncMakeHuffTable
    /* B326C 002B266C 22500080 */   addi      $s0, $s2, 0x80 /* handwritten instruction */
    /* B3270 002B2670 0C0ACA1C */  jal        rncMakeHuffTable
    /* B3274 002B2674 22500100 */   addi      $s0, $s2, 0x100 /* handwritten instruction */
    /* B3278 002B2678 2008FFFF */  addi       $t0, $zero, -0x1 /* handwritten instruction */
    /* B327C 002B267C 0C0ACA04 */  jal        rncInputBits
    /* B3280 002B2680 20090010 */   addi      $t1, $zero, 0x10 /* handwritten instruction */
    /* B3284 002B2684 8FBF0000 */  lw         $ra, 0x0($sp)
    /* B3288 002B2688 23BD0008 */  addi       $sp, $sp, 0x8 /* handwritten instruction */
    /* B328C 002B268C 01006021 */  addu       $t4, $t0, $zero
    /* B3290 002B2690 2001FFFF */  addi       $at, $zero, -0x1 /* handwritten instruction */
    /* B3294 002B2694 00010C02 */  srl        $at, $at, 16
    /* B3298 002B2698 218CFFFF */  addi       $t4, $t4, -0x1 /* handwritten instruction */
    /* B329C 002B269C 080AC9BD */  j          .L002B26F4
    /* B32A0 002B26A0 002C6024 */   and       $t4, $at, $t4
  .L002B26A4:
    /* B32A4 002B26A4 22500080 */  addi       $s0, $s2, 0x80 /* handwritten instruction */
    /* B32A8 002B26A8 03E0C021 */  addu       $t8, $ra, $zero
    /* B32AC 002B26AC 0C0AC9DB */  jal        rncReadHuffCode
    /* B32B0 002B26B0 00004021 */   addu      $t0, $zero, $zero
    /* B32B4 002B26B4 00084023 */  negu       $t0, $t0
    /* B32B8 002B26B8 02888820 */  add        $s1, $s4, $t0 /* handwritten instruction */
    /* B32BC 002B26BC 2231FFFF */  addi       $s1, $s1, -0x1 /* handwritten instruction */
    /* B32C0 002B26C0 0C0AC9DB */  jal        rncReadHuffCode
    /* B32C4 002B26C4 22500100 */   addi      $s0, $s2, 0x100 /* handwritten instruction */
    /* B32C8 002B26C8 0300F821 */  addu       $ra, $t8, $zero
    /* B32CC 002B26CC 22940001 */  addi       $s4, $s4, 0x1 /* handwritten instruction */
    /* B32D0 002B26D0 92210000 */  lbu        $at, 0x0($s1)
    /* B32D4 002B26D4 22310001 */  addi       $s1, $s1, 0x1 /* handwritten instruction */
    /* B32D8 002B26D8 A281FFFF */  sb         $at, -0x1($s4)
  .L002B26DC:
    /* B32DC 002B26DC 22940001 */  addi       $s4, $s4, 0x1 /* handwritten instruction */
    /* B32E0 002B26E0 92210000 */  lbu        $at, 0x0($s1)
    /* B32E4 002B26E4 22310001 */  addi       $s1, $s1, 0x1 /* handwritten instruction */
    /* B32E8 002B26E8 A281FFFF */  sb         $at, -0x1($s4)
    /* B32EC 002B26EC 1500FFFB */  bnez       $t0, .L002B26DC
    /* B32F0 002B26F0 2108FFFF */   addi      $t0, $t0, -0x1 /* handwritten instruction */
  .L002B26F4:
    /* B32F4 002B26F4 03E0C021 */  addu       $t8, $ra, $zero
    /* B32F8 002B26F8 0C0AC9DB */  jal        rncReadHuffCode
    /* B32FC 002B26FC 02408021 */   addu      $s0, $s2, $zero
    /* B3300 002B2700 0300F821 */  addu       $ra, $t8, $zero
    /* B3304 002B2704 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* B3308 002B2708 05000011 */  bltz       $t0, .L002B2750
    /* B330C 002B270C 00000000 */   nop
  .L002B2710:
    /* B3310 002B2710 92610000 */  lbu        $at, 0x0($s3)
    /* B3314 002B2714 22730001 */  addi       $s3, $s3, 0x1 /* handwritten instruction */
    /* B3318 002B2718 A2810000 */  sb         $at, 0x0($s4)
    /* B331C 002B271C 22940001 */  addi       $s4, $s4, 0x1 /* handwritten instruction */
    /* B3320 002B2720 1500FFFB */  bnez       $t0, .L002B2710
    /* B3324 002B2724 2108FFFF */   addi      $t0, $t0, -0x1 /* handwritten instruction */
    /* B3328 002B2728 92610001 */  lbu        $at, 0x1($s3)
    /* B332C 002B272C 92680000 */  lbu        $t0, 0x0($s3)
    /* B3330 002B2730 00010A00 */  sll        $at, $at, 8
    /* B3334 002B2734 00284025 */  or         $t0, $at, $t0
    /* B3338 002B2738 01E84004 */  sllv       $t0, $t0, $t7
    /* B333C 002B273C 20090001 */  addi       $t1, $zero, 0x1 /* handwritten instruction */
    /* B3340 002B2740 01E94804 */  sllv       $t1, $t1, $t7
    /* B3344 002B2744 2529FFFF */  addiu      $t1, $t1, -0x1
    /* B3348 002B2748 01C97024 */  and        $t6, $t6, $t1
    /* B334C 002B274C 010E7025 */  or         $t6, $t0, $t6
  .L002B2750:
    /* B3350 002B2750 1580FFD4 */  bnez       $t4, .L002B26A4
    /* B3354 002B2754 218CFFFF */   addi      $t4, $t4, -0x1 /* handwritten instruction */
    /* B3358 002B2758 02760822 */  sub        $at, $s3, $s6 /* handwritten instruction */
    /* B335C 002B275C 0420FFBE */  bltz       $at, .L002B2658
    /* B3360 002B2760 00000000 */   nop
    /* B3364 002B2764 03E00008 */  jr         $ra
    /* B3368 002B2768 23BD0180 */   addi      $sp, $sp, 0x180 /* handwritten instruction */
endlabel rncUnpackMethod1Body
