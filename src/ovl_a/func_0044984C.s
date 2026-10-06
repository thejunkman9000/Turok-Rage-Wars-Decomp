.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B784C-0x1B7914 (VRAM 0x0044984C) */
glabel func_0044984C
    /* 1B784C 0044984C 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* 1B7850 00449850 AFB00030 */  sw         $s0, 0x30($sp)
    /* 1B7854 00449854 00808021 */  addu       $s0, $a0, $zero
    /* 1B7858 00449858 AFBF0034 */  sw         $ra, 0x34($sp)
    /* 1B785C 0044985C 92020065 */  lbu        $v0, 0x65($s0)
    /* 1B7860 00449860 10400007 */  beqz       $v0, .L00449880
    /* 1B7864 00449864 24060001 */   addiu     $a2, $zero, 0x1
    /* 1B7868 00449868 0C112645 */  jal        __osPfsSelectBank
    /* 1B786C 0044986C A2000065 */   sb        $zero, 0x65($s0)
    /* 1B7870 00449870 00401821 */  addu       $v1, $v0, $zero
    /* 1B7874 00449874 14600023 */  bnez       $v1, .L00449904
    /* 1B7878 00449878 00000000 */   nop
    /* 1B787C 0044987C 24060001 */  addiu      $a2, $zero, 0x1
  .L00449880:
    /* 1B7880 00449880 8E040004 */  lw         $a0, 0x4($s0)
    /* 1B7884 00449884 8E050008 */  lw         $a1, 0x8($s0)
    /* 1B7888 00449888 0C0AF564 */  jal        __osContRamRead
    /* 1B788C 0044988C 27A70010 */   addiu     $a3, $sp, 0x10
    /* 1B7890 00449890 00401821 */  addu       $v1, $v0, $zero
    /* 1B7894 00449894 1060000F */  beqz       $v1, .L004498D4
    /* 1B7898 00449898 24020002 */   addiu     $v0, $zero, 0x2
    /* 1B789C 0044989C 14620019 */  bne        $v1, $v0, .L00449904
    /* 1B78A0 004498A0 00601021 */   addu      $v0, $v1, $zero
    /* 1B78A4 004498A4 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B78A8 004498A8 8E040004 */  lw         $a0, 0x4($s0)
    /* 1B78AC 004498AC 8E050008 */  lw         $a1, 0x8($s0)
    /* 1B78B0 004498B0 0C0AF564 */  jal        __osContRamRead
    /* 1B78B4 004498B4 27A70010 */   addiu     $a3, $sp, 0x10
    /* 1B78B8 004498B8 00401821 */  addu       $v1, $v0, $zero
    /* 1B78BC 004498BC 10600006 */  beqz       $v1, .L004498D8
    /* 1B78C0 004498C0 00002821 */   addu      $a1, $zero, $zero
    /* 1B78C4 004498C4 08112641 */  j          .L00449904
    /* 1B78C8 004498C8 00000000 */   nop
  .L004498CC:
    /* 1B78CC 004498CC 08112641 */  j          .L00449904
    /* 1B78D0 004498D0 24020002 */   addiu     $v0, $zero, 0x2
  .L004498D4:
    /* 1B78D4 004498D4 00002821 */  addu       $a1, $zero, $zero
  .L004498D8:
    /* 1B78D8 004498D8 27A60010 */  addiu      $a2, $sp, 0x10
    /* 1B78DC 004498DC 02051021 */  addu       $v0, $s0, $a1
  .L004498E0:
    /* 1B78E0 004498E0 00C51821 */  addu       $v1, $a2, $a1
    /* 1B78E4 004498E4 9044000C */  lbu        $a0, 0xC($v0)
    /* 1B78E8 004498E8 90620000 */  lbu        $v0, 0x0($v1)
    /* 1B78EC 004498EC 1482FFF7 */  bne        $a0, $v0, .L004498CC
    /* 1B78F0 004498F0 24A50001 */   addiu     $a1, $a1, 0x1
    /* 1B78F4 004498F4 28A20020 */  slti       $v0, $a1, 0x20
    /* 1B78F8 004498F8 1440FFF9 */  bnez       $v0, .L004498E0
    /* 1B78FC 004498FC 02051021 */   addu      $v0, $s0, $a1
    /* 1B7900 00449900 00001021 */  addu       $v0, $zero, $zero
  .L00449904:
    /* 1B7904 00449904 8FBF0034 */  lw         $ra, 0x34($sp)
    /* 1B7908 00449908 8FB00030 */  lw         $s0, 0x30($sp)
    /* 1B790C 0044990C 03E00008 */  jr         $ra
    /* 1B7910 00449910 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_0044984C
