.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7FC4-0xB802C (VRAM 0x002B73C4) */
glabel __alSeqNextDelta
    /* B7FC4 002B73C4 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B7FC8 002B73C8 AFB00010 */  sw         $s0, 0x10($sp)
    /* B7FCC 002B73CC 00808021 */  addu       $s0, $a0, $zero
    /* B7FD0 002B73D0 AFB20018 */  sw         $s2, 0x18($sp)
    /* B7FD4 002B73D4 AFBF001C */  sw         $ra, 0x1C($sp)
    /* B7FD8 002B73D8 AFB10014 */  sw         $s1, 0x14($sp)
    /* B7FDC 002B73DC 8E020000 */  lw         $v0, 0x0($s0)
    /* B7FE0 002B73E0 8E030010 */  lw         $v1, 0x10($s0)
    /* B7FE4 002B73E4 8E110008 */  lw         $s1, 0x8($s0)
    /* B7FE8 002B73E8 00431021 */  addu       $v0, $v0, $v1
    /* B7FEC 002B73EC 0222102B */  sltu       $v0, $s1, $v0
    /* B7FF0 002B73F0 10400007 */  beqz       $v0, .L002B7410
    /* B7FF4 002B73F4 00A09021 */   addu      $s2, $a1, $zero
    /* B7FF8 002B73F8 0C0ADD0B */  jal        __alSeqReadVarLen
    /* B7FFC 002B73FC 00000000 */   nop
    /* B8000 002B7400 AE420000 */  sw         $v0, 0x0($s2)
    /* B8004 002B7404 24020001 */  addiu      $v0, $zero, 0x1
    /* B8008 002B7408 080ADD05 */  j          .L002B7414
    /* B800C 002B740C AE110008 */   sw        $s1, 0x8($s0)
  .L002B7410:
    /* B8010 002B7410 00001021 */  addu       $v0, $zero, $zero
  .L002B7414:
    /* B8014 002B7414 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B8018 002B7418 8FB20018 */  lw         $s2, 0x18($sp)
    /* B801C 002B741C 8FB10014 */  lw         $s1, 0x14($sp)
    /* B8020 002B7420 8FB00010 */  lw         $s0, 0x10($sp)
    /* B8024 002B7424 03E00008 */  jr         $ra
    /* B8028 002B7428 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel __alSeqNextDelta
