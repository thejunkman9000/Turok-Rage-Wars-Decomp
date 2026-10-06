.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB583C-0xB59D0 (VRAM 0x002B4C3C) */
glabel func_002B4C3C
    /* B583C 002B4C3C 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B5840 002B4C40 AFB50034 */  sw         $s5, 0x34($sp)
    /* B5844 002B4C44 0080A821 */  addu       $s5, $a0, $zero
    /* B5848 002B4C48 AFB20028 */  sw         $s2, 0x28($sp)
    /* B584C 002B4C4C 00009021 */  addu       $s2, $zero, $zero
    /* B5850 002B4C50 AFB3002C */  sw         $s3, 0x2C($sp)
    /* B5854 002B4C54 AFBF003C */  sw         $ra, 0x3C($sp)
    /* B5858 002B4C58 AFB60038 */  sw         $s6, 0x38($sp)
    /* B585C 002B4C5C AFB40030 */  sw         $s4, 0x30($sp)
    /* B5860 002B4C60 AFB10024 */  sw         $s1, 0x24($sp)
    /* B5864 002B4C64 AFB00020 */  sw         $s0, 0x20($sp)
    /* B5868 002B4C68 90A30008 */  lbu        $v1, 0x8($a1)
    /* B586C 002B4C6C 240200FF */  addiu      $v0, $zero, 0xFF
    /* B5870 002B4C70 1462004D */  bne        $v1, $v0, .L002B4DA8
    /* B5874 002B4C74 02409821 */   addu      $s3, $s2, $zero
    /* B5878 002B4C78 90A30009 */  lbu        $v1, 0x9($a1)
    /* B587C 002B4C7C 24020051 */  addiu      $v0, $zero, 0x51
    /* B5880 002B4C80 14620049 */  bne        $v1, $v0, .L002B4DA8
    /* B5884 002B4C84 00000000 */   nop
    /* B5888 002B4C88 90A2000B */  lbu        $v0, 0xB($a1)
    /* B588C 002B4C8C 90A3000C */  lbu        $v1, 0xC($a1)
    /* B5890 002B4C90 90A5000D */  lbu        $a1, 0xD($a1)
    /* B5894 002B4C94 00021400 */  sll        $v0, $v0, 16
    /* B5898 002B4C98 00031A00 */  sll        $v1, $v1, 8
    /* B589C 002B4C9C 00431025 */  or         $v0, $v0, $v1
    /* B58A0 002B4CA0 00451025 */  or         $v0, $v0, $a1
    /* B58A4 002B4CA4 44820000 */  mtc1       $v0, $fv0
    /* B58A8 002B4CA8 46800020 */  cvt.s.w    $fv0, $fv0
    /* B58AC 002B4CAC 44050000 */  mfc1       $a1, $fv0
    /* B58B0 002B4CB0 8EB40024 */  lw         $s4, 0x24($s5)
    /* B58B4 002B4CB4 0C0AD3B3 */  jal        func_002B4ECC
    /* B58B8 002B4CB8 00000000 */   nop
    /* B58BC 002B4CBC 8EB00050 */  lw         $s0, 0x50($s5)
    /* B58C0 002B4CC0 5200001F */  beql       $s0, $zero, .L002B4D40
    /* B58C4 002B4CC4 02608021 */   addu      $s0, $s3, $zero
    /* B58C8 002B4CC8 24160015 */  addiu      $s6, $zero, 0x15
  .L002B4CCC:
    /* B58CC 002B4CCC 8E110000 */  lw         $s1, 0x0($s0)
    /* B58D0 002B4CD0 8E020008 */  lw         $v0, 0x8($s0)
    /* B58D4 002B4CD4 8603000C */  lh         $v1, 0xC($s0)
    /* B58D8 002B4CD8 14760015 */  bne        $v1, $s6, .L002B4D30
    /* B58DC 002B4CDC 02429021 */   addu      $s2, $s2, $v0
    /* B58E0 002B4CE0 0C0ADD48 */  jal        func_002B7520
    /* B58E4 002B4CE4 02002021 */   addu      $a0, $s0, $zero
    /* B58E8 002B4CE8 12600005 */  beqz       $s3, .L002B4D00
    /* B58EC 002B4CEC 02002021 */   addu      $a0, $s0, $zero
    /* B58F0 002B4CF0 0C0ADD54 */  jal        func_002B7550
    /* B58F4 002B4CF4 02602821 */   addu      $a1, $s3, $zero
    /* B58F8 002B4CF8 080AD344 */  j          .L002B4D10
    /* B58FC 002B4CFC 02402021 */   addu      $a0, $s2, $zero
  .L002B4D00:
    /* B5900 002B4D00 02009821 */  addu       $s3, $s0, $zero
    /* B5904 002B4D04 AE000000 */  sw         $zero, 0x0($s0)
    /* B5908 002B4D08 AE000004 */  sw         $zero, 0x4($s0)
    /* B590C 002B4D0C 02402021 */  addu       $a0, $s2, $zero
  .L002B4D10:
    /* B5910 002B4D10 52200007 */  beql       $s1, $zero, .L002B4D30
    /* B5914 002B4D14 AE040008 */   sw        $a0, 0x8($s0)
    /* B5918 002B4D18 8E030008 */  lw         $v1, 0x8($s0)
    /* B591C 002B4D1C 8E220008 */  lw         $v0, 0x8($s1)
    /* B5920 002B4D20 00839023 */  subu       $s2, $a0, $v1
    /* B5924 002B4D24 00431021 */  addu       $v0, $v0, $v1
    /* B5928 002B4D28 AE220008 */  sw         $v0, 0x8($s1)
    /* B592C 002B4D2C AE040008 */  sw         $a0, 0x8($s0)
  .L002B4D30:
    /* B5930 002B4D30 02208021 */  addu       $s0, $s1, $zero
    /* B5934 002B4D34 1600FFE5 */  bnez       $s0, .L002B4CCC
    /* B5938 002B4D38 00000000 */   nop
    /* B593C 002B4D3C 02608021 */  addu       $s0, $s3, $zero
  .L002B4D40:
    /* B5940 002B4D40 12000019 */  beqz       $s0, .L002B4DA8
    /* B5944 002B4D44 00000000 */   nop
  .L002B4D48:
    /* B5948 002B4D48 8E020008 */  lw         $v0, 0x8($s0)
    /* B594C 002B4D4C 0054001A */  div        $zero, $v0, $s4
    /* B5950 002B4D50 16800002 */  bnez       $s4, .L002B4D5C
    /* B5954 002B4D54 00000000 */   nop
    /* B5958 002B4D58 0007000D */  break      7
  .L002B4D5C:
    /* B595C 002B4D5C 2401FFFF */  addiu      $at, $zero, -0x1
    /* B5960 002B4D60 16810004 */  bne        $s4, $at, .L002B4D74
    /* B5964 002B4D64 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* B5968 002B4D68 14410002 */  bne        $v0, $at, .L002B4D74
    /* B596C 002B4D6C 00000000 */   nop
    /* B5970 002B4D70 0006000D */  break      6
  .L002B4D74:
    /* B5974 002B4D74 00001012 */  mflo       $v0
    /* B5978 002B4D78 8EA30024 */  lw         $v1, 0x24($s5)
    /* B597C 002B4D7C 00000000 */  nop
    /* B5980 002B4D80 00430018 */  mult       $v0, $v1
    /* B5984 002B4D84 26A40048 */  addiu      $a0, $s5, 0x48
    /* B5988 002B4D88 02002821 */  addu       $a1, $s0, $zero
    /* B598C 002B4D8C 8E110000 */  lw         $s1, 0x0($s0)
    /* B5990 002B4D90 00001012 */  mflo       $v0
    /* B5994 002B4D94 0C0AD38F */  jal        func_002B4E3C
    /* B5998 002B4D98 ACA20008 */   sw        $v0, 0x8($a1)
    /* B599C 002B4D9C 02208021 */  addu       $s0, $s1, $zero
    /* B59A0 002B4DA0 1600FFE9 */  bnez       $s0, .L002B4D48
    /* B59A4 002B4DA4 00000000 */   nop
  .L002B4DA8:
    /* B59A8 002B4DA8 8FBF003C */  lw         $ra, 0x3C($sp)
    /* B59AC 002B4DAC 8FB60038 */  lw         $s6, 0x38($sp)
    /* B59B0 002B4DB0 8FB50034 */  lw         $s5, 0x34($sp)
    /* B59B4 002B4DB4 8FB40030 */  lw         $s4, 0x30($sp)
    /* B59B8 002B4DB8 8FB3002C */  lw         $s3, 0x2C($sp)
    /* B59BC 002B4DBC 8FB20028 */  lw         $s2, 0x28($sp)
    /* B59C0 002B4DC0 8FB10024 */  lw         $s1, 0x24($sp)
    /* B59C4 002B4DC4 8FB00020 */  lw         $s0, 0x20($sp)
    /* B59C8 002B4DC8 03E00008 */  jr         $ra
    /* B59CC 002B4DCC 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel func_002B4C3C
