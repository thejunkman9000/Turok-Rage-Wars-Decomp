.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC4AA0-0xC4C74 (VRAM 0x002C3EA0) */
glabel adecReadBits
    /* C4AA0 002C3EA0 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* C4AA4 002C3EA4 AFB10004 */  sw         $s1, 0x4($sp)
    /* C4AA8 002C3EA8 00808821 */  addu       $s1, $a0, $zero
    /* C4AAC 002C3EAC 3C04800E */  lui        $a0, %hi(D_800D94E8)
    /* C4AB0 002C3EB0 248494E8 */  addiu      $a0, $a0, %lo(D_800D94E8)
    /* C4AB4 002C3EB4 AFB00000 */  sw         $s0, 0x0($sp)
    /* C4AB8 002C3EB8 94820000 */  lhu        $v0, 0x0($a0)
    /* C4ABC 002C3EBC 8FB90018 */  lw         $t9, 0x18($sp)
  .L002C3EC0:
    /* C4AC0 002C3EC0 1440000B */  bnez       $v0, .L002C3EF0
    /* C4AC4 002C3EC4 30C2FFFF */   andi      $v0, $a2, 0xFFFF
    /* C4AC8 002C3EC8 8F220014 */  lw         $v0, 0x14($t9)
    /* C4ACC 002C3ECC 94430000 */  lhu        $v1, 0x0($v0)
    /* C4AD0 002C3ED0 24420002 */  addiu      $v0, $v0, 0x2
    /* C4AD4 002C3ED4 AF220014 */  sw         $v0, 0x14($t9)
    /* C4AD8 002C3ED8 24020010 */  addiu      $v0, $zero, 0x10
    /* C4ADC 002C3EDC A4820000 */  sh         $v0, 0x0($a0)
    /* C4AE0 002C3EE0 3C028015 */  lui        $v0, %hi(D_80151090)
    /* C4AE4 002C3EE4 24421090 */  addiu      $v0, $v0, %lo(D_80151090)
    /* C4AE8 002C3EE8 A4430000 */  sh         $v1, 0x0($v0)
    /* C4AEC 002C3EEC 30C2FFFF */  andi       $v0, $a2, 0xFFFF
  .L002C3EF0:
    /* C4AF0 002C3EF0 1040005B */  beqz       $v0, .L002C4060
    /* C4AF4 002C3EF4 00004821 */   addu      $t1, $zero, $zero
    /* C4AF8 002C3EF8 00805021 */  addu       $t2, $a0, $zero
    /* C4AFC 002C3EFC 3C0B8015 */  lui        $t3, %hi(D_80151090)
    /* C4B00 002C3F00 256B1090 */  addiu      $t3, $t3, %lo(D_80151090)
    /* C4B04 002C3F04 24100010 */  addiu      $s0, $zero, 0x10
    /* C4B08 002C3F08 02071004 */  sllv       $v0, $a3, $s0
    /* C4B0C 002C3F0C 02027807 */  srav       $t7, $v0, $s0
    /* C4B10 002C3F10 30ADFFFF */  andi       $t5, $a1, 0xFFFF
    /* C4B14 002C3F14 3C02800E */  lui        $v0, %hi(D_800D93A4)
    /* C4B18 002C3F18 244293A4 */  addiu      $v0, $v0, %lo(D_800D93A4)
    /* C4B1C 002C3F1C 000D1840 */  sll        $v1, $t5, 1
    /* C4B20 002C3F20 00627021 */  addu       $t6, $v1, $v0
    /* C4B24 002C3F24 3C18800E */  lui        $t8, %hi(D_800D9380)
    /* C4B28 002C3F28 27189380 */  addiu      $t8, $t8, %lo(D_800D9380)
    /* C4B2C 002C3F2C 00786021 */  addu       $t4, $v1, $t8
  .L002C3F30:
    /* C4B30 002C3F30 95430000 */  lhu        $v1, 0x0($t2)
    /* C4B34 002C3F34 006D102B */  sltu       $v0, $v1, $t5
    /* C4B38 002C3F38 10400029 */  beqz       $v0, .L002C3FE0
    /* C4B3C 002C3F3C 3064FFFF */   andi      $a0, $v1, 0xFFFF
    /* C4B40 002C3F40 00A34023 */  subu       $t0, $a1, $v1
    /* C4B44 002C3F44 00042040 */  sll        $a0, $a0, 1
    /* C4B48 002C3F48 00982021 */  addu       $a0, $a0, $t8
    /* C4B4C 002C3F4C 00091400 */  sll        $v0, $t1, 16
    /* C4B50 002C3F50 000213C3 */  sra        $v0, $v0, 15
    /* C4B54 002C3F54 95630000 */  lhu        $v1, 0x0($t3)
    /* C4B58 002C3F58 94840000 */  lhu        $a0, 0x0($a0)
    /* C4B5C 002C3F5C 00513821 */  addu       $a3, $v0, $s1
    /* C4B60 002C3F60 00641824 */  and        $v1, $v1, $a0
    /* C4B64 002C3F64 3104FFFF */  andi       $a0, $t0, 0xFFFF
    /* C4B68 002C3F68 00831804 */  sllv       $v1, $v1, $a0
    /* C4B6C 002C3F6C A4E30000 */  sh         $v1, 0x0($a3)
    /* C4B70 002C3F70 8F220014 */  lw         $v0, 0x14($t9)
    /* C4B74 002C3F74 94430000 */  lhu        $v1, 0x0($v0)
    /* C4B78 002C3F78 24420002 */  addiu      $v0, $v0, 0x2
    /* C4B7C 002C3F7C AF220014 */  sw         $v0, 0x14($t9)
    /* C4B80 002C3F80 02041023 */  subu       $v0, $s0, $a0
    /* C4B84 002C3F84 00042040 */  sll        $a0, $a0, 1
    /* C4B88 002C3F88 00982021 */  addu       $a0, $a0, $t8
    /* C4B8C 002C3F8C A5630000 */  sh         $v1, 0x0($t3)
    /* C4B90 002C3F90 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* C4B94 002C3F94 00431807 */  srav       $v1, $v1, $v0
    /* C4B98 002C3F98 94820000 */  lhu        $v0, 0x0($a0)
    /* C4B9C 002C3F9C 94E40000 */  lhu        $a0, 0x0($a3)
    /* C4BA0 002C3FA0 00621824 */  and        $v1, $v1, $v0
    /* C4BA4 002C3FA4 00832025 */  or         $a0, $a0, $v1
    /* C4BA8 002C3FA8 11E0000B */  beqz       $t7, .L002C3FD8
    /* C4BAC 002C3FAC A4E40000 */   sh        $a0, 0x0($a3)
    /* C4BB0 002C3FB0 00041400 */  sll        $v0, $a0, 16
    /* C4BB4 002C3FB4 95C30000 */  lhu        $v1, 0x0($t6)
    /* C4BB8 002C3FB8 00021403 */  sra        $v0, $v0, 16
    /* C4BBC 002C3FBC 00431024 */  and        $v0, $v0, $v1
    /* C4BC0 002C3FC0 5040001E */  beql       $v0, $zero, .L002C403C
    /* C4BC4 002C3FC4 02081023 */   subu      $v0, $s0, $t0
    /* C4BC8 002C3FC8 95820000 */  lhu        $v0, 0x0($t4)
    /* C4BCC 002C3FCC 00021027 */  nor        $v0, $zero, $v0
    /* C4BD0 002C3FD0 00821025 */  or         $v0, $a0, $v0
    /* C4BD4 002C3FD4 A4E20000 */  sh         $v0, 0x0($a3)
  .L002C3FD8:
    /* C4BD8 002C3FD8 080B100F */  j          .L002C403C
    /* C4BDC 002C3FDC 02081023 */   subu      $v0, $s0, $t0
  .L002C3FE0:
    /* C4BE0 002C3FE0 95430000 */  lhu        $v1, 0x0($t2)
    /* C4BE4 002C3FE4 95620000 */  lhu        $v0, 0x0($t3)
    /* C4BE8 002C3FE8 95840000 */  lhu        $a0, 0x0($t4)
    /* C4BEC 002C3FEC 006D1823 */  subu       $v1, $v1, $t5
    /* C4BF0 002C3FF0 00621007 */  srav       $v0, $v0, $v1
    /* C4BF4 002C3FF4 00442024 */  and        $a0, $v0, $a0
    /* C4BF8 002C3FF8 00091400 */  sll        $v0, $t1, 16
    /* C4BFC 002C3FFC 000213C3 */  sra        $v0, $v0, 15
    /* C4C00 002C4000 00513821 */  addu       $a3, $v0, $s1
    /* C4C04 002C4004 11E0000B */  beqz       $t7, .L002C4034
    /* C4C08 002C4008 A4E40000 */   sh        $a0, 0x0($a3)
    /* C4C0C 002C400C 00041400 */  sll        $v0, $a0, 16
    /* C4C10 002C4010 95C30000 */  lhu        $v1, 0x0($t6)
    /* C4C14 002C4014 00021403 */  sra        $v0, $v0, 16
    /* C4C18 002C4018 00431024 */  and        $v0, $v0, $v1
    /* C4C1C 002C401C 10400005 */  beqz       $v0, .L002C4034
    /* C4C20 002C4020 00000000 */   nop
    /* C4C24 002C4024 95820000 */  lhu        $v0, 0x0($t4)
    /* C4C28 002C4028 00021027 */  nor        $v0, $zero, $v0
    /* C4C2C 002C402C 00821025 */  or         $v0, $a0, $v0
    /* C4C30 002C4030 A4E20000 */  sh         $v0, 0x0($a3)
  .L002C4034:
    /* C4C34 002C4034 95420000 */  lhu        $v0, 0x0($t2)
    /* C4C38 002C4038 00451023 */  subu       $v0, $v0, $a1
  .L002C403C:
    /* C4C3C 002C403C A5420000 */  sh         $v0, 0x0($t2)
    /* C4C40 002C4040 25220001 */  addiu      $v0, $t1, 0x1
    /* C4C44 002C4044 00404821 */  addu       $t1, $v0, $zero
    /* C4C48 002C4048 00021400 */  sll        $v0, $v0, 16
    /* C4C4C 002C404C 00021403 */  sra        $v0, $v0, 16
    /* C4C50 002C4050 30C3FFFF */  andi       $v1, $a2, 0xFFFF
    /* C4C54 002C4054 0043102A */  slt        $v0, $v0, $v1
    /* C4C58 002C4058 1440FFB5 */  bnez       $v0, .L002C3F30
    /* C4C5C 002C405C 00000000 */   nop
  .L002C4060:
    /* C4C60 002C4060 8FB10004 */  lw         $s1, 0x4($sp)
    /* C4C64 002C4064 8FB00000 */  lw         $s0, 0x0($sp)
    /* C4C68 002C4068 24020001 */  addiu      $v0, $zero, 0x1
    /* C4C6C 002C406C 03E00008 */  jr         $ra
    /* C4C70 002C4070 27BD0008 */   addiu     $sp, $sp, 0x8
endlabel adecReadBits
