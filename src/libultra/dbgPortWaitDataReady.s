.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB25C0-0xB2668 (VRAM 0x002B19C0) */
glabel dbgPortWaitDataReady
    /* B25C0 002B19C0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B25C4 002B19C4 AFB10014 */  sw         $s1, 0x14($sp)
    /* B25C8 002B19C8 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B25CC 002B19CC 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B25D0 002B19D0 AFB40020 */  sw         $s4, 0x20($sp)
    /* B25D4 002B19D4 24140001 */  addiu      $s4, $zero, 0x1
    /* B25D8 002B19D8 AFB20018 */  sw         $s2, 0x18($sp)
    /* B25DC 002B19DC 00009021 */  addu       $s2, $zero, $zero
    /* B25E0 002B19E0 AFB00010 */  sw         $s0, 0x10($sp)
    /* B25E4 002B19E4 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B25E8 002B19E8 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B25EC 002B19EC 309300FF */  andi       $s3, $a0, 0xFF
    /* B25F0 002B19F0 AFBF0024 */  sw         $ra, 0x24($sp)
  .L002B19F4:
    /* B25F4 002B19F4 0C0AF7A8 */  jal        osPiGetStatus
    /* B25F8 002B19F8 00000000 */   nop
    /* B25FC 002B19FC 30420003 */  andi       $v0, $v0, 0x3
    /* B2600 002B1A00 1440FFFC */  bnez       $v0, .L002B19F4
    /* B2604 002B1A04 00000000 */   nop
    /* B2608 002B1A08 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B260C 002B1A0C 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B2610 002B1A10 00541024 */  and        $v0, $v0, $s4
    /* B2614 002B1A14 14530003 */  bne        $v0, $s3, .L002B1A24
    /* B2618 002B1A18 02001021 */   addu      $v0, $s0, $zero
    /* B261C 002B1A1C 080AC691 */  j          .L002B1A44
    /* B2620 002B1A20 24120001 */   addiu     $s2, $zero, 0x1
  .L002B1A24:
    /* B2624 002B1A24 14400003 */  bnez       $v0, .L002B1A34
    /* B2628 002B1A28 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B262C 002B1A2C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B2630 002B1A30 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B1A34:
    /* B2634 002B1A34 1E20FFEF */  bgtz       $s1, .L002B19F4
    /* B2638 002B1A38 24020001 */   addiu     $v0, $zero, 0x1
    /* B263C 002B1A3C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B2640 002B1A40 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1A44:
    /* B2644 002B1A44 02401021 */  addu       $v0, $s2, $zero
    /* B2648 002B1A48 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B264C 002B1A4C 8FB40020 */  lw         $s4, 0x20($sp)
    /* B2650 002B1A50 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B2654 002B1A54 8FB20018 */  lw         $s2, 0x18($sp)
    /* B2658 002B1A58 8FB10014 */  lw         $s1, 0x14($sp)
    /* B265C 002B1A5C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2660 002B1A60 03E00008 */  jr         $ra
    /* B2664 002B1A64 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel dbgPortWaitDataReady
