.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBBB90-0xBBC20 (VRAM 0x002BAF90) */
.globl __osSiRawReadIo
__osSiRawReadIo:
    /* BBB90 002BAF90 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BBB94 002BAF94 AFB00010 */  sw         $s0, 0x10($sp)
    /* BBB98 002BAF98 00808021 */  addu       $s0, $a0, $zero
    /* BBB9C 002BAF9C AFB10014 */  sw         $s1, 0x14($sp)
    /* BBBA0 002BAFA0 00A08821 */  addu       $s1, $a1, $zero
    /* BBBA4 002BAFA4 32020003 */  andi       $v0, $s0, 0x3
    /* BBBA8 002BAFA8 10400007 */  .word 0x10400007
    /* BBBAC 002BAFAC AFBF0018 */  sw        $ra, 0x18($sp)
    /* BBBB0 002BAFB0 3C04800C */  lui        $a0, %hi(D_auto_800C7900)
    /* BBBB4 002BAFB4 24847900 */  addiu      $a0, $a0, %lo(D_auto_800C7900)
    /* BBBB8 002BAFB8 3C05800C */  lui        $a1, %hi(D_auto_800C7904)
    /* BBBBC 002BAFBC 24A57904 */  addiu      $a1, $a1, %lo(D_auto_800C7904)
    /* BBBC0 002BAFC0 0C0AEAE0 */  jal        __assert
    /* BBBC4 002BAFC4 24060033 */  addiu     $a2, $zero, 0x33
.Lauto_002BAFC8:
    /* BBBC8 002BAFC8 16200007 */  .word 0x16200007
    /* BBBCC 002BAFCC 00000000 */  nop
    /* BBBD0 002BAFD0 3C04800C */  lui        $a0, %hi(D_auto_800C7900)
    /* BBBD4 002BAFD4 24847900 */  addiu      $a0, $a0, %lo(D_auto_800C7900)
    /* BBBD8 002BAFD8 3C05800C */  lui        $a1, %hi(D_auto_800C7904)
    /* BBBDC 002BAFDC 24A57904 */  addiu      $a1, $a1, %lo(D_auto_800C7904)
    /* BBBE0 002BAFE0 0C0AEAE0 */  jal        __assert
    /* BBBE4 002BAFE4 24060034 */  addiu     $a2, $zero, 0x34
.Lauto_002BAFE8:
    /* BBBE8 002BAFE8 0C0AE728 */  jal        __osSiDeviceBusy
    /* BBBEC 002BAFEC 00000000 */  nop
    /* BBBF0 002BAFF0 14400006 */  .word 0x14400006
    /* BBBF4 002BAFF4 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BBBF8 002BAFF8 3C02A000 */  lui        $v0, %hi(D_auto_A0000000)
    /* BBBFC 002BAFFC 02021025 */  or         $v0, $s0, $v0
    /* BBC00 002BB000 8C430000 */  lw         $v1, %lo(D_auto_A0000000)($v0)
    /* BBC04 002BB004 00001021 */  addu       $v0, $zero, $zero
    /* BBC08 002BB008 AE230000 */  sw         $v1, 0x0($s1)
.Lauto_002BB00C:
    /* BBC0C 002BB00C 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BBC10 002BB010 8FB10014 */  lw         $s1, 0x14($sp)
    /* BBC14 002BB014 8FB00010 */  lw         $s0, 0x10($sp)
    /* BBC18 002BB018 03E00008 */  jr         $ra
    /* BBC1C 002BB01C 27BD0020 */  addiu     $sp, $sp, 0x20
