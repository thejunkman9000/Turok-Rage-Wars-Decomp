.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B559C-0x1B5670 (VRAM 0x0044759C) */
glabel func_0044759C
    /* 1B559C 0044759C 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* 1B55A0 004475A0 AFB20038 */  sw         $s2, 0x38($sp)
    /* 1B55A4 004475A4 00809021 */  addu       $s2, $a0, $zero
    /* 1B55A8 004475A8 AFB40040 */  sw         $s4, 0x40($sp)
    /* 1B55AC 004475AC 00C0A021 */  addu       $s4, $a2, $zero
    /* 1B55B0 004475B0 AFB3003C */  sw         $s3, 0x3C($sp)
    /* 1B55B4 004475B4 00A09821 */  addu       $s3, $a1, $zero
    /* 1B55B8 004475B8 AFBF0044 */  sw         $ra, 0x44($sp)
    /* 1B55BC 004475BC AFB10034 */  sw         $s1, 0x34($sp)
    /* 1B55C0 004475C0 AFB00030 */  sw         $s0, 0x30($sp)
    /* 1B55C4 004475C4 0C112645 */  jal        func_00449914
    /* 1B55C8 004475C8 A2470065 */   sb        $a3, 0x65($s2)
    /* 1B55CC 004475CC 00408021 */  addu       $s0, $v0, $zero
    /* 1B55D0 004475D0 12000008 */  beqz       $s0, .L004475F4
    /* 1B55D4 004475D4 00008821 */   addu      $s1, $zero, $zero
    /* 1B55D8 004475D8 08111D93 */  j          .L0044764C
    /* 1B55DC 004475DC 00000000 */   nop
  .L004475E0:
    /* 1B55E0 004475E0 A2400065 */  sb         $zero, 0x65($s2)
    /* 1B55E4 004475E4 0C112645 */  jal        func_00449914
    /* 1B55E8 004475E8 02402021 */   addu      $a0, $s2, $zero
    /* 1B55EC 004475EC 08111D93 */  j          .L0044764C
    /* 1B55F0 004475F0 02001021 */   addu      $v0, $s0, $zero
  .L004475F4:
    /* 1B55F4 004475F4 326200FF */  andi       $v0, $s3, 0xFF
    /* 1B55F8 004475F8 000298C0 */  sll        $s3, $v0, 3
  .L004475FC:
    /* 1B55FC 004475FC 02713021 */  addu       $a2, $s3, $s1
    /* 1B5600 00447600 30C6FFFF */  andi       $a2, $a2, 0xFFFF
    /* 1B5604 00447604 8E440004 */  lw         $a0, 0x4($s2)
    /* 1B5608 00447608 8E450008 */  lw         $a1, 0x8($s2)
    /* 1B560C 0044760C 0C0AF564 */  jal        __osContRamRead
    /* 1B5610 00447610 27A70010 */   addiu     $a3, $sp, 0x10
    /* 1B5614 00447614 00408021 */  addu       $s0, $v0, $zero
    /* 1B5618 00447618 1600FFF1 */  bnez       $s0, .L004475E0
    /* 1B561C 0044761C 27A40010 */   addiu     $a0, $sp, 0x10
    /* 1B5620 00447620 0C1125F5 */  jal        func_004497D4
    /* 1B5624 00447624 24050020 */   addiu     $a1, $zero, 0x20
    /* 1B5628 00447628 96830000 */  lhu        $v1, 0x0($s4)
    /* 1B562C 0044762C 26310001 */  addiu      $s1, $s1, 0x1
    /* 1B5630 00447630 00621821 */  addu       $v1, $v1, $v0
    /* 1B5634 00447634 2A220008 */  slti       $v0, $s1, 0x8
    /* 1B5638 00447638 1440FFF0 */  bnez       $v0, .L004475FC
    /* 1B563C 0044763C A6830000 */   sh        $v1, 0x0($s4)
    /* 1B5640 00447640 A2400065 */  sb         $zero, 0x65($s2)
    /* 1B5644 00447644 0C112645 */  jal        func_00449914
    /* 1B5648 00447648 02402021 */   addu      $a0, $s2, $zero
  .L0044764C:
    /* 1B564C 0044764C 8FBF0044 */  lw         $ra, 0x44($sp)
    /* 1B5650 00447650 8FB40040 */  lw         $s4, 0x40($sp)
    /* 1B5654 00447654 8FB3003C */  lw         $s3, 0x3C($sp)
    /* 1B5658 00447658 8FB20038 */  lw         $s2, 0x38($sp)
    /* 1B565C 0044765C 8FB10034 */  lw         $s1, 0x34($sp)
    /* 1B5660 00447660 8FB00030 */  lw         $s0, 0x30($sp)
    /* 1B5664 00447664 03E00008 */  jr         $ra
    /* 1B5668 00447668 27BD0048 */   addiu     $sp, $sp, 0x48


    /* 1B566C 0044766C 00C2102A */  .word      0x00C2102A /* linker padding */
endlabel func_0044759C
