.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDE80-0xBDEE8 (VRAM 0x002BD280) */
.globl osWritebackDCache
osWritebackDCache:
    /* BDE80 002BD280 18A0000E */  .word 0x18A0000E
    /* BDE84 002BD284 240B2000 */  addiu     $t3, $zero, 0x2000
    /* BDE88 002BD288 00AB082B */  sltu       $at, $a1, $t3
    /* BDE8C 002BD28C 1020000D */  .word 0x1020000D
    /* BDE90 002BD290 00804021 */  addu      $t0, $a0, $zero
    /* BDE94 002BD294 00854821 */  addu       $t1, $a0, $a1
    /* BDE98 002BD298 0109082B */  sltu       $at, $t0, $t1
    /* BDE9C 002BD29C 10200007 */  .word 0x10200007
    /* BDEA0 002BD2A0 2529FFF0 */  addiu     $t1, $t1, -0x10
    /* BDEA4 002BD2A4 310A000F */  andi       $t2, $t0, 0xF
    /* BDEA8 002BD2A8 010A4023 */  subu       $t0, $t0, $t2
.Lauto_002BD2AC:
    /* BDEAC 002BD2AC BD190000 */  cache      0x19, 0x0($t0) /* handwritten instruction */
    /* BDEB0 002BD2B0 0109082B */  sltu       $at, $t0, $t1
.Lauto_002BD2B4:
    /* BDEB4 002BD2B4 1420FFFD */  .word 0x1420FFFD
    /* BDEB8 002BD2B8 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BD2BC:
    /* BDEBC 002BD2BC 03E00008 */  jr         $ra
    /* BDEC0 002BD2C0 00000000 */  nop
.Lauto_002BD2C4:
    /* BDEC4 002BD2C4 3C088000 */  lui        $t0, 0x8000
    /* BDEC8 002BD2C8 010B4821 */  addu       $t1, $t0, $t3
    /* BDECC 002BD2CC 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD2D0:
    /* BDED0 002BD2D0 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDED4 002BD2D4 0109082B */  sltu       $at, $t0, $t1
    /* BDED8 002BD2D8 1420FFFD */  .word 0x1420FFFD
    /* BDEDC 002BD2DC 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDEE0 002BD2E0 03E00008 */  jr         $ra
    /* BDEE4 002BD2E4 00000000 */  nop
