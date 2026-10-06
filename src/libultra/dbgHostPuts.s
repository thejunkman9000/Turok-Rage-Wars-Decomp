.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB1F08-0xB2154 (VRAM 0x002B1308) */
glabel dbgHostPuts
    /* B1F08 002B1308 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B1F0C 002B130C AFB5002C */  sw         $s5, 0x2C($sp)
    /* B1F10 002B1310 0080A821 */  addu       $s5, $a0, $zero
    /* B1F14 002B1314 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1F18 002B1318 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1F1C 002B131C 24030064 */  addiu      $v1, $zero, 0x64
    /* B1F20 002B1320 AFBF0030 */  sw         $ra, 0x30($sp)
    /* B1F24 002B1324 AFB40028 */  sw         $s4, 0x28($sp)
    /* B1F28 002B1328 AFB30024 */  sw         $s3, 0x24($sp)
    /* B1F2C 002B132C AFB20020 */  sw         $s2, 0x20($sp)
    /* B1F30 002B1330 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B1F34 002B1334 AFB00018 */  sw         $s0, 0x18($sp)
    /* B1F38 002B1338 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1F3C 002B133C AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B1F40 002B1340 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1F44 002B1344 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B1F48 002B1348 34420004 */  ori        $v0, $v0, 0x4
    /* B1F4C 002B134C 00409021 */  addu       $s2, $v0, $zero
    /* B1F50 002B1350 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1F54 002B1354 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1358:
    /* B1F58 002B1358 0C0AF7A8 */  jal        osPiGetStatus
    /* B1F5C 002B135C 00000000 */   nop
    /* B1F60 002B1360 30420003 */  andi       $v0, $v0, 0x3
    /* B1F64 002B1364 1440FFFC */  bnez       $v0, .L002B1358
    /* B1F68 002B1368 24140002 */   addiu     $s4, $zero, 0x2
    /* B1F6C 002B136C 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B1F70 002B1370 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1F74 002B1374 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1F78 002B1378 24130002 */  addiu      $s3, $zero, 0x2
    /* B1F7C 002B137C 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1F80 002B1380 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B1384:
    /* B1F84 002B1384 0C0AF7A8 */  jal        osPiGetStatus
    /* B1F88 002B1388 00000000 */   nop
    /* B1F8C 002B138C 30420003 */  andi       $v0, $v0, 0x3
    /* B1F90 002B1390 1440FFFC */  bnez       $v0, .L002B1384
    /* B1F94 002B1394 00000000 */   nop
    /* B1F98 002B1398 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B1F9C 002B139C 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B1FA0 002B13A0 00541024 */  and        $v0, $v0, $s4
    /* B1FA4 002B13A4 10530009 */  beq        $v0, $s3, .L002B13CC
    /* B1FA8 002B13A8 02001021 */   addu      $v0, $s0, $zero
    /* B1FAC 002B13AC 14400003 */  bnez       $v0, .L002B13BC
    /* B1FB0 002B13B0 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B1FB4 002B13B4 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1FB8 002B13B8 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B13BC:
    /* B1FBC 002B13BC 1E20FFF1 */  bgtz       $s1, .L002B1384
    /* B1FC0 002B13C0 24020001 */   addiu     $v0, $zero, 0x1
    /* B1FC4 002B13C4 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1FC8 002B13C8 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B13CC:
    /* B1FCC 002B13CC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1FD0 002B13D0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1FD4 002B13D4 14400046 */  bnez       $v0, .L002B14F0
    /* B1FD8 002B13D8 00000000 */   nop
    /* B1FDC 002B13DC 0C0AB96B */  jal        dbgLinkSendByte
    /* B1FE0 002B13E0 24040010 */   addiu     $a0, $zero, 0x10
    /* B1FE4 002B13E4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1FE8 002B13E8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1FEC 002B13EC 1440000A */  bnez       $v0, .L002B1418
    /* B1FF0 002B13F0 00008021 */   addu      $s0, $zero, $zero
    /* B1FF4 002B13F4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1FF8 002B13F8 27A40010 */   addiu     $a0, $sp, 0x10
    /* B1FFC 002B13FC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2000 002B1400 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2004 002B1404 14400004 */  bnez       $v0, .L002B1418
    /* B2008 002B1408 00000000 */   nop
    /* B200C 002B140C 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2010 002B1410 38420011 */  xori       $v0, $v0, 0x11
    /* B2014 002B1414 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B1418:
    /* B2018 002B1418 12000035 */  beqz       $s0, .L002B14F0
    /* B201C 002B141C 00000000 */   nop
    /* B2020 002B1420 0C0AB96B */  jal        dbgLinkSendByte
    /* B2024 002B1424 240400C1 */   addiu     $a0, $zero, 0xC1
    /* B2028 002B1428 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B202C 002B142C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2030 002B1430 1440002F */  bnez       $v0, .L002B14F0
    /* B2034 002B1434 00000000 */   nop
    /* B2038 002B1438 02A08821 */  addu       $s1, $s5, $zero
  .L002B143C:
    /* B203C 002B143C 92220000 */  lbu        $v0, 0x0($s1)
    /* B2040 002B1440 305000FF */  andi       $s0, $v0, 0xFF
    /* B2044 002B1444 0C0AB96B */  jal        dbgLinkSendByte
    /* B2048 002B1448 02002021 */   addu      $a0, $s0, $zero
    /* B204C 002B144C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2050 002B1450 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2054 002B1454 14400026 */  bnez       $v0, .L002B14F0
    /* B2058 002B1458 26310001 */   addiu     $s1, $s1, 0x1
    /* B205C 002B145C 1600FFF7 */  bnez       $s0, .L002B143C
    /* B2060 002B1460 00000000 */   nop
    /* B2064 002B1464 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B2068 002B1468 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B206C 002B146C 304200FB */  andi       $v0, $v0, 0xFB
    /* B2070 002B1470 00409021 */  addu       $s2, $v0, $zero
    /* B2074 002B1474 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B2078 002B1478 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B147C:
    /* B207C 002B147C 0C0AF7A8 */  jal        osPiGetStatus
    /* B2080 002B1480 00000000 */   nop
    /* B2084 002B1484 30420003 */  andi       $v0, $v0, 0x3
    /* B2088 002B1488 1440FFFC */  bnez       $v0, .L002B147C
    /* B208C 002B148C 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* B2090 002B1490 24140002 */  addiu      $s4, $zero, 0x2
    /* B2094 002B1494 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B2098 002B1498 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B209C 002B149C 00009821 */  addu       $s3, $zero, $zero
    /* B20A0 002B14A0 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B20A4 002B14A4 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B14A8:
    /* B20A8 002B14A8 0C0AF7A8 */  jal        osPiGetStatus
    /* B20AC 002B14AC 00000000 */   nop
    /* B20B0 002B14B0 30420003 */  andi       $v0, $v0, 0x3
    /* B20B4 002B14B4 1440FFFC */  bnez       $v0, .L002B14A8
    /* B20B8 002B14B8 00000000 */   nop
    /* B20BC 002B14BC 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B20C0 002B14C0 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B20C4 002B14C4 00541024 */  and        $v0, $v0, $s4
    /* B20C8 002B14C8 10530009 */  beq        $v0, $s3, .L002B14F0
    /* B20CC 002B14CC 02001021 */   addu      $v0, $s0, $zero
    /* B20D0 002B14D0 14400003 */  bnez       $v0, .L002B14E0
    /* B20D4 002B14D4 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B20D8 002B14D8 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B20DC 002B14DC 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B14E0:
    /* B20E0 002B14E0 1E20FFF1 */  bgtz       $s1, .L002B14A8
    /* B20E4 002B14E4 24020001 */   addiu     $v0, $zero, 0x1
    /* B20E8 002B14E8 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B20EC 002B14EC AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B14F0:
    /* B20F0 002B14F0 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B20F4 002B14F4 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B20F8 002B14F8 304200FB */  andi       $v0, $v0, 0xFB
    /* B20FC 002B14FC 00408021 */  addu       $s0, $v0, $zero
    /* B2100 002B1500 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B2104 002B1504 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1508:
    /* B2108 002B1508 0C0AF7A8 */  jal        osPiGetStatus
    /* B210C 002B150C 00000000 */   nop
    /* B2110 002B1510 30420003 */  andi       $v0, $v0, 0x3
    /* B2114 002B1514 1440FFFC */  bnez       $v0, .L002B1508
    /* B2118 002B1518 00001021 */   addu      $v0, $zero, $zero
    /* B211C 002B151C 8FBF0030 */  lw         $ra, 0x30($sp)
    /* B2120 002B1520 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B2124 002B1524 8FB40028 */  lw         $s4, 0x28($sp)
    /* B2128 002B1528 8FB30024 */  lw         $s3, 0x24($sp)
    /* B212C 002B152C 8FB20020 */  lw         $s2, 0x20($sp)
    /* B2130 002B1530 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B2134 002B1534 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B2138 002B1538 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B213C 002B153C 8FB00018 */  lw         $s0, 0x18($sp)
    /* B2140 002B1540 24030001 */  addiu      $v1, $zero, 0x1
    /* B2144 002B1544 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B2148 002B1548 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B214C 002B154C 03E00008 */  jr         $ra
    /* B2150 002B1550 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel dbgHostPuts
