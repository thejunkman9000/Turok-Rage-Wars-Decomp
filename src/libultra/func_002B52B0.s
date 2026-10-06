.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5EB0-0xB5F28 (VRAM 0x002B52B0) */
glabel func_002B52B0
    /* B5EB0 002B52B0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5EB4 002B52B4 AFB20018 */  sw         $s2, 0x18($sp)
    /* B5EB8 002B52B8 00809021 */  addu       $s2, $a0, $zero
    /* B5EBC 002B52BC 24040001 */  addiu      $a0, $zero, 0x1
    /* B5EC0 002B52C0 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5EC4 002B52C4 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B5EC8 002B52C8 AFB10014 */  sw         $s1, 0x14($sp)
    /* B5ECC 002B52CC 0C0B0898 */  jal        osSetIntMask
    /* B5ED0 002B52D0 AFB00010 */   sw        $s0, 0x10($sp)
    /* B5ED4 002B52D4 8E510008 */  lw         $s1, 0x8($s2)
    /* B5ED8 002B52D8 1220000A */  beqz       $s1, .L002B5304
    /* B5EDC 002B52DC 00409821 */   addu      $s3, $v0, $zero
  .L002B52E0:
    /* B5EE0 002B52E0 8E300000 */  lw         $s0, 0x0($s1)
    /* B5EE4 002B52E4 0C0ADD48 */  jal        func_002B7520
    /* B5EE8 002B52E8 02202021 */   addu      $a0, $s1, $zero
    /* B5EEC 002B52EC 02202021 */  addu       $a0, $s1, $zero
    /* B5EF0 002B52F0 0C0ADD54 */  jal        func_002B7550
    /* B5EF4 002B52F4 02402821 */   addu      $a1, $s2, $zero
    /* B5EF8 002B52F8 02008821 */  addu       $s1, $s0, $zero
    /* B5EFC 002B52FC 1620FFF8 */  bnez       $s1, .L002B52E0
    /* B5F00 002B5300 00000000 */   nop
  .L002B5304:
    /* B5F04 002B5304 0C0B0898 */  jal        osSetIntMask
    /* B5F08 002B5308 02602021 */   addu      $a0, $s3, $zero
    /* B5F0C 002B530C 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5F10 002B5310 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B5F14 002B5314 8FB20018 */  lw         $s2, 0x18($sp)
    /* B5F18 002B5318 8FB10014 */  lw         $s1, 0x14($sp)
    /* B5F1C 002B531C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B5F20 002B5320 03E00008 */  jr         $ra
    /* B5F24 002B5324 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B52B0
