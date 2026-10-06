.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB77E4-0xB7904 (VRAM 0x002B6BE4) */
glabel __seqpReleaseVoice
    /* B77E4 002B6BE4 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B77E8 002B6BE8 AFB40030 */  sw         $s4, 0x30($sp)
    /* B77EC 002B6BEC 00A0A021 */  addu       $s4, $a1, $zero
    /* B77F0 002B6BF0 AFBF003C */  sw         $ra, 0x3C($sp)
    /* B77F4 002B6BF4 AFB60038 */  sw         $s6, 0x38($sp)
    /* B77F8 002B6BF8 AFB50034 */  sw         $s5, 0x34($sp)
    /* B77FC 002B6BFC AFB3002C */  sw         $s3, 0x2C($sp)
    /* B7800 002B6C00 AFB20028 */  sw         $s2, 0x28($sp)
    /* B7804 002B6C04 AFB10024 */  sw         $s1, 0x24($sp)
    /* B7808 002B6C08 AFB00020 */  sw         $s0, 0x20($sp)
    /* B780C 002B6C0C 8E920010 */  lw         $s2, 0x10($s4)
    /* B7810 002B6C10 00809821 */  addu       $s3, $a0, $zero
    /* B7814 002B6C14 92420034 */  lbu        $v0, 0x34($s2)
    /* B7818 002B6C18 14400019 */  bnez       $v0, .L002B6C80
    /* B781C 002B6C1C 00C0A821 */   addu      $s5, $a2, $zero
    /* B7820 002B6C20 8E700050 */  lw         $s0, 0x50($s3)
    /* B7824 002B6C24 12000016 */  beqz       $s0, .L002B6C80
    /* B7828 002B6C28 24160006 */   addiu     $s6, $zero, 0x6
  .L002B6C2C:
    /* B782C 002B6C2C 8602000C */  lh         $v0, 0xC($s0)
    /* B7830 002B6C30 8E110000 */  lw         $s1, 0x0($s0)
    /* B7834 002B6C34 54560010 */  bnel       $v0, $s6, .L002B6C78
    /* B7838 002B6C38 02208021 */   addu      $s0, $s1, $zero
    /* B783C 002B6C3C 8E020010 */  lw         $v0, 0x10($s0)
    /* B7840 002B6C40 5454000D */  bnel       $v0, $s4, .L002B6C78
    /* B7844 002B6C44 02208021 */   addu      $s0, $s1, $zero
    /* B7848 002B6C48 12200005 */  beqz       $s1, .L002B6C60
    /* B784C 002B6C4C 00000000 */   nop
    /* B7850 002B6C50 8E220008 */  lw         $v0, 0x8($s1)
    /* B7854 002B6C54 8E030008 */  lw         $v1, 0x8($s0)
    /* B7858 002B6C58 00431021 */  addu       $v0, $v0, $v1
    /* B785C 002B6C5C AE220008 */  sw         $v0, 0x8($s1)
  .L002B6C60:
    /* B7860 002B6C60 0C0ADD48 */  jal        alUnlink
    /* B7864 002B6C64 02002021 */   addu      $a0, $s0, $zero
    /* B7868 002B6C68 02002021 */  addu       $a0, $s0, $zero
    /* B786C 002B6C6C 0C0ADD54 */  jal        alLink
    /* B7870 002B6C70 26650048 */   addiu     $a1, $s3, 0x48
    /* B7874 002B6C74 02208021 */  addu       $s0, $s1, $zero
  .L002B6C78:
    /* B7878 002B6C78 1600FFEC */  bnez       $s0, .L002B6C2C
    /* B787C 002B6C7C 00000000 */   nop
  .L002B6C80:
    /* B7880 002B6C80 24020003 */  addiu      $v0, $zero, 0x3
    /* B7884 002B6C84 A2400033 */  sb         $zero, 0x33($s2)
    /* B7888 002B6C88 A2420034 */  sb         $v0, 0x34($s2)
    /* B788C 002B6C8C A2400030 */  sb         $zero, 0x30($s2)
    /* B7890 002B6C90 8E62001C */  lw         $v0, 0x1C($s3)
    /* B7894 002B6C94 02802821 */  addu       $a1, $s4, $zero
    /* B7898 002B6C98 00551021 */  addu       $v0, $v0, $s5
    /* B789C 002B6C9C AE420024 */  sw         $v0, 0x24($s2)
    /* B78A0 002B6CA0 8E640014 */  lw         $a0, 0x14($s3)
    /* B78A4 002B6CA4 0C0AE150 */  jal        alSynSetPriority
    /* B78A8 002B6CA8 00003021 */   addu      $a2, $zero, $zero
    /* B78AC 002B6CAC 02802821 */  addu       $a1, $s4, $zero
    /* B78B0 002B6CB0 00003021 */  addu       $a2, $zero, $zero
    /* B78B4 002B6CB4 8E640014 */  lw         $a0, 0x14($s3)
    /* B78B8 002B6CB8 0C0AE154 */  jal        alSynSetVol
    /* B78BC 002B6CBC 02A03821 */   addu      $a3, $s5, $zero
    /* B78C0 002B6CC0 26640048 */  addiu      $a0, $s3, 0x48
    /* B78C4 002B6CC4 27A50010 */  addiu      $a1, $sp, 0x10
    /* B78C8 002B6CC8 02A03021 */  addu       $a2, $s5, $zero
    /* B78CC 002B6CCC 24020005 */  addiu      $v0, $zero, 0x5
    /* B78D0 002B6CD0 A7A20010 */  sh         $v0, 0x10($sp)
    /* B78D4 002B6CD4 0C0AD469 */  jal        alEvtqPostEvent
    /* B78D8 002B6CD8 AFB40014 */   sw        $s4, 0x14($sp)
    /* B78DC 002B6CDC 8FBF003C */  lw         $ra, 0x3C($sp)
    /* B78E0 002B6CE0 8FB60038 */  lw         $s6, 0x38($sp)
    /* B78E4 002B6CE4 8FB50034 */  lw         $s5, 0x34($sp)
    /* B78E8 002B6CE8 8FB40030 */  lw         $s4, 0x30($sp)
    /* B78EC 002B6CEC 8FB3002C */  lw         $s3, 0x2C($sp)
    /* B78F0 002B6CF0 8FB20028 */  lw         $s2, 0x28($sp)
    /* B78F4 002B6CF4 8FB10024 */  lw         $s1, 0x24($sp)
    /* B78F8 002B6CF8 8FB00020 */  lw         $s0, 0x20($sp)
    /* B78FC 002B6CFC 03E00008 */  jr         $ra
    /* B7900 002B6D00 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel __seqpReleaseVoice
