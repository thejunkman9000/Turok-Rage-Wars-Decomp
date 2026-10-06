.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3040-0xB30C0 (VRAM 0x002B2440) */
glabel func_002B2440
    /* B3040 002B2440 8FB80010 */  lw         $t8, 0x10($sp)
    /* B3044 002B2444 20080007 */  addi       $t0, $zero, 0x7 /* handwritten instruction */
    /* B3048 002B2448 8FB90014 */  lw         $t9, 0x14($sp)
    /* B304C 002B244C 200FFFFF */  addi       $t7, $zero, -0x1 /* handwritten instruction */
    /* B3050 002B2450 0328C824 */  and        $t9, $t9, $t0
    /* B3054 002B2454 00F84824 */  and        $t1, $a3, $t8
    /* B3058 002B2458 112F0019 */  beq        $t1, $t7, func_002B24C0
    /* B305C 002B245C 37390018 */   ori       $t9, $t9, 0x18
    /* B3060 002B2460 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* B3064 002B2464 40840000 */  mtc0       $a0, $0 /* handwritten instruction */
    /* B3068 002B2468 40852800 */  mtc0       $a1, $5 /* handwritten instruction */
    /* B306C 002B246C 40865000 */  mtc0       $a2, $10 /* handwritten instruction */
    /* B3070 002B2470 10EF0005 */  beq        $a3, $t7, .L002B2488
    /* B3074 002B2474 200E0001 */   addi      $t6, $zero, 0x1 /* handwritten instruction */
    /* B3078 002B2478 00076982 */  srl        $t5, $a3, 6
    /* B307C 002B247C 01B96825 */  or         $t5, $t5, $t9
    /* B3080 002B2480 10000002 */  b          .L002B248C
    /* B3084 002B2484 408D1000 */   mtc0      $t5, $2 /* handwritten instruction */
  .L002B2488:
    /* B3088 002B2488 408E1000 */  mtc0       $t6, $2 /* handwritten instruction */
  .L002B248C:
    /* B308C 002B248C 130F0004 */  beq        $t8, $t7, .L002B24A0
    /* B3090 002B2490 408E1800 */   mtc0      $t6, $3 /* handwritten instruction */
    /* B3094 002B2494 00186982 */  srl        $t5, $t8, 6
    /* B3098 002B2498 01B96825 */  or         $t5, $t5, $t9
    /* B309C 002B249C 408D1800 */  mtc0       $t5, $3 /* handwritten instruction */
  .L002B24A0:
    /* B30A0 002B24A0 42000002 */  tlbwi /* handwritten instruction */
    /* B30A4 002B24A4 00000000 */  nop
    /* B30A8 002B24A8 00000000 */  nop
    /* B30AC 002B24AC 00000000 */  nop
    /* B30B0 002B24B0 00000000 */  nop
    /* B30B4 002B24B4 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* B30B8 002B24B8 03E00008 */  jr         $ra
    /* B30BC 002B24BC 00000000 */   nop
endlabel func_002B2440
