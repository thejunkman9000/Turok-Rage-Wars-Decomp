.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDE10-0xBDEA8 (VRAM 0x002BD210) */
.globl osInvalDCache
osInvalDCache:
    /* BDE10 002BD210 18A0001A */  .word 0x18A0001A
    /* BDE14 002BD214 00000000 */  nop
    /* BDE18 002BD218 240B2000 */  addiu      $t3, $zero, 0x2000
    /* BDE1C 002BD21C 00AB082B */  sltu       $at, $a1, $t3
    /* BDE20 002BD220 10200018 */  .word 0x10200018
    /* BDE24 002BD224 00804021 */  addu      $t0, $a0, $zero
    /* BDE28 002BD228 00854821 */  addu       $t1, $a0, $a1
    /* BDE2C 002BD22C 0109082B */  sltu       $at, $t0, $t1
    /* BDE30 002BD230 10200012 */  .word 0x10200012
    /* BDE34 002BD234 2529FFF0 */  addiu     $t1, $t1, -0x10
    /* BDE38 002BD238 310A000F */  andi       $t2, $t0, 0xF
    /* BDE3C 002BD23C 11400005 */  .word 0x11400005
    /* BDE40 002BD240 010A4023 */  subu      $t0, $t0, $t2
    /* BDE44 002BD244 BD150000 */  cache      0x15, 0x0($t0) /* handwritten instruction */
    /* BDE48 002BD248 0109082B */  sltu       $at, $t0, $t1
    /* BDE4C 002BD24C 1020000B */  .word 0x1020000B
    /* BDE50 002BD250 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BD254:
    /* BDE54 002BD254 312A000F */  andi       $t2, $t1, 0xF
    /* BDE58 002BD258 11400004 */  .word 0x11400004
    /* BDE5C 002BD25C 012A4823 */  subu      $t1, $t1, $t2
    /* BDE60 002BD260 BD350010 */  cache      0x15, 0x10($t1) /* handwritten instruction */
    /* BDE64 002BD264 0128082B */  sltu       $at, $t1, $t0
    /* BDE68 002BD268 14200004 */  .word 0x14200004
.Lauto_002BD26C:
    /* BDE6C 002BD26C BD110000 */  cache     0x11, 0x0($t0) /* handwritten instruction */
    /* BDE70 002BD270 0109082B */  sltu       $at, $t0, $t1
    /* BDE74 002BD274 1420FFFD */  .word 0x1420FFFD
    /* BDE78 002BD278 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BD27C:
    /* BDE7C 002BD27C 03E00008 */  jr         $ra
    /* BDE80 002BD280 00000000 */  nop
.Lauto_002BD284:
    /* BDE84 002BD284 3C088000 */  lui        $t0, 0x8000
    /* BDE88 002BD288 010B4821 */  addu       $t1, $t0, $t3
    /* BDE8C 002BD28C 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD290:
    /* BDE90 002BD290 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDE94 002BD294 0109082B */  sltu       $at, $t0, $t1
    /* BDE98 002BD298 1420FFFD */  .word 0x1420FFFD
    /* BDE9C 002BD29C 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDEA0 002BD2A0 03E00008 */  jr         $ra
    /* BDEA4 002BD2A4 00000000 */  nop
