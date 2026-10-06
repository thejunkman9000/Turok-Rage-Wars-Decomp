.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4680-0xB46FC (VRAM 0x002B3A80) */
glabel func_002B3A80
    /* B4680 002B3A80 8C820004 */  lw         $v0, 0x4($a0)
    /* B4684 002B3A84 8C890010 */  lw         $t1, 0x10($a0)
    /* B4688 002B3A88 14400003 */  bnez       $v0, .L002B3A98
    /* B468C 002B3A8C 2408FFFF */   addiu     $t0, $zero, -0x1
    /* B4690 002B3A90 03E00008 */  jr         $ra
    /* B4694 002B3A94 00001021 */   addu      $v0, $zero, $zero
  .L002B3A98:
    /* B4698 002B3A98 00003821 */  addu       $a3, $zero, $zero
    /* B469C 002B3A9C 00803021 */  addu       $a2, $a0, $zero
  .L002B3AA0:
    /* B46A0 002B3AA0 8C820004 */  lw         $v0, 0x4($a0)
    /* B46A4 002B3AA4 00E21006 */  srlv       $v0, $v0, $a3
    /* B46A8 002B3AA8 30420001 */  andi       $v0, $v0, 0x1
    /* B46AC 002B3AAC 5040000C */  beql       $v0, $zero, .L002B3AE0
    /* B46B0 002B3AB0 24E70001 */   addiu     $a3, $a3, 0x1
    /* B46B4 002B3AB4 8C820014 */  lw         $v0, 0x14($a0)
    /* B46B8 002B3AB8 10400004 */  beqz       $v0, .L002B3ACC
    /* B46BC 002B3ABC 00000000 */   nop
    /* B46C0 002B3AC0 8CC200B8 */  lw         $v0, 0xB8($a2)
    /* B46C4 002B3AC4 00491023 */  subu       $v0, $v0, $t1
    /* B46C8 002B3AC8 ACC200B8 */  sw         $v0, 0xB8($a2)
  .L002B3ACC:
    /* B46CC 002B3ACC 8CC300B8 */  lw         $v1, 0xB8($a2)
    /* B46D0 002B3AD0 0068102B */  sltu       $v0, $v1, $t0
    /* B46D4 002B3AD4 54400001 */  bnel       $v0, $zero, .L002B3ADC
    /* B46D8 002B3AD8 00604021 */   addu      $t0, $v1, $zero
  .L002B3ADC:
    /* B46DC 002B3ADC 24E70001 */  addiu      $a3, $a3, 0x1
  .L002B3AE0:
    /* B46E0 002B3AE0 2CE20010 */  sltiu      $v0, $a3, 0x10
    /* B46E4 002B3AE4 1440FFEE */  bnez       $v0, .L002B3AA0
    /* B46E8 002B3AE8 24C60004 */   addiu     $a2, $a2, 0x4
    /* B46EC 002B3AEC 24020001 */  addiu      $v0, $zero, 0x1
    /* B46F0 002B3AF0 AC800014 */  sw         $zero, 0x14($a0)
    /* B46F4 002B3AF4 03E00008 */  jr         $ra
    /* B46F8 002B3AF8 ACA80000 */   sw        $t0, 0x0($a1)
endlabel func_002B3A80
