.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB0CC-0xBB210 (VRAM 0x002BA4CC) */
glabel alAuxBusPull
    /* BB0CC 002BA4CC 02002821 */  addu       $a1, $s0, $zero
  alabel D_002BA4D0
    /* BB0D0 002BA4D0 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* BB0D4 002BA4D4 AFB70034 */  sw         $s7, 0x34($sp)
    /* BB0D8 002BA4D8 00C0B821 */  addu       $s7, $a2, $zero
    /* BB0DC 002BA4DC 3C030200 */  lui        $v1, (0x2000440 >> 16)
    /* BB0E0 002BA4E0 34630440 */  ori        $v1, $v1, (0x2000440 & 0xFFFF)
    /* BB0E4 002BA4E4 AFA50044 */  sw         $a1, 0x44($sp)
    /* BB0E8 002BA4E8 3C050200 */  lui        $a1, (0x2000580 >> 16)
    /* BB0EC 002BA4EC 8FA60050 */  lw         $a2, 0x50($sp)
    /* BB0F0 002BA4F0 34A50580 */  ori        $a1, $a1, (0x2000580 & 0xFFFF)
    /* BB0F4 002BA4F4 AFB1001C */  sw         $s1, 0x1C($sp)
    /* BB0F8 002BA4F8 00008821 */  addu       $s1, $zero, $zero
    /* BB0FC 002BA4FC AFB30024 */  sw         $s3, 0x24($sp)
    /* BB100 002BA500 00809821 */  addu       $s3, $a0, $zero
    /* BB104 002BA504 AFBF003C */  sw         $ra, 0x3C($sp)
    /* BB108 002BA508 AFBE0038 */  sw         $fp, 0x38($sp)
    /* BB10C 002BA50C AFB60030 */  sw         $s6, 0x30($sp)
    /* BB110 002BA510 AFB5002C */  sw         $s5, 0x2C($sp)
    /* BB114 002BA514 AFB40028 */  sw         $s4, 0x28($sp)
    /* BB118 002BA518 AFB20020 */  sw         $s2, 0x20($sp)
    /* BB11C 002BA51C AFB00018 */  sw         $s0, 0x18($sp)
    /* BB120 002BA520 AFA7004C */  sw         $a3, 0x4C($sp)
    /* BB124 002BA524 8E64001C */  lw         $a0, 0x1C($s3)
    /* BB128 002BA528 00C01021 */  addu       $v0, $a2, $zero
    /* BB12C 002BA52C 24C60008 */  addiu      $a2, $a2, 0x8
    /* BB130 002BA530 AC430000 */  sw         $v1, 0x0($v0)
    /* BB134 002BA534 00171840 */  sll        $v1, $s7, 1
    /* BB138 002BA538 AC430004 */  sw         $v1, 0x4($v0)
    /* BB13C 002BA53C 00C01021 */  addu       $v0, $a2, $zero
    /* BB140 002BA540 AC450000 */  sw         $a1, 0x0($v0)
    /* BB144 002BA544 AC430004 */  sw         $v1, 0x4($v0)
    /* BB148 002BA548 8E620014 */  lw         $v0, 0x14($s3)
    /* BB14C 002BA54C 18400023 */  blez       $v0, .L002BA5DC
    /* BB150 002BA550 24C60008 */   addiu     $a2, $a2, 0x8
    /* BB154 002BA554 3C1E0800 */  lui        $fp, (0x8000580 >> 16)
    /* BB158 002BA558 3076FFFF */  andi       $s6, $v1, 0xFFFF
    /* BB15C 002BA55C 3C120C00 */  lui        $s2, (0xC007FFF >> 16)
    /* BB160 002BA560 36527FFF */  ori        $s2, $s2, (0xC007FFF & 0xFFFF)
    /* BB164 002BA564 3C1506C0 */  lui        $s5, (0x6C00440 >> 16)
    /* BB168 002BA568 36B50440 */  ori        $s5, $s5, (0x6C00440 & 0xFFFF)
    /* BB16C 002BA56C 03C0A021 */  addu       $s4, $fp, $zero
    /* BB170 002BA570 36940580 */  ori        $s4, $s4, (0x8000580 & 0xFFFF)
    /* BB174 002BA574 00808021 */  addu       $s0, $a0, $zero
  .L002BA578:
    /* BB178 002BA578 8E020000 */  lw         $v0, 0x0($s0)
    /* BB17C 002BA57C AFA60010 */  sw         $a2, 0x10($sp)
    /* BB180 002BA580 8E040000 */  lw         $a0, 0x0($s0)
    /* BB184 002BA584 26100004 */  addiu      $s0, $s0, 0x4
    /* BB188 002BA588 26310001 */  addiu      $s1, $s1, 0x1
    /* BB18C 002BA58C 8FA50044 */  lw         $a1, 0x44($sp)
    /* BB190 002BA590 8FA7004C */  lw         $a3, 0x4C($sp)
    /* BB194 002BA594 8C420004 */  lw         $v0, 0x4($v0)
    /* BB198 002BA598 0040F809 */  jalr       $v0
    /* BB19C 002BA59C 02E03021 */   addu      $a2, $s7, $zero
    /* BB1A0 002BA5A0 00403021 */  addu       $a2, $v0, $zero
    /* BB1A4 002BA5A4 24C60008 */  addiu      $a2, $a2, 0x8
    /* BB1A8 002BA5A8 00C01821 */  addu       $v1, $a2, $zero
    /* BB1AC 002BA5AC 24C60008 */  addiu      $a2, $a2, 0x8
    /* BB1B0 002BA5B0 AC5E0000 */  sw         $fp, 0x0($v0)
    /* BB1B4 002BA5B4 AC560004 */  sw         $s6, 0x4($v0)
    /* BB1B8 002BA5B8 00C01021 */  addu       $v0, $a2, $zero
    /* BB1BC 002BA5BC AC720000 */  sw         $s2, 0x0($v1)
    /* BB1C0 002BA5C0 AC750004 */  sw         $s5, 0x4($v1)
    /* BB1C4 002BA5C4 AC520000 */  sw         $s2, 0x0($v0)
    /* BB1C8 002BA5C8 AC540004 */  sw         $s4, 0x4($v0)
    /* BB1CC 002BA5CC 8E620014 */  lw         $v0, 0x14($s3)
    /* BB1D0 002BA5D0 0222102A */  slt        $v0, $s1, $v0
    /* BB1D4 002BA5D4 1440FFE8 */  bnez       $v0, .L002BA578
    /* BB1D8 002BA5D8 24C60008 */   addiu     $a2, $a2, 0x8
  .L002BA5DC:
    /* BB1DC 002BA5DC 8FBF003C */  lw         $ra, 0x3C($sp)
    /* BB1E0 002BA5E0 8FBE0038 */  lw         $fp, 0x38($sp)
    /* BB1E4 002BA5E4 8FB70034 */  lw         $s7, 0x34($sp)
    /* BB1E8 002BA5E8 8FB60030 */  lw         $s6, 0x30($sp)
    /* BB1EC 002BA5EC 8FB5002C */  lw         $s5, 0x2C($sp)
    /* BB1F0 002BA5F0 8FB40028 */  lw         $s4, 0x28($sp)
    /* BB1F4 002BA5F4 8FB30024 */  lw         $s3, 0x24($sp)
    /* BB1F8 002BA5F8 8FB20020 */  lw         $s2, 0x20($sp)
    /* BB1FC 002BA5FC 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BB200 002BA600 8FB00018 */  lw         $s0, 0x18($sp)
    /* BB204 002BA604 00C01021 */  addu       $v0, $a2, $zero
    /* BB208 002BA608 03E00008 */  jr         $ra
    /* BB20C 002BA60C 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel alAuxBusPull
