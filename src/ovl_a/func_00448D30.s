.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B6D30-0x1B6EB0 (VRAM 0x00448D30) */
glabel func_00448D30
    /* 1B6D30 00448D30 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* 1B6D34 00448D34 AFB3003C */  sw         $s3, 0x3C($sp)
    /* 1B6D38 00448D38 8FB30068 */  lw         $s3, 0x68($sp)
    /* 1B6D3C 00448D3C AFB20038 */  sw         $s2, 0x38($sp)
    /* 1B6D40 00448D40 00809021 */  addu       $s2, $a0, $zero
    /* 1B6D44 00448D44 AFB50044 */  sw         $s5, 0x44($sp)
    /* 1B6D48 00448D48 8FB5006C */  lw         $s5, 0x6C($sp)
    /* 1B6D4C 00448D4C AFB7004C */  sw         $s7, 0x4C($sp)
    /* 1B6D50 00448D50 00C0B821 */  addu       $s7, $a2, $zero
    /* 1B6D54 00448D54 AFB40040 */  sw         $s4, 0x40($sp)
    /* 1B6D58 00448D58 00E0A021 */  addu       $s4, $a3, $zero
    /* 1B6D5C 00448D5C AFB10034 */  sw         $s1, 0x34($sp)
    /* 1B6D60 00448D60 00A08821 */  addu       $s1, $a1, $zero
    /* 1B6D64 00448D64 AFBF0050 */  sw         $ra, 0x50($sp)
    /* 1B6D68 00448D68 AFB60048 */  sw         $s6, 0x48($sp)
    /* 1B6D6C 00448D6C 0C112613 */  jal        func_0044984C
    /* 1B6D70 00448D70 AFB00030 */   sw        $s0, 0x30($sp)
    /* 1B6D74 00448D74 24030002 */  addiu      $v1, $zero, 0x2
    /* 1B6D78 00448D78 1043003F */  beq        $v0, $v1, .L00448E78
    /* 1B6D7C 00448D7C 00601021 */   addu      $v0, $v1, $zero
    /* 1B6D80 00448D80 8E420050 */  lw         $v0, 0x50($s2)
    /* 1B6D84 00448D84 18400039 */  blez       $v0, .L00448E6C
    /* 1B6D88 00448D88 00008021 */   addu      $s0, $zero, $zero
    /* 1B6D8C 00448D8C 3236FFFF */  andi       $s6, $s1, 0xFFFF
    /* 1B6D90 00448D90 27B10010 */  addiu      $s1, $sp, 0x10
    /* 1B6D94 00448D94 27A70010 */  addiu      $a3, $sp, 0x10
  .L00448D98:
    /* 1B6D98 00448D98 9646005E */  lhu        $a2, 0x5E($s2)
    /* 1B6D9C 00448D9C 8E440004 */  lw         $a0, 0x4($s2)
    /* 1B6DA0 00448DA0 8E450008 */  lw         $a1, 0x8($s2)
    /* 1B6DA4 00448DA4 00D03021 */  addu       $a2, $a2, $s0
    /* 1B6DA8 00448DA8 0C0AF564 */  jal        __osContRamRead
    /* 1B6DAC 00448DAC 30C6FFFF */   andi      $a2, $a2, 0xFFFF
    /* 1B6DB0 00448DB0 00403821 */  addu       $a3, $v0, $zero
    /* 1B6DB4 00448DB4 14E00030 */  bnez       $a3, .L00448E78
    /* 1B6DB8 00448DB8 00E01021 */   addu      $v0, $a3, $zero
    /* 1B6DBC 00448DBC 97A20014 */  lhu        $v0, 0x14($sp)
    /* 1B6DC0 00448DC0 14560025 */  bne        $v0, $s6, .L00448E58
    /* 1B6DC4 00448DC4 00000000 */   nop
    /* 1B6DC8 00448DC8 8FA20010 */  lw         $v0, 0x10($sp)
    /* 1B6DCC 00448DCC 14570022 */  bne        $v0, $s7, .L00448E58
    /* 1B6DD0 00448DD0 00000000 */   nop
    /* 1B6DD4 00448DD4 1280000B */  beqz       $s4, .L00448E04
    /* 1B6DD8 00448DD8 00003021 */   addu      $a2, $zero, $zero
    /* 1B6DDC 00448DDC 00C02821 */  addu       $a1, $a2, $zero
    /* 1B6DE0 00448DE0 02251021 */  addu       $v0, $s1, $a1
  .L00448DE4:
    /* 1B6DE4 00448DE4 02851821 */  addu       $v1, $s4, $a1
    /* 1B6DE8 00448DE8 90440010 */  lbu        $a0, 0x10($v0)
    /* 1B6DEC 00448DEC 90620000 */  lbu        $v0, 0x0($v1)
    /* 1B6DF0 00448DF0 14820017 */  bne        $a0, $v0, .L00448E50
    /* 1B6DF4 00448DF4 24A50001 */   addiu     $a1, $a1, 0x1
    /* 1B6DF8 00448DF8 28A20010 */  slti       $v0, $a1, 0x10
    /* 1B6DFC 00448DFC 1440FFF9 */  bnez       $v0, .L00448DE4
    /* 1B6E00 00448E00 02251021 */   addu      $v0, $s1, $a1
  .L00448E04:
    /* 1B6E04 00448E04 1260000C */  beqz       $s3, .L00448E38
    /* 1B6E08 00448E08 00000000 */   nop
    /* 1B6E0C 00448E0C 14C00012 */  bnez       $a2, .L00448E58
    /* 1B6E10 00448E10 00002821 */   addu      $a1, $zero, $zero
    /* 1B6E14 00448E14 02251021 */  addu       $v0, $s1, $a1
  .L00448E18:
    /* 1B6E18 00448E18 02651821 */  addu       $v1, $s3, $a1
    /* 1B6E1C 00448E1C 9044000C */  lbu        $a0, 0xC($v0)
    /* 1B6E20 00448E20 90620000 */  lbu        $v0, 0x0($v1)
    /* 1B6E24 00448E24 14820008 */  bne        $a0, $v0, .L00448E48
    /* 1B6E28 00448E28 24A50001 */   addiu     $a1, $a1, 0x1
    /* 1B6E2C 00448E2C 28A20004 */  slti       $v0, $a1, 0x4
    /* 1B6E30 00448E30 1440FFF9 */  bnez       $v0, .L00448E18
    /* 1B6E34 00448E34 02251021 */   addu      $v0, $s1, $a1
  .L00448E38:
    /* 1B6E38 00448E38 14C00007 */  bnez       $a2, .L00448E58
    /* 1B6E3C 00448E3C 00E01021 */   addu      $v0, $a3, $zero
    /* 1B6E40 00448E40 0811239E */  j          .L00448E78
    /* 1B6E44 00448E44 AEB00000 */   sw        $s0, 0x0($s5)
  .L00448E48:
    /* 1B6E48 00448E48 0811238E */  j          .L00448E38
    /* 1B6E4C 00448E4C 24060001 */   addiu     $a2, $zero, 0x1
  .L00448E50:
    /* 1B6E50 00448E50 08112381 */  j          .L00448E04
    /* 1B6E54 00448E54 24060001 */   addiu     $a2, $zero, 0x1
  .L00448E58:
    /* 1B6E58 00448E58 8E420050 */  lw         $v0, 0x50($s2)
    /* 1B6E5C 00448E5C 26100001 */  addiu      $s0, $s0, 0x1
    /* 1B6E60 00448E60 0202102A */  slt        $v0, $s0, $v0
    /* 1B6E64 00448E64 1440FFCC */  bnez       $v0, .L00448D98
    /* 1B6E68 00448E68 27A70010 */   addiu     $a3, $sp, 0x10
  .L00448E6C:
    /* 1B6E6C 00448E6C 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B6E70 00448E70 AEA20000 */  sw         $v0, 0x0($s5)
    /* 1B6E74 00448E74 24020005 */  addiu      $v0, $zero, 0x5
  .L00448E78:
    /* 1B6E78 00448E78 8FBF0050 */  lw         $ra, 0x50($sp)
    /* 1B6E7C 00448E7C 8FB7004C */  lw         $s7, 0x4C($sp)
    /* 1B6E80 00448E80 8FB60048 */  lw         $s6, 0x48($sp)
    /* 1B6E84 00448E84 8FB50044 */  lw         $s5, 0x44($sp)
    /* 1B6E88 00448E88 8FB40040 */  lw         $s4, 0x40($sp)
    /* 1B6E8C 00448E8C 8FB3003C */  lw         $s3, 0x3C($sp)
    /* 1B6E90 00448E90 8FB20038 */  lw         $s2, 0x38($sp)
    /* 1B6E94 00448E94 8FB10034 */  lw         $s1, 0x34($sp)
    /* 1B6E98 00448E98 8FB00030 */  lw         $s0, 0x30($sp)
    /* 1B6E9C 00448E9C 03E00008 */  jr         $ra
    /* 1B6EA0 00448EA0 27BD0058 */   addiu     $sp, $sp, 0x58


    /* 1B6EA4 00448EA4 C42273F4 */  .word      0xC42273F4 /* linker padding */
    /* 1B6EA8 00448EA8 3C01800C */  .word      0x3C01800C /* linker padding */
    /* 1B6EAC 00448EAC C42073F8 */  .word      0xC42073F8 /* linker padding */
endlabel func_00448D30
