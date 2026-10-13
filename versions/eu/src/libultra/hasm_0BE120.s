.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBE120-0xBE188 (VRAM 0x002BD520) */
.globl osWritebackDCache
osWritebackDCache:
    /* BE120 002BD520 18A0000E */  .word 0x18A0000E
    /* BE124 002BD524 240B2000 */  addiu     $t3, $zero, 0x2000
    /* BE128 002BD528 00AB082B */  sltu       $at, $a1, $t3
    /* BE12C 002BD52C 1020000D */  .word 0x1020000D
    /* BE130 002BD530 00804021 */  addu      $t0, $a0, $zero
    /* BE134 002BD534 00854821 */  addu       $t1, $a0, $a1
    /* BE138 002BD538 0109082B */  sltu       $at, $t0, $t1
    /* BE13C 002BD53C 10200007 */  .word 0x10200007
    /* BE140 002BD540 2529FFF0 */  addiu     $t1, $t1, -0x10
    /* BE144 002BD544 310A000F */  andi       $t2, $t0, 0xF
    /* BE148 002BD548 010A4023 */  subu       $t0, $t0, $t2
.Lauto_002BD54C:
    /* BE14C 002BD54C BD190000 */  cache      0x19, 0x0($t0) /* handwritten instruction */
    /* BE150 002BD550 0109082B */  sltu       $at, $t0, $t1
    /* BE154 002BD554 1420FFFD */  .word 0x1420FFFD
    /* BE158 002BD558 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BD55C:
    /* BE15C 002BD55C 03E00008 */  jr         $ra
    /* BE160 002BD560 00000000 */  nop
.Lauto_002BD564:
    /* BE164 002BD564 3C088000 */  lui        $t0, 0x8000
    /* BE168 002BD568 010B4821 */  addu       $t1, $t0, $t3
    /* BE16C 002BD56C 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD570:
    /* BE170 002BD570 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BE174 002BD574 0109082B */  sltu       $at, $t0, $t1
    /* BE178 002BD578 1420FFFD */  .word 0x1420FFFD
    /* BE17C 002BD57C 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BE180 002BD580 03E00008 */  jr         $ra
    /* BE184 002BD584 00000000 */  nop
