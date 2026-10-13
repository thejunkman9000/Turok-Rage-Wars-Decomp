.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBAB50-0xBAC08 (VRAM 0x002B9F50) */
.globl __osSiRawStartDma
__osSiRawStartDma:
    /* BAB50 002B9F50 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BAB54 002B9F54 AFB10014 */  sw         $s1, 0x14($sp)
    /* BAB58 002B9F58 00808821 */  addu       $s1, $a0, $zero
    /* BAB5C 002B9F5C AFB00010 */  sw         $s0, 0x10($sp)
    /* BAB60 002B9F60 00A08021 */  addu       $s0, $a1, $zero
    /* BAB64 002B9F64 32020003 */  andi       $v0, $s0, 0x3
    /* BAB68 002B9F68 10400007 */  .word 0x10400007
    /* BAB6C 002B9F6C AFBF0018 */  sw        $ra, 0x18($sp)
    /* BAB70 002B9F70 3C04800D */  lui        $a0, %hi(D_auto_800C8580)
    /* BAB74 002B9F74 24848580 */  addiu      $a0, $a0, %lo(D_auto_800C8580)
    /* BAB78 002B9F78 3C05800D */  lui        $a1, %hi(D_auto_800C8584)
    /* BAB7C 002B9F7C 24A58584 */  addiu      $a1, $a1, %lo(D_auto_800C8584)
    /* BAB80 002B9F80 0C0AEBBC */  jal        __assert
    /* BAB84 002B9F84 24060037 */  addiu     $a2, $zero, 0x37
.Lauto_002B9F88:
    /* BAB88 002B9F88 0C0AE804 */  jal        __osSiDeviceBusy
    /* BAB8C 002B9F8C 00000000 */  nop
    /* BAB90 002B9F90 14400018 */  .word 0x14400018
    /* BAB94 002B9F94 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BAB98 002B9F98 24020001 */  addiu      $v0, $zero, 0x1
    /* BAB9C 002B9F9C 16220003 */  .word 0x16220003
    /* BABA0 002B9FA0 02002021 */  addu      $a0, $s0, $zero
    /* BABA4 002B9FA4 0C0AF548 */  jal        osWritebackDCache
    /* BABA8 002B9FA8 24050040 */  addiu     $a1, $zero, 0x40
.Lauto_002B9FAC:
    /* BABAC 002B9FAC 0C0AEF98 */  jal        osVirtualToPhysical
    /* BABB0 002B9FB0 02002021 */  addu      $a0, $s0, $zero
    /* BABB4 002B9FB4 3C03A480 */  lui        $v1, %hi(SI_PIF_ADDR_RD64B_REG)
    /* BABB8 002B9FB8 AC620000 */  sw         $v0, %lo(SI_DRAM_ADDR_REG)($v1)
    /* BABBC 002B9FBC 56200003 */  .word 0x56200003
    /* BABC0 002B9FC0 3C03A480 */  lui       $v1, %hi(SI_PIF_ADDR_RD64B_REG)
    /* BABC4 002B9FC4 080AE7F4 */  .word 0x080AE7F4
    /* BABC8 002B9FC8 34630004 */  ori       $v1, $v1, %lo(SI_PIF_ADDR_RD64B_REG)
.Lauto_002B9FCC:
    /* BABCC 002B9FCC 34630010 */  ori        $v1, $v1, %lo(SI_PIF_ADDR_WR64B_REG)
.Lauto_002B9FD0:
    /* BABD0 002B9FD0 3C021FC0 */  lui        $v0, (0x1FC007C0 >> 16)
    /* BABD4 002B9FD4 344207C0 */  ori        $v0, $v0, (0x1FC007C0 & 0xFFFF)
    /* BABD8 002B9FD8 AC620000 */  sw         $v0, 0x0($v1)
    /* BABDC 002B9FDC 16200005 */  .word 0x16200005
    /* BABE0 002B9FE0 00001021 */  addu      $v0, $zero, $zero
    /* BABE4 002B9FE4 02002021 */  addu       $a0, $s0, $zero
    /* BABE8 002B9FE8 0C0AF484 */  jal        osInvalDCache
    /* BABEC 002B9FEC 24050040 */  addiu     $a1, $zero, 0x40
    /* BABF0 002B9FF0 00001021 */  addu       $v0, $zero, $zero
.Lauto_002B9FF4:
    /* BABF4 002B9FF4 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BABF8 002B9FF8 8FB10014 */  lw         $s1, 0x14($sp)
    /* BABFC 002B9FFC 8FB00010 */  lw         $s0, 0x10($sp)
    /* BAC00 002BA000 03E00008 */  jr         $ra
    /* BAC04 002BA004 27BD0020 */  addiu     $sp, $sp, 0x20
