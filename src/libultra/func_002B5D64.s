.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB6964-0xB71EC (VRAM 0x002B5D64) */
glabel func_002B5D64
    /* B6964 002B5D64 27BDFF90 */  addiu      $sp, $sp, -0x70
    /* B6968 002B5D68 AFB00040 */  sw         $s0, 0x40($sp)
    /* B696C 002B5D6C 00A08021 */  addu       $s0, $a1, $zero
    /* B6970 002B5D70 AFBF0060 */  sw         $ra, 0x60($sp)
    /* B6974 002B5D74 AFB7005C */  sw         $s7, 0x5C($sp)
    /* B6978 002B5D78 AFB60058 */  sw         $s6, 0x58($sp)
    /* B697C 002B5D7C AFB50054 */  sw         $s5, 0x54($sp)
    /* B6980 002B5D80 AFB40050 */  sw         $s4, 0x50($sp)
    /* B6984 002B5D84 AFB3004C */  sw         $s3, 0x4C($sp)
    /* B6988 002B5D88 AFB20048 */  sw         $s2, 0x48($sp)
    /* B698C 002B5D8C AFB10044 */  sw         $s1, 0x44($sp)
    /* B6990 002B5D90 F7B40068 */  sdc1       $fs0, 0x68($sp)
    /* B6994 002B5D94 96020000 */  lhu        $v0, 0x0($s0)
    /* B6998 002B5D98 2442FFFF */  addiu      $v0, $v0, -0x1
    /* B699C 002B5D9C 2C420002 */  sltiu      $v0, $v0, 0x2
    /* B69A0 002B5DA0 14400007 */  bnez       $v0, .L002B5DC0
    /* B69A4 002B5DA4 00809021 */   addu      $s2, $a0, $zero
    /* B69A8 002B5DA8 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B69AC 002B5DAC 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B69B0 002B5DB0 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B69B4 002B5DB4 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B69B8 002B5DB8 0C0AFF50 */  jal        __assert
    /* B69BC 002B5DBC 240601B4 */   addiu     $a2, $zero, 0x1B4
  .L002B5DC0:
    /* B69C0 002B5DC0 92020008 */  lbu        $v0, 0x8($s0)
    /* B69C4 002B5DC4 92140009 */  lbu        $s4, 0x9($s0)
    /* B69C8 002B5DC8 9210000A */  lbu        $s0, 0xA($s0)
    /* B69CC 002B5DCC 3055000F */  andi       $s5, $v0, 0xF
    /* B69D0 002B5DD0 304300F0 */  andi       $v1, $v0, 0xF0
    /* B69D4 002B5DD4 0280B021 */  addu       $s6, $s4, $zero
    /* B69D8 002B5DD8 240200B0 */  addiu      $v0, $zero, 0xB0
    /* B69DC 002B5DDC 1062012B */  beq        $v1, $v0, .L002B628C
    /* B69E0 002B5DE0 02009821 */   addu      $s3, $s0, $zero
    /* B69E4 002B5DE4 286200B1 */  slti       $v0, $v1, 0xB1
    /* B69E8 002B5DE8 1040000E */  beqz       $v0, .L002B5E24
    /* B69EC 002B5DEC 24020090 */   addiu     $v0, $zero, 0x90
    /* B69F0 002B5DF0 1062001A */  beq        $v1, $v0, .L002B5E5C
    /* B69F4 002B5DF4 28620091 */   slti      $v0, $v1, 0x91
    /* B69F8 002B5DF8 10400005 */  beqz       $v0, .L002B5E10
    /* B69FC 002B5DFC 24020080 */   addiu     $v0, $zero, 0x80
    /* B6A00 002B5E00 106200E0 */  beq        $v1, $v0, .L002B6184
    /* B6A04 002B5E04 02402021 */   addu      $a0, $s2, $zero
    /* B6A08 002B5E08 080AD96F */  j          .L002B65BC
    /* B6A0C 002B5E0C 00000000 */   nop
  .L002B5E10:
    /* B6A10 002B5E10 240200A0 */  addiu      $v0, $zero, 0xA0
    /* B6A14 002B5E14 106200F0 */  beq        $v1, $v0, .L002B61D8
    /* B6A18 002B5E18 02402021 */   addu      $a0, $s2, $zero
    /* B6A1C 002B5E1C 080AD96F */  j          .L002B65BC
    /* B6A20 002B5E20 00000000 */   nop
  .L002B5E24:
    /* B6A24 002B5E24 240200D0 */  addiu      $v0, $zero, 0xD0
    /* B6A28 002B5E28 10620100 */  beq        $v1, $v0, .L002B622C
    /* B6A2C 002B5E2C 286200D1 */   slti      $v0, $v1, 0xD1
    /* B6A30 002B5E30 10400005 */  beqz       $v0, .L002B5E48
    /* B6A34 002B5E34 240200C0 */   addiu     $v0, $zero, 0xC0
    /* B6A38 002B5E38 106201A6 */  beq        $v1, $v0, .L002B64D4
    /* B6A3C 002B5E3C 00000000 */   nop
    /* B6A40 002B5E40 080AD96F */  j          .L002B65BC
    /* B6A44 002B5E44 00000000 */   nop
  .L002B5E48:
    /* B6A48 002B5E48 240200E0 */  addiu      $v0, $zero, 0xE0
    /* B6A4C 002B5E4C 106201B7 */  beq        $v1, $v0, .L002B652C
    /* B6A50 002B5E50 320300FF */   andi      $v1, $s0, 0xFF
    /* B6A54 002B5E54 080AD96F */  j          .L002B65BC
    /* B6A58 002B5E58 00000000 */   nop
  .L002B5E5C:
    /* B6A5C 002B5E5C 321100FF */  andi       $s1, $s0, 0xFF
    /* B6A60 002B5E60 122000C7 */  beqz       $s1, .L002B6180
    /* B6A64 002B5E64 24020001 */   addiu     $v0, $zero, 0x1
    /* B6A68 002B5E68 8E43002C */  lw         $v1, 0x2C($s2)
    /* B6A6C 002B5E6C 146201D3 */  bne        $v1, $v0, .L002B65BC
    /* B6A70 002B5E70 02402021 */   addu      $a0, $s2, $zero
    /* B6A74 002B5E74 329300FF */  andi       $s3, $s4, 0xFF
    /* B6A78 002B5E78 02602821 */  addu       $a1, $s3, $zero
    /* B6A7C 002B5E7C 02203021 */  addu       $a2, $s1, $zero
    /* B6A80 002B5E80 32B000FF */  andi       $s0, $s5, 0xFF
    /* B6A84 002B5E84 0C0AD9EC */  jal        func_002B67B0
    /* B6A88 002B5E88 02003821 */   addu      $a3, $s0, $zero
    /* B6A8C 002B5E8C 0040B021 */  addu       $s6, $v0, $zero
    /* B6A90 002B5E90 12C001CA */  beqz       $s6, .L002B65BC
    /* B6A94 002B5E94 02402021 */   addu      $a0, $s2, $zero
    /* B6A98 002B5E98 02602821 */  addu       $a1, $s3, $zero
    /* B6A9C 002B5E9C 02203021 */  addu       $a2, $s1, $zero
    /* B6AA0 002B5EA0 8E420060 */  lw         $v0, 0x60($s2)
    /* B6AA4 002B5EA4 00109900 */  sll        $s3, $s0, 4
    /* B6AA8 002B5EA8 02621021 */  addu       $v0, $s3, $v0
    /* B6AAC 002B5EAC 90420008 */  lbu        $v0, 0x8($v0)
    /* B6AB0 002B5EB0 02003821 */  addu       $a3, $s0, $zero
    /* B6AB4 002B5EB4 A7A00032 */  sh         $zero, 0x32($sp)
    /* B6AB8 002B5EB8 A3A00034 */  sb         $zero, 0x34($sp)
    /* B6ABC 002B5EBC 0C0AD97B */  jal        func_002B65EC
    /* B6AC0 002B5EC0 A7A20030 */   sh        $v0, 0x30($sp)
    /* B6AC4 002B5EC4 00408821 */  addu       $s1, $v0, $zero
    /* B6AC8 002B5EC8 122001BC */  beqz       $s1, .L002B65BC
    /* B6ACC 002B5ECC 26370004 */   addiu     $s7, $s1, 0x4
    /* B6AD0 002B5ED0 02E02821 */  addu       $a1, $s7, $zero
    /* B6AD4 002B5ED4 8E440014 */  lw         $a0, 0x14($s2)
    /* B6AD8 002B5ED8 0C0AE034 */  jal        func_002B80D0
    /* B6ADC 002B5EDC 27A60030 */   addiu     $a2, $sp, 0x30
    /* B6AE0 002B5EE0 AE360020 */  sw         $s6, 0x20($s1)
    /* B6AE4 002B5EE4 A2200034 */  sb         $zero, 0x34($s1)
    /* B6AE8 002B5EE8 8E420060 */  lw         $v0, 0x60($s2)
    /* B6AEC 002B5EEC 02621021 */  addu       $v0, $s3, $v0
    /* B6AF0 002B5EF0 9042000B */  lbu        $v0, 0xB($v0)
    /* B6AF4 002B5EF4 2C420040 */  sltiu      $v0, $v0, 0x40
    /* B6AF8 002B5EF8 54400003 */  bnel       $v0, $zero, .L002B5F08
    /* B6AFC 002B5EFC A2200035 */   sb        $zero, 0x35($s1)
    /* B6B00 002B5F00 24020002 */  addiu      $v0, $zero, 0x2
    /* B6B04 002B5F04 A2220035 */  sb         $v0, 0x35($s1)
  .L002B5F08:
    /* B6B08 002B5F08 8EC20004 */  lw         $v0, 0x4($s6)
    /* B6B0C 002B5F0C 328300FF */  andi       $v1, $s4, 0xFF
    /* B6B10 002B5F10 90440005 */  lbu        $a0, 0x5($v0)
    /* B6B14 002B5F14 90420004 */  lbu        $v0, 0x4($v0)
    /* B6B18 002B5F18 00042600 */  sll        $a0, $a0, 24
    /* B6B1C 002B5F1C 00042603 */  sra        $a0, $a0, 24
    /* B6B20 002B5F20 00621823 */  subu       $v1, $v1, $v0
    /* B6B24 002B5F24 00031040 */  sll        $v0, $v1, 1
    /* B6B28 002B5F28 00431021 */  addu       $v0, $v0, $v1
    /* B6B2C 002B5F2C 000210C0 */  sll        $v0, $v0, 3
    /* B6B30 002B5F30 00431021 */  addu       $v0, $v0, $v1
    /* B6B34 002B5F34 00021080 */  sll        $v0, $v0, 2
    /* B6B38 002B5F38 00822021 */  addu       $a0, $a0, $v0
    /* B6B3C 002B5F3C 00042400 */  sll        $a0, $a0, 16
    /* B6B40 002B5F40 0C0AD3C0 */  jal        func_002B4F00
    /* B6B44 002B5F44 00042403 */   sra       $a0, $a0, 16
    /* B6B48 002B5F48 E6200028 */  swc1       $fv0, 0x28($s1)
    /* B6B4C 002B5F4C 8EC20000 */  lw         $v0, 0x0($s6)
    /* B6B50 002B5F50 3C01800D */  lui        $at, %hi(D_800CC710)
    /* B6B54 002B5F54 C420C710 */  lwc1       $fv0, %lo(D_800CC710)($at)
    /* B6B58 002B5F58 9042000C */  lbu        $v0, 0xC($v0)
    /* B6B5C 002B5F5C A2220030 */  sb         $v0, 0x30($s1)
    /* B6B60 002B5F60 8EC30000 */  lw         $v1, 0x0($s6)
    /* B6B64 002B5F64 8E42001C */  lw         $v0, 0x1C($s2)
    /* B6B68 002B5F68 8C630000 */  lw         $v1, 0x0($v1)
    /* B6B6C 002B5F6C A2200037 */  sb         $zero, 0x37($s1)
    /* B6B70 002B5F70 00431021 */  addu       $v0, $v0, $v1
    /* B6B74 002B5F74 AE220024 */  sw         $v0, 0x24($s1)
    /* B6B78 002B5F78 8E430060 */  lw         $v1, 0x60($s2)
    /* B6B7C 002B5F7C 00151100 */  sll        $v0, $s5, 4
    /* B6B80 002B5F80 00431021 */  addu       $v0, $v0, $v1
    /* B6B84 002B5F84 8C500000 */  lw         $s0, 0x0($v0)
    /* B6B88 002B5F88 E7A0003C */  swc1       $fv0, 0x3C($sp)
    /* B6B8C 002B5F8C 92020004 */  lbu        $v0, 0x4($s0)
    /* B6B90 002B5F90 1040001A */  beqz       $v0, .L002B5FFC
    /* B6B94 002B5F94 00000000 */   nop
    /* B6B98 002B5F98 8E420070 */  lw         $v0, 0x70($s2)
    /* B6B9C 002B5F9C 10400017 */  beqz       $v0, .L002B5FFC
    /* B6BA0 002B5FA0 27A40038 */   addiu     $a0, $sp, 0x38
    /* B6BA4 002B5FA4 92020006 */  lbu        $v0, 0x6($s0)
    /* B6BA8 002B5FA8 92060004 */  lbu        $a2, 0x4($s0)
    /* B6BAC 002B5FAC 92070005 */  lbu        $a3, 0x5($s0)
    /* B6BB0 002B5FB0 AFA20010 */  sw         $v0, 0x10($sp)
    /* B6BB4 002B5FB4 92020007 */  lbu        $v0, 0x7($s0)
    /* B6BB8 002B5FB8 AFA20014 */  sw         $v0, 0x14($sp)
    /* B6BBC 002B5FBC 8E420070 */  lw         $v0, 0x70($s2)
    /* B6BC0 002B5FC0 0040F809 */  jalr       $v0
    /* B6BC4 002B5FC4 27A5003C */   addiu     $a1, $sp, 0x3C
    /* B6BC8 002B5FC8 00403021 */  addu       $a2, $v0, $zero
    /* B6BCC 002B5FCC 10C0000B */  beqz       $a2, .L002B5FFC
    /* B6BD0 002B5FD0 26440048 */   addiu     $a0, $s2, 0x48
    /* B6BD4 002B5FD4 27A50020 */  addiu      $a1, $sp, 0x20
    /* B6BD8 002B5FD8 8FA30038 */  lw         $v1, 0x38($sp)
    /* B6BDC 002B5FDC 24020016 */  addiu      $v0, $zero, 0x16
    /* B6BE0 002B5FE0 A7A20020 */  sh         $v0, 0x20($sp)
    /* B6BE4 002B5FE4 AFB10024 */  sw         $s1, 0x24($sp)
    /* B6BE8 002B5FE8 0C0AD469 */  jal        func_002B51A4
    /* B6BEC 002B5FEC AFA30028 */   sw        $v1, 0x28($sp)
    /* B6BF0 002B5FF0 92220037 */  lbu        $v0, 0x37($s1)
    /* B6BF4 002B5FF4 34420001 */  ori        $v0, $v0, 0x1
    /* B6BF8 002B5FF8 A2220037 */  sb         $v0, 0x37($s1)
  .L002B5FFC:
    /* B6BFC 002B5FFC C7A0003C */  lwc1       $fv0, 0x3C($sp)
    /* B6C00 002B6000 3C01800D */  lui        $at, %hi(D_800CC710 + 0x4)
    /* B6C04 002B6004 C421C714 */  lwc1       $fv0f, %lo(D_800CC710 + 0x4)($at)
    /* B6C08 002B6008 4600083E */  c.le.s     $fv0f, $fv0
    /* B6C0C 002B600C 00000000 */  nop
    /* B6C10 002B6010 45010005 */  bc1t       .L002B6028
    /* B6C14 002B6014 26240036 */   addiu     $a0, $s1, 0x36
    /* B6C18 002B6018 4600008D */  trunc.w.s  $fv1, $fv0
    /* B6C1C 002B601C 44031000 */  mfc1       $v1, $fv1
    /* B6C20 002B6020 080AD80F */  j          .L002B603C
    /* B6C24 002B6024 00000000 */   nop
  .L002B6028:
    /* B6C28 002B6028 46010001 */  sub.s      $fv0, $fv0, $fv0f
    /* B6C2C 002B602C 3C028000 */  lui        $v0, (0x80000000 >> 16)
    /* B6C30 002B6030 4600008D */  trunc.w.s  $fv1, $fv0
    /* B6C34 002B6034 44031000 */  mfc1       $v1, $fv1
    /* B6C38 002B6038 00621825 */  or         $v1, $v1, $v0
  .L002B603C:
    /* B6C3C 002B603C 3C01800D */  lui        $at, %hi(D_800CC718)
    /* B6C40 002B6040 C420C718 */  lwc1       $fv0, %lo(D_800CC718)($at)
    /* B6C44 002B6044 A0830000 */  sb         $v1, 0x0($a0)
    /* B6C48 002B6048 E7A0003C */  swc1       $fv0, 0x3C($sp)
    /* B6C4C 002B604C 92020008 */  lbu        $v0, 0x8($s0)
    /* B6C50 002B6050 1040001B */  beqz       $v0, .L002B60C0
    /* B6C54 002B6054 00000000 */   nop
    /* B6C58 002B6058 8E420070 */  lw         $v0, 0x70($s2)
    /* B6C5C 002B605C 10400018 */  beqz       $v0, .L002B60C0
    /* B6C60 002B6060 27A40038 */   addiu     $a0, $sp, 0x38
    /* B6C64 002B6064 9202000A */  lbu        $v0, 0xA($s0)
    /* B6C68 002B6068 92060008 */  lbu        $a2, 0x8($s0)
    /* B6C6C 002B606C 92070009 */  lbu        $a3, 0x9($s0)
    /* B6C70 002B6070 AFA20010 */  sw         $v0, 0x10($sp)
    /* B6C74 002B6074 9202000B */  lbu        $v0, 0xB($s0)
    /* B6C78 002B6078 AFA20014 */  sw         $v0, 0x14($sp)
    /* B6C7C 002B607C 8E420070 */  lw         $v0, 0x70($s2)
    /* B6C80 002B6080 0040F809 */  jalr       $v0
    /* B6C84 002B6084 27A5003C */   addiu     $a1, $sp, 0x3C
    /* B6C88 002B6088 00403021 */  addu       $a2, $v0, $zero
    /* B6C8C 002B608C 10C0000C */  beqz       $a2, .L002B60C0
    /* B6C90 002B6090 26440048 */   addiu     $a0, $s2, 0x48
    /* B6C94 002B6094 27A50020 */  addiu      $a1, $sp, 0x20
    /* B6C98 002B6098 8FA30038 */  lw         $v1, 0x38($sp)
    /* B6C9C 002B609C 24020017 */  addiu      $v0, $zero, 0x17
    /* B6CA0 002B60A0 A7A20020 */  sh         $v0, 0x20($sp)
    /* B6CA4 002B60A4 AFB10024 */  sw         $s1, 0x24($sp)
    /* B6CA8 002B60A8 A3B5002C */  sb         $s5, 0x2C($sp)
    /* B6CAC 002B60AC 0C0AD469 */  jal        func_002B51A4
    /* B6CB0 002B60B0 AFA30028 */   sw        $v1, 0x28($sp)
    /* B6CB4 002B60B4 92220037 */  lbu        $v0, 0x37($s1)
    /* B6CB8 002B60B8 34420002 */  ori        $v0, $v0, 0x2
    /* B6CBC 002B60BC A2220037 */  sb         $v0, 0x37($s1)
  .L002B60C0:
    /* B6CC0 002B60C0 C7A1003C */  lwc1       $fv0f, 0x3C($sp)
    /* B6CC4 002B60C4 00151100 */  sll        $v0, $s5, 4
    /* B6CC8 002B60C8 E621002C */  swc1       $fv0f, 0x2C($s1)
    /* B6CCC 002B60CC 8E430060 */  lw         $v1, 0x60($s2)
    /* B6CD0 002B60D0 C6340028 */  lwc1       $fs0, 0x28($s1)
    /* B6CD4 002B60D4 00431021 */  addu       $v0, $v0, $v1
    /* B6CD8 002B60D8 C440000C */  lwc1       $fv0, 0xC($v0)
    /* B6CDC 002B60DC 4600A502 */  mul.s      $fs0, $fs0, $fv0
    /* B6CE0 002B60E0 02202021 */  addu       $a0, $s1, $zero
    /* B6CE4 002B60E4 9050000A */  lbu        $s0, 0xA($v0)
    /* B6CE8 002B60E8 4601A502 */  mul.s      $fs0, $fs0, $fv0f
    /* B6CEC 002B60EC 0C0ADA5D */  jal        func_002B6974
    /* B6CF0 002B60F0 02402821 */   addu      $a1, $s2, $zero
    /* B6CF4 002B60F4 02202021 */  addu       $a0, $s1, $zero
    /* B6CF8 002B60F8 02402821 */  addu       $a1, $s2, $zero
    /* B6CFC 002B60FC 0C0ADA39 */  jal        func_002B68E4
    /* B6D00 002B6100 00408821 */   addu      $s1, $v0, $zero
    /* B6D04 002B6104 00021400 */  sll        $v0, $v0, 16
    /* B6D08 002B6108 8EC30000 */  lw         $v1, 0x0($s6)
    /* B6D0C 002B610C 00021403 */  sra        $v0, $v0, 16
    /* B6D10 002B6110 8C660000 */  lw         $a2, 0x0($v1)
    /* B6D14 002B6114 321000FF */  andi       $s0, $s0, 0xFF
    /* B6D18 002B6118 AFA20010 */  sw         $v0, 0x10($sp)
    /* B6D1C 002B611C 322200FF */  andi       $v0, $s1, 0xFF
    /* B6D20 002B6120 AFA20014 */  sw         $v0, 0x14($sp)
    /* B6D24 002B6124 AFB00018 */  sw         $s0, 0x18($sp)
    /* B6D28 002B6128 AFA6001C */  sw         $a2, 0x1C($sp)
    /* B6D2C 002B612C 8E440014 */  lw         $a0, 0x14($s2)
    /* B6D30 002B6130 8EC60008 */  lw         $a2, 0x8($s6)
    /* B6D34 002B6134 4407A000 */  mfc1       $a3, $fs0
    /* B6D38 002B6138 0C0AE1AC */  jal        func_002B86B0
    /* B6D3C 002B613C 02E02821 */   addu      $a1, $s7, $zero
    /* B6D40 002B6140 24020006 */  addiu      $v0, $zero, 0x6
    /* B6D44 002B6144 A7A20020 */  sh         $v0, 0x20($sp)
    /* B6D48 002B6148 AFB70024 */  sw         $s7, 0x24($sp)
    /* B6D4C 002B614C 8EC20000 */  lw         $v0, 0x0($s6)
    /* B6D50 002B6150 9042000D */  lbu        $v0, 0xD($v0)
    /* B6D54 002B6154 A3A2002C */  sb         $v0, 0x2C($sp)
    /* B6D58 002B6158 8EC20000 */  lw         $v0, 0x0($s6)
    /* B6D5C 002B615C 8C420004 */  lw         $v0, 0x4($v0)
    /* B6D60 002B6160 AFA20028 */  sw         $v0, 0x28($sp)
    /* B6D64 002B6164 8EC20000 */  lw         $v0, 0x0($s6)
    /* B6D68 002B6168 26440048 */  addiu      $a0, $s2, 0x48
    /* B6D6C 002B616C 8C460000 */  lw         $a2, 0x0($v0)
    /* B6D70 002B6170 0C0AD469 */  jal        func_002B51A4
    /* B6D74 002B6174 27A50020 */   addiu     $a1, $sp, 0x20
    /* B6D78 002B6178 080AD96F */  j          .L002B65BC
    /* B6D7C 002B617C 00000000 */   nop
  .L002B6180:
    /* B6D80 002B6180 02402021 */  addu       $a0, $s2, $zero
  .L002B6184:
    /* B6D84 002B6184 328500FF */  andi       $a1, $s4, 0xFF
    /* B6D88 002B6188 0C0AD9D4 */  jal        func_002B6750
    /* B6D8C 002B618C 02A03021 */   addu      $a2, $s5, $zero
    /* B6D90 002B6190 00408821 */  addu       $s1, $v0, $zero
    /* B6D94 002B6194 12200109 */  beqz       $s1, .L002B65BC
    /* B6D98 002B6198 24020002 */   addiu     $v0, $zero, 0x2
    /* B6D9C 002B619C 92230035 */  lbu        $v1, 0x35($s1)
    /* B6DA0 002B61A0 14620004 */  bne        $v1, $v0, .L002B61B4
    /* B6DA4 002B61A4 24030003 */   addiu     $v1, $zero, 0x3
    /* B6DA8 002B61A8 24020004 */  addiu      $v0, $zero, 0x4
    /* B6DAC 002B61AC 080AD96F */  j          .L002B65BC
    /* B6DB0 002B61B0 A2220035 */   sb        $v0, 0x35($s1)
  .L002B61B4:
    /* B6DB4 002B61B4 8E220020 */  lw         $v0, 0x20($s1)
    /* B6DB8 002B61B8 A2230035 */  sb         $v1, 0x35($s1)
    /* B6DBC 002B61BC 8C420000 */  lw         $v0, 0x0($v0)
    /* B6DC0 002B61C0 02402021 */  addu       $a0, $s2, $zero
    /* B6DC4 002B61C4 8C460008 */  lw         $a2, 0x8($v0)
    /* B6DC8 002B61C8 0C0ADAF9 */  jal        func_002B6BE4
    /* B6DCC 002B61CC 26250004 */   addiu     $a1, $s1, 0x4
    /* B6DD0 002B61D0 080AD96F */  j          .L002B65BC
    /* B6DD4 002B61D4 00000000 */   nop
  .L002B61D8:
    /* B6DD8 002B61D8 328500FF */  andi       $a1, $s4, 0xFF
    /* B6DDC 002B61DC 0C0AD9D4 */  jal        func_002B6750
    /* B6DE0 002B61E0 02A03021 */   addu      $a2, $s5, $zero
    /* B6DE4 002B61E4 00408821 */  addu       $s1, $v0, $zero
    /* B6DE8 002B61E8 122000F4 */  beqz       $s1, .L002B65BC
    /* B6DEC 002B61EC 02202021 */   addu      $a0, $s1, $zero
    /* B6DF0 002B61F0 02402821 */  addu       $a1, $s2, $zero
    /* B6DF4 002B61F4 0C0ADA39 */  jal        func_002B68E4
    /* B6DF8 002B61F8 A2300033 */   sb        $s0, 0x33($s1)
    /* B6DFC 002B61FC 02202021 */  addu       $a0, $s1, $zero
    /* B6E00 002B6200 00028400 */  sll        $s0, $v0, 16
    /* B6E04 002B6204 8E45001C */  lw         $a1, 0x1C($s2)
    /* B6E08 002B6208 0C0ADA56 */  jal        func_002B6958
    /* B6E0C 002B620C 00108403 */   sra       $s0, $s0, 16
    /* B6E10 002B6210 26250004 */  addiu      $a1, $s1, 0x4
    /* B6E14 002B6214 02003021 */  addu       $a2, $s0, $zero
    /* B6E18 002B6218 8E440014 */  lw         $a0, 0x14($s2)
    /* B6E1C 002B621C 0C0AE154 */  jal        func_002B8550
    /* B6E20 002B6220 00403821 */   addu      $a3, $v0, $zero
    /* B6E24 002B6224 080AD96F */  j          .L002B65BC
    /* B6E28 002B6228 00000000 */   nop
  .L002B622C:
    /* B6E2C 002B622C 8E510064 */  lw         $s1, 0x64($s2)
    /* B6E30 002B6230 122000E2 */  beqz       $s1, .L002B65BC
    /* B6E34 002B6234 32B300FF */   andi      $s3, $s5, 0xFF
  .L002B6238:
    /* B6E38 002B6238 92220031 */  lbu        $v0, 0x31($s1)
    /* B6E3C 002B623C 1453000E */  bne        $v0, $s3, .L002B6278
    /* B6E40 002B6240 02202021 */   addu      $a0, $s1, $zero
    /* B6E44 002B6244 02402821 */  addu       $a1, $s2, $zero
    /* B6E48 002B6248 0C0ADA39 */  jal        func_002B68E4
    /* B6E4C 002B624C A2360033 */   sb        $s6, 0x33($s1)
    /* B6E50 002B6250 02202021 */  addu       $a0, $s1, $zero
    /* B6E54 002B6254 00028400 */  sll        $s0, $v0, 16
    /* B6E58 002B6258 8E45001C */  lw         $a1, 0x1C($s2)
    /* B6E5C 002B625C 0C0ADA56 */  jal        func_002B6958
    /* B6E60 002B6260 00108403 */   sra       $s0, $s0, 16
    /* B6E64 002B6264 26250004 */  addiu      $a1, $s1, 0x4
    /* B6E68 002B6268 02003021 */  addu       $a2, $s0, $zero
    /* B6E6C 002B626C 8E440014 */  lw         $a0, 0x14($s2)
    /* B6E70 002B6270 0C0AE154 */  jal        func_002B8550
    /* B6E74 002B6274 00403821 */   addu      $a3, $v0, $zero
  .L002B6278:
    /* B6E78 002B6278 8E310000 */  lw         $s1, 0x0($s1)
    /* B6E7C 002B627C 122000CF */  beqz       $s1, .L002B65BC
    /* B6E80 002B6280 00000000 */   nop
    /* B6E84 002B6284 080AD88E */  j          .L002B6238
    /* B6E88 002B6288 00000000 */   nop
  .L002B628C:
    /* B6E8C 002B628C 328300FF */  andi       $v1, $s4, 0xFF
    /* B6E90 002B6290 2862001C */  slti       $v0, $v1, 0x1C
    /* B6E94 002B6294 10400010 */  beqz       $v0, .L002B62D8
    /* B6E98 002B6298 28620014 */   slti      $v0, $v1, 0x14
    /* B6E9C 002B629C 104000C7 */  beqz       $v0, .L002B65BC
    /* B6EA0 002B62A0 2402000A */   addiu     $v0, $zero, 0xA
    /* B6EA4 002B62A4 10620015 */  beq        $v1, $v0, .L002B62FC
    /* B6EA8 002B62A8 2862000B */   slti      $v0, $v1, 0xB
    /* B6EAC 002B62AC 10400005 */  beqz       $v0, .L002B62C4
    /* B6EB0 002B62B0 24020007 */   addiu     $v0, $zero, 0x7
    /* B6EB4 002B62B4 10620027 */  beq        $v1, $v0, .L002B6354
    /* B6EB8 002B62B8 32A600FF */   andi      $a2, $s5, 0xFF
    /* B6EBC 002B62BC 080AD96F */  j          .L002B65BC
    /* B6EC0 002B62C0 00000000 */   nop
  .L002B62C4:
    /* B6EC4 002B62C4 24020010 */  addiu      $v0, $zero, 0x10
    /* B6EC8 002B62C8 10620041 */  beq        $v1, $v0, .L002B63D0
    /* B6ECC 002B62CC 00151100 */   sll       $v0, $s5, 4
    /* B6ED0 002B62D0 080AD96F */  j          .L002B65BC
    /* B6ED4 002B62D4 00000000 */   nop
  .L002B62D8:
    /* B6ED8 002B62D8 2402005B */  addiu      $v0, $zero, 0x5B
    /* B6EDC 002B62DC 1062006A */  beq        $v1, $v0, .L002B6488
    /* B6EE0 002B62E0 2862005C */   slti      $v0, $v1, 0x5C
    /* B6EE4 002B62E4 104000B5 */  beqz       $v0, .L002B65BC
    /* B6EE8 002B62E8 24020040 */   addiu     $v0, $zero, 0x40
    /* B6EEC 002B62EC 1062003C */  beq        $v1, $v0, .L002B63E0
    /* B6EF0 002B62F0 32A600FF */   andi      $a2, $s5, 0xFF
    /* B6EF4 002B62F4 080AD96F */  j          .L002B65BC
    /* B6EF8 002B62F8 00000000 */   nop
  .L002B62FC:
    /* B6EFC 002B62FC 32A600FF */  andi       $a2, $s5, 0xFF
    /* B6F00 002B6300 8E430060 */  lw         $v1, 0x60($s2)
    /* B6F04 002B6304 00061100 */  sll        $v0, $a2, 4
    /* B6F08 002B6308 00431021 */  addu       $v0, $v0, $v1
    /* B6F0C 002B630C A0500007 */  sb         $s0, 0x7($v0)
    /* B6F10 002B6310 8E510064 */  lw         $s1, 0x64($s2)
    /* B6F14 002B6314 122000A9 */  beqz       $s1, .L002B65BC
    /* B6F18 002B6318 00C08021 */   addu      $s0, $a2, $zero
  .L002B631C:
    /* B6F1C 002B631C 92220031 */  lbu        $v0, 0x31($s1)
    /* B6F20 002B6320 14500007 */  bne        $v0, $s0, .L002B6340
    /* B6F24 002B6324 02202021 */   addu      $a0, $s1, $zero
    /* B6F28 002B6328 0C0ADA5D */  jal        func_002B6974
    /* B6F2C 002B632C 02402821 */   addu      $a1, $s2, $zero
    /* B6F30 002B6330 8E440014 */  lw         $a0, 0x14($s2)
    /* B6F34 002B6334 26250004 */  addiu      $a1, $s1, 0x4
    /* B6F38 002B6338 0C0AE108 */  jal        func_002B8420
    /* B6F3C 002B633C 304600FF */   andi      $a2, $v0, 0xFF
  .L002B6340:
    /* B6F40 002B6340 8E310000 */  lw         $s1, 0x0($s1)
    /* B6F44 002B6344 1220009D */  beqz       $s1, .L002B65BC
    /* B6F48 002B6348 00000000 */   nop
    /* B6F4C 002B634C 080AD8C7 */  j          .L002B631C
    /* B6F50 002B6350 00000000 */   nop
  .L002B6354:
    /* B6F54 002B6354 8E430060 */  lw         $v1, 0x60($s2)
    /* B6F58 002B6358 00061100 */  sll        $v0, $a2, 4
    /* B6F5C 002B635C 00431021 */  addu       $v0, $v0, $v1
    /* B6F60 002B6360 A0500009 */  sb         $s0, 0x9($v0)
    /* B6F64 002B6364 8E510064 */  lw         $s1, 0x64($s2)
    /* B6F68 002B6368 12200094 */  beqz       $s1, .L002B65BC
    /* B6F6C 002B636C 00C09821 */   addu      $s3, $a2, $zero
    /* B6F70 002B6370 24140003 */  addiu      $s4, $zero, 0x3
  .L002B6374:
    /* B6F74 002B6374 92220031 */  lbu        $v0, 0x31($s1)
    /* B6F78 002B6378 14530010 */  bne        $v0, $s3, .L002B63BC
    /* B6F7C 002B637C 00000000 */   nop
    /* B6F80 002B6380 92220034 */  lbu        $v0, 0x34($s1)
    /* B6F84 002B6384 1054000D */  beq        $v0, $s4, .L002B63BC
    /* B6F88 002B6388 02202021 */   addu      $a0, $s1, $zero
    /* B6F8C 002B638C 0C0ADA39 */  jal        func_002B68E4
    /* B6F90 002B6390 02402821 */   addu      $a1, $s2, $zero
    /* B6F94 002B6394 02202021 */  addu       $a0, $s1, $zero
    /* B6F98 002B6398 8E45001C */  lw         $a1, 0x1C($s2)
    /* B6F9C 002B639C 0C0ADA56 */  jal        func_002B6958
    /* B6FA0 002B63A0 00408021 */   addu      $s0, $v0, $zero
    /* B6FA4 002B63A4 26250004 */  addiu      $a1, $s1, 0x4
    /* B6FA8 002B63A8 00103400 */  sll        $a2, $s0, 16
    /* B6FAC 002B63AC 00063403 */  sra        $a2, $a2, 16
    /* B6FB0 002B63B0 8E440014 */  lw         $a0, 0x14($s2)
    /* B6FB4 002B63B4 0C0AE154 */  jal        func_002B8550
    /* B6FB8 002B63B8 00403821 */   addu      $a3, $v0, $zero
  .L002B63BC:
    /* B6FBC 002B63BC 8E310000 */  lw         $s1, 0x0($s1)
    /* B6FC0 002B63C0 1220007E */  beqz       $s1, .L002B65BC
    /* B6FC4 002B63C4 00000000 */   nop
    /* B6FC8 002B63C8 080AD8DD */  j          .L002B6374
    /* B6FCC 002B63CC 00000000 */   nop
  .L002B63D0:
    /* B6FD0 002B63D0 8E430060 */  lw         $v1, 0x60($s2)
    /* B6FD4 002B63D4 00431021 */  addu       $v0, $v0, $v1
    /* B6FD8 002B63D8 080AD96F */  j          .L002B65BC
    /* B6FDC 002B63DC A0500008 */   sb        $s0, 0x8($v0)
  .L002B63E0:
    /* B6FE0 002B63E0 8E430060 */  lw         $v1, 0x60($s2)
    /* B6FE4 002B63E4 00061100 */  sll        $v0, $a2, 4
    /* B6FE8 002B63E8 00431021 */  addu       $v0, $v0, $v1
    /* B6FEC 002B63EC A050000B */  sb         $s0, 0xB($v0)
    /* B6FF0 002B63F0 8E510064 */  lw         $s1, 0x64($s2)
    /* B6FF4 002B63F4 12200071 */  beqz       $s1, .L002B65BC
    /* B6FF8 002B63F8 00C0A021 */   addu      $s4, $a2, $zero
    /* B6FFC 002B63FC 24130003 */  addiu      $s3, $zero, 0x3
    /* B7000 002B6400 320200FF */  andi       $v0, $s0, 0xFF
    /* B7004 002B6404 2C500040 */  sltiu      $s0, $v0, 0x40
    /* B7008 002B6408 24170002 */  addiu      $s7, $zero, 0x2
    /* B700C 002B640C 24160002 */  addiu      $s6, $zero, 0x2
    /* B7010 002B6410 24150004 */  addiu      $s5, $zero, 0x4
  .L002B6414:
    /* B7014 002B6414 92220031 */  lbu        $v0, 0x31($s1)
    /* B7018 002B6418 14540016 */  bne        $v0, $s4, .L002B6474
    /* B701C 002B641C 00000000 */   nop
    /* B7020 002B6420 92220035 */  lbu        $v0, 0x35($s1)
    /* B7024 002B6424 10530013 */  beq        $v0, $s3, .L002B6474
    /* B7028 002B6428 00000000 */   nop
    /* B702C 002B642C 16000005 */  bnez       $s0, .L002B6444
    /* B7030 002B6430 00000000 */   nop
    /* B7034 002B6434 5040000F */  beql       $v0, $zero, .L002B6474
    /* B7038 002B6438 A2370035 */   sb        $s7, 0x35($s1)
    /* B703C 002B643C 080AD91D */  j          .L002B6474
    /* B7040 002B6440 00000000 */   nop
  .L002B6444:
    /* B7044 002B6444 14560003 */  bne        $v0, $s6, .L002B6454
    /* B7048 002B6448 00000000 */   nop
    /* B704C 002B644C 080AD91D */  j          .L002B6474
    /* B7050 002B6450 A2200035 */   sb        $zero, 0x35($s1)
  .L002B6454:
    /* B7054 002B6454 14550007 */  bne        $v0, $s5, .L002B6474
    /* B7058 002B6458 02402021 */   addu      $a0, $s2, $zero
    /* B705C 002B645C 8E220020 */  lw         $v0, 0x20($s1)
    /* B7060 002B6460 A2330035 */  sb         $s3, 0x35($s1)
    /* B7064 002B6464 8C420000 */  lw         $v0, 0x0($v0)
    /* B7068 002B6468 8C460008 */  lw         $a2, 0x8($v0)
    /* B706C 002B646C 0C0ADAF9 */  jal        func_002B6BE4
    /* B7070 002B6470 26250004 */   addiu     $a1, $s1, 0x4
  .L002B6474:
    /* B7074 002B6474 8E310000 */  lw         $s1, 0x0($s1)
    /* B7078 002B6478 12200050 */  beqz       $s1, .L002B65BC
    /* B707C 002B647C 00000000 */   nop
    /* B7080 002B6480 080AD905 */  j          .L002B6414
    /* B7084 002B6484 00000000 */   nop
  .L002B6488:
    /* B7088 002B6488 32A600FF */  andi       $a2, $s5, 0xFF
    /* B708C 002B648C 8E430060 */  lw         $v1, 0x60($s2)
    /* B7090 002B6490 00061100 */  sll        $v0, $a2, 4
    /* B7094 002B6494 00431021 */  addu       $v0, $v0, $v1
    /* B7098 002B6498 A050000A */  sb         $s0, 0xA($v0)
    /* B709C 002B649C 8E510064 */  lw         $s1, 0x64($s2)
    /* B70A0 002B64A0 12200046 */  beqz       $s1, .L002B65BC
    /* B70A4 002B64A4 00C08021 */   addu      $s0, $a2, $zero
  .L002B64A8:
    /* B70A8 002B64A8 92220031 */  lbu        $v0, 0x31($s1)
    /* B70AC 002B64AC 14500004 */  bne        $v0, $s0, .L002B64C0
    /* B70B0 002B64B0 26250004 */   addiu     $a1, $s1, 0x4
    /* B70B4 002B64B4 8E440014 */  lw         $a0, 0x14($s2)
    /* B70B8 002B64B8 0C0AE0DC */  jal        func_002B8370
    /* B70BC 002B64BC 326600FF */   andi      $a2, $s3, 0xFF
  .L002B64C0:
    /* B70C0 002B64C0 8E310000 */  lw         $s1, 0x0($s1)
    /* B70C4 002B64C4 1220003D */  beqz       $s1, .L002B65BC
    /* B70C8 002B64C8 00000000 */   nop
    /* B70CC 002B64CC 080AD92A */  j          .L002B64A8
    /* B70D0 002B64D0 00000000 */   nop
  .L002B64D4:
    /* B70D4 002B64D4 8E420020 */  lw         $v0, 0x20($s2)
    /* B70D8 002B64D8 14400007 */  bnez       $v0, .L002B64F8
    /* B70DC 002B64DC 00000000 */   nop
    /* B70E0 002B64E0 3C04800D */  lui        $a0, %hi(D_800CC690)
    /* B70E4 002B64E4 2484C690 */  addiu      $a0, $a0, %lo(D_800CC690)
    /* B70E8 002B64E8 3C05800D */  lui        $a1, %hi(D_800CC694)
    /* B70EC 002B64EC 24A5C694 */  addiu      $a1, $a1, %lo(D_800CC694)
    /* B70F0 002B64F0 0C0AFF50 */  jal        __assert
    /* B70F4 002B64F4 240602CA */   addiu     $a2, $zero, 0x2CA
  .L002B64F8:
    /* B70F8 002B64F8 8E450020 */  lw         $a1, 0x20($s2)
    /* B70FC 002B64FC 84A20000 */  lh         $v0, 0x0($a1)
    /* B7100 002B6500 328300FF */  andi       $v1, $s4, 0xFF
    /* B7104 002B6504 0062102A */  slt        $v0, $v1, $v0
    /* B7108 002B6508 1040002C */  beqz       $v0, .L002B65BC
    /* B710C 002B650C 02402021 */   addu      $a0, $s2, $zero
    /* B7110 002B6510 00031080 */  sll        $v0, $v1, 2
    /* B7114 002B6514 00A21021 */  addu       $v0, $a1, $v0
    /* B7118 002B6518 8C45000C */  lw         $a1, 0xC($v0)
    /* B711C 002B651C 0C0ADAE4 */  jal        func_002B6B90
    /* B7120 002B6520 02A03021 */   addu      $a2, $s5, $zero
    /* B7124 002B6524 080AD96F */  j          .L002B65BC
    /* B7128 002B6528 00000000 */   nop
  .L002B652C:
    /* B712C 002B652C 000319C0 */  sll        $v1, $v1, 7
    /* B7130 002B6530 328200FF */  andi       $v0, $s4, 0xFF
    /* B7134 002B6534 00621821 */  addu       $v1, $v1, $v0
    /* B7138 002B6538 32B300FF */  andi       $s3, $s5, 0xFF
    /* B713C 002B653C 8E420060 */  lw         $v0, 0x60($s2)
    /* B7140 002B6540 00138100 */  sll        $s0, $s3, 4
    /* B7144 002B6544 02021021 */  addu       $v0, $s0, $v0
    /* B7148 002B6548 84420004 */  lh         $v0, 0x4($v0)
    /* B714C 002B654C 2463E000 */  addiu      $v1, $v1, -0x2000
    /* B7150 002B6550 00430018 */  mult       $v0, $v1
    /* B7154 002B6554 00001012 */  mflo       $v0
    /* B7158 002B6558 04420001 */  bltzl      $v0, .L002B6560
    /* B715C 002B655C 24421FFF */   addiu     $v0, $v0, 0x1FFF
  .L002B6560:
    /* B7160 002B6560 0C0AD3C0 */  jal        func_002B4F00
    /* B7164 002B6564 00022343 */   sra       $a0, $v0, 13
    /* B7168 002B6568 8E420060 */  lw         $v0, 0x60($s2)
    /* B716C 002B656C 46000506 */  mov.s      $fs0, $fv0
    /* B7170 002B6570 02021021 */  addu       $v0, $s0, $v0
    /* B7174 002B6574 E454000C */  swc1       $fs0, 0xC($v0)
    /* B7178 002B6578 8E510064 */  lw         $s1, 0x64($s2)
    /* B717C 002B657C 1220000F */  beqz       $s1, .L002B65BC
    /* B7180 002B6580 02608021 */   addu      $s0, $s3, $zero
  .L002B6584:
    /* B7184 002B6584 92220031 */  lbu        $v0, 0x31($s1)
    /* B7188 002B6588 14500009 */  bne        $v0, $s0, .L002B65B0
    /* B718C 002B658C 00000000 */   nop
    /* B7190 002B6590 C6200028 */  lwc1       $fv0, 0x28($s1)
    /* B7194 002B6594 46140002 */  mul.s      $fv0, $fv0, $fs0
    /* B7198 002B6598 C621002C */  lwc1       $fv0f, 0x2C($s1)
    /* B719C 002B659C 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B71A0 002B65A0 8E440014 */  lw         $a0, 0x14($s2)
    /* B71A4 002B65A4 44060000 */  mfc1       $a2, $fv0
    /* B71A8 002B65A8 0C0AE12C */  jal        func_002B84B0
    /* B71AC 002B65AC 26250004 */   addiu     $a1, $s1, 0x4
  .L002B65B0:
    /* B71B0 002B65B0 8E310000 */  lw         $s1, 0x0($s1)
    /* B71B4 002B65B4 1620FFF3 */  bnez       $s1, .L002B6584
    /* B71B8 002B65B8 00000000 */   nop
  .L002B65BC:
    /* B71BC 002B65BC 8FBF0060 */  lw         $ra, 0x60($sp)
    /* B71C0 002B65C0 8FB7005C */  lw         $s7, 0x5C($sp)
    /* B71C4 002B65C4 8FB60058 */  lw         $s6, 0x58($sp)
    /* B71C8 002B65C8 8FB50054 */  lw         $s5, 0x54($sp)
    /* B71CC 002B65CC 8FB40050 */  lw         $s4, 0x50($sp)
    /* B71D0 002B65D0 8FB3004C */  lw         $s3, 0x4C($sp)
    /* B71D4 002B65D4 8FB20048 */  lw         $s2, 0x48($sp)
    /* B71D8 002B65D8 8FB10044 */  lw         $s1, 0x44($sp)
    /* B71DC 002B65DC 8FB00040 */  lw         $s0, 0x40($sp)
    /* B71E0 002B65E0 D7B40068 */  ldc1       $fs0, 0x68($sp)
    /* B71E4 002B65E4 03E00008 */  jr         $ra
    /* B71E8 002B65E8 27BD0070 */   addiu     $sp, $sp, 0x70
endlabel func_002B5D64
