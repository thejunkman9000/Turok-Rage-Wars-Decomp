.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB0590-0xB08E4 (VRAM 0x002AF990) */
glabel func_002AF990
    /* B0590 002AF990 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B0594 002AF994 AFBF0044 */  sw         $ra, 0x44($sp)
    /* B0598 002AF998 AFB40040 */  sw         $s4, 0x40($sp)
    /* B059C 002AF99C AFB3003C */  sw         $s3, 0x3C($sp)
    /* B05A0 002AF9A0 AFB20038 */  sw         $s2, 0x38($sp)
    /* B05A4 002AF9A4 AFB10034 */  sw         $s1, 0x34($sp)
    /* B05A8 002AF9A8 0C0AB898 */  jal        func_002AE260
    /* B05AC 002AF9AC AFB00030 */   sw        $s0, 0x30($sp)
    /* B05B0 002AF9B0 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* B05B4 002AF9B4 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* B05B8 002AF9B8 34420040 */  ori        $v0, $v0, 0x40
    /* B05BC 002AF9BC 00408021 */  addu       $s0, $v0, $zero
    /* B05C0 002AF9C0 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* B05C4 002AF9C4 A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002AF9C8:
    /* B05C8 002AF9C8 0C0AF7A8 */  jal        osPiGetStatus
    /* B05CC 002AF9CC 00000000 */   nop
    /* B05D0 002AF9D0 30420003 */  andi       $v0, $v0, 0x3
    /* B05D4 002AF9D4 1440FFFC */  bnez       $v0, .L002AF9C8
    /* B05D8 002AF9D8 27B40010 */   addiu     $s4, $sp, 0x10
    /* B05DC 002AF9DC 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* B05E0 002AF9E0 A4300008 */  sh         $s0, %lo(D_B2000008)($at)
    /* B05E4 002AF9E4 27B30018 */  addiu      $s3, $sp, 0x18
    /* B05E8 002AF9E8 27B20020 */  addiu      $s2, $sp, 0x20
    /* B05EC 002AF9EC 27B10028 */  addiu      $s1, $sp, 0x28
  .L002AF9F0:
    /* B05F0 002AF9F0 0C0AB8E0 */  jal        func_002AE380
    /* B05F4 002AF9F4 02802021 */   addu      $a0, $s4, $zero
    /* B05F8 002AF9F8 104000B2 */  beqz       $v0, .L002AFCC4
    /* B05FC 002AF9FC 24020010 */   addiu     $v0, $zero, 0x10
    /* B0600 002AFA00 93A30010 */  lbu        $v1, 0x10($sp)
    /* B0604 002AFA04 1462FFFA */  bne        $v1, $v0, .L002AF9F0
    /* B0608 002AFA08 00000000 */   nop
    /* B060C 002AFA0C 0C0AB96B */  jal        func_002AE5AC
    /* B0610 002AFA10 24040011 */   addiu     $a0, $zero, 0x11
    /* B0614 002AFA14 1040FFF6 */  beqz       $v0, .L002AF9F0
    /* B0618 002AFA18 00000000 */   nop
    /* B061C 002AFA1C 0C0AB8E0 */  jal        func_002AE380
    /* B0620 002AFA20 02802021 */   addu      $a0, $s4, $zero
    /* B0624 002AFA24 1040FFF2 */  beqz       $v0, .L002AF9F0
    /* B0628 002AFA28 00000000 */   nop
    /* B062C 002AFA2C 93A20010 */  lbu        $v0, 0x10($sp)
    /* B0630 002AFA30 2443FFE8 */  addiu      $v1, $v0, -0x18
    /* B0634 002AFA34 2C620030 */  sltiu      $v0, $v1, 0x30
    /* B0638 002AFA38 1040FFED */  beqz       $v0, .L002AF9F0
    /* B063C 002AFA3C 00031080 */   sll       $v0, $v1, 2
    /* B0640 002AFA40 3C01800D */  lui        $at, %hi(jtbl_800CB490)
    /* B0644 002AFA44 00220821 */  addu       $at, $at, $v0
    /* B0648 002AFA48 8C22B490 */  lw         $v0, %lo(jtbl_800CB490)($at)
    /* B064C 002AFA4C 00400008 */  jr         $v0
    /* B0650 002AFA50 00000000 */   nop
    /* B0654 002AFA54 0C0ABBE1 */  jal        func_002AEF84
    /* B0658 002AFA58 00000000 */   nop
    /* B065C 002AFA5C 080ABE7C */  j          .L002AF9F0
    /* B0660 002AFA60 00000000 */   nop
    /* B0664 002AFA64 0C0ABD51 */  jal        func_002AF544
    /* B0668 002AFA68 00000000 */   nop
    /* B066C 002AFA6C 080ABE7C */  j          .L002AF9F0
    /* B0670 002AFA70 00000000 */   nop
    /* B0674 002AFA74 0C0ABDA8 */  jal        func_002AF6A0
    /* B0678 002AFA78 00000000 */   nop
    /* B067C 002AFA7C 080ABE7C */  j          .L002AF9F0
    /* B0680 002AFA80 00000000 */   nop
    /* B0684 002AFA84 0C0AB8E0 */  jal        func_002AE380
    /* B0688 002AFA88 02602021 */   addu      $a0, $s3, $zero
    /* B068C 002AFA8C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0690 002AFA90 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0694 002AFA94 1440FFD6 */  bnez       $v0, .L002AF9F0
    /* B0698 002AFA98 02602021 */   addu      $a0, $s3, $zero
    /* B069C 002AFA9C 93A20018 */  lbu        $v0, 0x18($sp)
    /* B06A0 002AFAA0 0C0AB8E0 */  jal        func_002AE380
    /* B06A4 002AFAA4 00028200 */   sll       $s0, $v0, 8
    /* B06A8 002AFAA8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B06AC 002AFAAC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B06B0 002AFAB0 1440FFCF */  bnez       $v0, .L002AF9F0
    /* B06B4 002AFAB4 02602021 */   addu      $a0, $s3, $zero
    /* B06B8 002AFAB8 93A20018 */  lbu        $v0, 0x18($sp)
    /* B06BC 002AFABC 0C0AB8E0 */  jal        func_002AE380
    /* B06C0 002AFAC0 02028025 */   or        $s0, $s0, $v0
    /* B06C4 002AFAC4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B06C8 002AFAC8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B06CC 002AFACC 1440FFC8 */  bnez       $v0, .L002AF9F0
    /* B06D0 002AFAD0 00108200 */   sll       $s0, $s0, 8
    /* B06D4 002AFAD4 93A20018 */  lbu        $v0, 0x18($sp)
    /* B06D8 002AFAD8 02602021 */  addu       $a0, $s3, $zero
    /* B06DC 002AFADC 0C0AB8E0 */  jal        func_002AE380
    /* B06E0 002AFAE0 02028025 */   or        $s0, $s0, $v0
    /* B06E4 002AFAE4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B06E8 002AFAE8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B06EC 002AFAEC 1440FFC0 */  bnez       $v0, .L002AF9F0
    /* B06F0 002AFAF0 00108200 */   sll       $s0, $s0, 8
    /* B06F4 002AFAF4 93A20018 */  lbu        $v0, 0x18($sp)
    /* B06F8 002AFAF8 02028025 */  or         $s0, $s0, $v0
    /* B06FC 002AFAFC AFB00014 */  sw         $s0, 0x14($sp)
    /* B0700 002AFB00 92040000 */  lbu        $a0, 0x0($s0)
    /* B0704 002AFB04 0C0AB96B */  jal        func_002AE5AC
    /* B0708 002AFB08 00000000 */   nop
    /* B070C 002AFB0C 080ABE7C */  j          .L002AF9F0
    /* B0710 002AFB10 00000000 */   nop
    /* B0714 002AFB14 0C0ABCCF */  jal        func_002AF33C
    /* B0718 002AFB18 00000000 */   nop
    /* B071C 002AFB1C 080ABE7C */  j          .L002AF9F0
    /* B0720 002AFB20 00000000 */   nop
    /* B0724 002AFB24 0C0ABD09 */  jal        func_002AF424
    /* B0728 002AFB28 00000000 */   nop
    /* B072C 002AFB2C 080ABE7C */  j          .L002AF9F0
    /* B0730 002AFB30 00000000 */   nop
    /* B0734 002AFB34 0C0AB8E0 */  jal        func_002AE380
    /* B0738 002AFB38 02402021 */   addu      $a0, $s2, $zero
    /* B073C 002AFB3C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0740 002AFB40 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0744 002AFB44 1440FFAA */  bnez       $v0, .L002AF9F0
    /* B0748 002AFB48 02402021 */   addu      $a0, $s2, $zero
    /* B074C 002AFB4C 93A20020 */  lbu        $v0, 0x20($sp)
    /* B0750 002AFB50 0C0AB8E0 */  jal        func_002AE380
    /* B0754 002AFB54 00028200 */   sll       $s0, $v0, 8
    /* B0758 002AFB58 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B075C 002AFB5C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0760 002AFB60 1440FFA3 */  bnez       $v0, .L002AF9F0
    /* B0764 002AFB64 02402021 */   addu      $a0, $s2, $zero
    /* B0768 002AFB68 93A20020 */  lbu        $v0, 0x20($sp)
    /* B076C 002AFB6C 0C0AB8E0 */  jal        func_002AE380
    /* B0770 002AFB70 02028025 */   or        $s0, $s0, $v0
    /* B0774 002AFB74 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0778 002AFB78 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B077C 002AFB7C 1440FF9C */  bnez       $v0, .L002AF9F0
    /* B0780 002AFB80 00108200 */   sll       $s0, $s0, 8
    /* B0784 002AFB84 93A20020 */  lbu        $v0, 0x20($sp)
    /* B0788 002AFB88 02402021 */  addu       $a0, $s2, $zero
    /* B078C 002AFB8C 0C0AB8E0 */  jal        func_002AE380
    /* B0790 002AFB90 02028025 */   or        $s0, $s0, $v0
    /* B0794 002AFB94 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0798 002AFB98 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B079C 002AFB9C 1440FF94 */  bnez       $v0, .L002AF9F0
    /* B07A0 002AFBA0 00108200 */   sll       $s0, $s0, 8
    /* B07A4 002AFBA4 93A20020 */  lbu        $v0, 0x20($sp)
    /* B07A8 002AFBA8 02028025 */  or         $s0, $s0, $v0
    /* B07AC 002AFBAC 1200FF90 */  beqz       $s0, .L002AF9F0
    /* B07B0 002AFBB0 AFB0001C */   sw        $s0, 0x1C($sp)
    /* B07B4 002AFBB4 0C0B0898 */  jal        osSetIntMask
    /* B07B8 002AFBB8 24040001 */   addiu     $a0, $zero, 0x1
    /* B07BC 002AFBBC 0C0B08F8 */  jal        osWritebackDCacheAll
    /* B07C0 002AFBC0 00000000 */   nop
    /* B07C4 002AFBC4 3C048000 */  lui        $a0, (0x80000000 >> 16)
    /* B07C8 002AFBC8 0C0B0840 */  jal        osInvalICache
    /* B07CC 002AFBCC 3C050080 */   lui       $a1, (0x800000 >> 16)
    /* B07D0 002AFBD0 0200F809 */  jalr       $s0
    /* B07D4 002AFBD4 00000000 */   nop
    /* B07D8 002AFBD8 080ABE7C */  j          .L002AF9F0
    /* B07DC 002AFBDC 00000000 */   nop
    /* B07E0 002AFBE0 0C0AB8E0 */  jal        func_002AE380
    /* B07E4 002AFBE4 02202021 */   addu      $a0, $s1, $zero
    /* B07E8 002AFBE8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B07EC 002AFBEC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B07F0 002AFBF0 1440FF7F */  bnez       $v0, .L002AF9F0
    /* B07F4 002AFBF4 02202021 */   addu      $a0, $s1, $zero
    /* B07F8 002AFBF8 93A20028 */  lbu        $v0, 0x28($sp)
    /* B07FC 002AFBFC 0C0AB8E0 */  jal        func_002AE380
    /* B0800 002AFC00 00028200 */   sll       $s0, $v0, 8
    /* B0804 002AFC04 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0808 002AFC08 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B080C 002AFC0C 1440FF78 */  bnez       $v0, .L002AF9F0
    /* B0810 002AFC10 02202021 */   addu      $a0, $s1, $zero
    /* B0814 002AFC14 93A20028 */  lbu        $v0, 0x28($sp)
    /* B0818 002AFC18 0C0AB8E0 */  jal        func_002AE380
    /* B081C 002AFC1C 02028025 */   or        $s0, $s0, $v0
    /* B0820 002AFC20 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0824 002AFC24 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0828 002AFC28 1440FF71 */  bnez       $v0, .L002AF9F0
    /* B082C 002AFC2C 00108200 */   sll       $s0, $s0, 8
    /* B0830 002AFC30 93A20028 */  lbu        $v0, 0x28($sp)
    /* B0834 002AFC34 02202021 */  addu       $a0, $s1, $zero
    /* B0838 002AFC38 0C0AB8E0 */  jal        func_002AE380
    /* B083C 002AFC3C 02028025 */   or        $s0, $s0, $v0
    /* B0840 002AFC40 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0844 002AFC44 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0848 002AFC48 1440FF69 */  bnez       $v0, .L002AF9F0
    /* B084C 002AFC4C 00108200 */   sll       $s0, $s0, 8
    /* B0850 002AFC50 93A20028 */  lbu        $v0, 0x28($sp)
    /* B0854 002AFC54 27A40029 */  addiu      $a0, $sp, 0x29
    /* B0858 002AFC58 02028025 */  or         $s0, $s0, $v0
    /* B085C 002AFC5C 0C0AB8E0 */  jal        func_002AE380
    /* B0860 002AFC60 AFB00024 */   sw        $s0, 0x24($sp)
    /* B0864 002AFC64 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0868 002AFC68 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B086C 002AFC6C 1440FF60 */  bnez       $v0, .L002AF9F0
    /* B0870 002AFC70 00000000 */   nop
    /* B0874 002AFC74 8FA30024 */  lw         $v1, 0x24($sp)
    /* B0878 002AFC78 93A20029 */  lbu        $v0, 0x29($sp)
    /* B087C 002AFC7C 080ABE7C */  j          .L002AF9F0
    /* B0880 002AFC80 A0620000 */   sb        $v0, 0x0($v1)
    /* B0884 002AFC84 0C0ABC39 */  jal        func_002AF0E4
    /* B0888 002AFC88 00000000 */   nop
    /* B088C 002AFC8C 080ABE7C */  j          .L002AF9F0
    /* B0890 002AFC90 00000000 */   nop
    /* B0894 002AFC94 0C0ABC7C */  jal        func_002AF1F0
    /* B0898 002AFC98 00000000 */   nop
    /* B089C 002AFC9C 080ABE7C */  j          .L002AF9F0
    /* B08A0 002AFCA0 00000000 */   nop
    /* B08A4 002AFCA4 0C0ABDFE */  jal        func_002AF7F8
    /* B08A8 002AFCA8 00000000 */   nop
    /* B08AC 002AFCAC 080ABE7C */  j          .L002AF9F0
    /* B08B0 002AFCB0 00000000 */   nop
    /* B08B4 002AFCB4 0C0ABB92 */  jal        func_002AEE48
    /* B08B8 002AFCB8 00000000 */   nop
    /* B08BC 002AFCBC 080ABE7C */  j          .L002AF9F0
    /* B08C0 002AFCC0 00000000 */   nop
  .L002AFCC4:
    /* B08C4 002AFCC4 8FBF0044 */  lw         $ra, 0x44($sp)
    /* B08C8 002AFCC8 8FB40040 */  lw         $s4, 0x40($sp)
    /* B08CC 002AFCCC 8FB3003C */  lw         $s3, 0x3C($sp)
    /* B08D0 002AFCD0 8FB20038 */  lw         $s2, 0x38($sp)
    /* B08D4 002AFCD4 8FB10034 */  lw         $s1, 0x34($sp)
    /* B08D8 002AFCD8 8FB00030 */  lw         $s0, 0x30($sp)
    /* B08DC 002AFCDC 03E00008 */  jr         $ra
    /* B08E0 002AFCE0 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel func_002AF990
