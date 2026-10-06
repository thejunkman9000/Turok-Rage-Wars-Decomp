.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5D0C-0xB5DA4 (VRAM 0x002B510C) */
glabel alEvtqNextEvent
    /* B5D0C 002B510C 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5D10 002B5110 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B5D14 002B5114 00809821 */  addu       $s3, $a0, $zero
    /* B5D18 002B5118 AFB10014 */  sw         $s1, 0x14($sp)
    /* B5D1C 002B511C 00A08821 */  addu       $s1, $a1, $zero
    /* B5D20 002B5120 24040001 */  addiu      $a0, $zero, 0x1
    /* B5D24 002B5124 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5D28 002B5128 AFB20018 */  sw         $s2, 0x18($sp)
    /* B5D2C 002B512C 0C0B0898 */  jal        osSetIntMask
    /* B5D30 002B5130 AFB00010 */   sw        $s0, 0x10($sp)
    /* B5D34 002B5134 8E700008 */  lw         $s0, 0x8($s3)
    /* B5D38 002B5138 1200000D */  beqz       $s0, .L002B5170
    /* B5D3C 002B513C 00409021 */   addu      $s2, $v0, $zero
    /* B5D40 002B5140 0C0ADD48 */  jal        alUnlink
    /* B5D44 002B5144 02002021 */   addu      $a0, $s0, $zero
    /* B5D48 002B5148 2604000C */  addiu      $a0, $s0, 0xC
    /* B5D4C 002B514C 02202821 */  addu       $a1, $s1, $zero
    /* B5D50 002B5150 0C0AD4F8 */  jal        alCopy
    /* B5D54 002B5154 24060010 */   addiu     $a2, $zero, 0x10
    /* B5D58 002B5158 02002021 */  addu       $a0, $s0, $zero
    /* B5D5C 002B515C 0C0ADD54 */  jal        alLink
    /* B5D60 002B5160 02602821 */   addu      $a1, $s3, $zero
    /* B5D64 002B5164 8E100008 */  lw         $s0, 0x8($s0)
    /* B5D68 002B5168 080AD45F */  j          .L002B517C
    /* B5D6C 002B516C 00000000 */   nop
  .L002B5170:
    /* B5D70 002B5170 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B5D74 002B5174 A6220000 */  sh         $v0, 0x0($s1)
    /* B5D78 002B5178 00008021 */  addu       $s0, $zero, $zero
  .L002B517C:
    /* B5D7C 002B517C 0C0B0898 */  jal        osSetIntMask
    /* B5D80 002B5180 02402021 */   addu      $a0, $s2, $zero
    /* B5D84 002B5184 02001021 */  addu       $v0, $s0, $zero
    /* B5D88 002B5188 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5D8C 002B518C 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B5D90 002B5190 8FB20018 */  lw         $s2, 0x18($sp)
    /* B5D94 002B5194 8FB10014 */  lw         $s1, 0x14($sp)
    /* B5D98 002B5198 8FB00010 */  lw         $s0, 0x10($sp)
    /* B5D9C 002B519C 03E00008 */  jr         $ra
    /* B5DA0 002B51A0 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alEvtqNextEvent
