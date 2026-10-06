.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB193C-0xB1C88 (VRAM 0x002B0D3C) */
glabel dbgHostFtell
    /* B193C 002B0D3C 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1940 002B0D40 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1944 002B0D44 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B1948 002B0D48 AFB60038 */  sw         $s6, 0x38($sp)
    /* B194C 002B0D4C 0080B021 */  addu       $s6, $a0, $zero
    /* B1950 002B0D50 AFB20028 */  sw         $s2, 0x28($sp)
    /* B1954 002B0D54 24120064 */  addiu      $s2, $zero, 0x64
    /* B1958 002B0D58 AFBF003C */  sw         $ra, 0x3C($sp)
    /* B195C 002B0D5C AFB50034 */  sw         $s5, 0x34($sp)
    /* B1960 002B0D60 AFB40030 */  sw         $s4, 0x30($sp)
    /* B1964 002B0D64 AFB3002C */  sw         $s3, 0x2C($sp)
    /* B1968 002B0D68 AFB10024 */  sw         $s1, 0x24($sp)
    /* B196C 002B0D6C AFB00020 */  sw         $s0, 0x20($sp)
    /* B1970 002B0D70 AFA00014 */  sw         $zero, 0x14($sp)
    /* B1974 002B0D74 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1978 002B0D78 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B197C 002B0D7C 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1980 002B0D80 AC323650 */  sw         $s2, %lo(D_800D3650)($at)
    /* B1984 002B0D84 34420004 */  ori        $v0, $v0, 0x4
    /* B1988 002B0D88 00409821 */  addu       $s3, $v0, $zero
    /* B198C 002B0D8C 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1990 002B0D90 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0D94:
    /* B1994 002B0D94 0C0AF7A8 */  jal        osPiGetStatus
    /* B1998 002B0D98 00000000 */   nop
    /* B199C 002B0D9C 30420003 */  andi       $v0, $v0, 0x3
    /* B19A0 002B0DA0 1440FFFC */  bnez       $v0, .L002B0D94
    /* B19A4 002B0DA4 24150002 */   addiu     $s5, $zero, 0x2
    /* B19A8 002B0DA8 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B19AC 002B0DAC 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B19B0 002B0DB0 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B19B4 002B0DB4 24140002 */  addiu      $s4, $zero, 0x2
    /* B19B8 002B0DB8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B19BC 002B0DBC A4330004 */  sh         $s3, %lo(D_B2000004)($at)
  .L002B0DC0:
    /* B19C0 002B0DC0 0C0AF7A8 */  jal        osPiGetStatus
    /* B19C4 002B0DC4 00000000 */   nop
    /* B19C8 002B0DC8 30420003 */  andi       $v0, $v0, 0x3
    /* B19CC 002B0DCC 1440FFFC */  bnez       $v0, .L002B0DC0
    /* B19D0 002B0DD0 00000000 */   nop
    /* B19D4 002B0DD4 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B19D8 002B0DD8 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B19DC 002B0DDC 00551024 */  and        $v0, $v0, $s5
    /* B19E0 002B0DE0 10540009 */  beq        $v0, $s4, .L002B0E08
    /* B19E4 002B0DE4 02001021 */   addu      $v0, $s0, $zero
    /* B19E8 002B0DE8 14400003 */  bnez       $v0, .L002B0DF8
    /* B19EC 002B0DEC 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B19F0 002B0DF0 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B19F4 002B0DF4 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B0DF8:
    /* B19F8 002B0DF8 1E20FFF1 */  bgtz       $s1, .L002B0DC0
    /* B19FC 002B0DFC 24020001 */   addiu     $v0, $zero, 0x1
    /* B1A00 002B0E00 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1A04 002B0E04 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B0E08:
    /* B1A08 002B0E08 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1A0C 002B0E0C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1A10 002B0E10 14400083 */  bnez       $v0, .L002B1020
    /* B1A14 002B0E14 00000000 */   nop
    /* B1A18 002B0E18 0C0AB96B */  jal        dbgLinkSendByte
    /* B1A1C 002B0E1C 24040010 */   addiu     $a0, $zero, 0x10
    /* B1A20 002B0E20 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1A24 002B0E24 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1A28 002B0E28 1440000A */  bnez       $v0, .L002B0E54
    /* B1A2C 002B0E2C 00008021 */   addu      $s0, $zero, $zero
    /* B1A30 002B0E30 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1A34 002B0E34 27A40010 */   addiu     $a0, $sp, 0x10
    /* B1A38 002B0E38 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1A3C 002B0E3C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1A40 002B0E40 14400004 */  bnez       $v0, .L002B0E54
    /* B1A44 002B0E44 00000000 */   nop
    /* B1A48 002B0E48 93A20010 */  lbu        $v0, 0x10($sp)
    /* B1A4C 002B0E4C 38420011 */  xori       $v0, $v0, 0x11
    /* B1A50 002B0E50 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B0E54:
    /* B1A54 002B0E54 12000072 */  beqz       $s0, .L002B1020
    /* B1A58 002B0E58 00000000 */   nop
    /* B1A5C 002B0E5C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1A60 002B0E60 24040085 */   addiu     $a0, $zero, 0x85
    /* B1A64 002B0E64 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1A68 002B0E68 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1A6C 002B0E6C 1440006C */  bnez       $v0, .L002B1020
    /* B1A70 002B0E70 00000000 */   nop
    /* B1A74 002B0E74 0C0AB96B */  jal        dbgLinkSendByte
    /* B1A78 002B0E78 00162602 */   srl       $a0, $s6, 24
    /* B1A7C 002B0E7C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1A80 002B0E80 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1A84 002B0E84 14400066 */  bnez       $v0, .L002B1020
    /* B1A88 002B0E88 00162402 */   srl       $a0, $s6, 16
    /* B1A8C 002B0E8C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1A90 002B0E90 308400FF */   andi      $a0, $a0, 0xFF
    /* B1A94 002B0E94 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1A98 002B0E98 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1A9C 002B0E9C 14400060 */  bnez       $v0, .L002B1020
    /* B1AA0 002B0EA0 00162202 */   srl       $a0, $s6, 8
    /* B1AA4 002B0EA4 0C0AB96B */  jal        dbgLinkSendByte
    /* B1AA8 002B0EA8 308400FF */   andi      $a0, $a0, 0xFF
    /* B1AAC 002B0EAC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1AB0 002B0EB0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1AB4 002B0EB4 1440005A */  bnez       $v0, .L002B1020
    /* B1AB8 002B0EB8 00000000 */   nop
    /* B1ABC 002B0EBC 0C0AB96B */  jal        dbgLinkSendByte
    /* B1AC0 002B0EC0 32C400FF */   andi      $a0, $s6, 0xFF
    /* B1AC4 002B0EC4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1AC8 002B0EC8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1ACC 002B0ECC 14400054 */  bnez       $v0, .L002B1020
    /* B1AD0 002B0ED0 00000000 */   nop
    /* B1AD4 002B0ED4 27B30014 */  addiu      $s3, $sp, 0x14
    /* B1AD8 002B0ED8 27B10018 */  addiu      $s1, $sp, 0x18
  .L002B0EDC:
    /* B1ADC 002B0EDC 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1AE0 002B0EE0 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B1AE4 002B0EE4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1AE8 002B0EE8 02202021 */   addu      $a0, $s1, $zero
    /* B1AEC 002B0EEC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1AF0 002B0EF0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1AF4 002B0EF4 1440001D */  bnez       $v0, .L002B0F6C
    /* B1AF8 002B0EF8 02401021 */   addu      $v0, $s2, $zero
    /* B1AFC 002B0EFC 93A20018 */  lbu        $v0, 0x18($sp)
    /* B1B00 002B0F00 02202021 */  addu       $a0, $s1, $zero
    /* B1B04 002B0F04 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1B08 002B0F08 00028200 */   sll       $s0, $v0, 8
    /* B1B0C 002B0F0C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1B10 002B0F10 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1B14 002B0F14 14400015 */  bnez       $v0, .L002B0F6C
    /* B1B18 002B0F18 02401021 */   addu      $v0, $s2, $zero
    /* B1B1C 002B0F1C 93A20018 */  lbu        $v0, 0x18($sp)
    /* B1B20 002B0F20 02202021 */  addu       $a0, $s1, $zero
    /* B1B24 002B0F24 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1B28 002B0F28 02028025 */   or        $s0, $s0, $v0
    /* B1B2C 002B0F2C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1B30 002B0F30 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1B34 002B0F34 1440000C */  bnez       $v0, .L002B0F68
    /* B1B38 002B0F38 00108200 */   sll       $s0, $s0, 8
    /* B1B3C 002B0F3C 93A20018 */  lbu        $v0, 0x18($sp)
    /* B1B40 002B0F40 02202021 */  addu       $a0, $s1, $zero
    /* B1B44 002B0F44 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1B48 002B0F48 02028025 */   or        $s0, $s0, $v0
    /* B1B4C 002B0F4C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1B50 002B0F50 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1B54 002B0F54 14400004 */  bnez       $v0, .L002B0F68
    /* B1B58 002B0F58 00108200 */   sll       $s0, $s0, 8
    /* B1B5C 002B0F5C 93A20018 */  lbu        $v0, 0x18($sp)
    /* B1B60 002B0F60 02028025 */  or         $s0, $s0, $v0
    /* B1B64 002B0F64 AE700000 */  sw         $s0, 0x0($s3)
  .L002B0F68:
    /* B1B68 002B0F68 02401021 */  addu       $v0, $s2, $zero
  .L002B0F6C:
    /* B1B6C 002B0F6C 18400005 */  blez       $v0, .L002B0F84
    /* B1B70 002B0F70 2652FFFF */   addiu     $s2, $s2, -0x1
    /* B1B74 002B0F74 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1B78 002B0F78 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1B7C 002B0F7C 1440FFD7 */  bnez       $v0, .L002B0EDC
    /* B1B80 002B0F80 00000000 */   nop
  .L002B0F84:
    /* B1B84 002B0F84 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1B88 002B0F88 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1B8C 002B0F8C 14400024 */  bnez       $v0, .L002B1020
    /* B1B90 002B0F90 00000000 */   nop
    /* B1B94 002B0F94 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1B98 002B0F98 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1B9C 002B0F9C 304200FB */  andi       $v0, $v0, 0xFB
    /* B1BA0 002B0FA0 00409021 */  addu       $s2, $v0, $zero
    /* B1BA4 002B0FA4 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1BA8 002B0FA8 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0FAC:
    /* B1BAC 002B0FAC 0C0AF7A8 */  jal        osPiGetStatus
    /* B1BB0 002B0FB0 00000000 */   nop
    /* B1BB4 002B0FB4 30420003 */  andi       $v0, $v0, 0x3
    /* B1BB8 002B0FB8 1440FFFC */  bnez       $v0, .L002B0FAC
    /* B1BBC 002B0FBC 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* B1BC0 002B0FC0 24140002 */  addiu      $s4, $zero, 0x2
    /* B1BC4 002B0FC4 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1BC8 002B0FC8 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1BCC 002B0FCC 00009821 */  addu       $s3, $zero, $zero
    /* B1BD0 002B0FD0 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1BD4 002B0FD4 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B0FD8:
    /* B1BD8 002B0FD8 0C0AF7A8 */  jal        osPiGetStatus
    /* B1BDC 002B0FDC 00000000 */   nop
    /* B1BE0 002B0FE0 30420003 */  andi       $v0, $v0, 0x3
    /* B1BE4 002B0FE4 1440FFFC */  bnez       $v0, .L002B0FD8
    /* B1BE8 002B0FE8 00000000 */   nop
    /* B1BEC 002B0FEC 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B1BF0 002B0FF0 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B1BF4 002B0FF4 00541024 */  and        $v0, $v0, $s4
    /* B1BF8 002B0FF8 10530009 */  beq        $v0, $s3, .L002B1020
    /* B1BFC 002B0FFC 02001021 */   addu      $v0, $s0, $zero
    /* B1C00 002B1000 14400003 */  bnez       $v0, .L002B1010
    /* B1C04 002B1004 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B1C08 002B1008 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1C0C 002B100C 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B1010:
    /* B1C10 002B1010 1E20FFF1 */  bgtz       $s1, .L002B0FD8
    /* B1C14 002B1014 24020001 */   addiu     $v0, $zero, 0x1
    /* B1C18 002B1018 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1C1C 002B101C AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1020:
    /* B1C20 002B1020 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1C24 002B1024 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1C28 002B1028 304200FB */  andi       $v0, $v0, 0xFB
    /* B1C2C 002B102C 00408021 */  addu       $s0, $v0, $zero
    /* B1C30 002B1030 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1C34 002B1034 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1038:
    /* B1C38 002B1038 0C0AF7A8 */  jal        osPiGetStatus
    /* B1C3C 002B103C 00000000 */   nop
    /* B1C40 002B1040 30420003 */  andi       $v0, $v0, 0x3
    /* B1C44 002B1044 1440FFFC */  bnez       $v0, .L002B1038
    /* B1C48 002B1048 24030001 */   addiu     $v1, $zero, 0x1
    /* B1C4C 002B104C 8FA20014 */  lw         $v0, 0x14($sp)
    /* B1C50 002B1050 8FBF003C */  lw         $ra, 0x3C($sp)
    /* B1C54 002B1054 8FB60038 */  lw         $s6, 0x38($sp)
    /* B1C58 002B1058 8FB50034 */  lw         $s5, 0x34($sp)
    /* B1C5C 002B105C 8FB40030 */  lw         $s4, 0x30($sp)
    /* B1C60 002B1060 8FB3002C */  lw         $s3, 0x2C($sp)
    /* B1C64 002B1064 8FB20028 */  lw         $s2, 0x28($sp)
    /* B1C68 002B1068 8FB10024 */  lw         $s1, 0x24($sp)
    /* B1C6C 002B106C 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1C70 002B1070 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B1C74 002B1074 8FB00020 */  lw         $s0, 0x20($sp)
    /* B1C78 002B1078 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1C7C 002B107C AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B1C80 002B1080 03E00008 */  jr         $ra
    /* B1C84 002B1084 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel dbgHostFtell
