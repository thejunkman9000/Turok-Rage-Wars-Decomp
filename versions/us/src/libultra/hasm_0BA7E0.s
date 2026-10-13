.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBA7E0-0xBA8A0 (VRAM 0x002B9BE0) */
.globl __osSiRawStartDma
__osSiRawStartDma:
    /* BA7E0 002B9BE0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BA7E4 002B9BE4 AFB10014 */  sw         $s1, 0x14($sp)
    /* BA7E8 002B9BE8 00808821 */  addu       $s1, $a0, $zero
    /* BA7EC 002B9BEC AFB00010 */  sw         $s0, 0x10($sp)
    /* BA7F0 002B9BF0 00A08021 */  addu       $s0, $a1, $zero
    /* BA7F4 002B9BF4 32020003 */  andi       $v0, $s0, 0x3
    /* BA7F8 002B9BF8 10400007 */  .word 0x10400007
    /* BA7FC 002B9BFC AFBF0018 */  sw        $ra, 0x18($sp)
    /* BA800 002B9C00 3C04800C */  lui        $a0, %hi(D_auto_800C78B0)
    /* BA804 002B9C04 248478B0 */  addiu      $a0, $a0, %lo(D_auto_800C78B0)
    /* BA808 002B9C08 3C05800C */  lui        $a1, %hi(D_auto_800C78B4)
    /* BA80C 002B9C0C 24A578B4 */  addiu      $a1, $a1, %lo(D_auto_800C78B4)
    /* BA810 002B9C10 0C0AEAE0 */  jal        __assert
    /* BA814 002B9C14 24060037 */  addiu     $a2, $zero, 0x37
.Lauto_002B9C18:
    /* BA818 002B9C18 0C0AE728 */  jal        __osSiDeviceBusy
    /* BA81C 002B9C1C 00000000 */  nop
    /* BA820 002B9C20 14400018 */  .word 0x14400018
    /* BA824 002B9C24 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BA828 002B9C28 24020001 */  addiu      $v0, $zero, 0x1
    /* BA82C 002B9C2C 16220003 */  .word 0x16220003
    /* BA830 002B9C30 02002021 */  addu      $a0, $s0, $zero
    /* BA834 002B9C34 0C0AF46C */  jal        osWritebackDCache
    /* BA838 002B9C38 24050040 */  addiu     $a1, $zero, 0x40
.Lauto_002B9C3C:
    /* BA83C 002B9C3C 0C0AEEBC */  jal        osVirtualToPhysical
    /* BA840 002B9C40 02002021 */  addu      $a0, $s0, $zero
    /* BA844 002B9C44 3C03A480 */  lui        $v1, %hi(SI_PIF_ADDR_RD64B_REG)
    /* BA848 002B9C48 AC620000 */  sw         $v0, %lo(SI_DRAM_ADDR_REG)($v1)
    /* BA84C 002B9C4C 56200003 */  .word 0x56200003
    /* BA850 002B9C50 3C03A480 */  lui       $v1, %hi(SI_PIF_ADDR_RD64B_REG)
    /* BA854 002B9C54 080AE718 */  .word 0x080AE718
    /* BA858 002B9C58 34630004 */  ori       $v1, $v1, %lo(SI_PIF_ADDR_RD64B_REG)
.Lauto_002B9C5C:
    /* BA85C 002B9C5C 34630010 */  ori        $v1, $v1, %lo(SI_PIF_ADDR_WR64B_REG)
.Lauto_002B9C60:
    /* BA860 002B9C60 3C021FC0 */  lui        $v0, (0x1FC007C0 >> 16)
    /* BA864 002B9C64 344207C0 */  ori        $v0, $v0, (0x1FC007C0 & 0xFFFF)
    /* BA868 002B9C68 AC620000 */  sw         $v0, 0x0($v1)
    /* BA86C 002B9C6C 16200005 */  .word 0x16200005
    /* BA870 002B9C70 00001021 */  addu      $v0, $zero, $zero
    /* BA874 002B9C74 02002021 */  addu       $a0, $s0, $zero
    /* BA878 002B9C78 0C0AF3A8 */  jal        osInvalDCache
    /* BA87C 002B9C7C 24050040 */  addiu     $a1, $zero, 0x40
    /* BA880 002B9C80 00001021 */  addu       $v0, $zero, $zero
.Lauto_002B9C84:
    /* BA884 002B9C84 8FBF0018 */  lw         $ra, 0x18($sp)
    /* BA888 002B9C88 8FB10014 */  lw         $s1, 0x14($sp)
    /* BA88C 002B9C8C 8FB00010 */  lw         $s0, 0x10($sp)
    /* BA890 002B9C90 03E00008 */  jr         $ra
    /* BA894 002B9C94 27BD0020 */  addiu     $sp, $sp, 0x20
.globl D_auto_002B9C98
D_auto_002B9C98:
    /* BA898 002B9C98 6D655200 */  .word 0x6D655200
    /* BA89C 002B9C9C 00580600 */  .word 0x00580600
