.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2668-0xB2710 (VRAM 0x002B1A68) */
glabel func_002B1A68
    /* B2668 002B1A68 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B266C 002B1A6C AFB10014 */  sw         $s1, 0x14($sp)
    /* B2670 002B1A70 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B2674 002B1A74 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B2678 002B1A78 AFB40020 */  sw         $s4, 0x20($sp)
    /* B267C 002B1A7C 24140001 */  addiu      $s4, $zero, 0x1
    /* B2680 002B1A80 AFB20018 */  sw         $s2, 0x18($sp)
    /* B2684 002B1A84 00009021 */  addu       $s2, $zero, $zero
    /* B2688 002B1A88 AFB00010 */  sw         $s0, 0x10($sp)
    /* B268C 002B1A8C 24100001 */  addiu      $s0, $zero, 0x1
    /* B2690 002B1A90 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B2694 002B1A94 309300FF */  andi       $s3, $a0, 0xFF
    /* B2698 002B1A98 AFBF0024 */  sw         $ra, 0x24($sp)
  .L002B1A9C:
    /* B269C 002B1A9C 0C0AF7A8 */  jal        osPiGetStatus
    /* B26A0 002B1AA0 00000000 */   nop
    /* B26A4 002B1AA4 30420003 */  andi       $v0, $v0, 0x3
    /* B26A8 002B1AA8 1440FFFC */  bnez       $v0, .L002B1A9C
    /* B26AC 002B1AAC 00000000 */   nop
    /* B26B0 002B1AB0 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B26B4 002B1AB4 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B26B8 002B1AB8 00541024 */  and        $v0, $v0, $s4
    /* B26BC 002B1ABC 14530003 */  bne        $v0, $s3, .L002B1ACC
    /* B26C0 002B1AC0 02001021 */   addu      $v0, $s0, $zero
    /* B26C4 002B1AC4 080AC6BB */  j          .L002B1AEC
    /* B26C8 002B1AC8 24120001 */   addiu     $s2, $zero, 0x1
  .L002B1ACC:
    /* B26CC 002B1ACC 14400003 */  bnez       $v0, .L002B1ADC
    /* B26D0 002B1AD0 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B26D4 002B1AD4 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B26D8 002B1AD8 24100001 */  addiu      $s0, $zero, 0x1
  .L002B1ADC:
    /* B26DC 002B1ADC 1E20FFEF */  bgtz       $s1, .L002B1A9C
    /* B26E0 002B1AE0 24020001 */   addiu     $v0, $zero, 0x1
    /* B26E4 002B1AE4 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B26E8 002B1AE8 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1AEC:
    /* B26EC 002B1AEC 02401021 */  addu       $v0, $s2, $zero
    /* B26F0 002B1AF0 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B26F4 002B1AF4 8FB40020 */  lw         $s4, 0x20($sp)
    /* B26F8 002B1AF8 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B26FC 002B1AFC 8FB20018 */  lw         $s2, 0x18($sp)
    /* B2700 002B1B00 8FB10014 */  lw         $s1, 0x14($sp)
    /* B2704 002B1B04 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2708 002B1B08 03E00008 */  jr         $ra
    /* B270C 002B1B0C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B1A68
