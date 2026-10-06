.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9714-0xB98C8 (VRAM 0x002B8B14) */
glabel alAudioFrame
    /* B9714 002B8B14 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B9718 002B8B18 AFB10024 */  sw         $s1, 0x24($sp)
    /* B971C 002B8B1C 3C11800E */  lui        $s1, %hi(alGlobalsp)
    /* B9720 002B8B20 8E3180A0 */  lw         $s1, %lo(alGlobalsp)($s1)
    /* B9724 002B8B24 AFB7003C */  sw         $s7, 0x3C($sp)
    /* B9728 002B8B28 0080B821 */  addu       $s7, $a0, $zero
    /* B972C 002B8B2C AFBE0040 */  sw         $fp, 0x40($sp)
    /* B9730 002B8B30 00A0F021 */  addu       $fp, $a1, $zero
    /* B9734 002B8B34 AFB3002C */  sw         $s3, 0x2C($sp)
    /* B9738 002B8B38 00E09821 */  addu       $s3, $a3, $zero
    /* B973C 002B8B3C AFB40030 */  sw         $s4, 0x30($sp)
    /* B9740 002B8B40 02E0A021 */  addu       $s4, $s7, $zero
    /* B9744 002B8B44 AFBF0044 */  sw         $ra, 0x44($sp)
    /* B9748 002B8B48 AFB60038 */  sw         $s6, 0x38($sp)
    /* B974C 002B8B4C AFB50034 */  sw         $s5, 0x34($sp)
    /* B9750 002B8B50 AFB20028 */  sw         $s2, 0x28($sp)
    /* B9754 002B8B54 AFB00020 */  sw         $s0, 0x20($sp)
    /* B9758 002B8B58 8E220000 */  lw         $v0, 0x0($s1)
    /* B975C 002B8B5C 00C0A821 */  addu       $s5, $a2, $zero
    /* B9760 002B8B60 14400003 */  bnez       $v0, .L002B8B70
    /* B9764 002B8B64 A7A0001C */   sh        $zero, 0x1C($sp)
    /* B9768 002B8B68 080AE325 */  j          .L002B8C94
    /* B976C 002B8B6C AFC00000 */   sw        $zero, 0x0($fp)
  .L002B8B70:
    /* B9770 002B8B70 02202021 */  addu       $a0, $s1, $zero
    /* B9774 002B8B74 0C0AE378 */  jal        __nextSampleTime
    /* B9778 002B8B78 27A50018 */   addiu     $a1, $sp, 0x18
    /* B977C 002B8B7C 8E230020 */  lw         $v1, 0x20($s1)
    /* B9780 002B8B80 AE22001C */  sw         $v0, 0x1C($s1)
    /* B9784 002B8B84 00431023 */  subu       $v0, $v0, $v1
    /* B9788 002B8B88 0053102A */  slt        $v0, $v0, $s3
    /* B978C 002B8B8C 10400019 */  beqz       $v0, .L002B8BF4
    /* B9790 002B8B90 00000000 */   nop
    /* B9794 002B8B94 2410FFF0 */  addiu      $s0, $zero, -0x10
  .L002B8B98:
    /* B9798 002B8B98 8E22001C */  lw         $v0, 0x1C($s1)
    /* B979C 002B8B9C 8FA40018 */  lw         $a0, 0x18($sp)
    /* B97A0 002B8BA0 00501024 */  and        $v0, $v0, $s0
    /* B97A4 002B8BA4 AE22001C */  sw         $v0, 0x1C($s1)
    /* B97A8 002B8BA8 8C820008 */  lw         $v0, 0x8($a0)
    /* B97AC 002B8BAC 0040F809 */  jalr       $v0
    /* B97B0 002B8BB0 00000000 */   nop
    /* B97B4 002B8BB4 02202021 */  addu       $a0, $s1, $zero
    /* B97B8 002B8BB8 0C0AE3A2 */  jal        _timeToSamplesNoRound_2
    /* B97BC 002B8BBC 00402821 */   addu      $a1, $v0, $zero
    /* B97C0 002B8BC0 8FA60018 */  lw         $a2, 0x18($sp)
    /* B97C4 002B8BC4 02202021 */  addu       $a0, $s1, $zero
    /* B97C8 002B8BC8 8CC30010 */  lw         $v1, 0x10($a2)
    /* B97CC 002B8BCC 27A50018 */  addiu      $a1, $sp, 0x18
    /* B97D0 002B8BD0 00621821 */  addu       $v1, $v1, $v0
    /* B97D4 002B8BD4 0C0AE378 */  jal        __nextSampleTime
    /* B97D8 002B8BD8 ACC30010 */   sw        $v1, 0x10($a2)
    /* B97DC 002B8BDC 8E230020 */  lw         $v1, 0x20($s1)
    /* B97E0 002B8BE0 AE22001C */  sw         $v0, 0x1C($s1)
    /* B97E4 002B8BE4 00431023 */  subu       $v0, $v0, $v1
    /* B97E8 002B8BE8 0053102A */  slt        $v0, $v0, $s3
    /* B97EC 002B8BEC 1440FFEA */  bnez       $v0, .L002B8B98
    /* B97F0 002B8BF0 00000000 */   nop
  .L002B8BF4:
    /* B97F4 002B8BF4 8E22001C */  lw         $v0, 0x1C($s1)
    /* B97F8 002B8BF8 2403FFF0 */  addiu      $v1, $zero, -0x10
    /* B97FC 002B8BFC 00431024 */  and        $v0, $v0, $v1
    /* B9800 002B8C00 1A60001F */  blez       $s3, .L002B8C80
    /* B9804 002B8C04 AE22001C */   sw        $v0, 0x1C($s1)
    /* B9808 002B8C08 3C160700 */  lui        $s6, (0x7000000 >> 16)
  .L002B8C0C:
    /* B980C 002B8C0C 8E230048 */  lw         $v1, 0x48($s1)
    /* B9810 002B8C10 0073102A */  slt        $v0, $v1, $s3
    /* B9814 002B8C14 10400002 */  beqz       $v0, .L002B8C20
    /* B9818 002B8C18 02609021 */   addu      $s2, $s3, $zero
    /* B981C 002B8C1C 00609021 */  addu       $s2, $v1, $zero
  .L002B8C20:
    /* B9820 002B8C20 24050006 */  addiu      $a1, $zero, 0x6
    /* B9824 002B8C24 AE960000 */  sw         $s6, 0x0($s4)
    /* B9828 002B8C28 AE800004 */  sw         $zero, 0x4($s4)
    /* B982C 002B8C2C 8E300038 */  lw         $s0, 0x38($s1)
    /* B9830 002B8C30 02A03021 */  addu       $a2, $s5, $zero
    /* B9834 002B8C34 8E020008 */  lw         $v0, 0x8($s0)
    /* B9838 002B8C38 0040F809 */  jalr       $v0
    /* B983C 002B8C3C 02002021 */   addu      $a0, $s0, $zero
    /* B9840 002B8C40 02002021 */  addu       $a0, $s0, $zero
    /* B9844 002B8C44 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9848 002B8C48 26820008 */  addiu      $v0, $s4, 0x8
    /* B984C 002B8C4C AFA20010 */  sw         $v0, 0x10($sp)
    /* B9850 002B8C50 8C820004 */  lw         $v0, 0x4($a0)
    /* B9854 002B8C54 8E270020 */  lw         $a3, 0x20($s1)
    /* B9858 002B8C58 0040F809 */  jalr       $v0
    /* B985C 002B8C5C 02403021 */   addu      $a2, $s2, $zero
    /* B9860 002B8C60 0040A021 */  addu       $s4, $v0, $zero
    /* B9864 002B8C64 02729823 */  subu       $s3, $s3, $s2
    /* B9868 002B8C68 00121880 */  sll        $v1, $s2, 2
    /* B986C 002B8C6C 8E220020 */  lw         $v0, 0x20($s1)
    /* B9870 002B8C70 02A3A821 */  addu       $s5, $s5, $v1
    /* B9874 002B8C74 00521021 */  addu       $v0, $v0, $s2
    /* B9878 002B8C78 1E60FFE4 */  bgtz       $s3, .L002B8C0C
    /* B987C 002B8C7C AE220020 */   sw        $v0, 0x20($s1)
  .L002B8C80:
    /* B9880 002B8C80 02971023 */  subu       $v0, $s4, $s7
    /* B9884 002B8C84 000210C3 */  sra        $v0, $v0, 3
    /* B9888 002B8C88 AFC20000 */  sw         $v0, 0x0($fp)
    /* B988C 002B8C8C 0C0AE353 */  jal        _collectPVoices
    /* B9890 002B8C90 02202021 */   addu      $a0, $s1, $zero
  .L002B8C94:
    /* B9894 002B8C94 02801021 */  addu       $v0, $s4, $zero
    /* B9898 002B8C98 8FBF0044 */  lw         $ra, 0x44($sp)
    /* B989C 002B8C9C 8FBE0040 */  lw         $fp, 0x40($sp)
    /* B98A0 002B8CA0 8FB7003C */  lw         $s7, 0x3C($sp)
    /* B98A4 002B8CA4 8FB60038 */  lw         $s6, 0x38($sp)
    /* B98A8 002B8CA8 8FB50034 */  lw         $s5, 0x34($sp)
    /* B98AC 002B8CAC 8FB40030 */  lw         $s4, 0x30($sp)
    /* B98B0 002B8CB0 8FB3002C */  lw         $s3, 0x2C($sp)
    /* B98B4 002B8CB4 8FB20028 */  lw         $s2, 0x28($sp)
    /* B98B8 002B8CB8 8FB10024 */  lw         $s1, 0x24($sp)
    /* B98BC 002B8CBC 8FB00020 */  lw         $s0, 0x20($sp)
    /* B98C0 002B8CC0 03E00008 */  jr         $ra
    /* B98C4 002B8CC4 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel alAudioFrame
