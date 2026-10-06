.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B7E38-0x1B8100 (VRAM 0x00449E38) */
glabel func_00449E38
    /* 1B7E38 00449E38 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* 1B7E3C 00449E3C AFB00010 */  sw         $s0, 0x10($sp)
    /* 1B7E40 00449E40 3C108014 */  lui        $s0, %hi(D_801462C8)
    /* 1B7E44 00449E44 261062C8 */  addiu      $s0, $s0, %lo(D_801462C8)
    /* 1B7E48 00449E48 AFBF0018 */  sw         $ra, 0x18($sp)
    /* 1B7E4C 00449E4C AFB10014 */  sw         $s1, 0x14($sp)
    /* 1B7E50 00449E50 9202001D */  lbu        $v0, 0x1D($s0)
    /* 1B7E54 00449E54 1040000F */  beqz       $v0, .L00449E94
    /* 1B7E58 00449E58 00808821 */   addu      $s1, $a0, $zero
    /* 1B7E5C 00449E5C 0C08AEB0 */  jal        func_0022BAC0
    /* 1B7E60 00449E60 00000000 */   nop
    /* 1B7E64 00449E64 0C08AEDC */  jal        func_0022BB70
    /* 1B7E68 00449E68 02202021 */   addu      $a0, $s1, $zero
    /* 1B7E6C 00449E6C 8E2205D8 */  lw         $v0, 0x5D8($s1)
    /* 1B7E70 00449E70 90420091 */  lbu        $v0, 0x91($v0)
    /* 1B7E74 00449E74 14400008 */  bnez       $v0, .L00449E98
    /* 1B7E78 00449E78 26220878 */   addiu     $v0, $s1, 0x878
    /* 1B7E7C 00449E7C 9203000D */  lbu        $v1, 0xD($s0)
    /* 1B7E80 00449E80 24020001 */  addiu      $v0, $zero, 0x1
    /* 1B7E84 00449E84 14620004 */  bne        $v1, $v0, .L00449E98
    /* 1B7E88 00449E88 26220878 */   addiu     $v0, $s1, 0x878
    /* 1B7E8C 00449E8C 0C10989C */  jal        func_00426270
    /* 1B7E90 00449E90 02202021 */   addu      $a0, $s1, $zero
  .L00449E94:
    /* 1B7E94 00449E94 26220878 */  addiu      $v0, $s1, 0x878
  .L00449E98:
    /* 1B7E98 00449E98 3C01800C */  lui        $at, %hi(D_800C73F0)
    /* 1B7E9C 00449E9C C42173F0 */  lwc1       $fv0f, %lo(D_800C73F0)($at)
    /* 1B7EA0 00449EA0 3C01800C */  lui        $at, %hi(D_800C73F0 + 0x4)
    /* 1B7EA4 00449EA4 C42273F4 */  lwc1       $fv1, %lo(D_800C73F0 + 0x4)($at)
    /* 1B7EA8 00449EA8 3C01800C */  lui        $at, %hi(D_800C73F8)
    /* 1B7EAC 00449EAC C42073F8 */  lwc1       $fv0, %lo(D_800C73F8)($at)
    /* 1B7EB0 00449EB0 3C01800C */  lui        $at, %hi(D_800C73F8 + 0x4)
    /* 1B7EB4 00449EB4 C42373FC */  lwc1       $fv1f, %lo(D_800C73F8 + 0x4)($at)
    /* 1B7EB8 00449EB8 3C01800C */  lui        $at, %hi(D_800C7400)
    /* 1B7EBC 00449EBC C4247400 */  lwc1       $ft0, %lo(D_800C7400)($at)
    /* 1B7EC0 00449EC0 2403FFFF */  addiu      $v1, $zero, -0x1
    /* 1B7EC4 00449EC4 AC4000B4 */  sw         $zero, 0xB4($v0)
    /* 1B7EC8 00449EC8 AC400008 */  sw         $zero, 0x8($v0)
    /* 1B7ECC 00449ECC AC4000B8 */  sw         $zero, 0xB8($v0)
    /* 1B7ED0 00449ED0 AC430004 */  sw         $v1, 0x4($v0)
    /* 1B7ED4 00449ED4 AE230878 */  sw         $v1, 0x878($s1)
    /* 1B7ED8 00449ED8 AC4000A8 */  sw         $zero, 0xA8($v0)
    /* 1B7EDC 00449EDC AC40009C */  sw         $zero, 0x9C($v0)
    /* 1B7EE0 00449EE0 AC4000A4 */  sw         $zero, 0xA4($v0)
    /* 1B7EE4 00449EE4 E44100AC */  swc1       $fv0f, 0xAC($v0)
    /* 1B7EE8 00449EE8 E44200B0 */  swc1       $fv1, 0xB0($v0)
    /* 1B7EEC 00449EEC E4400090 */  swc1       $fv0, 0x90($v0)
    /* 1B7EF0 00449EF0 E4430094 */  swc1       $fv1f, 0x94($v0)
    /* 1B7EF4 00449EF4 E4400098 */  swc1       $fv0, 0x98($v0)
    /* 1B7EF8 00449EF8 E44400A0 */  swc1       $ft0, 0xA0($v0)
    /* 1B7EFC 00449EFC 8E240698 */  lw         $a0, 0x698($s1)
    /* 1B7F00 00449F00 24050001 */  addiu      $a1, $zero, 0x1
    /* 1B7F04 00449F04 0C099202 */  jal        func_00264808
    /* 1B7F08 00449F08 AE2011B0 */   sw        $zero, 0x11B0($s1)
    /* 1B7F0C 00449F0C 26300E2C */  addiu      $s0, $s1, 0xE2C
    /* 1B7F10 00449F10 02002021 */  addu       $a0, $s0, $zero
    /* 1B7F14 00449F14 24050078 */  addiu      $a1, $zero, 0x78
    /* 1B7F18 00449F18 24060060 */  addiu      $a2, $zero, 0x60
    /* 1B7F1C 00449F1C AE200678 */  sw         $zero, 0x678($s1)
    /* 1B7F20 00449F20 AE20067C */  sw         $zero, 0x67C($s1)
    /* 1B7F24 00449F24 AE200680 */  sw         $zero, 0x680($s1)
    /* 1B7F28 00449F28 0C0AADB0 */  jal        func_002AB6C0
    /* 1B7F2C 00449F2C AE200684 */   sw        $zero, 0x684($s1)
    /* 1B7F30 00449F30 3C05800D */  lui        $a1, %hi(D_800CE4BC)
    /* 1B7F34 00449F34 24A5E4BC */  addiu      $a1, $a1, %lo(D_800CE4BC)
    /* 1B7F38 00449F38 0C0AADBF */  jal        func_002AB6FC
    /* 1B7F3C 00449F3C 02002021 */   addu      $a0, $s0, $zero
    /* 1B7F40 00449F40 26300E68 */  addiu      $s0, $s1, 0xE68
    /* 1B7F44 00449F44 02002021 */  addu       $a0, $s0, $zero
    /* 1B7F48 00449F48 240500BE */  addiu      $a1, $zero, 0xBE
    /* 1B7F4C 00449F4C 0C0AADB0 */  jal        func_002AB6C0
    /* 1B7F50 00449F50 24060060 */   addiu     $a2, $zero, 0x60
    /* 1B7F54 00449F54 3C05800D */  lui        $a1, %hi(D_800CE52C)
    /* 1B7F58 00449F58 24A5E52C */  addiu      $a1, $a1, %lo(D_800CE52C)
    /* 1B7F5C 00449F5C 0C0AADBF */  jal        func_002AB6FC
    /* 1B7F60 00449F60 02002021 */   addu      $a0, $s0, $zero
    /* 1B7F64 00449F64 26300EA4 */  addiu      $s0, $s1, 0xEA4
    /* 1B7F68 00449F68 02002021 */  addu       $a0, $s0, $zero
    /* 1B7F6C 00449F6C 24050104 */  addiu      $a1, $zero, 0x104
    /* 1B7F70 00449F70 0C0AADB0 */  jal        func_002AB6C0
    /* 1B7F74 00449F74 24060060 */   addiu     $a2, $zero, 0x60
    /* 1B7F78 00449F78 3C05800D */  lui        $a1, %hi(D_800CE59C)
    /* 1B7F7C 00449F7C 24A5E59C */  addiu      $a1, $a1, %lo(D_800CE59C)
    /* 1B7F80 00449F80 0C0AADBF */  jal        func_002AB6FC
    /* 1B7F84 00449F84 02002021 */   addu      $a0, $s0, $zero
    /* 1B7F88 00449F88 26300EE0 */  addiu      $s0, $s1, 0xEE0
    /* 1B7F8C 00449F8C 02002021 */  addu       $a0, $s0, $zero
    /* 1B7F90 00449F90 2405001C */  addiu      $a1, $zero, 0x1C
    /* 1B7F94 00449F94 0C0AADB0 */  jal        func_002AB6C0
    /* 1B7F98 00449F98 24060060 */   addiu     $a2, $zero, 0x60
    /* 1B7F9C 00449F9C 3C05800D */  lui        $a1, %hi(D_800CE480)
    /* 1B7FA0 00449FA0 24A5E480 */  addiu      $a1, $a1, %lo(D_800CE480)
    /* 1B7FA4 00449FA4 0C0AADBF */  jal        func_002AB6FC
    /* 1B7FA8 00449FA8 02002021 */   addu      $a0, $s0, $zero
    /* 1B7FAC 00449FAC 26300F1C */  addiu      $s0, $s1, 0xF1C
    /* 1B7FB0 00449FB0 02002021 */  addu       $a0, $s0, $zero
    /* 1B7FB4 00449FB4 2405FFC0 */  addiu      $a1, $zero, -0x40
    /* 1B7FB8 00449FB8 0C0AADB0 */  jal        func_002AB6C0
    /* 1B7FBC 00449FBC 24060010 */   addiu     $a2, $zero, 0x10
    /* 1B7FC0 00449FC0 3C05800D */  lui        $a1, %hi(D_800CE60C)
    /* 1B7FC4 00449FC4 24A5E60C */  addiu      $a1, $a1, %lo(D_800CE60C)
    /* 1B7FC8 00449FC8 0C0AADBF */  jal        func_002AB6FC
    /* 1B7FCC 00449FCC 02002021 */   addu      $a0, $s0, $zero
    /* 1B7FD0 00449FD0 26300F58 */  addiu      $s0, $s1, 0xF58
    /* 1B7FD4 00449FD4 02002021 */  addu       $a0, $s0, $zero
    /* 1B7FD8 00449FD8 24050028 */  addiu      $a1, $zero, 0x28
    /* 1B7FDC 00449FDC 0C0AADB0 */  jal        func_002AB6C0
    /* 1B7FE0 00449FE0 24060010 */   addiu     $a2, $zero, 0x10
    /* 1B7FE4 00449FE4 3C05800D */  lui        $a1, %hi(D_800CE630)
    /* 1B7FE8 00449FE8 24A5E630 */  addiu      $a1, $a1, %lo(D_800CE630)
    /* 1B7FEC 00449FEC 0C0AADBF */  jal        func_002AB6FC
    /* 1B7FF0 00449FF0 02002021 */   addu      $a0, $s0, $zero
    /* 1B7FF4 00449FF4 26301048 */  addiu      $s0, $s1, 0x1048
    /* 1B7FF8 00449FF8 02002021 */  addu       $a0, $s0, $zero
    /* 1B7FFC 00449FFC 2405FFAE */  addiu      $a1, $zero, -0x52
    /* 1B8000 0044A000 0C0AADB0 */  jal        func_002AB6C0
    /* 1B8004 0044A004 24060010 */   addiu     $a2, $zero, 0x10
    /* 1B8008 0044A008 3C05800D */  lui        $a1, %hi(D_800CE670)
    /* 1B800C 0044A00C 24A5E670 */  addiu      $a1, $a1, %lo(D_800CE670)
    /* 1B8010 0044A010 0C0AADBF */  jal        func_002AB6FC
    /* 1B8014 0044A014 02002021 */   addu      $a0, $s0, $zero
    /* 1B8018 0044A018 26301084 */  addiu      $s0, $s1, 0x1084
    /* 1B801C 0044A01C 02002021 */  addu       $a0, $s0, $zero
    /* 1B8020 0044A020 2405FFAE */  addiu      $a1, $zero, -0x52
    /* 1B8024 0044A024 3C01800C */  lui        $at, %hi(D_800C7404)
    /* 1B8028 0044A028 C4207404 */  lwc1       $fv0, %lo(D_800C7404)($at)
    /* 1B802C 0044A02C 24060044 */  addiu      $a2, $zero, 0x44
    /* 1B8030 0044A030 0C0AADB0 */  jal        func_002AB6C0
    /* 1B8034 0044A034 E620107C */   swc1      $fv0, 0x107C($s1)
    /* 1B8038 0044A038 3C05800D */  lui        $a1, %hi(D_800CE69C)
    /* 1B803C 0044A03C 24A5E69C */  addiu      $a1, $a1, %lo(D_800CE69C)
    /* 1B8040 0044A040 0C0AADBF */  jal        func_002AB6FC
    /* 1B8044 0044A044 02002021 */   addu      $a0, $s0, $zero
    /* 1B8048 0044A048 263010C0 */  addiu      $s0, $s1, 0x10C0
    /* 1B804C 0044A04C 02002021 */  addu       $a0, $s0, $zero
    /* 1B8050 0044A050 2405FFAE */  addiu      $a1, $zero, -0x52
    /* 1B8054 0044A054 0C0AADB0 */  jal        func_002AB6C0
    /* 1B8058 0044A058 24060044 */   addiu     $a2, $zero, 0x44
    /* 1B805C 0044A05C 3C05800D */  lui        $a1, %hi(D_800CE6D8)
    /* 1B8060 0044A060 24A5E6D8 */  addiu      $a1, $a1, %lo(D_800CE6D8)
    /* 1B8064 0044A064 0C0AADBF */  jal        func_002AB6FC
    /* 1B8068 0044A068 02002021 */   addu      $a0, $s0, $zero
    /* 1B806C 0044A06C 26240FD0 */  addiu      $a0, $s1, 0xFD0
    /* 1B8070 0044A070 3C10800E */  lui        $s0, %hi(D_800E28D0 + 0x6)
    /* 1B8074 0044A074 261028D6 */  addiu      $s0, $s0, %lo(D_800E28D0 + 0x6)
    /* 1B8078 0044A078 96060000 */  lhu        $a2, 0x0($s0)
    /* 1B807C 0044A07C 24050018 */  addiu      $a1, $zero, 0x18
    /* 1B8080 0044A080 24C60060 */  addiu      $a2, $a2, 0x60
    /* 1B8084 0044A084 00063400 */  sll        $a2, $a2, 16
    /* 1B8088 0044A088 0C0AADB0 */  jal        func_002AB6C0
    /* 1B808C 0044A08C 00063403 */   sra       $a2, $a2, 16
    /* 1B8090 0044A090 2624100C */  addiu      $a0, $s1, 0x100C
    /* 1B8094 0044A094 96060000 */  lhu        $a2, 0x0($s0)
    /* 1B8098 0044A098 24050018 */  addiu      $a1, $zero, 0x18
    /* 1B809C 0044A09C 24C60060 */  addiu      $a2, $a2, 0x60
    /* 1B80A0 0044A0A0 00063400 */  sll        $a2, $a2, 16
    /* 1B80A4 0044A0A4 0C0AADB0 */  jal        func_002AB6C0
    /* 1B80A8 0044A0A8 00063403 */   sra       $a2, $a2, 16
    /* 1B80AC 0044A0AC 262410FC */  addiu      $a0, $s1, 0x10FC
    /* 1B80B0 0044A0B0 24050064 */  addiu      $a1, $zero, 0x64
    /* 1B80B4 0044A0B4 0C0AADB0 */  jal        func_002AB6C0
    /* 1B80B8 0044A0B8 00A03021 */   addu      $a2, $a1, $zero
    /* 1B80BC 0044A0BC 8E2205E4 */  lw         $v0, 0x5E4($s1)
    /* 1B80C0 0044A0C0 8E2305DC */  lw         $v1, 0x5DC($s1)
    /* 1B80C4 0044A0C4 AE2011C4 */  sw         $zero, 0x11C4($s1)
    /* 1B80C8 0044A0C8 AE2007BC */  sw         $zero, 0x7BC($s1)
    /* 1B80CC 0044A0CC 10600009 */  beqz       $v1, .L0044A0F4
    /* 1B80D0 0044A0D0 AE221134 */   sw        $v0, 0x1134($s1)
    /* 1B80D4 0044A0D4 8C670140 */  lw         $a3, 0x140($v1)
    /* 1B80D8 0044A0D8 8C680144 */  lw         $t0, 0x144($v1)
    /* 1B80DC 0044A0DC 8C690148 */  lw         $t1, 0x148($v1)
    /* 1B80E0 0044A0E0 8C6A014C */  lw         $t2, 0x14C($v1)
    /* 1B80E4 0044A0E4 AE270760 */  sw         $a3, 0x760($s1)
    /* 1B80E8 0044A0E8 AE280764 */  sw         $t0, 0x764($s1)
    /* 1B80EC 0044A0EC AE290768 */  sw         $t1, 0x768($s1)
    /* 1B80F0 0044A0F0 AE2A076C */  sw         $t2, 0x76C($s1)
  .L0044A0F4:
    /* 1B80F4 0044A0F4 0C0869E3 */  jal        func_0021A78C
    /* 1B80F8 0044A0F8 02202021 */   addu      $a0, $s1, $zero
    /* 1B80FC 0044A0FC 0C0915DD */  jal        func_00245774
endlabel func_00449E38
