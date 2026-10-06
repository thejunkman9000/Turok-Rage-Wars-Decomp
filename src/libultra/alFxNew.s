.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9BE0-0xBA074 (VRAM 0x002B8FE0) */
glabel alFxNew
    /* B9BE0 002B8FE0 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B9BE4 002B8FE4 AFB30024 */  sw         $s3, 0x24($sp)
    /* B9BE8 002B8FE8 00809821 */  addu       $s3, $a0, $zero
    /* B9BEC 002B8FEC AFB70034 */  sw         $s7, 0x34($sp)
    /* B9BF0 002B8FF0 00A0B821 */  addu       $s7, $a1, $zero
    /* B9BF4 002B8FF4 AFB5002C */  sw         $s5, 0x2C($sp)
    /* B9BF8 002B8FF8 00C0A821 */  addu       $s5, $a2, $zero
    /* B9BFC 002B8FFC 00002821 */  addu       $a1, $zero, $zero
    /* B9C00 002B9000 3C06002C */  lui        $a2, %hi(alFxParam)
    /* B9C04 002B9004 24C6B1A8 */  addiu      $a2, $a2, %lo(alFxParam)
    /* B9C08 002B9008 AFBF0038 */  sw         $ra, 0x38($sp)
    /* B9C0C 002B900C AFB60030 */  sw         $s6, 0x30($sp)
    /* B9C10 002B9010 AFB40028 */  sw         $s4, 0x28($sp)
    /* B9C14 002B9014 AFB20020 */  sw         $s2, 0x20($sp)
    /* B9C18 002B9018 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B9C1C 002B901C AFB00018 */  sw         $s0, 0x18($sp)
    /* B9C20 002B9020 F7B40040 */  sdc1       $fs0, 0x40($sp)
    /* B9C24 002B9024 0C0AE92C */  jal        alFilterNew
    /* B9C28 002B9028 24070005 */   addiu     $a3, $zero, 0x5
    /* B9C2C 002B902C 3C02002C */  lui        $v0, %hi(alFxPull)
    /* B9C30 002B9030 2442A8C0 */  addiu      $v0, $v0, %lo(alFxPull)
    /* B9C34 002B9034 AE620004 */  sw         $v0, 0x4($s3)
    /* B9C38 002B9038 3C02002C */  lui        $v0, %hi(alFxParamHdl)
    /* B9C3C 002B903C 2442AC64 */  addiu      $v0, $v0, %lo(alFxParamHdl)
    /* B9C40 002B9040 AE620028 */  sw         $v0, 0x28($s3)
    /* B9C44 002B9044 92E2001C */  lbu        $v0, 0x1C($s7)
    /* B9C48 002B9048 2443FFFF */  addiu      $v1, $v0, -0x1
    /* B9C4C 002B904C 2C620006 */  sltiu      $v0, $v1, 0x6
    /* B9C50 002B9050 1040001D */  beqz       $v0, .L002B90C8
    /* B9C54 002B9054 00031080 */   sll       $v0, $v1, 2
    /* B9C58 002B9058 3C01800D */  lui        $at, %hi(jtbl_800CC7F0)
    /* B9C5C 002B905C 00220821 */  addu       $at, $at, $v0
    /* B9C60 002B9060 8C22C7F0 */  lw         $v0, %lo(jtbl_800CC7F0)($at)
    /* B9C64 002B9064 00400008 */  jr         $v0
    /* B9C68 002B9068 00000000 */   nop
    /* B9C6C 002B906C 3C12800E */  lui        $s2, %hi(D_800D80B0)
    /* B9C70 002B9070 265280B0 */  addiu      $s2, $s2, %lo(D_800D80B0)
    /* B9C74 002B9074 080AE435 */  j          .L002B90D4
    /* B9C78 002B9078 24110002 */   addiu     $s1, $zero, 0x2
    /* B9C7C 002B907C 3C12800E */  lui        $s2, %hi(D_800D8118)
    /* B9C80 002B9080 26528118 */  addiu      $s2, $s2, %lo(D_800D8118)
    /* B9C84 002B9084 080AE435 */  j          .L002B90D4
    /* B9C88 002B9088 24110002 */   addiu     $s1, $zero, 0x2
    /* B9C8C 002B908C 3C12800E */  lui        $s2, %hi(D_800D81A0)
    /* B9C90 002B9090 265281A0 */  addiu      $s2, $s2, %lo(D_800D81A0)
    /* B9C94 002B9094 080AE435 */  j          .L002B90D4
    /* B9C98 002B9098 24110002 */   addiu     $s1, $zero, 0x2
    /* B9C9C 002B909C 3C12800E */  lui        $s2, %hi(D_800D81C8)
    /* B9CA0 002B90A0 265281C8 */  addiu      $s2, $s2, %lo(D_800D81C8)
    /* B9CA4 002B90A4 080AE435 */  j          .L002B90D4
    /* B9CA8 002B90A8 24110002 */   addiu     $s1, $zero, 0x2
    /* B9CAC 002B90AC 3C12800E */  lui        $s2, %hi(D_800D81F0)
    /* B9CB0 002B90B0 265281F0 */  addiu      $s2, $s2, %lo(D_800D81F0)
    /* B9CB4 002B90B4 080AE435 */  j          .L002B90D4
    /* B9CB8 002B90B8 24110002 */   addiu     $s1, $zero, 0x2
    /* B9CBC 002B90BC 8EF20020 */  lw         $s2, 0x20($s7)
    /* B9CC0 002B90C0 080AE435 */  j          .L002B90D4
    /* B9CC4 002B90C4 24110002 */   addiu     $s1, $zero, 0x2
  .L002B90C8:
    /* B9CC8 002B90C8 3C12800E */  lui        $s2, %hi(D_800D8218)
    /* B9CCC 002B90CC 26528218 */  addiu      $s2, $s2, %lo(D_800D8218)
    /* B9CD0 002B90D0 24110002 */  addiu      $s1, $zero, 0x2
  .L002B90D4:
    /* B9CD4 002B90D4 00002021 */  addu       $a0, $zero, $zero
    /* B9CD8 002B90D8 92420003 */  lbu        $v0, 0x3($s2)
    /* B9CDC 002B90DC 00802821 */  addu       $a1, $a0, $zero
    /* B9CE0 002B90E0 A2620024 */  sb         $v0, 0x24($s3)
    /* B9CE4 002B90E4 304700FF */  andi       $a3, $v0, 0xFF
    /* B9CE8 002B90E8 8E420004 */  lw         $v0, 0x4($s2)
    /* B9CEC 002B90EC 02A03021 */  addu       $a2, $s5, $zero
    /* B9CF0 002B90F0 AE62001C */  sw         $v0, 0x1C($s3)
    /* B9CF4 002B90F4 24020028 */  addiu      $v0, $zero, 0x28
    /* B9CF8 002B90F8 0C0AD504 */  jal        alHeapDBAlloc
    /* B9CFC 002B90FC AFA20010 */   sw        $v0, 0x10($sp)
    /* B9D00 002B9100 00002021 */  addu       $a0, $zero, $zero
    /* B9D04 002B9104 00802821 */  addu       $a1, $a0, $zero
    /* B9D08 002B9108 AE620020 */  sw         $v0, 0x20($s3)
    /* B9D0C 002B910C 24020002 */  addiu      $v0, $zero, 0x2
    /* B9D10 002B9110 AFA20010 */  sw         $v0, 0x10($sp)
    /* B9D14 002B9114 8E67001C */  lw         $a3, 0x1C($s3)
    /* B9D18 002B9118 0C0AD504 */  jal        alHeapDBAlloc
    /* B9D1C 002B911C 02A03021 */   addu      $a2, $s5, $zero
    /* B9D20 002B9120 8E63001C */  lw         $v1, 0x1C($s3)
    /* B9D24 002B9124 00002021 */  addu       $a0, $zero, $zero
    /* B9D28 002B9128 AE620014 */  sw         $v0, 0x14($s3)
    /* B9D2C 002B912C 1060000C */  beqz       $v1, .L002B9160
    /* B9D30 002B9130 AE620018 */   sw        $v0, 0x18($s3)
    /* B9D34 002B9134 3082FFFF */  andi       $v0, $a0, 0xFFFF
  .L002B9138:
    /* B9D38 002B9138 24840001 */  addiu      $a0, $a0, 0x1
    /* B9D3C 002B913C 8E630014 */  lw         $v1, 0x14($s3)
    /* B9D40 002B9140 00021040 */  sll        $v0, $v0, 1
    /* B9D44 002B9144 00431021 */  addu       $v0, $v0, $v1
    /* B9D48 002B9148 A4400000 */  sh         $zero, 0x0($v0)
    /* B9D4C 002B914C 8E63001C */  lw         $v1, 0x1C($s3)
    /* B9D50 002B9150 3082FFFF */  andi       $v0, $a0, 0xFFFF
    /* B9D54 002B9154 0043102B */  sltu       $v0, $v0, $v1
    /* B9D58 002B9158 1440FFF7 */  bnez       $v0, .L002B9138
    /* B9D5C 002B915C 3082FFFF */   andi      $v0, $a0, 0xFFFF
  .L002B9160:
    /* B9D60 002B9160 92620024 */  lbu        $v0, 0x24($s3)
    /* B9D64 002B9164 104000B7 */  beqz       $v0, .L002B9444
    /* B9D68 002B9168 0000A021 */   addu      $s4, $zero, $zero
    /* B9D6C 002B916C 24160001 */  addiu      $s6, $zero, 0x1
    /* B9D70 002B9170 3C01800D */  lui        $at, %hi(D_800CC808)
    /* B9D74 002B9174 D434C808 */  ldc1       $fs0, %lo(D_800CC808)($at)
    /* B9D78 002B9178 3282FFFF */  andi       $v0, $s4, 0xFFFF
  .L002B917C:
    /* B9D7C 002B917C 00021880 */  sll        $v1, $v0, 2
    /* B9D80 002B9180 00621821 */  addu       $v1, $v1, $v0
    /* B9D84 002B9184 000318C0 */  sll        $v1, $v1, 3
    /* B9D88 002B9188 3222FFFF */  andi       $v0, $s1, 0xFFFF
    /* B9D8C 002B918C 00021080 */  sll        $v0, $v0, 2
    /* B9D90 002B9190 00521021 */  addu       $v0, $v0, $s2
    /* B9D94 002B9194 26250001 */  addiu      $a1, $s1, 0x1
    /* B9D98 002B9198 8E640020 */  lw         $a0, 0x20($s3)
    /* B9D9C 002B919C 8C420000 */  lw         $v0, 0x0($v0)
    /* B9DA0 002B91A0 00838021 */  addu       $s0, $a0, $v1
    /* B9DA4 002B91A4 AE020000 */  sw         $v0, 0x0($s0)
    /* B9DA8 002B91A8 30A2FFFF */  andi       $v0, $a1, 0xFFFF
    /* B9DAC 002B91AC 00021080 */  sll        $v0, $v0, 2
    /* B9DB0 002B91B0 00521021 */  addu       $v0, $v0, $s2
    /* B9DB4 002B91B4 8C430000 */  lw         $v1, 0x0($v0)
    /* B9DB8 002B91B8 24A20001 */  addiu      $v0, $a1, 0x1
    /* B9DBC 002B91BC 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* B9DC0 002B91C0 00021080 */  sll        $v0, $v0, 2
    /* B9DC4 002B91C4 00521021 */  addu       $v0, $v0, $s2
    /* B9DC8 002B91C8 AE030004 */  sw         $v1, 0x4($s0)
    /* B9DCC 002B91CC 94430002 */  lhu        $v1, 0x2($v0)
    /* B9DD0 002B91D0 24A20002 */  addiu      $v0, $a1, 0x2
    /* B9DD4 002B91D4 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* B9DD8 002B91D8 00021080 */  sll        $v0, $v0, 2
    /* B9DDC 002B91DC 00521021 */  addu       $v0, $v0, $s2
    /* B9DE0 002B91E0 A603000A */  sh         $v1, 0xA($s0)
    /* B9DE4 002B91E4 94430002 */  lhu        $v1, 0x2($v0)
    /* B9DE8 002B91E8 24A20003 */  addiu      $v0, $a1, 0x3
    /* B9DEC 002B91EC 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* B9DF0 002B91F0 00021080 */  sll        $v0, $v0, 2
    /* B9DF4 002B91F4 00521021 */  addu       $v0, $v0, $s2
    /* B9DF8 002B91F8 A6030008 */  sh         $v1, 0x8($s0)
    /* B9DFC 002B91FC 94420002 */  lhu        $v0, 0x2($v0)
    /* B9E00 002B9200 24A40004 */  addiu      $a0, $a1, 0x4
    /* B9E04 002B9204 A602000C */  sh         $v0, 0xC($s0)
    /* B9E08 002B9208 3082FFFF */  andi       $v0, $a0, 0xFFFF
    /* B9E0C 002B920C 00021080 */  sll        $v0, $v0, 2
    /* B9E10 002B9210 00521021 */  addu       $v0, $v0, $s2
    /* B9E14 002B9214 8C420000 */  lw         $v0, 0x0($v0)
    /* B9E18 002B9218 1040003D */  beqz       $v0, .L002B9310
    /* B9E1C 002B921C 24A30005 */   addiu     $v1, $a1, 0x5
    /* B9E20 002B9220 3082FFFF */  andi       $v0, $a0, 0xFFFF
    /* B9E24 002B9224 00021080 */  sll        $v0, $v0, 2
    /* B9E28 002B9228 00521021 */  addu       $v0, $v0, $s2
    /* B9E2C 002B922C C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* B9E30 002B9230 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* B9E34 002B9234 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* B9E38 002B9238 3C01800D */  lui        $at, %hi(D_800CC810)
    /* B9E3C 002B923C C420C810 */  lwc1       $fv0, %lo(D_800CC810)($at)
    /* B9E40 002B9240 00031880 */  sll        $v1, $v1, 2
    /* B9E44 002B9244 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* B9E48 002B9248 8E040004 */  lw         $a0, 0x4($s0)
    /* B9E4C 002B924C 8E020000 */  lw         $v0, 0x0($s0)
    /* B9E50 002B9250 00721821 */  addu       $v1, $v1, $s2
    /* B9E54 002B9254 00822023 */  subu       $a0, $a0, $v0
    /* B9E58 002B9258 46010840 */  add.s      $fv0f, $fv0f, $fv0f
    /* B9E5C 002B925C 44841000 */  mtc1       $a0, $fv1
    /* B9E60 002B9260 468010A1 */  cvt.d.w    $fv1, $fv1
    /* B9E64 002B9264 C6E00018 */  lwc1       $fv0, 0x18($s7)
    /* B9E68 002B9268 46800020 */  cvt.s.w    $fv0, $fv0
    /* B9E6C 002B926C 46000843 */  div.s      $fv0f, $fv0f, $fv0
    /* B9E70 002B9270 E6010010 */  swc1       $fv0f, 0x10($s0)
    /* B9E74 002B9274 C4630000 */  lwc1       $fv1f, 0x0($v1)
    /* B9E78 002B9278 468018E0 */  cvt.s.w    $fv1f, $fv1f
    /* B9E7C 002B927C 04810004 */  bgez       $a0, .L002B9290
    /* B9E80 002B9280 24B10006 */   addiu     $s1, $a1, 0x6
    /* B9E84 002B9284 3C01800D */  lui        $at, %hi(D_800CC818)
    /* B9E88 002B9288 D420C818 */  ldc1       $fv0, %lo(D_800CC818)($at)
    /* B9E8C 002B928C 46201080 */  add.d      $fv1, $fv1, $fv0
  .L002B9290:
    /* B9E90 002B9290 3C01800D */  lui        $at, %hi(D_800CC820)
    /* B9E94 002B9294 C420C820 */  lwc1       $fv0, %lo(D_800CC820)($at)
    /* B9E98 002B9298 46201060 */  cvt.s.d    $fv0f, $fv1
    /* B9E9C 002B929C 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* B9EA0 002B92A0 00002021 */  addu       $a0, $zero, $zero
    /* B9EA4 002B92A4 00802821 */  addu       $a1, $a0, $zero
    /* B9EA8 002B92A8 02A03021 */  addu       $a2, $s5, $zero
    /* B9EAC 002B92AC 24070001 */  addiu      $a3, $zero, 0x1
    /* B9EB0 002B92B0 46011842 */  mul.s      $fv0f, $fv1f, $fv0f
    /* B9EB4 002B92B4 3C01800D */  lui        $at, %hi(D_800CC824)
    /* B9EB8 002B92B8 C420C824 */  lwc1       $fv0, %lo(D_800CC824)($at)
    /* B9EBC 002B92BC 24020034 */  addiu      $v0, $zero, 0x34
    /* B9EC0 002B92C0 AE000018 */  sw         $zero, 0x18($s0)
    /* B9EC4 002B92C4 E6000014 */  swc1       $fv0, 0x14($s0)
    /* B9EC8 002B92C8 E601001C */  swc1       $fv0f, 0x1C($s0)
    /* B9ECC 002B92CC 0C0AD504 */  jal        alHeapDBAlloc
    /* B9ED0 002B92D0 AFA20010 */   sw        $v0, 0x10($sp)
    /* B9ED4 002B92D4 00002021 */  addu       $a0, $zero, $zero
    /* B9ED8 002B92D8 00802821 */  addu       $a1, $a0, $zero
    /* B9EDC 002B92DC 02A03021 */  addu       $a2, $s5, $zero
    /* B9EE0 002B92E0 24070001 */  addiu      $a3, $zero, 0x1
    /* B9EE4 002B92E4 AE020024 */  sw         $v0, 0x24($s0)
    /* B9EE8 002B92E8 24020020 */  addiu      $v0, $zero, 0x20
    /* B9EEC 002B92EC 0C0AD504 */  jal        alHeapDBAlloc
    /* B9EF0 002B92F0 AFA20010 */   sw        $v0, 0x10($sp)
    /* B9EF4 002B92F4 8E030024 */  lw         $v1, 0x24($s0)
    /* B9EF8 002B92F8 AC620014 */  sw         $v0, 0x14($v1)
    /* B9EFC 002B92FC 8E020024 */  lw         $v0, 0x24($s0)
    /* B9F00 002B9300 AC400020 */  sw         $zero, 0x20($v0)
    /* B9F04 002B9304 8E020024 */  lw         $v0, 0x24($s0)
    /* B9F08 002B9308 080AE4C6 */  j          .L002B9318
    /* B9F0C 002B930C AC560024 */   sw        $s6, 0x24($v0)
  .L002B9310:
    /* B9F10 002B9310 AE000024 */  sw         $zero, 0x24($s0)
    /* B9F14 002B9314 24B10006 */  addiu      $s1, $a1, 0x6
  .L002B9318:
    /* B9F18 002B9318 3222FFFF */  andi       $v0, $s1, 0xFFFF
    /* B9F1C 002B931C 00021080 */  sll        $v0, $v0, 2
    /* B9F20 002B9320 00521021 */  addu       $v0, $v0, $s2
    /* B9F24 002B9324 8C420000 */  lw         $v0, 0x0($v0)
    /* B9F28 002B9328 1040003E */  beqz       $v0, .L002B9424
    /* B9F2C 002B932C 00002021 */   addu      $a0, $zero, $zero
    /* B9F30 002B9330 00802821 */  addu       $a1, $a0, $zero
    /* B9F34 002B9334 02A03021 */  addu       $a2, $s5, $zero
    /* B9F38 002B9338 24070001 */  addiu      $a3, $zero, 0x1
    /* B9F3C 002B933C 24020030 */  addiu      $v0, $zero, 0x30
    /* B9F40 002B9340 0C0AD504 */  jal        alHeapDBAlloc
    /* B9F44 002B9344 AFA20010 */   sw        $v0, 0x10($sp)
    /* B9F48 002B9348 00002021 */  addu       $a0, $zero, $zero
    /* B9F4C 002B934C 00802821 */  addu       $a1, $a0, $zero
    /* B9F50 002B9350 02A03021 */  addu       $a2, $s5, $zero
    /* B9F54 002B9354 24070001 */  addiu      $a3, $zero, 0x1
    /* B9F58 002B9358 AE020020 */  sw         $v0, 0x20($s0)
    /* B9F5C 002B935C 24020008 */  addiu      $v0, $zero, 0x8
    /* B9F60 002B9360 0C0AD504 */  jal        alHeapDBAlloc
    /* B9F64 002B9364 AFA20010 */   sw        $v0, 0x10($sp)
    /* B9F68 002B9368 8E030020 */  lw         $v1, 0x20($s0)
    /* B9F6C 002B936C 24050007 */  addiu      $a1, $zero, 0x7
    /* B9F70 002B9370 AC620028 */  sw         $v0, 0x28($v1)
    /* B9F74 002B9374 02201021 */  addu       $v0, $s1, $zero
    /* B9F78 002B9378 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* B9F7C 002B937C 00021080 */  sll        $v0, $v0, 2
    /* B9F80 002B9380 00521021 */  addu       $v0, $v0, $s2
    /* B9F84 002B9384 8E030020 */  lw         $v1, 0x20($s0)
    /* B9F88 002B9388 94420002 */  lhu        $v0, 0x2($v0)
    /* B9F8C 002B938C 26310001 */  addiu      $s1, $s1, 0x1
    /* B9F90 002B9390 A4620000 */  sh         $v0, 0x0($v1)
    /* B9F94 002B9394 8E040020 */  lw         $a0, 0x20($s0)
    /* B9F98 002B9398 24024000 */  addiu      $v0, $zero, 0x4000
    /* B9F9C 002B939C 84830000 */  lh         $v1, 0x0($a0)
    /* B9FA0 002B93A0 2486000E */  addiu      $a2, $a0, 0xE
    /* B9FA4 002B93A4 AC96002C */  sw         $s6, 0x2C($a0)
    /* B9FA8 002B93A8 00031843 */  sra        $v1, $v1, 1
    /* B9FAC 002B93AC 00603821 */  addu       $a3, $v1, $zero
    /* B9FB0 002B93B0 00431023 */  subu       $v0, $v0, $v1
    /* B9FB4 002B93B4 A4820002 */  sh         $v0, 0x2($a0)
  .L002B93B8:
    /* B9FB8 002B93B8 A4C00008 */  sh         $zero, 0x8($a2)
    /* B9FBC 002B93BC 24A5FFFF */  addiu      $a1, $a1, -0x1
    /* B9FC0 002B93C0 04A1FFFD */  bgez       $a1, .L002B93B8
    /* B9FC4 002B93C4 24C6FFFE */   addiu     $a2, $a2, -0x2
    /* B9FC8 002B93C8 00071400 */  sll        $v0, $a3, 16
    /* B9FCC 002B93CC 00021403 */  sra        $v0, $v0, 16
    /* B9FD0 002B93D0 3C01800D */  lui        $at, %hi(D_800CC828)
    /* B9FD4 002B93D4 D421C828 */  ldc1       $fv0f, %lo(D_800CC828)($at)
    /* B9FD8 002B93D8 44820000 */  mtc1       $v0, $fv0
    /* B9FDC 002B93DC 46800021 */  cvt.d.w    $fv0, $fv0
    /* B9FE0 002B93E0 46210042 */  mul.d      $fv0f, $fv0, $fv0f
    /* B9FE4 002B93E4 24050009 */  addiu      $a1, $zero, 0x9
    /* B9FE8 002B93E8 24830012 */  addiu      $v1, $a0, 0x12
    /* B9FEC 002B93EC A4870018 */  sh         $a3, 0x18($a0)
    /* B9FF0 002B93F0 46200886 */  mov.d      $fv1, $fv0f
  .L002B93F4:
    /* B9FF4 002B93F4 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B9FF8 002B93F8 00000000 */  nop
    /* B9FFC 002B93FC 46340802 */  mul.d      $fv0, $fv0f, $fs0
    /* BA000 002B9400 24A50001 */  addiu      $a1, $a1, 0x1
    /* BA004 002B9404 4620010D */  trunc.w.d  $ft0, $fv0
    /* BA008 002B9408 44022000 */  mfc1       $v0, $ft0
    /* BA00C 002B940C A4620008 */  sh         $v0, 0x8($v1)
    /* BA010 002B9410 28A20010 */  slti       $v0, $a1, 0x10
    /* BA014 002B9414 1440FFF7 */  bnez       $v0, .L002B93F4
    /* BA018 002B9418 24630002 */   addiu     $v1, $v1, 0x2
    /* BA01C 002B941C 080AE50C */  j          .L002B9430
    /* BA020 002B9420 26940001 */   addiu     $s4, $s4, 0x1
  .L002B9424:
    /* BA024 002B9424 AE000020 */  sw         $zero, 0x20($s0)
    /* BA028 002B9428 26310001 */  addiu      $s1, $s1, 0x1
    /* BA02C 002B942C 26940001 */  addiu      $s4, $s4, 0x1
  .L002B9430:
    /* BA030 002B9430 92630024 */  lbu        $v1, 0x24($s3)
    /* BA034 002B9434 3282FFFF */  andi       $v0, $s4, 0xFFFF
    /* BA038 002B9438 0043102B */  sltu       $v0, $v0, $v1
    /* BA03C 002B943C 1440FF4F */  bnez       $v0, .L002B917C
    /* BA040 002B9440 3282FFFF */   andi      $v0, $s4, 0xFFFF
  .L002B9444:
    /* BA044 002B9444 8FBF0038 */  lw         $ra, 0x38($sp)
    /* BA048 002B9448 8FB70034 */  lw         $s7, 0x34($sp)
    /* BA04C 002B944C 8FB60030 */  lw         $s6, 0x30($sp)
    /* BA050 002B9450 8FB5002C */  lw         $s5, 0x2C($sp)
    /* BA054 002B9454 8FB40028 */  lw         $s4, 0x28($sp)
    /* BA058 002B9458 8FB30024 */  lw         $s3, 0x24($sp)
    /* BA05C 002B945C 8FB20020 */  lw         $s2, 0x20($sp)
    /* BA060 002B9460 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BA064 002B9464 8FB00018 */  lw         $s0, 0x18($sp)
    /* BA068 002B9468 D7B40040 */  ldc1       $fs0, 0x40($sp)
    /* BA06C 002B946C 03E00008 */  jr         $ra
    /* BA070 002B9470 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel alFxNew
