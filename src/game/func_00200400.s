.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1000-0x1100 (VRAM 0x00200400) */
glabel func_00200400
    /* 1000 00200400 3C1D803F */  lui        $sp, (0x803FFFC0 >> 16)
    /* 1004 00200404 37BDFFC0 */  ori        $sp, $sp, (0x803FFFC0 & 0xFFFF)
    /* 1008 00200408 2404001E */  addiu      $a0, $zero, 0x1E
  .L0020040C:
    /* 100C 0020040C 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* 1010 00200410 40840000 */  mtc0       $a0, $0 /* handwritten instruction */
    /* 1014 00200414 3C098000 */  lui        $t1, (0x80000000 >> 16)
    /* 1018 00200418 40895000 */  mtc0       $t1, $10 /* handwritten instruction */
    /* 101C 0020041C 40801000 */  mtc0       $zero, $2 /* handwritten instruction */
    /* 1020 00200420 40801800 */  mtc0       $zero, $3 /* handwritten instruction */
    /* 1024 00200424 00000000 */  nop
    /* 1028 00200428 42000002 */  tlbwi /* handwritten instruction */
    /* 102C 0020042C 00000000 */  nop
    /* 1030 00200430 00000000 */  nop
    /* 1034 00200434 00000000 */  nop
    /* 1038 00200438 00000000 */  nop
    /* 103C 0020043C 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* 1040 00200440 00000000 */  nop
    /* 1044 00200444 1480FFF1 */  bnez       $a0, .L0020040C
    /* 1048 00200448 2084FFFF */   addi      $a0, $a0, -0x1 /* handwritten instruction */
    /* 104C 0020044C 2404001F */  addiu      $a0, $zero, 0x1F
    /* 1050 00200450 3C05001F */  lui        $a1, (0x1FE000 >> 16)
    /* 1054 00200454 34A5E000 */  ori        $a1, $a1, (0x1FE000 & 0xFFFF)
    /* 1058 00200458 3C060020 */  lui        $a2, (0x200000 >> 16)
    /* 105C 0020045C 24070000 */  addiu      $a3, $zero, 0x0
    /* 1060 00200460 3C090010 */  lui        $t1, (0x100000 >> 16)
    /* 1064 00200464 AFA90010 */  sw         $t1, 0x10($sp)
    /* 1068 00200468 24080007 */  addiu      $t0, $zero, 0x7
    /* 106C 0020046C 0C000122 */  .word      0x0C000122 /* was: jal        func_488 */
    /* 1070 00200470 AFA80014 */   sw        $t0, 0x14($sp)
    /* 1074 00200474 3C04002B */  lui        $a0, %hi(func_002A81B0)
    /* 1078 00200478 248481B0 */  addiu      $a0, $a0, %lo(func_002A81B0)
    /* 107C 0020047C 0080F809 */  jalr       $a0
    /* 1080 00200480 00000000 */   nop
    /* 1084 00200484 0001008D */  break      1, 2
    /* 1088 00200488 8FB80010 */  lw         $t8, 0x10($sp)
    /* 108C 0020048C 20080007 */  addi       $t0, $zero, 0x7 /* handwritten instruction */
    /* 1090 00200490 8FB90014 */  lw         $t9, 0x14($sp)
    /* 1094 00200494 200FFFFF */  addi       $t7, $zero, -0x1 /* handwritten instruction */
    /* 1098 00200498 0328C824 */  and        $t9, $t9, $t0
    /* 109C 0020049C 37390018 */  ori        $t9, $t9, 0x18
    /* 10A0 002004A0 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* 10A4 002004A4 40840000 */  mtc0       $a0, $0 /* handwritten instruction */
    /* 10A8 002004A8 40852800 */  mtc0       $a1, $5 /* handwritten instruction */
    /* 10AC 002004AC 40865000 */  mtc0       $a2, $10 /* handwritten instruction */
    /* 10B0 002004B0 10EF0005 */  beq        $a3, $t7, .L002004C8
    /* 10B4 002004B4 200E0001 */   addi      $t6, $zero, 0x1 /* handwritten instruction */
    /* 10B8 002004B8 00076982 */  srl        $t5, $a3, 6
    /* 10BC 002004BC 01B96825 */  or         $t5, $t5, $t9
    /* 10C0 002004C0 10000002 */  b          .L002004CC
    /* 10C4 002004C4 408D1000 */   mtc0      $t5, $2 /* handwritten instruction */
  .L002004C8:
    /* 10C8 002004C8 408E1000 */  mtc0       $t6, $2 /* handwritten instruction */
  .L002004CC:
    /* 10CC 002004CC 130F0004 */  beq        $t8, $t7, .L002004E0
    /* 10D0 002004D0 408E1800 */   mtc0      $t6, $3 /* handwritten instruction */
    /* 10D4 002004D4 00186982 */  srl        $t5, $t8, 6
    /* 10D8 002004D8 01B96825 */  or         $t5, $t5, $t9
    /* 10DC 002004DC 408D1800 */  mtc0       $t5, $3 /* handwritten instruction */
  .L002004E0:
    /* 10E0 002004E0 42000002 */  tlbwi /* handwritten instruction */
    /* 10E4 002004E4 00000000 */  nop
    /* 10E8 002004E8 00000000 */  nop
    /* 10EC 002004EC 00000000 */  nop
    /* 10F0 002004F0 00000000 */  nop
    /* 10F4 002004F4 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* 10F8 002004F8 03E00008 */  jr         $ra
    /* 10FC 002004FC 00000000 */   nop
endlabel func_00200400
