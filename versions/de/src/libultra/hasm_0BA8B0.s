.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBA8B0-0xBA968 (VRAM 0x002B9CB0) */
.globl __osSiRawStartDma
__osSiRawStartDma:
    /* BA8B0 002B9CB0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BA8B4 002B9CB4 AFB10014 */  sw         $s1, 0x14($sp)
    /* BA8B8 002B9CB8 00808821 */  addu       $s1, $a0, $zero
    /* BA8BC 002B9CBC AFB00010 */  sw         $s0, 0x10($sp)
    /* BA8C0 002B9CC0 00A08021 */  addu       $s0, $a1, $zero
    /* BA8C4 002B9CC4 32020003 */  andi       $v0, $s0, 0x3
    /* BA8C8 002B9CC8 10400007 */  .word 0x10400007
    /* BA8CC 002B9CCC AFBF0018 */  sw        $ra, 0x18($sp)
    /* BA8D0 002B9CD0 3C04800C */  lui        $a0, %hi(D_auto_800C7990)
    /* BA8D4 002B9CD4 24847990 */  addiu      $a0, $a0, %lo(D_auto_800C7990)
    /* BA8D8 002B9CD8 3C05800C */  lui        $a1, %hi(D_auto_800C7994)
    /* BA8DC 002B9CDC 24A57994 */  addiu      $a1, $a1, %lo(D_auto_800C7994)
    /* BA8E0 002B9CE0 0C0AEB14 */  jal        __assert
    /* BA8E4 002B9CE4 24060037 */  addiu     $a2, $zero, 0x37
.Lauto_002B9CE8:
    /* BA8E8 002B9CE8 0C0AE75C */  jal        __osSiDeviceBusy
    /* BA8EC 002B9CEC 00000000 */  nop
    /* BA8F0 002B9CF0 14400018 */  .word 0x14400018
    /* BA8F4 002B9CF4 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BA8F8 002B9CF8 24020001 */  addiu      $v0, $zero, 0x1
    /* BA8FC 002B9CFC 16220003 */  .word 0x16220003
    /* BA900 002B9D00 02002021 */  addu      $a0, $s0, $zero
    /* BA904 002B9D04 0C0AF4A0 */  jal        osWritebackDCache
    /* BA908 002B9D08 24050040 */  addiu     $a1, $zero, 0x40
.Lauto_002B9D0C:
    /* BA90C 002B9D0C 0C0AEEF0 */  jal        osVirtualToPhysical
    /* BA910 002B9D10 02002021 */  addu      $a0, $s0, $zero
    /* BA914 002B9D14 3C03A480 */  lui        $v1, %hi(SI_PIF_ADDR_RD64B_REG)
    /* BA918 002B9D18 AC620000 */  sw         $v0, %lo(SI_DRAM_ADDR_REG)($v1)
    /* BA91C 002B9D1C 56200003 */  .word 0x56200003
    /* BA920 002B9D20 3C03A480 */  lui       $v1, %hi(SI_PIF_ADDR_RD64B_REG)
    /* BA924 002B9D24 080AE74C */  .word 0x080AE74C
    /* BA928 002B9D28 34630004 */  ori       $v1, $v1, %lo(SI_PIF_ADDR_RD64B_REG)
.Lauto_002B9D2C:
    /* BA92C 002B9D2C 34630010 */  ori        $v1, $v1, %lo(SI_PIF_ADDR_WR64B_REG)
.Lauto_002B9D30:
    /* BA930 002B9D30 3C021FC0 */  lui        $v0, (0x1FC007C0 >> 16)
    /* BA934 002B9D34 344207C0 */  ori        $v0, $v0, (0x1FC007C0 & 0xFFFF)
    /* BA938 002B9D38 AC620000 */  sw         $v0, 0x0($v1)
    /* BA93C 002B9D3C 16200005 */  .word 0x16200005
    /* BA940 002B9D40 00001021 */  addu      $v0, $zero, $zero
    /* BA944 002B9D44 02002021 */  addu       $a0, $s0, $zero
    /* BA948 002B9D48 0C0AF3DC */  jal        osInvalDCache
    /* BA94C 002B9D4C 24050040 */  addiu     $a1, $zero, 0x40
    /* BA950 002B9D50 00001021 */  addu       $v0, $zero, $zero
.Lauto_002B9D54:
    /* BA954 002B9D54 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BA958 002B9D58 8FB10014 */  lw         $s1, 0x14($sp)
    /* BA95C 002B9D5C 8FB00010 */  lw         $s0, 0x10($sp)
    /* BA960 002B9D60 03E00008 */  jr         $ra
    /* BA964 002B9D64 27BD0020 */  addiu     $sp, $sp, 0x20
