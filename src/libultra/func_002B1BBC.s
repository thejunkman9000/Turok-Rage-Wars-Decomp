.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB27BC-0xB2868 (VRAM 0x002B1BBC) */
glabel func_002B1BBC
    /* B27BC 002B1BBC 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B27C0 002B1BC0 AFB40020 */  sw         $s4, 0x20($sp)
    /* B27C4 002B1BC4 24140040 */  addiu      $s4, $zero, 0x40
    /* B27C8 002B1BC8 AFB10014 */  sw         $s1, 0x14($sp)
    /* B27CC 002B1BCC 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B27D0 002B1BD0 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B27D4 002B1BD4 00042180 */  sll        $a0, $a0, 6
    /* B27D8 002B1BD8 AFB20018 */  sw         $s2, 0x18($sp)
    /* B27DC 002B1BDC 00009021 */  addu       $s2, $zero, $zero
    /* B27E0 002B1BE0 AFB00010 */  sw         $s0, 0x10($sp)
    /* B27E4 002B1BE4 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B27E8 002B1BE8 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B27EC 002B1BEC 309300FF */  andi       $s3, $a0, 0xFF
    /* B27F0 002B1BF0 AFBF0024 */  sw         $ra, 0x24($sp)
  .L002B1BF4:
    /* B27F4 002B1BF4 0C0AF7A8 */  jal        osPiGetStatus
    /* B27F8 002B1BF8 00000000 */   nop
    /* B27FC 002B1BFC 30420003 */  andi       $v0, $v0, 0x3
    /* B2800 002B1C00 1440FFFC */  bnez       $v0, .L002B1BF4
    /* B2804 002B1C04 00000000 */   nop
    /* B2808 002B1C08 3C02B200 */  lui        $v0, %hi(D_B2000011)
    /* B280C 002B1C0C 90420011 */  lbu        $v0, %lo(D_B2000011)($v0)
    /* B2810 002B1C10 00541024 */  and        $v0, $v0, $s4
    /* B2814 002B1C14 14530003 */  bne        $v0, $s3, .L002B1C24
    /* B2818 002B1C18 02001021 */   addu      $v0, $s0, $zero
    /* B281C 002B1C1C 080AC711 */  j          .L002B1C44
    /* B2820 002B1C20 24120001 */   addiu     $s2, $zero, 0x1
  .L002B1C24:
    /* B2824 002B1C24 14400003 */  bnez       $v0, .L002B1C34
    /* B2828 002B1C28 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B282C 002B1C2C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B2830 002B1C30 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B1C34:
    /* B2834 002B1C34 1E20FFEF */  bgtz       $s1, .L002B1BF4
    /* B2838 002B1C38 24020001 */   addiu     $v0, $zero, 0x1
    /* B283C 002B1C3C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B2840 002B1C40 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1C44:
    /* B2844 002B1C44 02401021 */  addu       $v0, $s2, $zero
    /* B2848 002B1C48 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B284C 002B1C4C 8FB40020 */  lw         $s4, 0x20($sp)
    /* B2850 002B1C50 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B2854 002B1C54 8FB20018 */  lw         $s2, 0x18($sp)
    /* B2858 002B1C58 8FB10014 */  lw         $s1, 0x14($sp)
    /* B285C 002B1C5C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2860 002B1C60 03E00008 */  jr         $ra
    /* B2864 002B1C64 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B1BBC
