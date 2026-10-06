.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4288-0xB438C (VRAM 0x002B3688) */
glabel func_002B3688
    /* B4288 002B3688 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B428C 002B368C AFB20018 */  sw         $s2, 0x18($sp)
    /* B4290 002B3690 00809021 */  addu       $s2, $a0, $zero
    /* B4294 002B3694 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B4298 002B3698 00A09821 */  addu       $s3, $a1, $zero
    /* B429C 002B369C AFB00010 */  sw         $s0, 0x10($sp)
    /* B42A0 002B36A0 00008021 */  addu       $s0, $zero, $zero
    /* B42A4 002B36A4 AFB40020 */  sw         $s4, 0x20($sp)
    /* B42A8 002B36A8 24140001 */  addiu      $s4, $zero, 0x1
    /* B42AC 002B36AC AFB10014 */  sw         $s1, 0x14($sp)
    /* B42B0 002B36B0 02408821 */  addu       $s1, $s2, $zero
    /* B42B4 002B36B4 02801021 */  addu       $v0, $s4, $zero
    /* B42B8 002B36B8 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B42BC 002B36BC AE530000 */  sw         $s3, 0x0($s2)
    /* B42C0 002B36C0 AE400004 */  sw         $zero, 0x4($s2)
    /* B42C4 002B36C4 AE400010 */  sw         $zero, 0x10($s2)
    /* B42C8 002B36C8 AE40000C */  sw         $zero, 0xC($s2)
    /* B42CC 002B36CC AE420014 */  sw         $v0, 0x14($s2)
  .L002B36D0:
    /* B42D0 002B36D0 02501021 */  addu       $v0, $s2, $s0
    /* B42D4 002B36D4 A04000A8 */  sb         $zero, 0xA8($v0)
    /* B42D8 002B36D8 AE200058 */  sw         $zero, 0x58($s1)
    /* B42DC 002B36DC A0400098 */  sb         $zero, 0x98($v0)
    /* B42E0 002B36E0 8E420000 */  lw         $v0, 0x0($s2)
    /* B42E4 002B36E4 00101880 */  sll        $v1, $s0, 2
    /* B42E8 002B36E8 00431021 */  addu       $v0, $v0, $v1
    /* B42EC 002B36EC 8C440000 */  lw         $a0, 0x0($v0)
    /* B42F0 002B36F0 1080000B */  beqz       $a0, .L002B3720
    /* B42F4 002B36F4 02141804 */   sllv      $v1, $s4, $s0
    /* B42F8 002B36F8 8E420004 */  lw         $v0, 0x4($s2)
    /* B42FC 002B36FC 02002821 */  addu       $a1, $s0, $zero
    /* B4300 002B3700 00431025 */  or         $v0, $v0, $v1
    /* B4304 002B3704 AE420004 */  sw         $v0, 0x4($s2)
    /* B4308 002B3708 02641021 */  addu       $v0, $s3, $a0
    /* B430C 002B370C 02402021 */  addu       $a0, $s2, $zero
    /* B4310 002B3710 0C0ACEBF */  jal        func_002B3AFC
    /* B4314 002B3714 AE220018 */   sw        $v0, 0x18($s1)
    /* B4318 002B3718 080ACDC9 */  j          .L002B3724
    /* B431C 002B371C AE2200B8 */   sw        $v0, 0xB8($s1)
  .L002B3720:
    /* B4320 002B3720 AE200018 */  sw         $zero, 0x18($s1)
  .L002B3724:
    /* B4324 002B3724 26100001 */  addiu      $s0, $s0, 0x1
    /* B4328 002B3728 2E020010 */  sltiu      $v0, $s0, 0x10
    /* B432C 002B372C 1440FFE8 */  bnez       $v0, .L002B36D0
    /* B4330 002B3730 26310004 */   addiu     $s1, $s1, 0x4
    /* B4334 002B3734 8E420000 */  lw         $v0, 0x0($s2)
    /* B4338 002B3738 8C420040 */  lw         $v0, 0x40($v0)
    /* B433C 002B373C 44820800 */  mtc1       $v0, $fv0f
    /* B4340 002B3740 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* B4344 002B3744 04410004 */  bgez       $v0, .L002B3758
    /* B4348 002B3748 00000000 */   nop
    /* B434C 002B374C 3C01800D */  lui        $at, %hi(D_800CC550)
    /* B4350 002B3750 D420C550 */  ldc1       $fv0, %lo(D_800CC550)($at)
    /* B4354 002B3754 46200840 */  add.d      $fv0f, $fv0f, $fv0
  .L002B3758:
    /* B4358 002B3758 3C01800D */  lui        $at, %hi(D_800CC558)
    /* B435C 002B375C C420C558 */  lwc1       $fv0, %lo(D_800CC558)($at)
    /* B4360 002B3760 46200860 */  cvt.s.d    $fv0f, $fv0f
    /* B4364 002B3764 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* B4368 002B3768 E6400008 */  swc1       $fv0, 0x8($s2)
    /* B436C 002B376C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B4370 002B3770 8FB40020 */  lw         $s4, 0x20($sp)
    /* B4374 002B3774 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B4378 002B3778 8FB20018 */  lw         $s2, 0x18($sp)
    /* B437C 002B377C 8FB10014 */  lw         $s1, 0x14($sp)
    /* B4380 002B3780 8FB00010 */  lw         $s0, 0x10($sp)
    /* B4384 002B3784 03E00008 */  jr         $ra
    /* B4388 002B3788 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B3688
