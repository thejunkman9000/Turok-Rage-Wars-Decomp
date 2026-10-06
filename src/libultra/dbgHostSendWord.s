.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB1C88-0xB1F08 (VRAM 0x002B1088) */
glabel dbgHostSendWord
    /* B1C88 002B1088 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B1C8C 002B108C AFB5002C */  sw         $s5, 0x2C($sp)
    /* B1C90 002B1090 0080A821 */  addu       $s5, $a0, $zero
    /* B1C94 002B1094 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1C98 002B1098 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1C9C 002B109C 24030064 */  addiu      $v1, $zero, 0x64
    /* B1CA0 002B10A0 AFBF0030 */  sw         $ra, 0x30($sp)
    /* B1CA4 002B10A4 AFB40028 */  sw         $s4, 0x28($sp)
    /* B1CA8 002B10A8 AFB30024 */  sw         $s3, 0x24($sp)
    /* B1CAC 002B10AC AFB20020 */  sw         $s2, 0x20($sp)
    /* B1CB0 002B10B0 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B1CB4 002B10B4 AFB00018 */  sw         $s0, 0x18($sp)
    /* B1CB8 002B10B8 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1CBC 002B10BC AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B1CC0 002B10C0 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1CC4 002B10C4 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B1CC8 002B10C8 34420004 */  ori        $v0, $v0, 0x4
    /* B1CCC 002B10CC 00409021 */  addu       $s2, $v0, $zero
    /* B1CD0 002B10D0 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1CD4 002B10D4 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B10D8:
    /* B1CD8 002B10D8 0C0AF7A8 */  jal        osPiGetStatus
    /* B1CDC 002B10DC 00000000 */   nop
    /* B1CE0 002B10E0 30420003 */  andi       $v0, $v0, 0x3
    /* B1CE4 002B10E4 1440FFFC */  bnez       $v0, .L002B10D8
    /* B1CE8 002B10E8 24140002 */   addiu     $s4, $zero, 0x2
    /* B1CEC 002B10EC 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B1CF0 002B10F0 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1CF4 002B10F4 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1CF8 002B10F8 24130002 */  addiu      $s3, $zero, 0x2
    /* B1CFC 002B10FC 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1D00 002B1100 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B1104:
    /* B1D04 002B1104 0C0AF7A8 */  jal        osPiGetStatus
    /* B1D08 002B1108 00000000 */   nop
    /* B1D0C 002B110C 30420003 */  andi       $v0, $v0, 0x3
    /* B1D10 002B1110 1440FFFC */  bnez       $v0, .L002B1104
    /* B1D14 002B1114 00000000 */   nop
    /* B1D18 002B1118 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B1D1C 002B111C 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B1D20 002B1120 00541024 */  and        $v0, $v0, $s4
    /* B1D24 002B1124 10530009 */  beq        $v0, $s3, .L002B114C
    /* B1D28 002B1128 02001021 */   addu      $v0, $s0, $zero
    /* B1D2C 002B112C 14400003 */  bnez       $v0, .L002B113C
    /* B1D30 002B1130 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B1D34 002B1134 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1D38 002B1138 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B113C:
    /* B1D3C 002B113C 1E20FFF1 */  bgtz       $s1, .L002B1104
    /* B1D40 002B1140 24020001 */   addiu     $v0, $zero, 0x1
    /* B1D44 002B1144 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1D48 002B1148 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B114C:
    /* B1D4C 002B114C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1D50 002B1150 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1D54 002B1154 14400053 */  bnez       $v0, .L002B12A4
    /* B1D58 002B1158 00000000 */   nop
    /* B1D5C 002B115C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1D60 002B1160 24040010 */   addiu     $a0, $zero, 0x10
    /* B1D64 002B1164 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1D68 002B1168 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1D6C 002B116C 1440000A */  bnez       $v0, .L002B1198
    /* B1D70 002B1170 00008021 */   addu      $s0, $zero, $zero
    /* B1D74 002B1174 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1D78 002B1178 27A40010 */   addiu     $a0, $sp, 0x10
    /* B1D7C 002B117C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1D80 002B1180 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1D84 002B1184 14400004 */  bnez       $v0, .L002B1198
    /* B1D88 002B1188 00000000 */   nop
    /* B1D8C 002B118C 93A20010 */  lbu        $v0, 0x10($sp)
    /* B1D90 002B1190 38420011 */  xori       $v0, $v0, 0x11
    /* B1D94 002B1194 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B1198:
    /* B1D98 002B1198 12000042 */  beqz       $s0, .L002B12A4
    /* B1D9C 002B119C 00000000 */   nop
    /* B1DA0 002B11A0 0C0AB96B */  jal        dbgLinkSendByte
    /* B1DA4 002B11A4 240400C0 */   addiu     $a0, $zero, 0xC0
    /* B1DA8 002B11A8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1DAC 002B11AC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1DB0 002B11B0 1440003C */  bnez       $v0, .L002B12A4
    /* B1DB4 002B11B4 00000000 */   nop
    /* B1DB8 002B11B8 0C0AB96B */  jal        dbgLinkSendByte
    /* B1DBC 002B11BC 00152602 */   srl       $a0, $s5, 24
    /* B1DC0 002B11C0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1DC4 002B11C4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1DC8 002B11C8 14400036 */  bnez       $v0, .L002B12A4
    /* B1DCC 002B11CC 00152402 */   srl       $a0, $s5, 16
    /* B1DD0 002B11D0 0C0AB96B */  jal        dbgLinkSendByte
    /* B1DD4 002B11D4 308400FF */   andi      $a0, $a0, 0xFF
    /* B1DD8 002B11D8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1DDC 002B11DC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1DE0 002B11E0 14400030 */  bnez       $v0, .L002B12A4
    /* B1DE4 002B11E4 00152202 */   srl       $a0, $s5, 8
    /* B1DE8 002B11E8 0C0AB96B */  jal        dbgLinkSendByte
    /* B1DEC 002B11EC 308400FF */   andi      $a0, $a0, 0xFF
    /* B1DF0 002B11F0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1DF4 002B11F4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1DF8 002B11F8 1440002A */  bnez       $v0, .L002B12A4
    /* B1DFC 002B11FC 00000000 */   nop
    /* B1E00 002B1200 0C0AB96B */  jal        dbgLinkSendByte
    /* B1E04 002B1204 32A400FF */   andi      $a0, $s5, 0xFF
    /* B1E08 002B1208 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1E0C 002B120C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1E10 002B1210 14400024 */  bnez       $v0, .L002B12A4
    /* B1E14 002B1214 00000000 */   nop
    /* B1E18 002B1218 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1E1C 002B121C 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1E20 002B1220 304200FB */  andi       $v0, $v0, 0xFB
    /* B1E24 002B1224 00409021 */  addu       $s2, $v0, $zero
    /* B1E28 002B1228 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1E2C 002B122C A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1230:
    /* B1E30 002B1230 0C0AF7A8 */  jal        osPiGetStatus
    /* B1E34 002B1234 00000000 */   nop
    /* B1E38 002B1238 30420003 */  andi       $v0, $v0, 0x3
    /* B1E3C 002B123C 1440FFFC */  bnez       $v0, .L002B1230
    /* B1E40 002B1240 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* B1E44 002B1244 24140002 */  addiu      $s4, $zero, 0x2
    /* B1E48 002B1248 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1E4C 002B124C 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1E50 002B1250 00009821 */  addu       $s3, $zero, $zero
    /* B1E54 002B1254 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1E58 002B1258 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B125C:
    /* B1E5C 002B125C 0C0AF7A8 */  jal        osPiGetStatus
    /* B1E60 002B1260 00000000 */   nop
    /* B1E64 002B1264 30420003 */  andi       $v0, $v0, 0x3
    /* B1E68 002B1268 1440FFFC */  bnez       $v0, .L002B125C
    /* B1E6C 002B126C 00000000 */   nop
    /* B1E70 002B1270 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B1E74 002B1274 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B1E78 002B1278 00541024 */  and        $v0, $v0, $s4
    /* B1E7C 002B127C 10530009 */  beq        $v0, $s3, .L002B12A4
    /* B1E80 002B1280 02001021 */   addu      $v0, $s0, $zero
    /* B1E84 002B1284 14400003 */  bnez       $v0, .L002B1294
    /* B1E88 002B1288 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B1E8C 002B128C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1E90 002B1290 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B1294:
    /* B1E94 002B1294 1E20FFF1 */  bgtz       $s1, .L002B125C
    /* B1E98 002B1298 24020001 */   addiu     $v0, $zero, 0x1
    /* B1E9C 002B129C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1EA0 002B12A0 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B12A4:
    /* B1EA4 002B12A4 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1EA8 002B12A8 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1EAC 002B12AC 304200FB */  andi       $v0, $v0, 0xFB
    /* B1EB0 002B12B0 00408021 */  addu       $s0, $v0, $zero
    /* B1EB4 002B12B4 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1EB8 002B12B8 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B12BC:
    /* B1EBC 002B12BC 0C0AF7A8 */  jal        osPiGetStatus
    /* B1EC0 002B12C0 00000000 */   nop
    /* B1EC4 002B12C4 30420003 */  andi       $v0, $v0, 0x3
    /* B1EC8 002B12C8 1440FFFC */  bnez       $v0, .L002B12BC
    /* B1ECC 002B12CC 00001021 */   addu      $v0, $zero, $zero
    /* B1ED0 002B12D0 8FBF0030 */  lw         $ra, 0x30($sp)
    /* B1ED4 002B12D4 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B1ED8 002B12D8 8FB40028 */  lw         $s4, 0x28($sp)
    /* B1EDC 002B12DC 8FB30024 */  lw         $s3, 0x24($sp)
    /* B1EE0 002B12E0 8FB20020 */  lw         $s2, 0x20($sp)
    /* B1EE4 002B12E4 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B1EE8 002B12E8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1EEC 002B12EC A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B1EF0 002B12F0 8FB00018 */  lw         $s0, 0x18($sp)
    /* B1EF4 002B12F4 24030001 */  addiu      $v1, $zero, 0x1
    /* B1EF8 002B12F8 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1EFC 002B12FC AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B1F00 002B1300 03E00008 */  jr         $ra
    /* B1F04 002B1304 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel dbgHostSendWord
