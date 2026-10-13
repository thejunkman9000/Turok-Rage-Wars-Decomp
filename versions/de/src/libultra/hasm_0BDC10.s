.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDC10-0xBDC78 (VRAM 0x002BD010) */
.globl osInvalICache
osInvalICache:
    /* BDC10 002BD010 18A0000E */  .word 0x18A0000E
    /* BDC14 002BD014 240B4000 */  addiu     $t3, $zero, 0x4000
    /* BDC18 002BD018 00AB082B */  sltu       $at, $a1, $t3
    /* BDC1C 002BD01C 1020000D */  .word 0x1020000D
    /* BDC20 002BD020 00804021 */  addu      $t0, $a0, $zero
    /* BDC24 002BD024 00854821 */  addu       $t1, $a0, $a1
    /* BDC28 002BD028 0109082B */  sltu       $at, $t0, $t1
    /* BDC2C 002BD02C 10200007 */  .word 0x10200007
    /* BDC30 002BD030 2529FFE0 */  addiu     $t1, $t1, -0x20
    /* BDC34 002BD034 310A001F */  andi       $t2, $t0, 0x1F
    /* BDC38 002BD038 010A4023 */  subu       $t0, $t0, $t2
.Lauto_002BD03C:
    /* BDC3C 002BD03C BD100000 */  cache      0x10, 0x0($t0) /* handwritten instruction */
    /* BDC40 002BD040 0109082B */  sltu       $at, $t0, $t1
.Lauto_002BD044:
    /* BDC44 002BD044 1420FFFD */  .word 0x1420FFFD
    /* BDC48 002BD048 25080020 */  addiu     $t0, $t0, 0x20
.Lauto_002BD04C:
    /* BDC4C 002BD04C 03E00008 */  jr         $ra
    /* BDC50 002BD050 00000000 */  nop
.Lauto_002BD054:
    /* BDC54 002BD054 3C088000 */  lui        $t0, 0x8000
    /* BDC58 002BD058 010B4821 */  addu       $t1, $t0, $t3
    /* BDC5C 002BD05C 2529FFE0 */  addiu      $t1, $t1, -0x20
.Lauto_002BD060:
    /* BDC60 002BD060 BD000000 */  cache      0x00, 0x0($t0) /* handwritten instruction */
    /* BDC64 002BD064 0109082B */  sltu       $at, $t0, $t1
    /* BDC68 002BD068 1420FFFD */  .word 0x1420FFFD
    /* BDC6C 002BD06C 25080020 */  addiu     $t0, $t0, (0x80000020 & 0xFFFF)
    /* BDC70 002BD070 03E00008 */  jr         $ra
    /* BDC74 002BD074 00000000 */  nop
