.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC536C-0xC54F4 (VRAM 0x002C476C) */
glabel mdctFftInit
    /* C536C 002C476C 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* C5370 002C4770 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C5374 002C4774 00809821 */  addu       $s3, $a0, $zero
    /* C5378 002C4778 AFB10014 */  sw         $s1, 0x14($sp)
    /* C537C 002C477C AFB20018 */  sw         $s2, 0x18($sp)
    /* C5380 002C4780 00139043 */  sra        $s2, $s3, 1
    /* C5384 002C4784 AFB40020 */  sw         $s4, 0x20($sp)
    /* C5388 002C4788 3C14800E */  lui        $s4, %hi(D_800D9370)
    /* C538C 002C478C 26949370 */  addiu      $s4, $s4, %lo(D_800D9370)
    /* C5390 002C4790 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C5394 002C4794 AFB00010 */  sw         $s0, 0x10($sp)
    /* C5398 002C4798 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C539C 002C479C F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C53A0 002C47A0 F7B40028 */  sdc1       $fs0, 0x28($sp)
    /* C53A4 002C47A4 1A400018 */  blez       $s2, .L002C4808
    /* C53A8 002C47A8 00008821 */   addu      $s1, $zero, $zero
    /* C53AC 002C47AC 3C01800D */  lui        $at, %hi(D_800CCF20)
    /* C53B0 002C47B0 C436CF20 */  lwc1       $fs1, %lo(D_800CCF20)($at)
    /* C53B4 002C47B4 4493A800 */  mtc1       $s3, $fs0f
    /* C53B8 002C47B8 4680AD60 */  cvt.s.w    $fs0f, $fs0f
  .L002C47BC:
    /* C53BC 002C47BC 4491A000 */  mtc1       $s1, $fs0
    /* C53C0 002C47C0 4680A520 */  cvt.s.w    $fs0, $fs0
    /* C53C4 002C47C4 4616A502 */  mul.s      $fs0, $fs0, $fs1
    /* C53C8 002C47C8 4615A503 */  div.s      $fs0, $fs0, $fs0f
    /* C53CC 002C47CC 0C0AED8C */  jal        cosf
    /* C53D0 002C47D0 4600A306 */   mov.s     $fa0, $fs0
    /* C53D4 002C47D4 4600A306 */  mov.s      $fa0, $fs0
    /* C53D8 002C47D8 8E820000 */  lw         $v0, 0x0($s4)
    /* C53DC 002C47DC 00118080 */  sll        $s0, $s1, 2
    /* C53E0 002C47E0 02021021 */  addu       $v0, $s0, $v0
    /* C53E4 002C47E4 0C0AF080 */  jal        sinf
    /* C53E8 002C47E8 E4400000 */   swc1      $fv0, 0x0($v0)
    /* C53EC 002C47EC 26310001 */  addiu      $s1, $s1, 0x1
    /* C53F0 002C47F0 8E820004 */  lw         $v0, 0x4($s4)
    /* C53F4 002C47F4 46000007 */  neg.s      $fv0, $fv0
    /* C53F8 002C47F8 02028021 */  addu       $s0, $s0, $v0
    /* C53FC 002C47FC 0232102A */  slt        $v0, $s1, $s2
    /* C5400 002C4800 1440FFEE */  bnez       $v0, .L002C47BC
    /* C5404 002C4804 E6000000 */   swc1      $fv0, 0x0($s0)
  .L002C4808:
    /* C5408 002C4808 00003821 */  addu       $a3, $zero, $zero
    /* C540C 002C480C 8E880008 */  lw         $t0, 0x8($s4)
    /* C5410 002C4810 1A600007 */  blez       $s3, .L002C4830
    /* C5414 002C4814 00134840 */   sll       $t1, $s3, 1
    /* C5418 002C4818 01001821 */  addu       $v1, $t0, $zero
  .L002C481C:
    /* C541C 002C481C AC670000 */  sw         $a3, 0x0($v1)
    /* C5420 002C4820 24E70001 */  addiu      $a3, $a3, 0x1
    /* C5424 002C4824 00F3102A */  slt        $v0, $a3, $s3
    /* C5428 002C4828 1440FFFC */  bnez       $v0, .L002C481C
    /* C542C 002C482C 24630004 */   addiu     $v1, $v1, 0x4
  .L002C4830:
    /* C5430 002C4830 24060001 */  addiu      $a2, $zero, 0x1
    /* C5434 002C4834 19200022 */  blez       $t1, .L002C48C0
    /* C5438 002C4838 00C03821 */   addu      $a3, $a2, $zero
    /* C543C 002C483C 2A6A0002 */  slti       $t2, $s3, 0x2
  .L002C4840:
    /* C5440 002C4840 00E6102A */  slt        $v0, $a3, $a2
    /* C5444 002C4844 10400010 */  beqz       $v0, .L002C4888
    /* C5448 002C4848 24C4FFFF */   addiu     $a0, $a2, -0x1
    /* C544C 002C484C 000417C2 */  srl        $v0, $a0, 31
    /* C5450 002C4850 00822021 */  addu       $a0, $a0, $v0
    /* C5454 002C4854 00042043 */  sra        $a0, $a0, 1
    /* C5458 002C4858 00042080 */  sll        $a0, $a0, 2
    /* C545C 002C485C 00882021 */  addu       $a0, $a0, $t0
    /* C5460 002C4860 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C5464 002C4864 00021FC2 */  srl        $v1, $v0, 31
    /* C5468 002C4868 00431021 */  addu       $v0, $v0, $v1
    /* C546C 002C486C 00021043 */  sra        $v0, $v0, 1
    /* C5470 002C4870 00021080 */  sll        $v0, $v0, 2
    /* C5474 002C4874 00481021 */  addu       $v0, $v0, $t0
    /* C5478 002C4878 8C430000 */  lw         $v1, 0x0($v0)
    /* C547C 002C487C 8C850000 */  lw         $a1, 0x0($a0)
    /* C5480 002C4880 AC830000 */  sw         $v1, 0x0($a0)
    /* C5484 002C4884 AC450000 */  sw         $a1, 0x0($v0)
  .L002C4888:
    /* C5488 002C4888 15400009 */  bnez       $t2, .L002C48B0
    /* C548C 002C488C 02601821 */   addu      $v1, $s3, $zero
    /* C5490 002C4890 0066102A */  slt        $v0, $v1, $a2
  .L002C4894:
    /* C5494 002C4894 50400007 */  beql       $v0, $zero, .L002C48B4
    /* C5498 002C4898 24E70002 */   addiu     $a3, $a3, 0x2
    /* C549C 002C489C 00C33023 */  subu       $a2, $a2, $v1
    /* C54A0 002C48A0 00031843 */  sra        $v1, $v1, 1
    /* C54A4 002C48A4 28620002 */  slti       $v0, $v1, 0x2
    /* C54A8 002C48A8 1040FFFA */  beqz       $v0, .L002C4894
    /* C54AC 002C48AC 0066102A */   slt       $v0, $v1, $a2
  .L002C48B0:
    /* C54B0 002C48B0 24E70002 */  addiu      $a3, $a3, 0x2
  .L002C48B4:
    /* C54B4 002C48B4 0127102A */  slt        $v0, $t1, $a3
    /* C54B8 002C48B8 1040FFE1 */  beqz       $v0, .L002C4840
    /* C54BC 002C48BC 00C33021 */   addu      $a2, $a2, $v1
  .L002C48C0:
    /* C54C0 002C48C0 02801021 */  addu       $v0, $s4, $zero
    /* C54C4 002C48C4 AE93000C */  sw         $s3, 0xC($s4)
    /* C54C8 002C48C8 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C54CC 002C48CC 8FB40020 */  lw         $s4, 0x20($sp)
    /* C54D0 002C48D0 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C54D4 002C48D4 8FB20018 */  lw         $s2, 0x18($sp)
    /* C54D8 002C48D8 8FB10014 */  lw         $s1, 0x14($sp)
    /* C54DC 002C48DC 8FB00010 */  lw         $s0, 0x10($sp)
    /* C54E0 002C48E0 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C54E4 002C48E4 D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C54E8 002C48E8 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C54EC 002C48EC 03E00008 */  jr         $ra
    /* C54F0 002C48F0 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel mdctFftInit
