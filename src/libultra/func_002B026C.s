.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB0E6C-0xB11C8 (VRAM 0x002B026C) */
glabel func_002B026C
    /* B0E6C 002B026C 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B0E70 002B0270 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0E74 002B0274 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B0E78 002B0278 AFBE0038 */  sw         $fp, 0x38($sp)
    /* B0E7C 002B027C 00A0F021 */  addu       $fp, $a1, $zero
    /* B0E80 002B0280 AFB70034 */  sw         $s7, 0x34($sp)
    /* B0E84 002B0284 00C0B821 */  addu       $s7, $a2, $zero
    /* B0E88 002B0288 AFB60030 */  sw         $s6, 0x30($sp)
    /* B0E8C 002B028C 00E0B021 */  addu       $s6, $a3, $zero
    /* B0E90 002B0290 AFB20020 */  sw         $s2, 0x20($sp)
    /* B0E94 002B0294 24120064 */  addiu      $s2, $zero, 0x64
    /* B0E98 002B0298 AFBF003C */  sw         $ra, 0x3C($sp)
    /* B0E9C 002B029C AFB5002C */  sw         $s5, 0x2C($sp)
    /* B0EA0 002B02A0 AFB40028 */  sw         $s4, 0x28($sp)
    /* B0EA4 002B02A4 AFB30024 */  sw         $s3, 0x24($sp)
    /* B0EA8 002B02A8 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B0EAC 002B02AC AFB00018 */  sw         $s0, 0x18($sp)
    /* B0EB0 002B02B0 AFA40040 */  sw         $a0, 0x40($sp)
    /* B0EB4 002B02B4 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0EB8 002B02B8 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B0EBC 002B02BC 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B0EC0 002B02C0 AC323650 */  sw         $s2, %lo(D_800D3650)($at)
    /* B0EC4 002B02C4 34420004 */  ori        $v0, $v0, 0x4
    /* B0EC8 002B02C8 00409821 */  addu       $s3, $v0, $zero
    /* B0ECC 002B02CC 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B0ED0 002B02D0 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B02D4:
    /* B0ED4 002B02D4 0C0AF7A8 */  jal        osPiGetStatus
    /* B0ED8 002B02D8 00000000 */   nop
    /* B0EDC 002B02DC 30420003 */  andi       $v0, $v0, 0x3
    /* B0EE0 002B02E0 1440FFFC */  bnez       $v0, .L002B02D4
    /* B0EE4 002B02E4 24150002 */   addiu     $s5, $zero, 0x2
    /* B0EE8 002B02E8 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B0EEC 002B02EC 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B0EF0 002B02F0 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B0EF4 002B02F4 24140002 */  addiu      $s4, $zero, 0x2
    /* B0EF8 002B02F8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0EFC 002B02FC A4330004 */  sh         $s3, %lo(D_B2000004)($at)
  .L002B0300:
    /* B0F00 002B0300 0C0AF7A8 */  jal        osPiGetStatus
    /* B0F04 002B0304 00000000 */   nop
    /* B0F08 002B0308 30420003 */  andi       $v0, $v0, 0x3
    /* B0F0C 002B030C 1440FFFC */  bnez       $v0, .L002B0300
    /* B0F10 002B0310 00000000 */   nop
    /* B0F14 002B0314 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B0F18 002B0318 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B0F1C 002B031C 00551024 */  and        $v0, $v0, $s5
    /* B0F20 002B0320 10540009 */  beq        $v0, $s4, .L002B0348
    /* B0F24 002B0324 02001021 */   addu      $v0, $s0, $zero
    /* B0F28 002B0328 14400003 */  bnez       $v0, .L002B0338
    /* B0F2C 002B032C 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B0F30 002B0330 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B0F34 002B0334 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B0338:
    /* B0F38 002B0338 1E20FFF1 */  bgtz       $s1, .L002B0300
    /* B0F3C 002B033C 24020001 */   addiu     $v0, $zero, 0x1
    /* B0F40 002B0340 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0F44 002B0344 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B0348:
    /* B0F48 002B0348 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0F4C 002B034C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0F50 002B0350 14400081 */  bnez       $v0, .L002B0558
    /* B0F54 002B0354 00000000 */   nop
    /* B0F58 002B0358 0C0AB96B */  jal        func_002AE5AC
    /* B0F5C 002B035C 24040010 */   addiu     $a0, $zero, 0x10
    /* B0F60 002B0360 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0F64 002B0364 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0F68 002B0368 1440000A */  bnez       $v0, .L002B0394
    /* B0F6C 002B036C 00008021 */   addu      $s0, $zero, $zero
    /* B0F70 002B0370 0C0AB8E0 */  jal        func_002AE380
    /* B0F74 002B0374 27A40010 */   addiu     $a0, $sp, 0x10
    /* B0F78 002B0378 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0F7C 002B037C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0F80 002B0380 14400004 */  bnez       $v0, .L002B0394
    /* B0F84 002B0384 00000000 */   nop
    /* B0F88 002B0388 93A20010 */  lbu        $v0, 0x10($sp)
    /* B0F8C 002B038C 38420011 */  xori       $v0, $v0, 0x11
    /* B0F90 002B0390 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B0394:
    /* B0F94 002B0394 12000070 */  beqz       $s0, .L002B0558
    /* B0F98 002B0398 00000000 */   nop
    /* B0F9C 002B039C 0C0AB96B */  jal        func_002AE5AC
    /* B0FA0 002B03A0 24040082 */   addiu     $a0, $zero, 0x82
    /* B0FA4 002B03A4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0FA8 002B03A8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0FAC 002B03AC 1440006A */  bnez       $v0, .L002B0558
    /* B0FB0 002B03B0 00000000 */   nop
    /* B0FB4 002B03B4 0C0AB96B */  jal        func_002AE5AC
    /* B0FB8 002B03B8 00162602 */   srl       $a0, $s6, 24
    /* B0FBC 002B03BC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0FC0 002B03C0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0FC4 002B03C4 14400064 */  bnez       $v0, .L002B0558
    /* B0FC8 002B03C8 00162402 */   srl       $a0, $s6, 16
    /* B0FCC 002B03CC 0C0AB96B */  jal        func_002AE5AC
    /* B0FD0 002B03D0 308400FF */   andi      $a0, $a0, 0xFF
    /* B0FD4 002B03D4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0FD8 002B03D8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0FDC 002B03DC 1440005E */  bnez       $v0, .L002B0558
    /* B0FE0 002B03E0 00162202 */   srl       $a0, $s6, 8
    /* B0FE4 002B03E4 0C0AB96B */  jal        func_002AE5AC
    /* B0FE8 002B03E8 308400FF */   andi      $a0, $a0, 0xFF
    /* B0FEC 002B03EC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0FF0 002B03F0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0FF4 002B03F4 14400058 */  bnez       $v0, .L002B0558
    /* B0FF8 002B03F8 00000000 */   nop
    /* B0FFC 002B03FC 0C0AB96B */  jal        func_002AE5AC
    /* B1000 002B0400 32C400FF */   andi      $a0, $s6, 0xFF
    /* B1004 002B0404 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1008 002B0408 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B100C 002B040C 03D70018 */  mult       $fp, $s7
    /* B1010 002B0410 14400051 */  bnez       $v0, .L002B0558
    /* B1014 002B0414 00000000 */   nop
    /* B1018 002B0418 00008012 */  mflo       $s0
    /* B101C 002B041C 0C0AB96B */  jal        func_002AE5AC
    /* B1020 002B0420 00102602 */   srl       $a0, $s0, 24
    /* B1024 002B0424 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1028 002B0428 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B102C 002B042C 1440004A */  bnez       $v0, .L002B0558
    /* B1030 002B0430 00102402 */   srl       $a0, $s0, 16
    /* B1034 002B0434 0C0AB96B */  jal        func_002AE5AC
    /* B1038 002B0438 308400FF */   andi      $a0, $a0, 0xFF
    /* B103C 002B043C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1040 002B0440 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1044 002B0444 14400044 */  bnez       $v0, .L002B0558
    /* B1048 002B0448 00102202 */   srl       $a0, $s0, 8
    /* B104C 002B044C 0C0AB96B */  jal        func_002AE5AC
    /* B1050 002B0450 308400FF */   andi      $a0, $a0, 0xFF
    /* B1054 002B0454 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1058 002B0458 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B105C 002B045C 1440003E */  bnez       $v0, .L002B0558
    /* B1060 002B0460 00000000 */   nop
    /* B1064 002B0464 0C0AB96B */  jal        func_002AE5AC
    /* B1068 002B0468 320400FF */   andi      $a0, $s0, 0xFF
    /* B106C 002B046C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1070 002B0470 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1074 002B0474 14400038 */  bnez       $v0, .L002B0558
    /* B1078 002B0478 00000000 */   nop
  .L002B047C:
    /* B107C 002B047C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1080 002B0480 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B1084 002B0484 0C0AB8E0 */  jal        func_002AE380
    /* B1088 002B0488 27A40011 */   addiu     $a0, $sp, 0x11
    /* B108C 002B048C 02401021 */  addu       $v0, $s2, $zero
    /* B1090 002B0490 18400005 */  blez       $v0, .L002B04A8
    /* B1094 002B0494 2652FFFF */   addiu     $s2, $s2, -0x1
    /* B1098 002B0498 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B109C 002B049C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B10A0 002B04A0 1440FFF6 */  bnez       $v0, .L002B047C
    /* B10A4 002B04A4 00000000 */   nop
  .L002B04A8:
    /* B10A8 002B04A8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B10AC 002B04AC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B10B0 002B04B0 03D70018 */  mult       $fp, $s7
    /* B10B4 002B04B4 14400028 */  bnez       $v0, .L002B0558
    /* B10B8 002B04B8 00000000 */   nop
    /* B10BC 002B04BC 8FA40040 */  lw         $a0, 0x40($sp)
    /* B10C0 002B04C0 00002812 */  mflo       $a1
    /* B10C4 002B04C4 0C0ABA0D */  jal        func_002AE834
    /* B10C8 002B04C8 27A60014 */   addiu     $a2, $sp, 0x14
    /* B10CC 002B04CC 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B10D0 002B04D0 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B10D4 002B04D4 304200FB */  andi       $v0, $v0, 0xFB
    /* B10D8 002B04D8 00409021 */  addu       $s2, $v0, $zero
    /* B10DC 002B04DC 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B10E0 002B04E0 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B04E4:
    /* B10E4 002B04E4 0C0AF7A8 */  jal        osPiGetStatus
    /* B10E8 002B04E8 00000000 */   nop
    /* B10EC 002B04EC 30420003 */  andi       $v0, $v0, 0x3
    /* B10F0 002B04F0 1440FFFC */  bnez       $v0, .L002B04E4
    /* B10F4 002B04F4 00009821 */   addu      $s3, $zero, $zero
    /* B10F8 002B04F8 24140002 */  addiu      $s4, $zero, 0x2
    /* B10FC 002B04FC 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B1100 002B0500 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1104 002B0504 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1108 002B0508 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B110C 002B050C A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B0510:
    /* B1110 002B0510 0C0AF7A8 */  jal        osPiGetStatus
    /* B1114 002B0514 00000000 */   nop
    /* B1118 002B0518 30420003 */  andi       $v0, $v0, 0x3
    /* B111C 002B051C 1440FFFC */  bnez       $v0, .L002B0510
    /* B1120 002B0520 00000000 */   nop
    /* B1124 002B0524 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B1128 002B0528 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B112C 002B052C 00541024 */  and        $v0, $v0, $s4
    /* B1130 002B0530 10530009 */  beq        $v0, $s3, .L002B0558
    /* B1134 002B0534 02001021 */   addu      $v0, $s0, $zero
    /* B1138 002B0538 14400003 */  bnez       $v0, .L002B0548
    /* B113C 002B053C 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B1140 002B0540 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1144 002B0544 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B0548:
    /* B1148 002B0548 1E20FFF1 */  bgtz       $s1, .L002B0510
    /* B114C 002B054C 24020001 */   addiu     $v0, $zero, 0x1
    /* B1150 002B0550 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1154 002B0554 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B0558:
    /* B1158 002B0558 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B115C 002B055C 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1160 002B0560 304200FB */  andi       $v0, $v0, 0xFB
    /* B1164 002B0564 00408021 */  addu       $s0, $v0, $zero
    /* B1168 002B0568 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B116C 002B056C A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0570:
    /* B1170 002B0570 0C0AF7A8 */  jal        osPiGetStatus
    /* B1174 002B0574 00000000 */   nop
    /* B1178 002B0578 30420003 */  andi       $v0, $v0, 0x3
    /* B117C 002B057C 1440FFFC */  bnez       $v0, .L002B0570
    /* B1180 002B0580 02E01021 */   addu      $v0, $s7, $zero
    /* B1184 002B0584 8FBF003C */  lw         $ra, 0x3C($sp)
    /* B1188 002B0588 8FBE0038 */  lw         $fp, 0x38($sp)
    /* B118C 002B058C 8FB70034 */  lw         $s7, 0x34($sp)
    /* B1190 002B0590 8FB60030 */  lw         $s6, 0x30($sp)
    /* B1194 002B0594 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B1198 002B0598 8FB40028 */  lw         $s4, 0x28($sp)
    /* B119C 002B059C 8FB30024 */  lw         $s3, 0x24($sp)
    /* B11A0 002B05A0 8FB20020 */  lw         $s2, 0x20($sp)
    /* B11A4 002B05A4 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B11A8 002B05A8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B11AC 002B05AC A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B11B0 002B05B0 8FB00018 */  lw         $s0, 0x18($sp)
    /* B11B4 002B05B4 24030001 */  addiu      $v1, $zero, 0x1
    /* B11B8 002B05B8 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B11BC 002B05BC AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B11C0 002B05C0 03E00008 */  jr         $ra
    /* B11C4 002B05C4 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel func_002B026C
