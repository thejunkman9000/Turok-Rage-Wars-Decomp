.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDB70-0xBDC08 (VRAM 0x002BCF70) */
.globl osInvalDCache
osInvalDCache:
    /* BDB70 002BCF70 18A0001A */  .word 0x18A0001A
    /* BDB74 002BCF74 00000000 */  nop
    /* BDB78 002BCF78 240B2000 */  addiu      $t3, $zero, 0x2000
    /* BDB7C 002BCF7C 00AB082B */  sltu       $at, $a1, $t3
    /* BDB80 002BCF80 10200018 */  .word 0x10200018
    /* BDB84 002BCF84 00804021 */  addu      $t0, $a0, $zero
    /* BDB88 002BCF88 00854821 */  addu       $t1, $a0, $a1
    /* BDB8C 002BCF8C 0109082B */  sltu       $at, $t0, $t1
    /* BDB90 002BCF90 10200012 */  .word 0x10200012
    /* BDB94 002BCF94 2529FFF0 */  addiu     $t1, $t1, -0x10
    /* BDB98 002BCF98 310A000F */  andi       $t2, $t0, 0xF
    /* BDB9C 002BCF9C 11400005 */  .word 0x11400005
    /* BDBA0 002BCFA0 010A4023 */  subu      $t0, $t0, $t2
    /* BDBA4 002BCFA4 BD150000 */  cache      0x15, 0x0($t0) /* handwritten instruction */
    /* BDBA8 002BCFA8 0109082B */  sltu       $at, $t0, $t1
    /* BDBAC 002BCFAC 1020000B */  .word 0x1020000B
    /* BDBB0 002BCFB0 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BCFB4:
    /* BDBB4 002BCFB4 312A000F */  andi       $t2, $t1, 0xF
    /* BDBB8 002BCFB8 11400004 */  .word 0x11400004
    /* BDBBC 002BCFBC 012A4823 */  subu      $t1, $t1, $t2
    /* BDBC0 002BCFC0 BD350010 */  cache      0x15, 0x10($t1) /* handwritten instruction */
    /* BDBC4 002BCFC4 0128082B */  sltu       $at, $t1, $t0
    /* BDBC8 002BCFC8 14200004 */  .word 0x14200004
.Lauto_002BCFCC:
    /* BDBCC 002BCFCC BD110000 */  cache     0x11, 0x0($t0) /* handwritten instruction */
    /* BDBD0 002BCFD0 0109082B */  sltu       $at, $t0, $t1
    /* BDBD4 002BCFD4 1420FFFD */  .word 0x1420FFFD
    /* BDBD8 002BCFD8 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BCFDC:
    /* BDBDC 002BCFDC 03E00008 */  jr         $ra
    /* BDBE0 002BCFE0 00000000 */  nop
.Lauto_002BCFE4:
    /* BDBE4 002BCFE4 3C088000 */  lui        $t0, 0x8000
    /* BDBE8 002BCFE8 010B4821 */  addu       $t1, $t0, $t3
    /* BDBEC 002BCFEC 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BCFF0:
    /* BDBF0 002BCFF0 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDBF4 002BCFF4 0109082B */  sltu       $at, $t0, $t1
    /* BDBF8 002BCFF8 1420FFFD */  .word 0x1420FFFD
    /* BDBFC 002BCFFC 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDC00 002BD000 03E00008 */  jr         $ra
    /* BDC04 002BD004 00000000 */  nop
