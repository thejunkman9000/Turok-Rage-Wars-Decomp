.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9AC4-0xB9BAC (VRAM 0x002B8EC4) */
glabel alMainBusPull
    /* B9AC4 002B8EC4 00021040 */  sll        $v0, $v0, 1
    /* B9AC8 002B8EC8 8623001A */  lh         $v1, 0x1A($s1)
    /* B9ACC 002B8ECC 3C01800E */  lui        $at, (0x800E0000 >> 16)
    /* B9AD0 002B8ED0 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B9AD4 002B8ED4 AFB40028 */  sw         $s4, 0x28($sp)
    /* B9AD8 002B8ED8 00A0A021 */  addu       $s4, $a1, $zero
    /* B9ADC 002B8EDC AFB30024 */  sw         $s3, 0x24($sp)
    /* B9AE0 002B8EE0 00C09821 */  addu       $s3, $a2, $zero
    /* B9AE4 002B8EE4 AFB5002C */  sw         $s5, 0x2C($sp)
    /* B9AE8 002B8EE8 00E0A821 */  addu       $s5, $a3, $zero
    /* B9AEC 002B8EEC 3C030200 */  lui        $v1, (0x20006C0 >> 16)
    /* B9AF0 002B8EF0 346306C0 */  ori        $v1, $v1, (0x20006C0 & 0xFFFF)
    /* B9AF4 002B8EF4 3C050200 */  lui        $a1, (0x2000800 >> 16)
    /* B9AF8 002B8EF8 8FA60048 */  lw         $a2, 0x48($sp)
    /* B9AFC 002B8EFC 34A50800 */  ori        $a1, $a1, (0x2000800 & 0xFFFF)
    /* B9B00 002B8F00 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B9B04 002B8F04 00008821 */  addu       $s1, $zero, $zero
    /* B9B08 002B8F08 AFB20020 */  sw         $s2, 0x20($sp)
    /* B9B0C 002B8F0C 00809021 */  addu       $s2, $a0, $zero
    /* B9B10 002B8F10 AFBF0030 */  sw         $ra, 0x30($sp)
    /* B9B14 002B8F14 AFB00018 */  sw         $s0, 0x18($sp)
    /* B9B18 002B8F18 8E44001C */  lw         $a0, 0x1C($s2)
    /* B9B1C 002B8F1C 00C01021 */  addu       $v0, $a2, $zero
    /* B9B20 002B8F20 24C60008 */  addiu      $a2, $a2, 0x8
    /* B9B24 002B8F24 AC430000 */  sw         $v1, 0x0($v0)
    /* B9B28 002B8F28 00131840 */  sll        $v1, $s3, 1
    /* B9B2C 002B8F2C AC430004 */  sw         $v1, 0x4($v0)
    /* B9B30 002B8F30 00C01021 */  addu       $v0, $a2, $zero
    /* B9B34 002B8F34 AC450000 */  sw         $a1, 0x0($v0)
    /* B9B38 002B8F38 AC430004 */  sw         $v1, 0x4($v0)
    /* B9B3C 002B8F3C 8E420014 */  lw         $v0, 0x14($s2)
    /* B9B40 002B8F40 18400010 */  blez       $v0, .L002B8F84
    /* B9B44 002B8F44 24C60008 */   addiu     $a2, $a2, 0x8
    /* B9B48 002B8F48 00808021 */  addu       $s0, $a0, $zero
  .L002B8F4C:
    /* B9B4C 002B8F4C 8E020000 */  lw         $v0, 0x0($s0)
    /* B9B50 002B8F50 AFA60010 */  sw         $a2, 0x10($sp)
    /* B9B54 002B8F54 8E040000 */  lw         $a0, 0x0($s0)
    /* B9B58 002B8F58 26100004 */  addiu      $s0, $s0, 0x4
    /* B9B5C 002B8F5C 26310001 */  addiu      $s1, $s1, 0x1
    /* B9B60 002B8F60 02802821 */  addu       $a1, $s4, $zero
    /* B9B64 002B8F64 02603021 */  addu       $a2, $s3, $zero
    /* B9B68 002B8F68 8C420004 */  lw         $v0, 0x4($v0)
    /* B9B6C 002B8F6C 0040F809 */  jalr       $v0
    /* B9B70 002B8F70 02A03821 */   addu      $a3, $s5, $zero
    /* B9B74 002B8F74 8E430014 */  lw         $v1, 0x14($s2)
    /* B9B78 002B8F78 0223182A */  slt        $v1, $s1, $v1
    /* B9B7C 002B8F7C 1460FFF3 */  bnez       $v1, .L002B8F4C
    /* B9B80 002B8F80 00403021 */   addu      $a2, $v0, $zero
  .L002B8F84:
    /* B9B84 002B8F84 8FBF0030 */  lw         $ra, 0x30($sp)
    /* B9B88 002B8F88 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B9B8C 002B8F8C 8FB40028 */  lw         $s4, 0x28($sp)
    /* B9B90 002B8F90 8FB30024 */  lw         $s3, 0x24($sp)
    /* B9B94 002B8F94 8FB20020 */  lw         $s2, 0x20($sp)
    /* B9B98 002B8F98 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B9B9C 002B8F9C 8FB00018 */  lw         $s0, 0x18($sp)
    /* B9BA0 002B8FA0 00C01021 */  addu       $v0, $a2, $zero
    /* B9BA4 002B8FA4 03E00008 */  jr         $ra
    /* B9BA8 002B8FA8 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel alMainBusPull
