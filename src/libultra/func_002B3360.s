.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3F60-0xB41D0 (VRAM 0x002B3360) */
glabel func_002B3360
    /* B3F60 002B3360 27BDFEC0 */  addiu      $sp, $sp, -0x140
    /* B3F64 002B3364 AFB5012C */  sw         $s5, 0x12C($sp)
    /* B3F68 002B3368 00A0A821 */  addu       $s5, $a1, $zero
    /* B3F6C 002B336C AFB70134 */  sw         $s7, 0x134($sp)
    /* B3F70 002B3370 00C0B821 */  addu       $s7, $a2, $zero
    /* B3F74 002B3374 AFB00118 */  sw         $s0, 0x118($sp)
    /* B3F78 002B3378 00008021 */  addu       $s0, $zero, $zero
    /* B3F7C 002B337C AFB60130 */  sw         $s6, 0x130($sp)
    /* B3F80 002B3380 24160001 */  addiu      $s6, $zero, 0x1
    /* B3F84 002B3384 AFB30124 */  sw         $s3, 0x124($sp)
    /* B3F88 002B3388 27B30020 */  addiu      $s3, $sp, 0x20
    /* B3F8C 002B338C AFB1011C */  sw         $s1, 0x11C($sp)
    /* B3F90 002B3390 02608821 */  addu       $s1, $s3, $zero
    /* B3F94 002B3394 AFBF0138 */  sw         $ra, 0x138($sp)
    /* B3F98 002B3398 AFB40128 */  sw         $s4, 0x128($sp)
    /* B3F9C 002B339C AFB20120 */  sw         $s2, 0x120($sp)
    /* B3FA0 002B33A0 8C920000 */  lw         $s2, 0x0($a0)
    /* B3FA4 002B33A4 02C01021 */  addu       $v0, $s6, $zero
    /* B3FA8 002B33A8 AFA00024 */  sw         $zero, 0x24($sp)
    /* B3FAC 002B33AC AFA00030 */  sw         $zero, 0x30($sp)
    /* B3FB0 002B33B0 AFA0002C */  sw         $zero, 0x2C($sp)
    /* B3FB4 002B33B4 AFA20034 */  sw         $v0, 0x34($sp)
    /* B3FB8 002B33B8 AFB20020 */  sw         $s2, 0x20($sp)
  .L002B33BC:
    /* B3FBC 002B33BC 02701021 */  addu       $v0, $s3, $s0
    /* B3FC0 002B33C0 A04000A8 */  sb         $zero, 0xA8($v0)
    /* B3FC4 002B33C4 AE200058 */  sw         $zero, 0x58($s1)
    /* B3FC8 002B33C8 A0400098 */  sb         $zero, 0x98($v0)
    /* B3FCC 002B33CC 8FA20020 */  lw         $v0, 0x20($sp)
    /* B3FD0 002B33D0 00101880 */  sll        $v1, $s0, 2
    /* B3FD4 002B33D4 00431021 */  addu       $v0, $v0, $v1
    /* B3FD8 002B33D8 8C460000 */  lw         $a2, 0x0($v0)
    /* B3FDC 002B33DC 10C0000B */  beqz       $a2, .L002B340C
    /* B3FE0 002B33E0 27A40020 */   addiu     $a0, $sp, 0x20
    /* B3FE4 002B33E4 02002821 */  addu       $a1, $s0, $zero
    /* B3FE8 002B33E8 8FA20024 */  lw         $v0, 0x24($sp)
    /* B3FEC 002B33EC 02161804 */  sllv       $v1, $s6, $s0
    /* B3FF0 002B33F0 00431025 */  or         $v0, $v0, $v1
    /* B3FF4 002B33F4 AFA20024 */  sw         $v0, 0x24($sp)
    /* B3FF8 002B33F8 02461021 */  addu       $v0, $s2, $a2
    /* B3FFC 002B33FC 0C0ACEBF */  jal        func_002B3AFC
    /* B4000 002B3400 AE220018 */   sw        $v0, 0x18($s1)
    /* B4004 002B3404 080ACD04 */  j          .L002B3410
    /* B4008 002B3408 AE2200B8 */   sw        $v0, 0xB8($s1)
  .L002B340C:
    /* B400C 002B340C AE200018 */  sw         $zero, 0x18($s1)
  .L002B3410:
    /* B4010 002B3410 26100001 */  addiu      $s0, $s0, 0x1
    /* B4014 002B3414 2E020010 */  sltiu      $v0, $s0, 0x10
    /* B4018 002B3418 1440FFE8 */  bnez       $v0, .L002B33BC
    /* B401C 002B341C 26310004 */   addiu     $s1, $s1, 0x4
    /* B4020 002B3420 8FA20020 */  lw         $v0, 0x20($sp)
    /* B4024 002B3424 8C420040 */  lw         $v0, 0x40($v0)
    /* B4028 002B3428 44820800 */  mtc1       $v0, $fv0f
    /* B402C 002B342C 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* B4030 002B3430 04410004 */  bgez       $v0, .L002B3444
    /* B4034 002B3434 27B30020 */   addiu     $s3, $sp, 0x20
    /* B4038 002B3438 3C01800D */  lui        $at, %hi(D_800CC540)
    /* B403C 002B343C D420C540 */  ldc1       $fv0, %lo(D_800CC540)($at)
    /* B4040 002B3440 46200840 */  add.d      $fv0f, $fv0f, $fv0
  .L002B3444:
    /* B4044 002B3444 3C01800D */  lui        $at, %hi(D_800CC548)
    /* B4048 002B3448 C420C548 */  lwc1       $fv0, %lo(D_800CC548)($at)
    /* B404C 002B344C 46200860 */  cvt.s.d    $fv0f, $fv0f
    /* B4050 002B3450 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* B4054 002B3454 E7A00028 */  swc1       $fv0, 0x28($sp)
  .L002B3458:
    /* B4058 002B3458 8FA20024 */  lw         $v0, 0x24($sp)
    /* B405C 002B345C 00003821 */  addu       $a3, $zero, $zero
    /* B4060 002B3460 AEA20000 */  sw         $v0, 0x0($s5)
    /* B4064 002B3464 8FA2002C */  lw         $v0, 0x2C($sp)
    /* B4068 002B3468 02603021 */  addu       $a2, $s3, $zero
    /* B406C 002B346C AEA20004 */  sw         $v0, 0x4($s5)
    /* B4070 002B3470 8FA20030 */  lw         $v0, 0x30($sp)
    /* B4074 002B3474 02A02821 */  addu       $a1, $s5, $zero
    /* B4078 002B3478 AEA20008 */  sw         $v0, 0x8($s5)
  .L002B347C:
    /* B407C 002B347C 8CC20018 */  lw         $v0, 0x18($a2)
    /* B4080 002B3480 ACA2000C */  sw         $v0, 0xC($a1)
    /* B4084 002B3484 8CC20058 */  lw         $v0, 0x58($a2)
    /* B4088 002B3488 ACA2004C */  sw         $v0, 0x4C($a1)
    /* B408C 002B348C 02671021 */  addu       $v0, $s3, $a3
    /* B4090 002B3490 90440098 */  lbu        $a0, 0x98($v0)
    /* B4094 002B3494 02A71821 */  addu       $v1, $s5, $a3
    /* B4098 002B3498 A064008C */  sb         $a0, 0x8C($v1)
    /* B409C 002B349C 904200A8 */  lbu        $v0, 0xA8($v0)
    /* B40A0 002B34A0 24E70001 */  addiu      $a3, $a3, 0x1
    /* B40A4 002B34A4 A062009C */  sb         $v0, 0x9C($v1)
    /* B40A8 002B34A8 8CC200B8 */  lw         $v0, 0xB8($a2)
    /* B40AC 002B34AC 24C60004 */  addiu      $a2, $a2, 0x4
    /* B40B0 002B34B0 ACA200AC */  sw         $v0, 0xAC($a1)
    /* B40B4 002B34B4 28E20010 */  slti       $v0, $a3, 0x10
    /* B40B8 002B34B8 1440FFF0 */  bnez       $v0, .L002B347C
    /* B40BC 002B34BC 24A50004 */   addiu     $a1, $a1, 0x4
    /* B40C0 002B34C0 27B10010 */  addiu      $s1, $sp, 0x10
    /* B40C4 002B34C4 2410FFFF */  addiu      $s0, $zero, -0x1
    /* B40C8 002B34C8 8FA60030 */  lw         $a2, 0x30($sp)
    /* B40CC 002B34CC 00002821 */  addu       $a1, $zero, $zero
    /* B40D0 002B34D0 27B20020 */  addiu      $s2, $sp, 0x20
    /* B40D4 002B34D4 02402021 */  addu       $a0, $s2, $zero
  .L002B34D8:
    /* B40D8 002B34D8 8FA20024 */  lw         $v0, 0x24($sp)
    /* B40DC 002B34DC 00A21006 */  srlv       $v0, $v0, $a1
    /* B40E0 002B34E0 30420001 */  andi       $v0, $v0, 0x1
    /* B40E4 002B34E4 5040000E */  beql       $v0, $zero, .L002B3520
    /* B40E8 002B34E8 24A50001 */   addiu     $a1, $a1, 0x1
    /* B40EC 002B34EC 8FA20034 */  lw         $v0, 0x34($sp)
    /* B40F0 002B34F0 10400004 */  beqz       $v0, .L002B3504
    /* B40F4 002B34F4 00000000 */   nop
    /* B40F8 002B34F8 8C8200B8 */  lw         $v0, 0xB8($a0)
    /* B40FC 002B34FC 00461023 */  subu       $v0, $v0, $a2
    /* B4100 002B3500 AC8200B8 */  sw         $v0, 0xB8($a0)
  .L002B3504:
    /* B4104 002B3504 8C8300B8 */  lw         $v1, 0xB8($a0)
    /* B4108 002B3508 0070102B */  sltu       $v0, $v1, $s0
    /* B410C 002B350C 50400004 */  beql       $v0, $zero, .L002B3520
    /* B4110 002B3510 24A50001 */   addiu     $a1, $a1, 0x1
    /* B4114 002B3514 00608021 */  addu       $s0, $v1, $zero
    /* B4118 002B3518 00A0A021 */  addu       $s4, $a1, $zero
    /* B411C 002B351C 24A50001 */  addiu      $a1, $a1, 0x1
  .L002B3520:
    /* B4120 002B3520 2CA20010 */  sltiu      $v0, $a1, 0x10
    /* B4124 002B3524 1440FFEC */  bnez       $v0, .L002B34D8
    /* B4128 002B3528 24840004 */   addiu     $a0, $a0, 0x4
    /* B412C 002B352C 27A40020 */  addiu      $a0, $sp, 0x20
    /* B4130 002B3530 02802821 */  addu       $a1, $s4, $zero
    /* B4134 002B3534 0C0ACC40 */  jal        func_002B3100
    /* B4138 002B3538 02203021 */   addu      $a2, $s1, $zero
    /* B413C 002B353C AE300004 */  sw         $s0, 0x4($s1)
    /* B4140 002B3540 8FA2002C */  lw         $v0, 0x2C($sp)
    /* B4144 002B3544 AFB00030 */  sw         $s0, 0x30($sp)
    /* B4148 002B3548 00501021 */  addu       $v0, $v0, $s0
    /* B414C 002B354C AFA2002C */  sw         $v0, 0x2C($sp)
    /* B4150 002B3550 86230000 */  lh         $v1, 0x0($s1)
    /* B4154 002B3554 24020012 */  addiu      $v0, $zero, 0x12
    /* B4158 002B3558 10620008 */  beq        $v1, $v0, .L002B357C
    /* B415C 002B355C 27A40020 */   addiu     $a0, $sp, 0x20
    /* B4160 002B3560 0C0ACEBF */  jal        func_002B3AFC
    /* B4164 002B3564 02802821 */   addu      $a1, $s4, $zero
    /* B4168 002B3568 00142080 */  sll        $a0, $s4, 2
    /* B416C 002B356C 02442021 */  addu       $a0, $s2, $a0
    /* B4170 002B3570 8C8300B8 */  lw         $v1, 0xB8($a0)
    /* B4174 002B3574 00621821 */  addu       $v1, $v1, $v0
    /* B4178 002B3578 AC8300B8 */  sw         $v1, 0xB8($a0)
  .L002B357C:
    /* B417C 002B357C 87A30010 */  lh         $v1, 0x10($sp)
    /* B4180 002B3580 24020001 */  addiu      $v0, $zero, 0x1
    /* B4184 002B3584 AFA20034 */  sw         $v0, 0x34($sp)
    /* B4188 002B3588 24020004 */  addiu      $v0, $zero, 0x4
    /* B418C 002B358C 10620005 */  beq        $v1, $v0, .L002B35A4
    /* B4190 002B3590 00000000 */   nop
    /* B4194 002B3594 8FA2002C */  lw         $v0, 0x2C($sp)
    /* B4198 002B3598 0057102B */  sltu       $v0, $v0, $s7
    /* B419C 002B359C 1440FFAE */  bnez       $v0, .L002B3458
    /* B41A0 002B35A0 00000000 */   nop
  .L002B35A4:
    /* B41A4 002B35A4 8FBF0138 */  lw         $ra, 0x138($sp)
    /* B41A8 002B35A8 8FB70134 */  lw         $s7, 0x134($sp)
    /* B41AC 002B35AC 8FB60130 */  lw         $s6, 0x130($sp)
    /* B41B0 002B35B0 8FB5012C */  lw         $s5, 0x12C($sp)
    /* B41B4 002B35B4 8FB40128 */  lw         $s4, 0x128($sp)
    /* B41B8 002B35B8 8FB30124 */  lw         $s3, 0x124($sp)
    /* B41BC 002B35BC 8FB20120 */  lw         $s2, 0x120($sp)
    /* B41C0 002B35C0 8FB1011C */  lw         $s1, 0x11C($sp)
    /* B41C4 002B35C4 8FB00118 */  lw         $s0, 0x118($sp)
    /* B41C8 002B35C8 03E00008 */  jr         $ra
    /* B41CC 002B35CC 27BD0140 */   addiu     $sp, $sp, 0x140
endlabel func_002B3360
