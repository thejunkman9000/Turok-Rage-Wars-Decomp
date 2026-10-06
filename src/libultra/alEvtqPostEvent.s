.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5DA4-0xB5EB0 (VRAM 0x002B51A4) */
glabel alEvtqPostEvent
    /* B5DA4 002B51A4 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B5DA8 002B51A8 AFB40020 */  sw         $s4, 0x20($sp)
    /* B5DAC 002B51AC 0080A021 */  addu       $s4, $a0, $zero
    /* B5DB0 002B51B0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B5DB4 002B51B4 00A09821 */  addu       $s3, $a1, $zero
    /* B5DB8 002B51B8 AFB10014 */  sw         $s1, 0x14($sp)
    /* B5DBC 002B51BC 00C08821 */  addu       $s1, $a2, $zero
    /* B5DC0 002B51C0 AFB20018 */  sw         $s2, 0x18($sp)
    /* B5DC4 002B51C4 00009021 */  addu       $s2, $zero, $zero
    /* B5DC8 002B51C8 24040001 */  addiu      $a0, $zero, 0x1
    /* B5DCC 002B51CC AFBF0028 */  sw         $ra, 0x28($sp)
    /* B5DD0 002B51D0 AFB50024 */  sw         $s5, 0x24($sp)
    /* B5DD4 002B51D4 0C0B0898 */  jal        osSetIntMask
    /* B5DD8 002B51D8 AFB00010 */   sw        $s0, 0x10($sp)
    /* B5DDC 002B51DC 8E900000 */  lw         $s0, 0x0($s4)
    /* B5DE0 002B51E0 1600000A */  bnez       $s0, .L002B520C
    /* B5DE4 002B51E4 0040A821 */   addu      $s5, $v0, $zero
    /* B5DE8 002B51E8 080AD4A1 */  j          .L002B5284
    /* B5DEC 002B51EC 00000000 */   nop
  .L002B51F0:
    /* B5DF0 002B51F0 AC910008 */  sw         $s1, 0x8($a0)
    /* B5DF4 002B51F4 8CC20008 */  lw         $v0, 0x8($a2)
    /* B5DF8 002B51F8 00511023 */  subu       $v0, $v0, $s1
    /* B5DFC 002B51FC 0C0ADD54 */  jal        alLink
    /* B5E00 002B5200 ACC20008 */   sw        $v0, 0x8($a2)
    /* B5E04 002B5204 080AD4A1 */  j          .L002B5284
    /* B5E08 002B5208 00000000 */   nop
  .L002B520C:
    /* B5E0C 002B520C 0C0ADD48 */  jal        alUnlink
    /* B5E10 002B5210 02002021 */   addu      $a0, $s0, $zero
    /* B5E14 002B5214 02602021 */  addu       $a0, $s3, $zero
    /* B5E18 002B5218 2605000C */  addiu      $a1, $s0, 0xC
    /* B5E1C 002B521C 0C0AD4F8 */  jal        alCopy
    /* B5E20 002B5220 24060010 */   addiu     $a2, $zero, 0x10
    /* B5E24 002B5224 3C027FFF */  lui        $v0, (0x7FFFFFFF >> 16)
    /* B5E28 002B5228 3442FFFF */  ori        $v0, $v0, (0x7FFFFFFF & 0xFFFF)
    /* B5E2C 002B522C 52220001 */  beql       $s1, $v0, .L002B5234
    /* B5E30 002B5230 2412FFFF */   addiu     $s2, $zero, -0x1
  .L002B5234:
    /* B5E34 002B5234 26850008 */  addiu      $a1, $s4, 0x8
    /* B5E38 002B5238 10A00012 */  beqz       $a1, .L002B5284
    /* B5E3C 002B523C 00000000 */   nop
  .L002B5240:
    /* B5E40 002B5240 8CA60000 */  lw         $a2, 0x0($a1)
    /* B5E44 002B5244 14C00008 */  bnez       $a2, .L002B5268
    /* B5E48 002B5248 00000000 */   nop
    /* B5E4C 002B524C 52400002 */  beql       $s2, $zero, .L002B5258
    /* B5E50 002B5250 AE110008 */   sw        $s1, 0x8($s0)
    /* B5E54 002B5254 AE000008 */  sw         $zero, 0x8($s0)
  .L002B5258:
    /* B5E58 002B5258 0C0ADD54 */  jal        alLink
    /* B5E5C 002B525C 02002021 */   addu      $a0, $s0, $zero
    /* B5E60 002B5260 080AD4A1 */  j          .L002B5284
    /* B5E64 002B5264 00000000 */   nop
  .L002B5268:
    /* B5E68 002B5268 8CC30008 */  lw         $v1, 0x8($a2)
    /* B5E6C 002B526C 0223102A */  slt        $v0, $s1, $v1
    /* B5E70 002B5270 1440FFDF */  bnez       $v0, .L002B51F0
    /* B5E74 002B5274 02002021 */   addu      $a0, $s0, $zero
    /* B5E78 002B5278 02238823 */  subu       $s1, $s1, $v1
    /* B5E7C 002B527C 080AD490 */  j          .L002B5240
    /* B5E80 002B5280 00C02821 */   addu      $a1, $a2, $zero
  .L002B5284:
    /* B5E84 002B5284 0C0B0898 */  jal        osSetIntMask
    /* B5E88 002B5288 02A02021 */   addu      $a0, $s5, $zero
    /* B5E8C 002B528C 8FBF0028 */  lw         $ra, 0x28($sp)
    /* B5E90 002B5290 8FB50024 */  lw         $s5, 0x24($sp)
    /* B5E94 002B5294 8FB40020 */  lw         $s4, 0x20($sp)
    /* B5E98 002B5298 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B5E9C 002B529C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B5EA0 002B52A0 8FB10014 */  lw         $s1, 0x14($sp)
    /* B5EA4 002B52A4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B5EA8 002B52A8 03E00008 */  jr         $ra
    /* B5EAC 002B52AC 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel alEvtqPostEvent
