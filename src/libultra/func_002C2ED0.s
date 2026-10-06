.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC3AD0-0xC3D20 (VRAM 0x002C2ED0) */
glabel func_002C2ED0
    /* C3AD0 002C2ED0 27BDFFA0 */  addiu      $sp, $sp, -0x60
    /* C3AD4 002C2ED4 AFB5004C */  sw         $s5, 0x4C($sp)
    /* C3AD8 002C2ED8 0080A821 */  addu       $s5, $a0, $zero
    /* C3ADC 002C2EDC AFB70054 */  sw         $s7, 0x54($sp)
    /* C3AE0 002C2EE0 3C17800E */  lui        $s7, %hi(D_800D9330)
    /* C3AE4 002C2EE4 26F79330 */  addiu      $s7, $s7, %lo(D_800D9330)
    /* C3AE8 002C2EE8 30A300FF */  andi       $v1, $a1, 0xFF
    /* C3AEC 002C2EEC 24040058 */  addiu      $a0, $zero, 0x58
    /* C3AF0 002C2EF0 AFBF0058 */  sw         $ra, 0x58($sp)
    /* C3AF4 002C2EF4 AFB60050 */  sw         $s6, 0x50($sp)
    /* C3AF8 002C2EF8 AFB40048 */  sw         $s4, 0x48($sp)
    /* C3AFC 002C2EFC AFB30044 */  sw         $s3, 0x44($sp)
    /* C3B00 002C2F00 AFB20040 */  sw         $s2, 0x40($sp)
    /* C3B04 002C2F04 AFB1003C */  sw         $s1, 0x3C($sp)
    /* C3B08 002C2F08 14640003 */  bne        $v1, $a0, .L002C2F18
    /* C3B0C 002C2F0C AFB00038 */   sw        $s0, 0x38($sp)
    /* C3B10 002C2F10 3C17800E */  lui        $s7, %hi(D_800D9344)
    /* C3B14 002C2F14 26F79344 */  addiu      $s7, $s7, %lo(D_800D9344)
  .L002C2F18:
    /* C3B18 002C2F18 2402006F */  addiu      $v0, $zero, 0x6F
    /* C3B1C 002C2F1C 10620007 */  beq        $v1, $v0, .L002C2F3C
    /* C3B20 002C2F20 24020078 */   addiu     $v0, $zero, 0x78
    /* C3B24 002C2F24 10620006 */  beq        $v1, $v0, .L002C2F40
    /* C3B28 002C2F28 24160010 */   addiu     $s6, $zero, 0x10
    /* C3B2C 002C2F2C 54640004 */  bnel       $v1, $a0, .L002C2F40
    /* C3B30 002C2F30 2416000A */   addiu     $s6, $zero, 0xA
    /* C3B34 002C2F34 080B0BD1 */  j          .L002C2F44
    /* C3B38 002C2F38 24140018 */   addiu     $s4, $zero, 0x18
  .L002C2F3C:
    /* C3B3C 002C2F3C 24160008 */  addiu      $s6, $zero, 0x8
  .L002C2F40:
    /* C3B40 002C2F40 24140018 */  addiu      $s4, $zero, 0x18
  .L002C2F44:
    /* C3B44 002C2F44 8EB20000 */  lw         $s2, 0x0($s5)
    /* C3B48 002C2F48 8EB30004 */  lw         $s3, 0x4($s5)
    /* C3B4C 002C2F4C 30A500FF */  andi       $a1, $a1, 0xFF
    /* C3B50 002C2F50 24020064 */  addiu      $v0, $zero, 0x64
    /* C3B54 002C2F54 10A20003 */  beq        $a1, $v0, .L002C2F64
    /* C3B58 002C2F58 24020069 */   addiu     $v0, $zero, 0x69
    /* C3B5C 002C2F5C 14A20009 */  bne        $a1, $v0, .L002C2F84
    /* C3B60 002C2F60 02721025 */   or        $v0, $s3, $s2
  .L002C2F64:
    /* C3B64 002C2F64 8EA20000 */  lw         $v0, 0x0($s5)
    /* C3B68 002C2F68 04410006 */  bgez       $v0, .L002C2F84
    /* C3B6C 002C2F6C 02721025 */   or        $v0, $s3, $s2
    /* C3B70 002C2F70 00139823 */  negu       $s3, $s3
    /* C3B74 002C2F74 00129023 */  negu       $s2, $s2
    /* C3B78 002C2F78 0013102B */  sltu       $v0, $zero, $s3
    /* C3B7C 002C2F7C 02429023 */  subu       $s2, $s2, $v0
    /* C3B80 002C2F80 02721025 */  or         $v0, $s3, $s2
  .L002C2F84:
    /* C3B84 002C2F84 54400005 */  bnel       $v0, $zero, .L002C2F9C
    /* C3B88 002C2F88 2694FFFF */   addiu     $s4, $s4, -0x1
    /* C3B8C 002C2F8C 8EA20024 */  lw         $v0, 0x24($s5)
    /* C3B90 002C2F90 1040000D */  beqz       $v0, .L002C2FC8
    /* C3B94 002C2F94 02C03821 */   addu      $a3, $s6, $zero
    /* C3B98 002C2F98 2694FFFF */  addiu      $s4, $s4, -0x1
  .L002C2F9C:
    /* C3B9C 002C2F9C 02C03821 */  addu       $a3, $s6, $zero
    /* C3BA0 002C2FA0 00003021 */  addu       $a2, $zero, $zero
    /* C3BA4 002C2FA4 02402021 */  addu       $a0, $s2, $zero
    /* C3BA8 002C2FA8 02602821 */  addu       $a1, $s3, $zero
    /* C3BAC 002C2FAC 27B00010 */  addiu      $s0, $sp, 0x10
    /* C3BB0 002C2FB0 0C0B1908 */  jal        func_002C6420
    /* C3BB4 002C2FB4 02148021 */   addu      $s0, $s0, $s4
    /* C3BB8 002C2FB8 02E31021 */  addu       $v0, $s7, $v1
    /* C3BBC 002C2FBC 90420000 */  lbu        $v0, 0x0($v0)
    /* C3BC0 002C2FC0 A2020000 */  sb         $v0, 0x0($s0)
    /* C3BC4 002C2FC4 02C03821 */  addu       $a3, $s6, $zero
  .L002C2FC8:
    /* C3BC8 002C2FC8 00003021 */  addu       $a2, $zero, $zero
    /* C3BCC 002C2FCC 02402021 */  addu       $a0, $s2, $zero
    /* C3BD0 002C2FD0 0C0B17A4 */  jal        func_002C5E90
    /* C3BD4 002C2FD4 02602821 */   addu      $a1, $s3, $zero
    /* C3BD8 002C2FD8 AEA20000 */  sw         $v0, 0x0($s5)
    /* C3BDC 002C2FDC AEA30004 */  sw         $v1, 0x4($s5)
    /* C3BE0 002C2FE0 080B0C18 */  j          .L002C3060
    /* C3BE4 002C2FE4 00000000 */   nop
  .L002C2FE8:
    /* C3BE8 002C2FE8 5A800025 */  blezl      $s4, .L002C3080
    /* C3BEC 002C2FEC 27A50010 */   addiu     $a1, $sp, 0x10
    /* C3BF0 002C2FF0 02C08821 */  addu       $s1, $s6, $zero
    /* C3BF4 002C2FF4 00008021 */  addu       $s0, $zero, $zero
    /* C3BF8 002C2FF8 8EB20000 */  lw         $s2, 0x0($s5)
    /* C3BFC 002C2FFC 8EB30004 */  lw         $s3, 0x4($s5)
    /* C3C00 002C3000 02003021 */  addu       $a2, $s0, $zero
    /* C3C04 002C3004 02203821 */  addu       $a3, $s1, $zero
    /* C3C08 002C3008 02402021 */  addu       $a0, $s2, $zero
    /* C3C0C 002C300C 0C0B14C8 */  jal        func_002C5320
    /* C3C10 002C3010 02602821 */   addu      $a1, $s3, $zero
    /* C3C14 002C3014 02402021 */  addu       $a0, $s2, $zero
    /* C3C18 002C3018 02602821 */  addu       $a1, $s3, $zero
    /* C3C1C 002C301C 02003021 */  addu       $a2, $s0, $zero
    /* C3C20 002C3020 AFA20028 */  sw         $v0, 0x28($sp)
    /* C3C24 002C3024 AFA3002C */  sw         $v1, 0x2C($sp)
    /* C3C28 002C3028 0C0B1644 */  jal        func_002C5910
    /* C3C2C 002C302C 02203821 */   addu      $a3, $s1, $zero
    /* C3C30 002C3030 8FA40028 */  lw         $a0, 0x28($sp)
    /* C3C34 002C3034 8FA5002C */  lw         $a1, 0x2C($sp)
    /* C3C38 002C3038 AFA20030 */  sw         $v0, 0x30($sp)
    /* C3C3C 002C303C AFA30034 */  sw         $v1, 0x34($sp)
    /* C3C40 002C3040 AEA40000 */  sw         $a0, 0x0($s5)
    /* C3C44 002C3044 AEA50004 */  sw         $a1, 0x4($s5)
    /* C3C48 002C3048 8FA20034 */  lw         $v0, 0x34($sp)
    /* C3C4C 002C304C 2694FFFF */  addiu      $s4, $s4, -0x1
    /* C3C50 002C3050 02E21021 */  addu       $v0, $s7, $v0
    /* C3C54 002C3054 90430000 */  lbu        $v1, 0x0($v0)
    /* C3C58 002C3058 03B41021 */  addu       $v0, $sp, $s4
    /* C3C5C 002C305C A0430010 */  sb         $v1, 0x10($v0)
  .L002C3060:
    /* C3C60 002C3060 8EA20000 */  lw         $v0, 0x0($s5)
    /* C3C64 002C3064 1C40FFE0 */  bgtz       $v0, .L002C2FE8
    /* C3C68 002C3068 00000000 */   nop
    /* C3C6C 002C306C 14400004 */  bnez       $v0, .L002C3080
    /* C3C70 002C3070 27A50010 */   addiu     $a1, $sp, 0x10
    /* C3C74 002C3074 8EA20004 */  lw         $v0, 0x4($s5)
    /* C3C78 002C3078 1440FFDB */  bnez       $v0, .L002C2FE8
    /* C3C7C 002C307C 00000000 */   nop
  .L002C3080:
    /* C3C80 002C3080 00B42821 */  addu       $a1, $a1, $s4
    /* C3C84 002C3084 24060018 */  addiu      $a2, $zero, 0x18
    /* C3C88 002C3088 8EA40008 */  lw         $a0, 0x8($s5)
    /* C3C8C 002C308C 00D43023 */  subu       $a2, $a2, $s4
    /* C3C90 002C3090 0C0B0924 */  jal        memcpy
    /* C3C94 002C3094 AEA60014 */   sw        $a2, 0x14($s5)
    /* C3C98 002C3098 8EA40014 */  lw         $a0, 0x14($s5)
    /* C3C9C 002C309C 8EA30024 */  lw         $v1, 0x24($s5)
    /* C3CA0 002C30A0 0083102A */  slt        $v0, $a0, $v1
    /* C3CA4 002C30A4 10400002 */  beqz       $v0, .L002C30B0
    /* C3CA8 002C30A8 00641023 */   subu      $v0, $v1, $a0
    /* C3CAC 002C30AC AEA20010 */  sw         $v0, 0x10($s5)
  .L002C30B0:
    /* C3CB0 002C30B0 8EA20024 */  lw         $v0, 0x24($s5)
    /* C3CB4 002C30B4 0441000F */  bgez       $v0, .L002C30F4
    /* C3CB8 002C30B8 24030010 */   addiu     $v1, $zero, 0x10
    /* C3CBC 002C30BC 8EA20030 */  lw         $v0, 0x30($s5)
    /* C3CC0 002C30C0 30420014 */  andi       $v0, $v0, 0x14
    /* C3CC4 002C30C4 1443000B */  bne        $v0, $v1, .L002C30F4
    /* C3CC8 002C30C8 00000000 */   nop
    /* C3CCC 002C30CC 8EA20028 */  lw         $v0, 0x28($s5)
    /* C3CD0 002C30D0 8EA3000C */  lw         $v1, 0xC($s5)
    /* C3CD4 002C30D4 8EA40010 */  lw         $a0, 0x10($s5)
    /* C3CD8 002C30D8 00431023 */  subu       $v0, $v0, $v1
    /* C3CDC 002C30DC 8EA30014 */  lw         $v1, 0x14($s5)
    /* C3CE0 002C30E0 00441023 */  subu       $v0, $v0, $a0
    /* C3CE4 002C30E4 0043A023 */  subu       $s4, $v0, $v1
    /* C3CE8 002C30E8 1A800002 */  blez       $s4, .L002C30F4
    /* C3CEC 002C30EC 00941021 */   addu      $v0, $a0, $s4
    /* C3CF0 002C30F0 AEA20010 */  sw         $v0, 0x10($s5)
  .L002C30F4:
    /* C3CF4 002C30F4 8FBF0058 */  lw         $ra, 0x58($sp)
    /* C3CF8 002C30F8 8FB70054 */  lw         $s7, 0x54($sp)
    /* C3CFC 002C30FC 8FB60050 */  lw         $s6, 0x50($sp)
    /* C3D00 002C3100 8FB5004C */  lw         $s5, 0x4C($sp)
    /* C3D04 002C3104 8FB40048 */  lw         $s4, 0x48($sp)
    /* C3D08 002C3108 8FB30044 */  lw         $s3, 0x44($sp)
    /* C3D0C 002C310C 8FB20040 */  lw         $s2, 0x40($sp)
    /* C3D10 002C3110 8FB1003C */  lw         $s1, 0x3C($sp)
    /* C3D14 002C3114 8FB00038 */  lw         $s0, 0x38($sp)
    /* C3D18 002C3118 03E00008 */  jr         $ra
    /* C3D1C 002C311C 27BD0060 */   addiu     $sp, $sp, 0x60
endlabel func_002C2ED0
