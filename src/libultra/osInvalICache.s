.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2D00-0xC2D70 (VRAM 0x002C2100) */
glabel osInvalICache
    /* C2D00 002C2100 18A0000E */  blez       $a1, .L002C213C
    /* C2D04 002C2104 240B4000 */   addiu     $t3, $zero, 0x4000
    /* C2D08 002C2108 00AB082B */  sltu       $at, $a1, $t3
    /* C2D0C 002C210C 1020000D */  beqz       $at, .L002C2144
    /* C2D10 002C2110 00804021 */   addu      $t0, $a0, $zero
    /* C2D14 002C2114 00854821 */  addu       $t1, $a0, $a1
    /* C2D18 002C2118 0109082B */  sltu       $at, $t0, $t1
    /* C2D1C 002C211C 10200007 */  beqz       $at, .L002C213C
    /* C2D20 002C2120 2529FFE0 */   addiu     $t1, $t1, -0x20
    /* C2D24 002C2124 310A001F */  andi       $t2, $t0, 0x1F
    /* C2D28 002C2128 010A4023 */  subu       $t0, $t0, $t2
  .L002C212C:
    /* C2D2C 002C212C BD100000 */  cache      0x10, 0x0($t0) /* handwritten instruction */
    /* C2D30 002C2130 0109082B */  sltu       $at, $t0, $t1
    /* C2D34 002C2134 1420FFFD */  bnez       $at, .L002C212C
    /* C2D38 002C2138 25080020 */   addiu     $t0, $t0, 0x20
  .L002C213C:
    /* C2D3C 002C213C 03E00008 */  jr         $ra
    /* C2D40 002C2140 00000000 */   nop
  .L002C2144:
    /* C2D44 002C2144 3C088000 */  lui        $t0, 0x8000
    /* C2D48 002C2148 010B4821 */  addu       $t1, $t0, $t3
    /* C2D4C 002C214C 2529FFE0 */  addiu      $t1, $t1, -0x20
  .L002C2150:
    /* C2D50 002C2150 BD000000 */  cache      0x00, 0x0($t0) /* handwritten instruction */
    /* C2D54 002C2154 0109082B */  sltu       $at, $t0, $t1
    /* C2D58 002C2158 1420FFFD */  bnez       $at, .L002C2150
    /* C2D5C 002C215C 25080020 */   addiu     $t0, $t0, (0x80000020 & 0xFFFF)
    /* C2D60 002C2160 03E00008 */  jr         $ra
    /* C2D64 002C2164 00000000 */   nop


    /* C2D68 002C2168 02202821 */  .word      0x02202821 /* linker padding */
    /* C2D6C 002C216C 02403021 */  .word      0x02403021 /* linker padding */
endlabel osInvalICache
