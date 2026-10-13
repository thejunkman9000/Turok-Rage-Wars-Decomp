.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDA80-0xBDC8C (VRAM 0x002BCE80) */
.globl __osRestoreInt
__osRestoreInt:
    /* BDA80 002BCE80 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* BDA84 002BCE84 01044025 */  or         $t0, $t0, $a0
    /* BDA88 002BCE88 40886000 */  mtc0       $t0, $12 /* handwritten instruction */
    /* BDA8C 002BCE8C 00000000 */  nop
    /* BDA90 002BCE90 00000000 */  nop
    /* BDA94 002BCE94 03E00008 */  jr         $ra
    /* BDA98 002BCE98 00000000 */  nop
.globl D_auto_002BCE9C
D_auto_002BCE9C:
    /* BDA9C 002BCE9C 0008000C */  .word 0x0008000C
.globl osInvalDCache
osInvalDCache:
    /* BDAA0 002BCEA0 18A0001A */  .word 0x18A0001A
    /* BDAA4 002BCEA4 00000000 */  nop
    /* BDAA8 002BCEA8 240B2000 */  addiu      $t3, $zero, 0x2000
    /* BDAAC 002BCEAC 00AB082B */  sltu       $at, $a1, $t3
    /* BDAB0 002BCEB0 10200018 */  .word 0x10200018
    /* BDAB4 002BCEB4 00804021 */  addu      $t0, $a0, $zero
    /* BDAB8 002BCEB8 00854821 */  addu       $t1, $a0, $a1
    /* BDABC 002BCEBC 0109082B */  sltu       $at, $t0, $t1
    /* BDAC0 002BCEC0 10200012 */  .word 0x10200012
    /* BDAC4 002BCEC4 2529FFF0 */  addiu     $t1, $t1, -0x10
    /* BDAC8 002BCEC8 310A000F */  andi       $t2, $t0, 0xF
    /* BDACC 002BCECC 11400005 */  .word 0x11400005
    /* BDAD0 002BCED0 010A4023 */  subu      $t0, $t0, $t2
    /* BDAD4 002BCED4 BD150000 */  cache      0x15, 0x0($t0) /* handwritten instruction */
    /* BDAD8 002BCED8 0109082B */  sltu       $at, $t0, $t1
    /* BDADC 002BCEDC 1020000B */  .word 0x1020000B
    /* BDAE0 002BCEE0 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BCEE4:
    /* BDAE4 002BCEE4 312A000F */  andi       $t2, $t1, 0xF
    /* BDAE8 002BCEE8 11400004 */  .word 0x11400004
    /* BDAEC 002BCEEC 012A4823 */  subu      $t1, $t1, $t2
    /* BDAF0 002BCEF0 BD350010 */  cache      0x15, 0x10($t1) /* handwritten instruction */
    /* BDAF4 002BCEF4 0128082B */  sltu       $at, $t1, $t0
    /* BDAF8 002BCEF8 14200004 */  .word 0x14200004
.Lauto_002BCEFC:
    /* BDAFC 002BCEFC BD110000 */  cache     0x11, 0x0($t0) /* handwritten instruction */
    /* BDB00 002BCF00 0109082B */  sltu       $at, $t0, $t1
    /* BDB04 002BCF04 1420FFFD */  .word 0x1420FFFD
    /* BDB08 002BCF08 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BCF0C:
    /* BDB0C 002BCF0C 03E00008 */  jr         $ra
    /* BDB10 002BCF10 00000000 */  nop
.Lauto_002BCF14:
    /* BDB14 002BCF14 3C088000 */  lui        $t0, 0x8000
    /* BDB18 002BCF18 010B4821 */  addu       $t1, $t0, $t3
    /* BDB1C 002BCF1C 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BCF20:
    /* BDB20 002BCF20 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDB24 002BCF24 0109082B */  sltu       $at, $t0, $t1
    /* BDB28 002BCF28 1420FFFD */  .word 0x1420FFFD
    /* BDB2C 002BCF2C 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDB30 002BCF30 03E00008 */  jr         $ra
    /* BDB34 002BCF34 00000000 */  nop
.globl D_auto_002BCF38
D_auto_002BCF38:
    /* BDB38 002BCF38 63496E73 */  .word 0x63496E73
    /* BDB3C 002BCF3C 74616E63 */  .word 0x74616E63
.globl osInvalICache
osInvalICache:
    /* BDB40 002BCF40 18A0000E */  .word 0x18A0000E
    /* BDB44 002BCF44 240B4000 */  addiu     $t3, $zero, 0x4000
    /* BDB48 002BCF48 00AB082B */  sltu       $at, $a1, $t3
    /* BDB4C 002BCF4C 1020000D */  .word 0x1020000D
    /* BDB50 002BCF50 00804021 */  addu      $t0, $a0, $zero
    /* BDB54 002BCF54 00854821 */  addu       $t1, $a0, $a1
    /* BDB58 002BCF58 0109082B */  sltu       $at, $t0, $t1
    /* BDB5C 002BCF5C 10200007 */  .word 0x10200007
    /* BDB60 002BCF60 2529FFE0 */  addiu     $t1, $t1, -0x20
    /* BDB64 002BCF64 310A001F */  andi       $t2, $t0, 0x1F
    /* BDB68 002BCF68 010A4023 */  subu       $t0, $t0, $t2
.Lauto_002BCF6C:
    /* BDB6C 002BCF6C BD100000 */  cache      0x10, 0x0($t0) /* handwritten instruction */
    /* BDB70 002BCF70 0109082B */  sltu       $at, $t0, $t1
    /* BDB74 002BCF74 1420FFFD */  .word 0x1420FFFD
    /* BDB78 002BCF78 25080020 */  addiu     $t0, $t0, 0x20
.Lauto_002BCF7C:
    /* BDB7C 002BCF7C 03E00008 */  jr         $ra
    /* BDB80 002BCF80 00000000 */  nop
.Lauto_002BCF84:
    /* BDB84 002BCF84 3C088000 */  lui        $t0, 0x8000
    /* BDB88 002BCF88 010B4821 */  addu       $t1, $t0, $t3
    /* BDB8C 002BCF8C 2529FFE0 */  addiu      $t1, $t1, -0x20
.Lauto_002BCF90:
    /* BDB90 002BCF90 BD000000 */  cache      0x00, 0x0($t0) /* handwritten instruction */
    /* BDB94 002BCF94 0109082B */  sltu       $at, $t0, $t1
    /* BDB98 002BCF98 1420FFFD */  .word 0x1420FFFD
    /* BDB9C 002BCF9C 25080020 */  addiu     $t0, $t0, (0x80000020 & 0xFFFF)
    /* BDBA0 002BCFA0 03E00008 */  jr         $ra
    /* BDBA4 002BCFA4 00000000 */  nop
    /* BDBA8 002BCFA8 00000000 */  nop
.globl D_auto_002BCFAC
D_auto_002BCFAC:
    /* BDBAC 002BCFAC 00080008 */  .word 0x00080008
.globl __osProbeTLB
__osProbeTLB:
    /* BDBB0 002BCFB0 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* BDBB4 002BCFB4 00000000 */  nop
    /* BDBB8 002BCFB8 310900FF */  andi       $t1, $t0, 0xFF
    /* BDBBC 002BCFBC 2401E000 */  addiu      $at, $zero, -0x2000
    /* BDBC0 002BCFC0 00815024 */  and        $t2, $a0, $at
    /* BDBC4 002BCFC4 012A4825 */  or         $t1, $t1, $t2
    /* BDBC8 002BCFC8 40895000 */  mtc0       $t1, $10 /* handwritten instruction */
    /* BDBCC 002BCFCC 00000000 */  nop
    /* BDBD0 002BCFD0 00000000 */  nop
    /* BDBD4 002BCFD4 00000000 */  nop
    /* BDBD8 002BCFD8 42000008 */  tlbp /* handwritten instruction */
    /* BDBDC 002BCFDC 00000000 */  nop
    /* BDBE0 002BCFE0 00000000 */  nop
    /* BDBE4 002BCFE4 400B0000 */  mfc0       $t3, $0 /* handwritten instruction */
    /* BDBE8 002BCFE8 00000000 */  nop
    /* BDBEC 002BCFEC 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* BDBF0 002BCFF0 01615824 */  and        $t3, $t3, $at
    /* BDBF4 002BCFF4 1560001C */  .word 0x1560001C
    /* BDBF8 002BCFF8 00000000 */  nop
    /* BDBFC 002BCFFC 42000001 */  tlbr /* handwritten instruction */
    /* BDC00 002BD000 00000000 */  nop
    /* BDC04 002BD004 00000000 */  nop
    /* BDC08 002BD008 00000000 */  nop
    /* BDC0C 002BD00C 400B2800 */  mfc0       $t3, $5 /* handwritten instruction */
    /* BDC10 002BD010 00000000 */  nop
    /* BDC14 002BD014 216B2000 */  addi       $t3, $t3, 0x2000 /* handwritten instruction */
    /* BDC18 002BD018 000B5842 */  srl        $t3, $t3, 1
    /* BDC1C 002BD01C 01646024 */  and        $t4, $t3, $a0
    /* BDC20 002BD020 15800004 */  .word 0x15800004
    /* BDC24 002BD024 216BFFFF */  addi      $t3, $t3, -0x1 /* handwritten instruction */
    /* BDC28 002BD028 40021000 */  mfc0       $v0, $2 /* handwritten instruction */
    /* BDC2C 002BD02C 04010002 */  .word 0x04010002
    /* BDC30 002BD030 00000000 */  nop
.Lauto_002BD034:
    /* BDC34 002BD034 40021800 */  mfc0       $v0, $3 /* handwritten instruction */
.Lauto_002BD038:
    /* BDC38 002BD038 00000000 */  nop
    /* BDC3C 002BD03C 304D0002 */  andi       $t5, $v0, 0x2
    /* BDC40 002BD040 11A00009 */  .word 0x11A00009
    /* BDC44 002BD044 00000000 */  nop
    /* BDC48 002BD048 3C013FFF */  lui        $at, (0x3FFFFFC0 >> 16)
    /* BDC4C 002BD04C 3421FFC0 */  ori        $at, $at, (0x3FFFFFC0 & 0xFFFF)
    /* BDC50 002BD050 00411024 */  and        $v0, $v0, $at
    /* BDC54 002BD054 00021180 */  sll        $v0, $v0, 6
    /* BDC58 002BD058 008B6824 */  and        $t5, $a0, $t3
    /* BDC5C 002BD05C 004D1020 */  add        $v0, $v0, $t5 /* handwritten instruction */
    /* BDC60 002BD060 04010002 */  .word 0x04010002
    /* BDC64 002BD064 00000000 */  nop
.Lauto_002BD068:
    /* BDC68 002BD068 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002BD06C:
    /* BDC6C 002BD06C 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* BDC70 002BD070 03E00008 */  jr         $ra
    /* BDC74 002BD074 00000000 */  nop
.globl D_auto_002BD078
D_auto_002BD078:
    /* BDC78 002BD078 4D6F6465 */  .word 0x4D6F6465
    /* BDC7C 002BD07C 6C520000 */  .word 0x6C520000
.globl __osSetCompare
__osSetCompare:
    /* BDC80 002BD080 40845800 */  mtc0       $a0, $11 /* handwritten instruction */
    /* BDC84 002BD084 03E00008 */  jr         $ra
    /* BDC88 002BD088 00000000 */  nop
