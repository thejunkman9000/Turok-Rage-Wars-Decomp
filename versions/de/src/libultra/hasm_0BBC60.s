.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBBC60-0xBBCF0 (VRAM 0x002BB060) */
.globl __osSiRawReadIo
__osSiRawReadIo:
    /* BBC60 002BB060 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BBC64 002BB064 AFB00010 */  sw         $s0, 0x10($sp)
    /* BBC68 002BB068 00808021 */  addu       $s0, $a0, $zero
    /* BBC6C 002BB06C AFB10014 */  sw         $s1, 0x14($sp)
    /* BBC70 002BB070 00A08821 */  addu       $s1, $a1, $zero
    /* BBC74 002BB074 32020003 */  andi       $v0, $s0, 0x3
    /* BBC78 002BB078 10400007 */  .word 0x10400007
    /* BBC7C 002BB07C AFBF0018 */  sw        $ra, 0x18($sp)
    /* BBC80 002BB080 3C04800C */  lui        $a0, %hi(D_auto_800C79E0)
    /* BBC84 002BB084 248479E0 */  addiu      $a0, $a0, %lo(D_auto_800C79E0)
    /* BBC88 002BB088 3C05800C */  lui        $a1, %hi(D_auto_800C79E4)
    /* BBC8C 002BB08C 24A579E4 */  addiu      $a1, $a1, %lo(D_auto_800C79E4)
    /* BBC90 002BB090 0C0AEB14 */  jal        __assert
    /* BBC94 002BB094 24060033 */  addiu     $a2, $zero, 0x33
.Lauto_002BB098:
    /* BBC98 002BB098 16200007 */  .word 0x16200007
    /* BBC9C 002BB09C 00000000 */  nop
    /* BBCA0 002BB0A0 3C04800C */  lui        $a0, %hi(D_auto_800C79E0)
    /* BBCA4 002BB0A4 248479E0 */  addiu      $a0, $a0, %lo(D_auto_800C79E0)
    /* BBCA8 002BB0A8 3C05800C */  lui        $a1, %hi(D_auto_800C79E4)
    /* BBCAC 002BB0AC 24A579E4 */  addiu      $a1, $a1, %lo(D_auto_800C79E4)
    /* BBCB0 002BB0B0 0C0AEB14 */  jal        __assert
    /* BBCB4 002BB0B4 24060034 */  addiu     $a2, $zero, 0x34
.Lauto_002BB0B8:
    /* BBCB8 002BB0B8 0C0AE75C */  jal        __osSiDeviceBusy
    /* BBCBC 002BB0BC 00000000 */  nop
    /* BBCC0 002BB0C0 14400006 */  .word 0x14400006
    /* BBCC4 002BB0C4 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BBCC8 002BB0C8 3C02A000 */  lui        $v0, %hi(D_auto_A0000000)
    /* BBCCC 002BB0CC 02021025 */  or         $v0, $s0, $v0
    /* BBCD0 002BB0D0 8C430000 */  lw         $v1, %lo(D_auto_A0000000)($v0)
    /* BBCD4 002BB0D4 00001021 */  addu       $v0, $zero, $zero
    /* BBCD8 002BB0D8 AE230000 */  sw         $v1, 0x0($s1)
.Lauto_002BB0DC:
    /* BBCDC 002BB0DC 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BBCE0 002BB0E0 8FB10014 */  lw         $s1, 0x14($sp)
    /* BBCE4 002BB0E4 8FB00010 */  lw         $s0, 0x10($sp)
    /* BBCE8 002BB0E8 03E00008 */  jr         $ra
    /* BBCEC 002BB0EC 27BD0020 */  addiu     $sp, $sp, 0x20
