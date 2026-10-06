.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB864-0xBBA40 (VRAM 0x002BAC64) */
glabel alFxParamHdl
    /* BB864 002BAC64 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* BB868 002BAC68 AFBF0010 */  sw         $ra, 0x10($sp)
    /* BB86C 002BAC6C 24A8FFFE */  addiu      $t0, $a1, -0x2
    /* BB870 002BAC70 05010002 */  bgez       $t0, .L002BAC7C
    /* BB874 002BAC74 01001021 */   addu      $v0, $t0, $zero
    /* BB878 002BAC78 24A20005 */  addiu      $v0, $a1, 0x5
  .L002BAC7C:
    /* BB87C 002BAC7C 000238C3 */  sra        $a3, $v0, 3
    /* BB880 002BAC80 00E02821 */  addu       $a1, $a3, $zero
    /* BB884 002BAC84 000510C0 */  sll        $v0, $a1, 3
    /* BB888 002BAC88 01023823 */  subu       $a3, $t0, $v0
    /* BB88C 002BAC8C 8CC60000 */  lw         $a2, 0x0($a2)
    /* BB890 002BAC90 2CE20008 */  sltiu      $v0, $a3, 0x8
    /* BB894 002BAC94 10400066 */  beqz       $v0, .L002BAE30
    /* BB898 002BAC98 00071080 */   sll       $v0, $a3, 2
    /* BB89C 002BAC9C 3C01800D */  lui        $at, %hi(jtbl_800CC9E8)
    /* BB8A0 002BACA0 00220821 */  addu       $at, $at, $v0
    /* BB8A4 002BACA4 8C22C9E8 */  lw         $v0, %lo(jtbl_800CC9E8)($at)
    /* BB8A8 002BACA8 00400008 */  jr         $v0
    /* BB8AC 002BACAC 00000000 */   nop
    /* BB8B0 002BACB0 00051080 */  sll        $v0, $a1, 2
    /* BB8B4 002BACB4 00451021 */  addu       $v0, $v0, $a1
    /* BB8B8 002BACB8 8C830020 */  lw         $v1, 0x20($a0)
    /* BB8BC 002BACBC 000210C0 */  sll        $v0, $v0, 3
    /* BB8C0 002BACC0 00431021 */  addu       $v0, $v0, $v1
    /* BB8C4 002BACC4 2403FFF8 */  addiu      $v1, $zero, -0x8
    /* BB8C8 002BACC8 00C31824 */  and        $v1, $a2, $v1
    /* BB8CC 002BACCC 080AEB8C */  j          .L002BAE30
    /* BB8D0 002BACD0 AC430000 */   sw        $v1, 0x0($v0)
    /* BB8D4 002BACD4 00051080 */  sll        $v0, $a1, 2
    /* BB8D8 002BACD8 00451021 */  addu       $v0, $v0, $a1
    /* BB8DC 002BACDC 8C830020 */  lw         $v1, 0x20($a0)
    /* BB8E0 002BACE0 000210C0 */  sll        $v0, $v0, 3
    /* BB8E4 002BACE4 00431021 */  addu       $v0, $v0, $v1
    /* BB8E8 002BACE8 2403FFF8 */  addiu      $v1, $zero, -0x8
    /* BB8EC 002BACEC 00C31824 */  and        $v1, $a2, $v1
    /* BB8F0 002BACF0 080AEB8C */  j          .L002BAE30
    /* BB8F4 002BACF4 AC430004 */   sw        $v1, 0x4($v0)
    /* BB8F8 002BACF8 00051080 */  sll        $v0, $a1, 2
    /* BB8FC 002BACFC 00451021 */  addu       $v0, $v0, $a1
    /* BB900 002BAD00 8C830020 */  lw         $v1, 0x20($a0)
    /* BB904 002BAD04 000210C0 */  sll        $v0, $v0, 3
    /* BB908 002BAD08 00431021 */  addu       $v0, $v0, $v1
    /* BB90C 002BAD0C 080AEB8C */  j          .L002BAE30
    /* BB910 002BAD10 A4460008 */   sh        $a2, 0x8($v0)
    /* BB914 002BAD14 00051080 */  sll        $v0, $a1, 2
    /* BB918 002BAD18 00451021 */  addu       $v0, $v0, $a1
    /* BB91C 002BAD1C 8C830020 */  lw         $v1, 0x20($a0)
    /* BB920 002BAD20 000210C0 */  sll        $v0, $v0, 3
    /* BB924 002BAD24 00431021 */  addu       $v0, $v0, $v1
    /* BB928 002BAD28 080AEB8C */  j          .L002BAE30
    /* BB92C 002BAD2C A446000A */   sh        $a2, 0xA($v0)
    /* BB930 002BAD30 00051080 */  sll        $v0, $a1, 2
    /* BB934 002BAD34 00451021 */  addu       $v0, $v0, $a1
    /* BB938 002BAD38 8C830020 */  lw         $v1, 0x20($a0)
    /* BB93C 002BAD3C 000210C0 */  sll        $v0, $v0, 3
    /* BB940 002BAD40 00431021 */  addu       $v0, $v0, $v1
    /* BB944 002BAD44 080AEB8C */  j          .L002BAE30
    /* BB948 002BAD48 A446000C */   sh        $a2, 0xC($v0)
    /* BB94C 002BAD4C 44860000 */  mtc1       $a2, $fv0
    /* BB950 002BAD50 46800020 */  cvt.s.w    $fv0, $fv0
    /* BB954 002BAD54 3C01800D */  lui        $at, %hi(D_800CCA08)
    /* BB958 002BAD58 C421CA08 */  lwc1       $fv0f, %lo(D_800CCA08)($at)
    /* BB95C 002BAD5C 00051080 */  sll        $v0, $a1, 2
    /* BB960 002BAD60 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* BB964 002BAD64 00451021 */  addu       $v0, $v0, $a1
    /* BB968 002BAD68 000210C0 */  sll        $v0, $v0, 3
    /* BB96C 002BAD6C 8C830020 */  lw         $v1, 0x20($a0)
    /* BB970 002BAD70 3C04800E */  lui        $a0, %hi(D_800D80A0)
    /* BB974 002BAD74 8C8480A0 */  lw         $a0, %lo(D_800D80A0)($a0)
    /* BB978 002BAD78 46000000 */  add.s      $fv0, $fv0, $fv0
    /* BB97C 002BAD7C 00431021 */  addu       $v0, $v0, $v1
    /* BB980 002BAD80 C4810044 */  lwc1       $fv0f, 0x44($a0)
    /* BB984 002BAD84 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BB988 002BAD88 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* BB98C 002BAD8C 080AEB8C */  j          .L002BAE30
    /* BB990 002BAD90 E4400010 */   swc1      $fv0, 0x10($v0)
    /* BB994 002BAD94 00051080 */  sll        $v0, $a1, 2
    /* BB998 002BAD98 00451021 */  addu       $v0, $v0, $a1
    /* BB99C 002BAD9C 8C830020 */  lw         $v1, 0x20($a0)
    /* BB9A0 002BADA0 000210C0 */  sll        $v0, $v0, 3
    /* BB9A4 002BADA4 00432021 */  addu       $a0, $v0, $v1
    /* BB9A8 002BADA8 8C820004 */  lw         $v0, 0x4($a0)
    /* BB9AC 002BADAC 8C830000 */  lw         $v1, 0x0($a0)
    /* BB9B0 002BADB0 44861800 */  mtc1       $a2, $fv1f
    /* BB9B4 002BADB4 468018E0 */  cvt.s.w    $fv1f, $fv1f
    /* BB9B8 002BADB8 00431023 */  subu       $v0, $v0, $v1
    /* BB9BC 002BADBC 44821000 */  mtc1       $v0, $fv1
    /* BB9C0 002BADC0 468010A1 */  cvt.d.w    $fv1, $fv1
    /* BB9C4 002BADC4 04410004 */  bgez       $v0, .L002BADD8
    /* BB9C8 002BADC8 00000000 */   nop
    /* BB9CC 002BADCC 3C01800D */  lui        $at, %hi(D_800CCA10)
    /* BB9D0 002BADD0 D420CA10 */  ldc1       $fv0, %lo(D_800CCA10)($at)
    /* BB9D4 002BADD4 46201080 */  add.d      $fv1, $fv1, $fv0
  .L002BADD8:
    /* BB9D8 002BADD8 3C01800D */  lui        $at, %hi(D_800CCA18)
    /* BB9DC 002BADDC C421CA18 */  lwc1       $fv0f, %lo(D_800CCA18)($at)
    /* BB9E0 002BADE0 46201020 */  cvt.s.d    $fv0, $fv1
    /* BB9E4 002BADE4 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* BB9E8 002BADE8 00000000 */  nop
    /* BB9EC 002BADEC 46001802 */  mul.s      $fv0, $fv1f, $fv0
    /* BB9F0 002BADF0 080AEB8C */  j          .L002BAE30
    /* BB9F4 002BADF4 E480001C */   swc1      $fv0, 0x1C($a0)
    /* BB9F8 002BADF8 00051080 */  sll        $v0, $a1, 2
    /* BB9FC 002BADFC 00451021 */  addu       $v0, $v0, $a1
    /* BBA00 002BAE00 8C830020 */  lw         $v1, 0x20($a0)
    /* BBA04 002BAE04 000228C0 */  sll        $a1, $v0, 3
    /* BBA08 002BAE08 00A31821 */  addu       $v1, $a1, $v1
    /* BBA0C 002BAE0C 8C620020 */  lw         $v0, 0x20($v1)
    /* BBA10 002BAE10 10400007 */  beqz       $v0, .L002BAE30
    /* BBA14 002BAE14 00000000 */   nop
    /* BBA18 002BAE18 A4460000 */  sh         $a2, 0x0($v0)
    /* BBA1C 002BAE1C 8C820020 */  lw         $v0, 0x20($a0)
    /* BBA20 002BAE20 00A21021 */  addu       $v0, $a1, $v0
    /* BBA24 002BAE24 8C440020 */  lw         $a0, 0x20($v0)
    /* BBA28 002BAE28 0C0AE5D7 */  jal        init_lpfilter
    /* BBA2C 002BAE2C 00000000 */   nop
  .L002BAE30:
    /* BBA30 002BAE30 8FBF0010 */  lw         $ra, 0x10($sp)
    /* BBA34 002BAE34 00001021 */  addu       $v0, $zero, $zero
    /* BBA38 002BAE38 03E00008 */  jr         $ra
    /* BBA3C 002BAE3C 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel alFxParamHdl
