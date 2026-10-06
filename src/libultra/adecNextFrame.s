.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5E5C-0xC5EFC (VRAM 0x002C525C) */
glabel adecNextFrame
    /* C5E5C 002C525C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C5E60 002C5260 AFB20018 */  sw         $s2, 0x18($sp)
    /* C5E64 002C5264 3C128015 */  lui        $s2, %hi(D_80151CC8)
    /* C5E68 002C5268 26521CC8 */  addiu      $s2, $s2, %lo(D_80151CC8)
    /* C5E6C 002C526C AFBF001C */  sw         $ra, 0x1C($sp)
    /* C5E70 002C5270 AFB10014 */  sw         $s1, 0x14($sp)
    /* C5E74 002C5274 AFB00010 */  sw         $s0, 0x10($sp)
    /* C5E78 002C5278 8E420010 */  lw         $v0, 0x10($s2)
    /* C5E7C 002C527C 10400019 */  beqz       $v0, .L002C52E4
    /* C5E80 002C5280 00001021 */   addu      $v0, $zero, $zero
    /* C5E84 002C5284 0C0B111E */  jal        adecDecodeFrame
    /* C5E88 002C5288 02402021 */   addu      $a0, $s2, $zero
    /* C5E8C 002C528C 3C11800E */  lui        $s1, %hi(D_800D94F2)
    /* C5E90 002C5290 263194F2 */  addiu      $s1, $s1, %lo(D_800D94F2)
    /* C5E94 002C5294 96220000 */  lhu        $v0, 0x0($s1)
    /* C5E98 002C5298 24420001 */  addiu      $v0, $v0, 0x1
    /* C5E9C 002C529C A6220000 */  sh         $v0, 0x0($s1)
    /* C5EA0 002C52A0 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C5EA4 002C52A4 2C420006 */  sltiu      $v0, $v0, 0x6
    /* C5EA8 002C52A8 50400001 */  beql       $v0, $zero, .L002C52B0
    /* C5EAC 002C52AC A6200000 */   sh        $zero, 0x0($s1)
  .L002C52B0:
    /* C5EB0 002C52B0 3C108015 */  lui        $s0, %hi(D_80151F80)
    /* C5EB4 002C52B4 26101F80 */  addiu      $s0, $s0, %lo(D_80151F80)
    /* C5EB8 002C52B8 96240000 */  lhu        $a0, 0x0($s1)
    /* C5EBC 002C52BC 02402821 */  addu       $a1, $s2, $zero
    /* C5EC0 002C52C0 00042240 */  sll        $a0, $a0, 9
    /* C5EC4 002C52C4 0C0B12E7 */  jal        adecImdctFrame
    /* C5EC8 002C52C8 00902021 */   addu      $a0, $a0, $s0
    /* C5ECC 002C52CC 96220000 */  lhu        $v0, 0x0($s1)
    /* C5ED0 002C52D0 8E430010 */  lw         $v1, 0x10($s2)
    /* C5ED4 002C52D4 00021240 */  sll        $v0, $v0, 9
    /* C5ED8 002C52D8 00501021 */  addu       $v0, $v0, $s0
    /* C5EDC 002C52DC 2463FFFF */  addiu      $v1, $v1, -0x1
    /* C5EE0 002C52E0 AE430010 */  sw         $v1, 0x10($s2)
  .L002C52E4:
    /* C5EE4 002C52E4 8FBF001C */  lw         $ra, 0x1C($sp)
    /* C5EE8 002C52E8 8FB20018 */  lw         $s2, 0x18($sp)
    /* C5EEC 002C52EC 8FB10014 */  lw         $s1, 0x14($sp)
    /* C5EF0 002C52F0 8FB00010 */  lw         $s0, 0x10($sp)
    /* C5EF4 002C52F4 03E00008 */  jr         $ra
    /* C5EF8 002C52F8 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel adecNextFrame
