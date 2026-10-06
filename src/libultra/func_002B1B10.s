.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2710-0xB27BC (VRAM 0x002B1B10) */
glabel func_002B1B10
    /* B2710 002B1B10 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B2714 002B1B14 AFB40020 */  sw         $s4, 0x20($sp)
    /* B2718 002B1B18 24140040 */  addiu      $s4, $zero, 0x40
    /* B271C 002B1B1C AFB10014 */  sw         $s1, 0x14($sp)
    /* B2720 002B1B20 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B2724 002B1B24 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B2728 002B1B28 00042180 */  sll        $a0, $a0, 6
    /* B272C 002B1B2C AFB20018 */  sw         $s2, 0x18($sp)
    /* B2730 002B1B30 00009021 */  addu       $s2, $zero, $zero
    /* B2734 002B1B34 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2738 002B1B38 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B273C 002B1B3C AFB3001C */  sw         $s3, 0x1C($sp)
    /* B2740 002B1B40 309300FF */  andi       $s3, $a0, 0xFF
    /* B2744 002B1B44 AFBF0024 */  sw         $ra, 0x24($sp)
  .L002B1B48:
    /* B2748 002B1B48 0C0AF7A8 */  jal        osPiGetStatus
    /* B274C 002B1B4C 00000000 */   nop
    /* B2750 002B1B50 30420003 */  andi       $v0, $v0, 0x3
    /* B2754 002B1B54 1440FFFC */  bnez       $v0, .L002B1B48
    /* B2758 002B1B58 00000000 */   nop
    /* B275C 002B1B5C 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B2760 002B1B60 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B2764 002B1B64 00541024 */  and        $v0, $v0, $s4
    /* B2768 002B1B68 14530003 */  bne        $v0, $s3, .L002B1B78
    /* B276C 002B1B6C 02001021 */   addu      $v0, $s0, $zero
    /* B2770 002B1B70 080AC6E6 */  j          .L002B1B98
    /* B2774 002B1B74 24120001 */   addiu     $s2, $zero, 0x1
  .L002B1B78:
    /* B2778 002B1B78 14400003 */  bnez       $v0, .L002B1B88
    /* B277C 002B1B7C 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B2780 002B1B80 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B2784 002B1B84 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B1B88:
    /* B2788 002B1B88 1E20FFEF */  bgtz       $s1, .L002B1B48
    /* B278C 002B1B8C 24020001 */   addiu     $v0, $zero, 0x1
    /* B2790 002B1B90 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B2794 002B1B94 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1B98:
    /* B2798 002B1B98 02401021 */  addu       $v0, $s2, $zero
    /* B279C 002B1B9C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B27A0 002B1BA0 8FB40020 */  lw         $s4, 0x20($sp)
    /* B27A4 002B1BA4 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B27A8 002B1BA8 8FB20018 */  lw         $s2, 0x18($sp)
    /* B27AC 002B1BAC 8FB10014 */  lw         $s1, 0x14($sp)
    /* B27B0 002B1BB0 8FB00010 */  lw         $s0, 0x10($sp)
    /* B27B4 002B1BB4 03E00008 */  jr         $ra
    /* B27B8 002B1BB8 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B1B10
