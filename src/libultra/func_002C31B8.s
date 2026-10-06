.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC3DB8-0xC4204 (VRAM 0x002C31B8) */
glabel func_002C31B8
    /* C3DB8 002C31B8 0C0B0FA8 */  jal        func_002C3EA0
    /* C3DBC 002C31BC AFAB0010 */   sw        $t3, 0x10($sp)
  alabel D_002C31C0
    /* C3DC0 002C31C0 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* C3DC4 002C31C4 AFB20038 */  sw         $s2, 0x38($sp)
    /* C3DC8 002C31C8 8FB20068 */  lw         $s2, 0x68($sp)
    /* C3DCC 002C31CC AFB7004C */  sw         $s7, 0x4C($sp)
    /* C3DD0 002C31D0 00A0B821 */  addu       $s7, $a1, $zero
    /* C3DD4 002C31D4 AFB50044 */  sw         $s5, 0x44($sp)
    /* C3DD8 002C31D8 00C0A821 */  addu       $s5, $a2, $zero
    /* C3DDC 002C31DC AFB00030 */  sw         $s0, 0x30($sp)
    /* C3DE0 002C31E0 00808021 */  addu       $s0, $a0, $zero
    /* C3DE4 002C31E4 AFBF0054 */  sw         $ra, 0x54($sp)
    /* C3DE8 002C31E8 AFBE0050 */  sw         $fp, 0x50($sp)
    /* C3DEC 002C31EC AFB60048 */  sw         $s6, 0x48($sp)
    /* C3DF0 002C31F0 AFB40040 */  sw         $s4, 0x40($sp)
    /* C3DF4 002C31F4 AFB3003C */  sw         $s3, 0x3C($sp)
    /* C3DF8 002C31F8 AFB10034 */  sw         $s1, 0x34($sp)
    /* C3DFC 002C31FC AFA00020 */  sw         $zero, 0x20($sp)
    /* C3E00 002C3200 12A000F3 */  beqz       $s5, .L002C35D0
    /* C3E04 002C3204 02408821 */   addu      $s1, $s2, $zero
    /* C3E08 002C3208 3C0300FF */  lui        $v1, (0xFFFFFF >> 16)
    /* C3E0C 002C320C 8E02002C */  lw         $v0, 0x2C($s0)
    /* C3E10 002C3210 3463FFFF */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* C3E14 002C3214 00431024 */  and        $v0, $v0, $v1
    /* C3E18 002C3218 3C030B00 */  lui        $v1, (0xB000000 >> 16)
    /* C3E1C 002C321C 00431025 */  or         $v0, $v0, $v1
    /* C3E20 002C3220 AE220000 */  sw         $v0, 0x0($s1)
    /* C3E24 002C3224 8E020028 */  lw         $v0, 0x28($s0)
    /* C3E28 002C3228 26520008 */  addiu      $s2, $s2, 0x8
    /* C3E2C 002C322C 8C440010 */  lw         $a0, 0x10($v0)
    /* C3E30 002C3230 8E05002C */  lw         $a1, 0x2C($s0)
    /* C3E34 002C3234 0C095C38 */  jal        func_002570E0
    /* C3E38 002C3238 24840008 */   addiu     $a0, $a0, 0x8
    /* C3E3C 002C323C 00002021 */  addu       $a0, $zero, $zero
    /* C3E40 002C3240 AE220004 */  sw         $v0, 0x4($s1)
    /* C3E44 002C3244 8E050038 */  lw         $a1, 0x38($s0)
    /* C3E48 002C3248 8E030020 */  lw         $v1, 0x20($s0)
    /* C3E4C 002C324C 02A51021 */  addu       $v0, $s5, $a1
    /* C3E50 002C3250 0062102B */  sltu       $v0, $v1, $v0
    /* C3E54 002C3254 10400003 */  beqz       $v0, .L002C3264
    /* C3E58 002C3258 0080F021 */   addu      $fp, $a0, $zero
    /* C3E5C 002C325C 8E020024 */  lw         $v0, 0x24($s0)
    /* C3E60 002C3260 0082202B */  sltu       $a0, $a0, $v0
  .L002C3264:
    /* C3E64 002C3264 10800002 */  beqz       $a0, .L002C3270
    /* C3E68 002C3268 02A08821 */   addu      $s1, $s5, $zero
    /* C3E6C 002C326C 00658823 */  subu       $s1, $v1, $a1
  .L002C3270:
    /* C3E70 002C3270 8E03003C */  lw         $v1, 0x3C($s0)
    /* C3E74 002C3274 10600003 */  beqz       $v1, .L002C3284
    /* C3E78 002C3278 24020010 */   addiu     $v0, $zero, 0x10
    /* C3E7C 002C327C 080B0CA2 */  j          .L002C3288
    /* C3E80 002C3280 0043B023 */   subu      $s6, $v0, $v1
  .L002C3284:
    /* C3E84 002C3284 0000B021 */  addu       $s6, $zero, $zero
  .L002C3288:
    /* C3E88 002C3288 02363023 */  subu       $a2, $s1, $s6
    /* C3E8C 002C328C 04C20001 */  bltzl      $a2, .L002C3294
    /* C3E90 002C3290 00003021 */   addu      $a2, $zero, $zero
  .L002C3294:
    /* C3E94 002C3294 24C2000F */  addiu      $v0, $a2, 0xF
    /* C3E98 002C3298 00029903 */  sra        $s3, $v0, 4
    /* C3E9C 002C329C 001328C0 */  sll        $a1, $s3, 3
    /* C3EA0 002C32A0 10800071 */  beqz       $a0, .L002C3468
    /* C3EA4 002C32A4 00B33821 */   addu      $a3, $a1, $s3
    /* C3EA8 002C32A8 86E20000 */  lh         $v0, 0x0($s7)
    /* C3EAC 002C32AC 02402021 */  addu       $a0, $s2, $zero
    /* C3EB0 002C32B0 AFA00014 */  sw         $zero, 0x14($sp)
    /* C3EB4 002C32B4 AFA20010 */  sw         $v0, 0x10($sp)
    /* C3EB8 002C32B8 8E020040 */  lw         $v0, 0x40($s0)
    /* C3EBC 002C32BC 02002821 */  addu       $a1, $s0, $zero
    /* C3EC0 002C32C0 0C0B0F49 */  jal        func_002C3D24
    /* C3EC4 002C32C4 AFA20018 */   sw        $v0, 0x18($sp)
    /* C3EC8 002C32C8 8E03003C */  lw         $v1, 0x3C($s0)
    /* C3ECC 002C32CC 10600007 */  beqz       $v1, .L002C32EC
    /* C3ED0 002C32D0 00409021 */   addu      $s2, $v0, $zero
    /* C3ED4 002C32D4 9602003E */  lhu        $v0, 0x3E($s0)
    /* C3ED8 002C32D8 96E30000 */  lhu        $v1, 0x0($s7)
    /* C3EDC 002C32DC 00021040 */  sll        $v0, $v0, 1
    /* C3EE0 002C32E0 00621821 */  addu       $v1, $v1, $v0
    /* C3EE4 002C32E4 080B0CBE */  j          .L002C32F8
    /* C3EE8 002C32E8 A6E30000 */   sh        $v1, 0x0($s7)
  .L002C32EC:
    /* C3EEC 002C32EC 96E20000 */  lhu        $v0, 0x0($s7)
    /* C3EF0 002C32F0 24420020 */  addiu      $v0, $v0, 0x20
    /* C3EF4 002C32F4 A6E20000 */  sh         $v0, 0x0($s7)
  .L002C32F8:
    /* C3EF8 002C32F8 8E02001C */  lw         $v0, 0x1C($s0)
    /* C3EFC 002C32FC 8E05001C */  lw         $a1, 0x1C($s0)
    /* C3F00 002C3300 3042000F */  andi       $v0, $v0, 0xF
    /* C3F04 002C3304 00A01821 */  addu       $v1, $a1, $zero
    /* C3F08 002C3308 00031902 */  srl        $v1, $v1, 4
    /* C3F0C 002C330C AE02003C */  sw         $v0, 0x3C($s0)
    /* C3F10 002C3310 8E020028 */  lw         $v0, 0x28($s0)
    /* C3F14 002C3314 24630001 */  addiu      $v1, $v1, 0x1
    /* C3F18 002C3318 8C440000 */  lw         $a0, 0x0($v0)
    /* C3F1C 002C331C 000310C0 */  sll        $v0, $v1, 3
    /* C3F20 002C3320 00431021 */  addu       $v0, $v0, $v1
    /* C3F24 002C3324 AE050038 */  sw         $a1, 0x38($s0)
    /* C3F28 002C3328 00822021 */  addu       $a0, $a0, $v0
    /* C3F2C 002C332C 0235102A */  slt        $v0, $s1, $s5
    /* C3F30 002C3330 AE040044 */  sw         $a0, 0x44($s0)
    /* C3F34 002C3334 86F40000 */  lh         $s4, 0x0($s7)
    /* C3F38 002C3338 1040003D */  beqz       $v0, .L002C3430
    /* C3F3C 002C333C 001E1400 */   sll       $v0, $fp, 16
    /* C3F40 002C3340 0002BC03 */  sra        $s7, $v0, 16
  .L002C3344:
    /* C3F44 002C3344 26630001 */  addiu      $v1, $s3, 0x1
    /* C3F48 002C3348 00031940 */  sll        $v1, $v1, 5
    /* C3F4C 002C334C 02831821 */  addu       $v1, $s4, $v1
    /* C3F50 002C3350 00111040 */  sll        $v0, $s1, 1
    /* C3F54 002C3354 0282A021 */  addu       $s4, $s4, $v0
    /* C3F58 002C3358 2402FFE0 */  addiu      $v0, $zero, -0x20
    /* C3F5C 002C335C 0062B024 */  and        $s6, $v1, $v0
    /* C3F60 002C3360 8E030024 */  lw         $v1, 0x24($s0)
    /* C3F64 002C3364 2402FFFF */  addiu      $v0, $zero, -0x1
    /* C3F68 002C3368 10620004 */  beq        $v1, $v0, .L002C337C
    /* C3F6C 002C336C 02B1A823 */   subu      $s5, $s5, $s1
    /* C3F70 002C3370 10600002 */  beqz       $v1, .L002C337C
    /* C3F74 002C3374 00621021 */   addu      $v0, $v1, $v0
    /* C3F78 002C3378 AE020024 */  sw         $v0, 0x24($s0)
  .L002C337C:
    /* C3F7C 002C337C 8E030020 */  lw         $v1, 0x20($s0)
    /* C3F80 002C3380 8E02001C */  lw         $v0, 0x1C($s0)
    /* C3F84 002C3384 00621823 */  subu       $v1, $v1, $v0
    /* C3F88 002C3388 02A3102B */  sltu       $v0, $s5, $v1
    /* C3F8C 002C338C 14400002 */  bnez       $v0, .L002C3398
    /* C3F90 002C3390 02A08821 */   addu      $s1, $s5, $zero
    /* C3F94 002C3394 00608821 */  addu       $s1, $v1, $zero
  .L002C3398:
    /* C3F98 002C3398 8E02003C */  lw         $v0, 0x3C($s0)
    /* C3F9C 002C339C 2442FFF0 */  addiu      $v0, $v0, -0x10
    /* C3FA0 002C33A0 02223021 */  addu       $a2, $s1, $v0
    /* C3FA4 002C33A4 04C20001 */  bltzl      $a2, .L002C33AC
    /* C3FA8 002C33A8 00003021 */   addu      $a2, $zero, $zero
  .L002C33AC:
    /* C3FAC 002C33AC 24C2000F */  addiu      $v0, $a2, 0xF
    /* C3FB0 002C33B0 00029903 */  sra        $s3, $v0, 4
    /* C3FB4 002C33B4 02402021 */  addu       $a0, $s2, $zero
    /* C3FB8 002C33B8 02002821 */  addu       $a1, $s0, $zero
    /* C3FBC 002C33BC 00161400 */  sll        $v0, $s6, 16
    /* C3FC0 002C33C0 00021403 */  sra        $v0, $v0, 16
    /* C3FC4 002C33C4 001338C0 */  sll        $a3, $s3, 3
    /* C3FC8 002C33C8 AFA20010 */  sw         $v0, 0x10($sp)
    /* C3FCC 002C33CC AFB70014 */  sw         $s7, 0x14($sp)
    /* C3FD0 002C33D0 8E020040 */  lw         $v0, 0x40($s0)
    /* C3FD4 002C33D4 00F33821 */  addu       $a3, $a3, $s3
    /* C3FD8 002C33D8 34420002 */  ori        $v0, $v0, 0x2
    /* C3FDC 002C33DC 0C0B0F49 */  jal        func_002C3D24
    /* C3FE0 002C33E0 AFA20018 */   sw        $v0, 0x18($sp)
    /* C3FE4 002C33E4 00409021 */  addu       $s2, $v0, $zero
    /* C3FE8 002C33E8 02402821 */  addu       $a1, $s2, $zero
    /* C3FEC 002C33EC 3C0600FF */  lui        $a2, (0xFFFFFF >> 16)
    /* C3FF0 002C33F0 34C6FFFF */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* C3FF4 002C33F4 00142400 */  sll        $a0, $s4, 16
    /* C3FF8 002C33F8 00111840 */  sll        $v1, $s1, 1
    /* C3FFC 002C33FC 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* C4000 002C3400 00832025 */  or         $a0, $a0, $v1
    /* C4004 002C3404 8E02003C */  lw         $v0, 0x3C($s0)
    /* C4008 002C3408 3C030A00 */  lui        $v1, (0xA000000 >> 16)
    /* C400C 002C340C ACA40004 */  sw         $a0, 0x4($a1)
    /* C4010 002C3410 00021040 */  sll        $v0, $v0, 1
    /* C4014 002C3414 02C21021 */  addu       $v0, $s6, $v0
    /* C4018 002C3418 00461024 */  and        $v0, $v0, $a2
    /* C401C 002C341C 00431025 */  or         $v0, $v0, $v1
    /* C4020 002C3420 ACA20000 */  sw         $v0, 0x0($a1)
    /* C4024 002C3424 0235102A */  slt        $v0, $s1, $s5
    /* C4028 002C3428 1440FFC6 */  bnez       $v0, .L002C3344
    /* C402C 002C342C 26520008 */   addiu     $s2, $s2, 0x8
  .L002C3430:
    /* C4030 002C3430 02401021 */  addu       $v0, $s2, $zero
    /* C4034 002C3434 8E03003C */  lw         $v1, 0x3C($s0)
    /* C4038 002C3438 8E040038 */  lw         $a0, 0x38($s0)
    /* C403C 002C343C 02A31821 */  addu       $v1, $s5, $v1
    /* C4040 002C3440 3063000F */  andi       $v1, $v1, 0xF
    /* C4044 002C3444 00952021 */  addu       $a0, $a0, $s5
    /* C4048 002C3448 AE03003C */  sw         $v1, 0x3C($s0)
    /* C404C 002C344C 001318C0 */  sll        $v1, $s3, 3
    /* C4050 002C3450 AE040038 */  sw         $a0, 0x38($s0)
    /* C4054 002C3454 8E040044 */  lw         $a0, 0x44($s0)
    /* C4058 002C3458 00731821 */  addu       $v1, $v1, $s3
    /* C405C 002C345C 00832021 */  addu       $a0, $a0, $v1
    /* C4060 002C3460 080B0D75 */  j          .L002C35D4
    /* C4064 002C3464 AE040044 */   sw        $a0, 0x44($s0)
  .L002C3468:
    /* C4068 002C3468 8E040028 */  lw         $a0, 0x28($s0)
    /* C406C 002C346C 8E030044 */  lw         $v1, 0x44($s0)
    /* C4070 002C3470 8C820000 */  lw         $v0, 0x0($a0)
    /* C4074 002C3474 8C840004 */  lw         $a0, 0x4($a0)
    /* C4078 002C3478 00671821 */  addu       $v1, $v1, $a3
    /* C407C 002C347C 00441021 */  addu       $v0, $v0, $a0
    /* C4080 002C3480 00622023 */  subu       $a0, $v1, $v0
    /* C4084 002C3484 04810002 */  bgez       $a0, .L002C3490
    /* C4088 002C3488 00138900 */   sll       $s1, $s3, 4
    /* C408C 002C348C 00002021 */  addu       $a0, $zero, $zero
  .L002C3490:
    /* C4090 002C3490 3C0238E3 */  lui        $v0, (0x38E38E39 >> 16)
    /* C4094 002C3494 34428E39 */  ori        $v0, $v0, (0x38E38E39 & 0xFFFF)
    /* C4098 002C3498 00820018 */  mult       $a0, $v0
    /* C409C 002C349C 00041FC3 */  sra        $v1, $a0, 31
    /* C40A0 002C34A0 00004010 */  mfhi       $t0
    /* C40A4 002C34A4 00081043 */  sra        $v0, $t0, 1
    /* C40A8 002C34A8 00431023 */  subu       $v0, $v0, $v1
    /* C40AC 002C34AC 0002A100 */  sll        $s4, $v0, 4
    /* C40B0 002C34B0 02361821 */  addu       $v1, $s1, $s6
    /* C40B4 002C34B4 0074102A */  slt        $v0, $v1, $s4
    /* C40B8 002C34B8 54400001 */  bnel       $v0, $zero, .L002C34C0
    /* C40BC 002C34BC 0060A021 */   addu      $s4, $v1, $zero
  .L002C34C0:
    /* C40C0 002C34C0 3282000F */  andi       $v0, $s4, 0xF
    /* C40C4 002C34C4 02821023 */  subu       $v0, $s4, $v0
    /* C40C8 002C34C8 0055102A */  slt        $v0, $v0, $s5
    /* C40CC 002C34CC 10400025 */  beqz       $v0, .L002C3564
    /* C40D0 002C34D0 00E43823 */   subu      $a3, $a3, $a0
    /* C40D4 002C34D4 24080001 */  addiu      $t0, $zero, 0x1
    /* C40D8 002C34D8 02402021 */  addu       $a0, $s2, $zero
    /* C40DC 002C34DC AFA80020 */  sw         $t0, 0x20($sp)
    /* C40E0 002C34E0 86E20000 */  lh         $v0, 0x0($s7)
    /* C40E4 002C34E4 02002821 */  addu       $a1, $s0, $zero
    /* C40E8 002C34E8 AFA00014 */  sw         $zero, 0x14($sp)
    /* C40EC 002C34EC AFA20010 */  sw         $v0, 0x10($sp)
    /* C40F0 002C34F0 8E020040 */  lw         $v0, 0x40($s0)
    /* C40F4 002C34F4 02343023 */  subu       $a2, $s1, $s4
    /* C40F8 002C34F8 0C0B0F49 */  jal        func_002C3D24
    /* C40FC 002C34FC AFA20018 */   sw        $v0, 0x18($sp)
    /* C4100 002C3500 8E03003C */  lw         $v1, 0x3C($s0)
    /* C4104 002C3504 10600007 */  beqz       $v1, .L002C3524
    /* C4108 002C3508 00409021 */   addu      $s2, $v0, $zero
    /* C410C 002C350C 9602003E */  lhu        $v0, 0x3E($s0)
    /* C4110 002C3510 96E30000 */  lhu        $v1, 0x0($s7)
    /* C4114 002C3514 00021040 */  sll        $v0, $v0, 1
    /* C4118 002C3518 00621821 */  addu       $v1, $v1, $v0
    /* C411C 002C351C 080B0D4C */  j          .L002C3530
    /* C4120 002C3520 A6E30000 */   sh        $v1, 0x0($s7)
  .L002C3524:
    /* C4124 002C3524 96E20000 */  lhu        $v0, 0x0($s7)
    /* C4128 002C3528 24420020 */  addiu      $v0, $v0, 0x20
    /* C412C 002C352C A6E20000 */  sh         $v0, 0x0($s7)
  .L002C3530:
    /* C4130 002C3530 8E02003C */  lw         $v0, 0x3C($s0)
    /* C4134 002C3534 8E030038 */  lw         $v1, 0x38($s0)
    /* C4138 002C3538 02A21021 */  addu       $v0, $s5, $v0
    /* C413C 002C353C 3042000F */  andi       $v0, $v0, 0xF
    /* C4140 002C3540 00751821 */  addu       $v1, $v1, $s5
    /* C4144 002C3544 AE02003C */  sw         $v0, 0x3C($s0)
    /* C4148 002C3548 001310C0 */  sll        $v0, $s3, 3
    /* C414C 002C354C AE030038 */  sw         $v1, 0x38($s0)
    /* C4150 002C3550 8E030044 */  lw         $v1, 0x44($s0)
    /* C4154 002C3554 00531021 */  addu       $v0, $v0, $s3
    /* C4158 002C3558 00621821 */  addu       $v1, $v1, $v0
    /* C415C 002C355C 080B0D5E */  j          .L002C3578
    /* C4160 002C3560 AE030044 */   sw        $v1, 0x44($s0)
  .L002C3564:
    /* C4164 002C3564 8E020044 */  lw         $v0, 0x44($s0)
    /* C4168 002C3568 00B31821 */  addu       $v1, $a1, $s3
    /* C416C 002C356C AE00003C */  sw         $zero, 0x3C($s0)
    /* C4170 002C3570 00431021 */  addu       $v0, $v0, $v1
    /* C4174 002C3574 AE020044 */  sw         $v0, 0x44($s0)
  .L002C3578:
    /* C4178 002C3578 12800016 */  beqz       $s4, .L002C35D4
    /* C417C 002C357C 02401021 */   addu      $v0, $s2, $zero
    /* C4180 002C3580 AE00003C */  sw         $zero, 0x3C($s0)
    /* C4184 002C3584 8FA80020 */  lw         $t0, 0x20($sp)
    /* C4188 002C3588 11000004 */  beqz       $t0, .L002C359C
    /* C418C 002C358C 02D11021 */   addu      $v0, $s6, $s1
    /* C4190 002C3590 00541023 */  subu       $v0, $v0, $s4
    /* C4194 002C3594 080B0D68 */  j          .L002C35A0
    /* C4198 002C3598 00023040 */   sll       $a2, $v0, 1
  .L002C359C:
    /* C419C 002C359C 00003021 */  addu       $a2, $zero, $zero
  .L002C35A0:
    /* C41A0 002C35A0 02402821 */  addu       $a1, $s2, $zero
    /* C41A4 002C35A4 26520008 */  addiu      $s2, $s2, 0x8
    /* C41A8 002C35A8 3C0400FF */  lui        $a0, (0xFFFFFF >> 16)
    /* C41AC 002C35AC 3484FFFF */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* C41B0 002C35B0 86E20000 */  lh         $v0, 0x0($s7)
    /* C41B4 002C35B4 00141840 */  sll        $v1, $s4, 1
    /* C41B8 002C35B8 ACA30004 */  sw         $v1, 0x4($a1)
    /* C41BC 002C35BC 3C030200 */  lui        $v1, (0x2000000 >> 16)
    /* C41C0 002C35C0 00C21021 */  addu       $v0, $a2, $v0
    /* C41C4 002C35C4 00441024 */  and        $v0, $v0, $a0
    /* C41C8 002C35C8 00431025 */  or         $v0, $v0, $v1
    /* C41CC 002C35CC ACA20000 */  sw         $v0, 0x0($a1)
  .L002C35D0:
    /* C41D0 002C35D0 02401021 */  addu       $v0, $s2, $zero
  .L002C35D4:
    /* C41D4 002C35D4 8FBF0054 */  lw         $ra, 0x54($sp)
    /* C41D8 002C35D8 8FBE0050 */  lw         $fp, 0x50($sp)
    /* C41DC 002C35DC 8FB7004C */  lw         $s7, 0x4C($sp)
    /* C41E0 002C35E0 8FB60048 */  lw         $s6, 0x48($sp)
    /* C41E4 002C35E4 8FB50044 */  lw         $s5, 0x44($sp)
    /* C41E8 002C35E8 8FB40040 */  lw         $s4, 0x40($sp)
    /* C41EC 002C35EC 8FB3003C */  lw         $s3, 0x3C($sp)
    /* C41F0 002C35F0 8FB20038 */  lw         $s2, 0x38($sp)
    /* C41F4 002C35F4 8FB10034 */  lw         $s1, 0x34($sp)
    /* C41F8 002C35F8 8FB00030 */  lw         $s0, 0x30($sp)
    /* C41FC 002C35FC 03E00008 */  jr         $ra
    /* C4200 002C3600 27BD0058 */   addiu     $sp, $sp, 0x58
endlabel func_002C31B8
