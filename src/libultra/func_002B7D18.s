.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8918-0xB89C0 (VRAM 0x002B7D18) */
glabel func_002B7D18
    /* B8918 002B7D18 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B891C 002B7D1C AFB20018 */  sw         $s2, 0x18($sp)
    /* B8920 002B7D20 00809021 */  addu       $s2, $a0, $zero
    /* B8924 002B7D24 AFB40020 */  sw         $s4, 0x20($sp)
    /* B8928 002B7D28 00A0A021 */  addu       $s4, $a1, $zero
    /* B892C 002B7D2C 24040001 */  addiu      $a0, $zero, 0x1
    /* B8930 002B7D30 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B8934 002B7D34 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B8938 002B7D38 AFB10014 */  sw         $s1, 0x14($sp)
    /* B893C 002B7D3C 0C0B0898 */  jal        osSetIntMask
    /* B8940 002B7D40 AFB00010 */   sw        $s0, 0x10($sp)
    /* B8944 002B7D44 8E500008 */  lw         $s0, 0x8($s2)
    /* B8948 002B7D48 12000013 */  beqz       $s0, .L002B7D98
    /* B894C 002B7D4C 00409821 */   addu      $s3, $v0, $zero
  .L002B7D50:
    /* B8950 002B7D50 8E020010 */  lw         $v0, 0x10($s0)
    /* B8954 002B7D54 8E110000 */  lw         $s1, 0x0($s0)
    /* B8958 002B7D58 5454000D */  bnel       $v0, $s4, .L002B7D90
    /* B895C 002B7D5C 02208021 */   addu      $s0, $s1, $zero
    /* B8960 002B7D60 12200005 */  beqz       $s1, .L002B7D78
    /* B8964 002B7D64 00000000 */   nop
    /* B8968 002B7D68 8E220008 */  lw         $v0, 0x8($s1)
    /* B896C 002B7D6C 8E030008 */  lw         $v1, 0x8($s0)
    /* B8970 002B7D70 00431021 */  addu       $v0, $v0, $v1
    /* B8974 002B7D74 AE220008 */  sw         $v0, 0x8($s1)
  .L002B7D78:
    /* B8978 002B7D78 0C0ADD48 */  jal        func_002B7520
    /* B897C 002B7D7C 02002021 */   addu      $a0, $s0, $zero
    /* B8980 002B7D80 02002021 */  addu       $a0, $s0, $zero
    /* B8984 002B7D84 0C0ADD54 */  jal        func_002B7550
    /* B8988 002B7D88 02402821 */   addu      $a1, $s2, $zero
    /* B898C 002B7D8C 02208021 */  addu       $s0, $s1, $zero
  .L002B7D90:
    /* B8990 002B7D90 1600FFEF */  bnez       $s0, .L002B7D50
    /* B8994 002B7D94 00000000 */   nop
  .L002B7D98:
    /* B8998 002B7D98 0C0B0898 */  jal        osSetIntMask
    /* B899C 002B7D9C 02602021 */   addu      $a0, $s3, $zero
    /* B89A0 002B7DA0 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B89A4 002B7DA4 8FB40020 */  lw         $s4, 0x20($sp)
    /* B89A8 002B7DA8 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B89AC 002B7DAC 8FB20018 */  lw         $s2, 0x18($sp)
    /* B89B0 002B7DB0 8FB10014 */  lw         $s1, 0x14($sp)
    /* B89B4 002B7DB4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B89B8 002B7DB8 03E00008 */  jr         $ra
    /* B89BC 002B7DBC 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B7D18
