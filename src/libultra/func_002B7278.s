.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7E78-0xB7F8C (VRAM 0x002B7278) */
glabel func_002B7278
    /* B7E78 002B7278 27BDFFB0 */  addiu      $sp, $sp, -0x50
    /* B7E7C 002B727C AFB00028 */  sw         $s0, 0x28($sp)
    /* B7E80 002B7280 00808021 */  addu       $s0, $a0, $zero
    /* B7E84 002B7284 AFB40038 */  sw         $s4, 0x38($sp)
    /* B7E88 002B7288 00A0A021 */  addu       $s4, $a1, $zero
    /* B7E8C 002B728C AFB5003C */  sw         $s5, 0x3C($sp)
    /* B7E90 002B7290 00C0A821 */  addu       $s5, $a2, $zero
    /* B7E94 002B7294 AFBF004C */  sw         $ra, 0x4C($sp)
    /* B7E98 002B7298 AFBE0048 */  sw         $fp, 0x48($sp)
    /* B7E9C 002B729C AFB70044 */  sw         $s7, 0x44($sp)
    /* B7EA0 002B72A0 AFB60040 */  sw         $s6, 0x40($sp)
    /* B7EA4 002B72A4 AFB30034 */  sw         $s3, 0x34($sp)
    /* B7EA8 002B72A8 AFB20030 */  sw         $s2, 0x30($sp)
    /* B7EAC 002B72AC 16A0000C */  bnez       $s5, .L002B72E0
    /* B7EB0 002B72B0 AFB1002C */   sw        $s1, 0x2C($sp)
    /* B7EB4 002B72B4 8E020004 */  lw         $v0, 0x4($s0)
    /* B7EB8 002B72B8 A680000C */  sh         $zero, 0xC($s4)
    /* B7EBC 002B72BC AE800004 */  sw         $zero, 0x4($s4)
    /* B7EC0 002B72C0 AE800008 */  sw         $zero, 0x8($s4)
    /* B7EC4 002B72C4 080ADCD7 */  j          .L002B735C
    /* B7EC8 002B72C8 AE820000 */   sw        $v0, 0x0($s4)
  .L002B72CC:
    /* B7ECC 002B72CC 8E130008 */  lw         $s3, 0x8($s0)
    /* B7ED0 002B72D0 9612001A */  lhu        $s2, 0x1A($s0)
    /* B7ED4 002B72D4 8E11000C */  lw         $s1, 0xC($s0)
    /* B7ED8 002B72D8 080ADCCF */  j          .L002B733C
    /* B7EDC 002B72DC AE930000 */   sw        $s3, 0x0($s4)
  .L002B72E0:
    /* B7EE0 002B72E0 9603001A */  lhu        $v1, 0x1A($s0)
    /* B7EE4 002B72E4 8E170008 */  lw         $s7, 0x8($s0)
    /* B7EE8 002B72E8 A7A30020 */  sh         $v1, 0x20($sp)
    /* B7EEC 002B72EC 8E1E000C */  lw         $fp, 0xC($s0)
    /* B7EF0 002B72F0 8E020004 */  lw         $v0, 0x4($s0)
    /* B7EF4 002B72F4 24160004 */  addiu      $s6, $zero, 0x4
    /* B7EF8 002B72F8 A600001A */  sh         $zero, 0x1A($s0)
    /* B7EFC 002B72FC AE00000C */  sw         $zero, 0xC($s0)
    /* B7F00 002B7300 AE020008 */  sw         $v0, 0x8($s0)
    /* B7F04 002B7304 02002021 */  addu       $a0, $s0, $zero
  .L002B7308:
    /* B7F08 002B7308 8E130008 */  lw         $s3, 0x8($s0)
    /* B7F0C 002B730C 9612001A */  lhu        $s2, 0x1A($s0)
    /* B7F10 002B7310 8E11000C */  lw         $s1, 0xC($s0)
    /* B7F14 002B7314 0C0ADBD4 */  jal        func_002B6F50
    /* B7F18 002B7318 27A50010 */   addiu     $a1, $sp, 0x10
    /* B7F1C 002B731C 87A20010 */  lh         $v0, 0x10($sp)
    /* B7F20 002B7320 1056FFEA */  beq        $v0, $s6, .L002B72CC
    /* B7F24 002B7324 00000000 */   nop
    /* B7F28 002B7328 8E02000C */  lw         $v0, 0xC($s0)
    /* B7F2C 002B732C 0055102B */  sltu       $v0, $v0, $s5
    /* B7F30 002B7330 1440FFF5 */  bnez       $v0, .L002B7308
    /* B7F34 002B7334 02002021 */   addu      $a0, $s0, $zero
    /* B7F38 002B7338 AE930000 */  sw         $s3, 0x0($s4)
  .L002B733C:
    /* B7F3C 002B733C A692000C */  sh         $s2, 0xC($s4)
    /* B7F40 002B7340 AE910004 */  sw         $s1, 0x4($s4)
    /* B7F44 002B7344 8E02000C */  lw         $v0, 0xC($s0)
    /* B7F48 002B7348 AE820008 */  sw         $v0, 0x8($s4)
    /* B7F4C 002B734C AE170008 */  sw         $s7, 0x8($s0)
    /* B7F50 002B7350 97A30020 */  lhu        $v1, 0x20($sp)
    /* B7F54 002B7354 A603001A */  sh         $v1, 0x1A($s0)
    /* B7F58 002B7358 AE1E000C */  sw         $fp, 0xC($s0)
  .L002B735C:
    /* B7F5C 002B735C 8FBF004C */  lw         $ra, 0x4C($sp)
    /* B7F60 002B7360 8FBE0048 */  lw         $fp, 0x48($sp)
    /* B7F64 002B7364 8FB70044 */  lw         $s7, 0x44($sp)
    /* B7F68 002B7368 8FB60040 */  lw         $s6, 0x40($sp)
    /* B7F6C 002B736C 8FB5003C */  lw         $s5, 0x3C($sp)
    /* B7F70 002B7370 8FB40038 */  lw         $s4, 0x38($sp)
    /* B7F74 002B7374 8FB30034 */  lw         $s3, 0x34($sp)
    /* B7F78 002B7378 8FB20030 */  lw         $s2, 0x30($sp)
    /* B7F7C 002B737C 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B7F80 002B7380 8FB00028 */  lw         $s0, 0x28($sp)
    /* B7F84 002B7384 03E00008 */  jr         $ra
    /* B7F88 002B7388 27BD0050 */   addiu     $sp, $sp, 0x50
endlabel func_002B7278
