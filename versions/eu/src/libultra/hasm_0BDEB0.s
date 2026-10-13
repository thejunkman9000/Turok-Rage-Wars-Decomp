.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDEB0-0xBDF18 (VRAM 0x002BD2B0) */
.globl osInvalICache
osInvalICache:
    /* BDEB0 002BD2B0 18A0000E */  .word 0x18A0000E
    /* BDEB4 002BD2B4 240B4000 */  addiu     $t3, $zero, 0x4000
    /* BDEB8 002BD2B8 00AB082B */  sltu       $at, $a1, $t3
    /* BDEBC 002BD2BC 1020000D */  .word 0x1020000D
    /* BDEC0 002BD2C0 00804021 */  addu      $t0, $a0, $zero
    /* BDEC4 002BD2C4 00854821 */  addu       $t1, $a0, $a1
    /* BDEC8 002BD2C8 0109082B */  sltu       $at, $t0, $t1
    /* BDECC 002BD2CC 10200007 */  .word 0x10200007
    /* BDED0 002BD2D0 2529FFE0 */  addiu     $t1, $t1, -0x20
    /* BDED4 002BD2D4 310A001F */  andi       $t2, $t0, 0x1F
    /* BDED8 002BD2D8 010A4023 */  subu       $t0, $t0, $t2
.Lauto_002BD2DC:
    /* BDEDC 002BD2DC BD100000 */  cache      0x10, 0x0($t0) /* handwritten instruction */
    /* BDEE0 002BD2E0 0109082B */  sltu       $at, $t0, $t1
    /* BDEE4 002BD2E4 1420FFFD */  .word 0x1420FFFD
    /* BDEE8 002BD2E8 25080020 */  addiu     $t0, $t0, 0x20
.Lauto_002BD2EC:
    /* BDEEC 002BD2EC 03E00008 */  jr         $ra
    /* BDEF0 002BD2F0 00000000 */  nop
.Lauto_002BD2F4:
    /* BDEF4 002BD2F4 3C088000 */  lui        $t0, 0x8000
    /* BDEF8 002BD2F8 010B4821 */  addu       $t1, $t0, $t3
    /* BDEFC 002BD2FC 2529FFE0 */  addiu      $t1, $t1, -0x20
.Lauto_002BD300:
    /* BDF00 002BD300 BD000000 */  cache      0x00, 0x0($t0) /* handwritten instruction */
    /* BDF04 002BD304 0109082B */  sltu       $at, $t0, $t1
    /* BDF08 002BD308 1420FFFD */  .word 0x1420FFFD
    /* BDF0C 002BD30C 25080020 */  addiu     $t0, $t0, (0x80000020 & 0xFFFF)
    /* BDF10 002BD310 03E00008 */  jr         $ra
    /* BDF14 002BD314 00000000 */  nop
