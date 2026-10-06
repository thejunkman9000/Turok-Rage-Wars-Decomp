.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB08E4-0xB0BEC (VRAM 0x002AFCE4) */
glabel dbgHostFopen
    /* B08E4 002AFCE4 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B08E8 002AFCE8 AFB50034 */  sw         $s5, 0x34($sp)
    /* B08EC 002AFCEC 0080A821 */  addu       $s5, $a0, $zero
    /* B08F0 002AFCF0 AFB60038 */  sw         $s6, 0x38($sp)
    /* B08F4 002AFCF4 00A0B021 */  addu       $s6, $a1, $zero
    /* B08F8 002AFCF8 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B08FC 002AFCFC 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0900 002AFD00 24030064 */  addiu      $v1, $zero, 0x64
    /* B0904 002AFD04 AFBF003C */  sw         $ra, 0x3C($sp)
    /* B0908 002AFD08 AFB40030 */  sw         $s4, 0x30($sp)
    /* B090C 002AFD0C AFB3002C */  sw         $s3, 0x2C($sp)
    /* B0910 002AFD10 AFB20028 */  sw         $s2, 0x28($sp)
    /* B0914 002AFD14 AFB10024 */  sw         $s1, 0x24($sp)
    /* B0918 002AFD18 AFB00020 */  sw         $s0, 0x20($sp)
    /* B091C 002AFD1C AFA00014 */  sw         $zero, 0x14($sp)
    /* B0920 002AFD20 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0924 002AFD24 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B0928 002AFD28 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B092C 002AFD2C AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B0930 002AFD30 34420004 */  ori        $v0, $v0, 0x4
    /* B0934 002AFD34 00409021 */  addu       $s2, $v0, $zero
    /* B0938 002AFD38 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B093C 002AFD3C A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AFD40:
    /* B0940 002AFD40 0C0AF7A8 */  jal        osPiGetStatus
    /* B0944 002AFD44 00000000 */   nop
    /* B0948 002AFD48 30420003 */  andi       $v0, $v0, 0x3
    /* B094C 002AFD4C 1440FFFC */  bnez       $v0, .L002AFD40
    /* B0950 002AFD50 24140002 */   addiu     $s4, $zero, 0x2
    /* B0954 002AFD54 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B0958 002AFD58 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B095C 002AFD5C 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B0960 002AFD60 24130002 */  addiu      $s3, $zero, 0x2
    /* B0964 002AFD64 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0968 002AFD68 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002AFD6C:
    /* B096C 002AFD6C 0C0AF7A8 */  jal        osPiGetStatus
    /* B0970 002AFD70 00000000 */   nop
    /* B0974 002AFD74 30420003 */  andi       $v0, $v0, 0x3
    /* B0978 002AFD78 1440FFFC */  bnez       $v0, .L002AFD6C
    /* B097C 002AFD7C 00000000 */   nop
    /* B0980 002AFD80 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B0984 002AFD84 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B0988 002AFD88 00541024 */  and        $v0, $v0, $s4
    /* B098C 002AFD8C 10530009 */  beq        $v0, $s3, .L002AFDB4
    /* B0990 002AFD90 02001021 */   addu      $v0, $s0, $zero
    /* B0994 002AFD94 14400003 */  bnez       $v0, .L002AFDA4
    /* B0998 002AFD98 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B099C 002AFD9C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B09A0 002AFDA0 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AFDA4:
    /* B09A4 002AFDA4 1E20FFF1 */  bgtz       $s1, .L002AFD6C
    /* B09A8 002AFDA8 24020001 */   addiu     $v0, $zero, 0x1
    /* B09AC 002AFDAC 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B09B0 002AFDB0 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AFDB4:
    /* B09B4 002AFDB4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B09B8 002AFDB8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B09BC 002AFDBC 14400071 */  bnez       $v0, .L002AFF84
    /* B09C0 002AFDC0 00000000 */   nop
    /* B09C4 002AFDC4 0C0AB96B */  jal        dbgLinkSendByte
    /* B09C8 002AFDC8 24040010 */   addiu     $a0, $zero, 0x10
    /* B09CC 002AFDCC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B09D0 002AFDD0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B09D4 002AFDD4 1440000A */  bnez       $v0, .L002AFE00
    /* B09D8 002AFDD8 00008021 */   addu      $s0, $zero, $zero
    /* B09DC 002AFDDC 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B09E0 002AFDE0 27A40010 */   addiu     $a0, $sp, 0x10
    /* B09E4 002AFDE4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B09E8 002AFDE8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B09EC 002AFDEC 14400004 */  bnez       $v0, .L002AFE00
    /* B09F0 002AFDF0 00000000 */   nop
    /* B09F4 002AFDF4 93A20010 */  lbu        $v0, 0x10($sp)
    /* B09F8 002AFDF8 38420011 */  xori       $v0, $v0, 0x11
    /* B09FC 002AFDFC 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002AFE00:
    /* B0A00 002AFE00 12000060 */  beqz       $s0, .L002AFF84
    /* B0A04 002AFE04 00000000 */   nop
    /* B0A08 002AFE08 0C0AB96B */  jal        dbgLinkSendByte
    /* B0A0C 002AFE0C 24040080 */   addiu     $a0, $zero, 0x80
    /* B0A10 002AFE10 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0A14 002AFE14 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0A18 002AFE18 1440005A */  bnez       $v0, .L002AFF84
    /* B0A1C 002AFE1C 00000000 */   nop
    /* B0A20 002AFE20 02A08821 */  addu       $s1, $s5, $zero
  .L002AFE24:
    /* B0A24 002AFE24 92220000 */  lbu        $v0, 0x0($s1)
    /* B0A28 002AFE28 305000FF */  andi       $s0, $v0, 0xFF
    /* B0A2C 002AFE2C 0C0AB96B */  jal        dbgLinkSendByte
    /* B0A30 002AFE30 02002021 */   addu      $a0, $s0, $zero
    /* B0A34 002AFE34 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0A38 002AFE38 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0A3C 002AFE3C 14400051 */  bnez       $v0, .L002AFF84
    /* B0A40 002AFE40 26310001 */   addiu     $s1, $s1, 0x1
    /* B0A44 002AFE44 1600FFF7 */  bnez       $s0, .L002AFE24
    /* B0A48 002AFE48 00000000 */   nop
    /* B0A4C 002AFE4C 02C08821 */  addu       $s1, $s6, $zero
  .L002AFE50:
    /* B0A50 002AFE50 92220000 */  lbu        $v0, 0x0($s1)
    /* B0A54 002AFE54 305000FF */  andi       $s0, $v0, 0xFF
    /* B0A58 002AFE58 0C0AB96B */  jal        dbgLinkSendByte
    /* B0A5C 002AFE5C 02002021 */   addu      $a0, $s0, $zero
    /* B0A60 002AFE60 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0A64 002AFE64 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0A68 002AFE68 14400046 */  bnez       $v0, .L002AFF84
    /* B0A6C 002AFE6C 26310001 */   addiu     $s1, $s1, 0x1
    /* B0A70 002AFE70 1600FFF7 */  bnez       $s0, .L002AFE50
    /* B0A74 002AFE74 00000000 */   nop
    /* B0A78 002AFE78 27B10018 */  addiu      $s1, $sp, 0x18
    /* B0A7C 002AFE7C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0A80 002AFE80 02202021 */   addu      $a0, $s1, $zero
    /* B0A84 002AFE84 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0A88 002AFE88 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0A8C 002AFE8C 1440003D */  bnez       $v0, .L002AFF84
    /* B0A90 002AFE90 02202021 */   addu      $a0, $s1, $zero
    /* B0A94 002AFE94 93A20018 */  lbu        $v0, 0x18($sp)
    /* B0A98 002AFE98 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0A9C 002AFE9C 00028200 */   sll       $s0, $v0, 8
    /* B0AA0 002AFEA0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0AA4 002AFEA4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0AA8 002AFEA8 14400036 */  bnez       $v0, .L002AFF84
    /* B0AAC 002AFEAC 02202021 */   addu      $a0, $s1, $zero
    /* B0AB0 002AFEB0 93A20018 */  lbu        $v0, 0x18($sp)
    /* B0AB4 002AFEB4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0AB8 002AFEB8 02028025 */   or        $s0, $s0, $v0
    /* B0ABC 002AFEBC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0AC0 002AFEC0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0AC4 002AFEC4 1440002F */  bnez       $v0, .L002AFF84
    /* B0AC8 002AFEC8 00108200 */   sll       $s0, $s0, 8
    /* B0ACC 002AFECC 93A20018 */  lbu        $v0, 0x18($sp)
    /* B0AD0 002AFED0 02202021 */  addu       $a0, $s1, $zero
    /* B0AD4 002AFED4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0AD8 002AFED8 02028025 */   or        $s0, $s0, $v0
    /* B0ADC 002AFEDC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0AE0 002AFEE0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0AE4 002AFEE4 14400027 */  bnez       $v0, .L002AFF84
    /* B0AE8 002AFEE8 00108200 */   sll       $s0, $s0, 8
    /* B0AEC 002AFEEC 93A30018 */  lbu        $v1, 0x18($sp)
    /* B0AF0 002AFEF0 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B0AF4 002AFEF4 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0AF8 002AFEF8 02038025 */  or         $s0, $s0, $v1
    /* B0AFC 002AFEFC 304200FB */  andi       $v0, $v0, 0xFB
    /* B0B00 002AFF00 00409021 */  addu       $s2, $v0, $zero
    /* B0B04 002AFF04 AFB00014 */  sw         $s0, 0x14($sp)
    /* B0B08 002AFF08 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B0B0C 002AFF0C A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AFF10:
    /* B0B10 002AFF10 0C0AF7A8 */  jal        osPiGetStatus
    /* B0B14 002AFF14 00000000 */   nop
    /* B0B18 002AFF18 30420003 */  andi       $v0, $v0, 0x3
    /* B0B1C 002AFF1C 1440FFFC */  bnez       $v0, .L002AFF10
    /* B0B20 002AFF20 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* B0B24 002AFF24 24140002 */  addiu      $s4, $zero, 0x2
    /* B0B28 002AFF28 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B0B2C 002AFF2C 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B0B30 002AFF30 00009821 */  addu       $s3, $zero, $zero
    /* B0B34 002AFF34 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0B38 002AFF38 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002AFF3C:
    /* B0B3C 002AFF3C 0C0AF7A8 */  jal        osPiGetStatus
    /* B0B40 002AFF40 00000000 */   nop
    /* B0B44 002AFF44 30420003 */  andi       $v0, $v0, 0x3
    /* B0B48 002AFF48 1440FFFC */  bnez       $v0, .L002AFF3C
    /* B0B4C 002AFF4C 00000000 */   nop
    /* B0B50 002AFF50 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B0B54 002AFF54 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B0B58 002AFF58 00541024 */  and        $v0, $v0, $s4
    /* B0B5C 002AFF5C 10530009 */  beq        $v0, $s3, .L002AFF84
    /* B0B60 002AFF60 02001021 */   addu      $v0, $s0, $zero
    /* B0B64 002AFF64 14400003 */  bnez       $v0, .L002AFF74
    /* B0B68 002AFF68 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B0B6C 002AFF6C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B0B70 002AFF70 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AFF74:
    /* B0B74 002AFF74 1E20FFF1 */  bgtz       $s1, .L002AFF3C
    /* B0B78 002AFF78 24020001 */   addiu     $v0, $zero, 0x1
    /* B0B7C 002AFF7C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0B80 002AFF80 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AFF84:
    /* B0B84 002AFF84 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B0B88 002AFF88 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0B8C 002AFF8C 304200FB */  andi       $v0, $v0, 0xFB
    /* B0B90 002AFF90 00408021 */  addu       $s0, $v0, $zero
    /* B0B94 002AFF94 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B0B98 002AFF98 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AFF9C:
    /* B0B9C 002AFF9C 0C0AF7A8 */  jal        osPiGetStatus
    /* B0BA0 002AFFA0 00000000 */   nop
    /* B0BA4 002AFFA4 30420003 */  andi       $v0, $v0, 0x3
    /* B0BA8 002AFFA8 1440FFFC */  bnez       $v0, .L002AFF9C
    /* B0BAC 002AFFAC 24030001 */   addiu     $v1, $zero, 0x1
    /* B0BB0 002AFFB0 8FA20014 */  lw         $v0, 0x14($sp)
    /* B0BB4 002AFFB4 8FBF003C */  lw         $ra, 0x3C($sp)
    /* B0BB8 002AFFB8 8FB60038 */  lw         $s6, 0x38($sp)
    /* B0BBC 002AFFBC 8FB50034 */  lw         $s5, 0x34($sp)
    /* B0BC0 002AFFC0 8FB40030 */  lw         $s4, 0x30($sp)
    /* B0BC4 002AFFC4 8FB3002C */  lw         $s3, 0x2C($sp)
    /* B0BC8 002AFFC8 8FB20028 */  lw         $s2, 0x28($sp)
    /* B0BCC 002AFFCC 8FB10024 */  lw         $s1, 0x24($sp)
    /* B0BD0 002AFFD0 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0BD4 002AFFD4 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B0BD8 002AFFD8 8FB00020 */  lw         $s0, 0x20($sp)
    /* B0BDC 002AFFDC 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B0BE0 002AFFE0 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B0BE4 002AFFE4 03E00008 */  jr         $ra
    /* B0BE8 002AFFE8 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel dbgHostFopen
