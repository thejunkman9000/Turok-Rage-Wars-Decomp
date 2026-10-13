.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBBF00-0xBBF90 (VRAM 0x002BB300) */
.globl __osSiRawReadIo
__osSiRawReadIo:
    /* BBF00 002BB300 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BBF04 002BB304 AFB00010 */  sw         $s0, 0x10($sp)
    /* BBF08 002BB308 00808021 */  addu       $s0, $a0, $zero
    /* BBF0C 002BB30C AFB10014 */  sw         $s1, 0x14($sp)
    /* BBF10 002BB310 00A08821 */  addu       $s1, $a1, $zero
    /* BBF14 002BB314 32020003 */  andi       $v0, $s0, 0x3
    /* BBF18 002BB318 10400007 */  .word 0x10400007
    /* BBF1C 002BB31C AFBF0018 */  sw        $ra, 0x18($sp)
    /* BBF20 002BB320 3C04800D */  lui        $a0, %hi(D_auto_800C85D0)
    /* BBF24 002BB324 248485D0 */  addiu      $a0, $a0, %lo(D_auto_800C85D0)
    /* BBF28 002BB328 3C05800D */  lui        $a1, %hi(D_auto_800C85D4)
    /* BBF2C 002BB32C 24A585D4 */  addiu      $a1, $a1, %lo(D_auto_800C85D4)
    /* BBF30 002BB330 0C0AEBBC */  jal        __assert
    /* BBF34 002BB334 24060033 */  addiu     $a2, $zero, 0x33
.Lauto_002BB338:
    /* BBF38 002BB338 16200007 */  .word 0x16200007
    /* BBF3C 002BB33C 00000000 */  nop
    /* BBF40 002BB340 3C04800D */  lui        $a0, %hi(D_auto_800C85D0)
    /* BBF44 002BB344 248485D0 */  addiu      $a0, $a0, %lo(D_auto_800C85D0)
    /* BBF48 002BB348 3C05800D */  lui        $a1, %hi(D_auto_800C85D4)
    /* BBF4C 002BB34C 24A585D4 */  addiu      $a1, $a1, %lo(D_auto_800C85D4)
    /* BBF50 002BB350 0C0AEBBC */  jal        __assert
    /* BBF54 002BB354 24060034 */  addiu     $a2, $zero, 0x34
.Lauto_002BB358:
    /* BBF58 002BB358 0C0AE804 */  jal        __osSiDeviceBusy
    /* BBF5C 002BB35C 00000000 */  nop
    /* BBF60 002BB360 14400006 */  .word 0x14400006
    /* BBF64 002BB364 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BBF68 002BB368 3C02A000 */  lui        $v0, %hi(D_auto_A0000000)
    /* BBF6C 002BB36C 02021025 */  or         $v0, $s0, $v0
    /* BBF70 002BB370 8C430000 */  lw         $v1, %lo(D_auto_A0000000)($v0)
    /* BBF74 002BB374 00001021 */  addu       $v0, $zero, $zero
    /* BBF78 002BB378 AE230000 */  sw         $v1, 0x0($s1)
.Lauto_002BB37C:
    /* BBF7C 002BB37C 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BBF80 002BB380 8FB10014 */  lw         $s1, 0x14($sp)
    /* BBF84 002BB384 8FB00010 */  lw         $s0, 0x10($sp)
    /* BBF88 002BB388 03E00008 */  jr         $ra
    /* BBF8C 002BB38C 27BD0020 */  addiu     $sp, $sp, 0x20
