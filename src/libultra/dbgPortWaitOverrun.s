.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2868-0xB2914 (VRAM 0x002B1C68) */
glabel dbgPortWaitOverrun
    /* B2868 002B1C68 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B286C 002B1C6C AFB40020 */  sw         $s4, 0x20($sp)
    /* B2870 002B1C70 24140002 */  addiu      $s4, $zero, 0x2
    /* B2874 002B1C74 AFB10014 */  sw         $s1, 0x14($sp)
    /* B2878 002B1C78 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B287C 002B1C7C 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B2880 002B1C80 00042040 */  sll        $a0, $a0, 1
    /* B2884 002B1C84 AFB20018 */  sw         $s2, 0x18($sp)
    /* B2888 002B1C88 00009021 */  addu       $s2, $zero, $zero
    /* B288C 002B1C8C AFB00010 */  sw         $s0, 0x10($sp)
    /* B2890 002B1C90 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B2894 002B1C94 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B2898 002B1C98 309300FF */  andi       $s3, $a0, 0xFF
    /* B289C 002B1C9C AFBF0024 */  sw         $ra, 0x24($sp)
  .L002B1CA0:
    /* B28A0 002B1CA0 0C0AF7A8 */  jal        osPiGetStatus
    /* B28A4 002B1CA4 00000000 */   nop
    /* B28A8 002B1CA8 30420003 */  andi       $v0, $v0, 0x3
    /* B28AC 002B1CAC 1440FFFC */  bnez       $v0, .L002B1CA0
    /* B28B0 002B1CB0 00000000 */   nop
    /* B28B4 002B1CB4 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B28B8 002B1CB8 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B28BC 002B1CBC 00541024 */  and        $v0, $v0, $s4
    /* B28C0 002B1CC0 14530003 */  bne        $v0, $s3, .L002B1CD0
    /* B28C4 002B1CC4 02001021 */   addu      $v0, $s0, $zero
    /* B28C8 002B1CC8 080AC73C */  j          .L002B1CF0
    /* B28CC 002B1CCC 24120001 */   addiu     $s2, $zero, 0x1
  .L002B1CD0:
    /* B28D0 002B1CD0 14400003 */  bnez       $v0, .L002B1CE0
    /* B28D4 002B1CD4 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B28D8 002B1CD8 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B28DC 002B1CDC 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B1CE0:
    /* B28E0 002B1CE0 1E20FFEF */  bgtz       $s1, .L002B1CA0
    /* B28E4 002B1CE4 24020001 */   addiu     $v0, $zero, 0x1
    /* B28E8 002B1CE8 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B28EC 002B1CEC AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1CF0:
    /* B28F0 002B1CF0 02401021 */  addu       $v0, $s2, $zero
    /* B28F4 002B1CF4 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B28F8 002B1CF8 8FB40020 */  lw         $s4, 0x20($sp)
    /* B28FC 002B1CFC 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B2900 002B1D00 8FB20018 */  lw         $s2, 0x18($sp)
    /* B2904 002B1D04 8FB10014 */  lw         $s1, 0x14($sp)
    /* B2908 002B1D08 8FB00010 */  lw         $s0, 0x10($sp)
    /* B290C 002B1D0C 03E00008 */  jr         $ra
    /* B2910 002B1D10 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel dbgPortWaitOverrun
