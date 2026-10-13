.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDC80-0xBDD4C (VRAM 0x002BD080) */
.globl __osProbeTLB
__osProbeTLB:
    /* BDC80 002BD080 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* BDC84 002BD084 00000000 */  nop
    /* BDC88 002BD088 310900FF */  andi       $t1, $t0, 0xFF
    /* BDC8C 002BD08C 2401E000 */  addiu      $at, $zero, -0x2000
    /* BDC90 002BD090 00815024 */  and        $t2, $a0, $at
    /* BDC94 002BD094 012A4825 */  or         $t1, $t1, $t2
    /* BDC98 002BD098 40895000 */  mtc0       $t1, $10 /* handwritten instruction */
    /* BDC9C 002BD09C 00000000 */  nop
    /* BDCA0 002BD0A0 00000000 */  nop
    /* BDCA4 002BD0A4 00000000 */  nop
    /* BDCA8 002BD0A8 42000008 */  tlbp /* handwritten instruction */
    /* BDCAC 002BD0AC 00000000 */  nop
    /* BDCB0 002BD0B0 00000000 */  nop
    /* BDCB4 002BD0B4 400B0000 */  mfc0       $t3, $0 /* handwritten instruction */
    /* BDCB8 002BD0B8 00000000 */  nop
    /* BDCBC 002BD0BC 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* BDCC0 002BD0C0 01615824 */  and        $t3, $t3, $at
    /* BDCC4 002BD0C4 1560001C */  .word 0x1560001C
    /* BDCC8 002BD0C8 00000000 */  nop
    /* BDCCC 002BD0CC 42000001 */  tlbr /* handwritten instruction */
    /* BDCD0 002BD0D0 00000000 */  nop
    /* BDCD4 002BD0D4 00000000 */  nop
    /* BDCD8 002BD0D8 00000000 */  nop
    /* BDCDC 002BD0DC 400B2800 */  mfc0       $t3, $5 /* handwritten instruction */
    /* BDCE0 002BD0E0 00000000 */  nop
    /* BDCE4 002BD0E4 216B2000 */  addi       $t3, $t3, 0x2000 /* handwritten instruction */
    /* BDCE8 002BD0E8 000B5842 */  srl        $t3, $t3, 1
    /* BDCEC 002BD0EC 01646024 */  and        $t4, $t3, $a0
    /* BDCF0 002BD0F0 15800004 */  .word 0x15800004
    /* BDCF4 002BD0F4 216BFFFF */  addi      $t3, $t3, -0x1 /* handwritten instruction */
    /* BDCF8 002BD0F8 40021000 */  mfc0       $v0, $2 /* handwritten instruction */
    /* BDCFC 002BD0FC 04010002 */  .word 0x04010002
    /* BDD00 002BD100 00000000 */  nop
.Lauto_002BD104:
    /* BDD04 002BD104 40021800 */  mfc0       $v0, $3 /* handwritten instruction */
.Lauto_002BD108:
    /* BDD08 002BD108 00000000 */  nop
    /* BDD0C 002BD10C 304D0002 */  andi       $t5, $v0, 0x2
    /* BDD10 002BD110 11A00009 */  .word 0x11A00009
    /* BDD14 002BD114 00000000 */  nop
    /* BDD18 002BD118 3C013FFF */  lui        $at, (0x3FFFFFC0 >> 16)
    /* BDD1C 002BD11C 3421FFC0 */  ori        $at, $at, (0x3FFFFFC0 & 0xFFFF)
    /* BDD20 002BD120 00411024 */  and        $v0, $v0, $at
    /* BDD24 002BD124 00021180 */  sll        $v0, $v0, 6
    /* BDD28 002BD128 008B6824 */  and        $t5, $a0, $t3
    /* BDD2C 002BD12C 004D1020 */  add        $v0, $v0, $t5 /* handwritten instruction */
    /* BDD30 002BD130 04010002 */  .word 0x04010002
    /* BDD34 002BD134 00000000 */  nop
.Lauto_002BD138:
    /* BDD38 002BD138 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002BD13C:
    /* BDD3C 002BD13C 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* BDD40 002BD140 03E00008 */  jr         $ra
    /* BDD44 002BD144 00000000 */  nop
    /* BDD48 002BD148 00000000 */  nop
