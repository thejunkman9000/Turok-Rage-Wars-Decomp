.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB79F4-0xB7ABC (VRAM 0x002B6DF4) */
glabel func_002B6DF4
    /* B79F4 002B6DF4 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B79F8 002B6DF8 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B79FC 002B6DFC 00808821 */  addu       $s1, $a0, $zero
    /* B7A00 002B6E00 24030001 */  addiu      $v1, $zero, 0x1
    /* B7A04 002B6E04 AFBF0030 */  sw         $ra, 0x30($sp)
    /* B7A08 002B6E08 AFB00028 */  sw         $s0, 0x28($sp)
    /* B7A0C 002B6E0C 8E22002C */  lw         $v0, 0x2C($s1)
    /* B7A10 002B6E10 8E300018 */  lw         $s0, 0x18($s1)
    /* B7A14 002B6E14 14430024 */  bne        $v0, $v1, .L002B6EA8
    /* B7A18 002B6E18 00000000 */   nop
    /* B7A1C 002B6E1C 12000022 */  beqz       $s0, .L002B6EA8
    /* B7A20 002B6E20 02002021 */   addu      $a0, $s0, $zero
    /* B7A24 002B6E24 0C0ADCF1 */  jal        func_002B73C4
    /* B7A28 002B6E28 27A50020 */   addiu     $a1, $sp, 0x20
    /* B7A2C 002B6E2C 304200FF */  andi       $v0, $v0, 0xFF
    /* B7A30 002B6E30 1040001D */  beqz       $v0, .L002B6EA8
    /* B7A34 002B6E34 00000000 */   nop
    /* B7A38 002B6E38 8E220084 */  lw         $v0, 0x84($s1)
    /* B7A3C 002B6E3C 10400012 */  beqz       $v0, .L002B6E88
    /* B7A40 002B6E40 00000000 */   nop
    /* B7A44 002B6E44 0C0ADC66 */  jal        func_002B7198
    /* B7A48 002B6E48 02002021 */   addu      $a0, $s0, $zero
    /* B7A4C 002B6E4C 8E230080 */  lw         $v1, 0x80($s1)
    /* B7A50 002B6E50 8FA40020 */  lw         $a0, 0x20($sp)
    /* B7A54 002B6E54 8C630008 */  lw         $v1, 0x8($v1)
    /* B7A58 002B6E58 00441021 */  addu       $v0, $v0, $a0
    /* B7A5C 002B6E5C 0043102A */  slt        $v0, $v0, $v1
    /* B7A60 002B6E60 14400009 */  bnez       $v0, .L002B6E88
    /* B7A64 002B6E64 00000000 */   nop
    /* B7A68 002B6E68 8E25007C */  lw         $a1, 0x7C($s1)
    /* B7A6C 002B6E6C 0C0ADCE3 */  jal        func_002B738C
    /* B7A70 002B6E70 02002021 */   addu      $a0, $s0, $zero
    /* B7A74 002B6E74 8E230084 */  lw         $v1, 0x84($s1)
    /* B7A78 002B6E78 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B7A7C 002B6E7C 10620002 */  beq        $v1, $v0, .L002B6E88
    /* B7A80 002B6E80 00621021 */   addu      $v0, $v1, $v0
    /* B7A84 002B6E84 AE220084 */  sw         $v0, 0x84($s1)
  .L002B6E88:
    /* B7A88 002B6E88 8FA20020 */  lw         $v0, 0x20($sp)
    /* B7A8C 002B6E8C A7A00010 */  sh         $zero, 0x10($sp)
    /* B7A90 002B6E90 8E260024 */  lw         $a2, 0x24($s1)
    /* B7A94 002B6E94 00460018 */  mult       $v0, $a2
    /* B7A98 002B6E98 26240048 */  addiu      $a0, $s1, 0x48
    /* B7A9C 002B6E9C 00003012 */  mflo       $a2
    /* B7AA0 002B6EA0 0C0AD469 */  jal        func_002B51A4
    /* B7AA4 002B6EA4 27A50010 */   addiu     $a1, $sp, 0x10
  .L002B6EA8:
    /* B7AA8 002B6EA8 8FBF0030 */  lw         $ra, 0x30($sp)
    /* B7AAC 002B6EAC 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B7AB0 002B6EB0 8FB00028 */  lw         $s0, 0x28($sp)
    /* B7AB4 002B6EB4 03E00008 */  jr         $ra
    /* B7AB8 002B6EB8 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_002B6DF4
