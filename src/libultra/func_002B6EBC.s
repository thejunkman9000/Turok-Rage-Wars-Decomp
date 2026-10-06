.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7ABC-0xB7B20 (VRAM 0x002B6EBC) */
glabel func_002B6EBC
    /* B7ABC 002B6EBC 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B7AC0 002B6EC0 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B7AC4 002B6EC4 90A30008 */  lbu        $v1, 0x8($a1)
    /* B7AC8 002B6EC8 240200FF */  addiu      $v0, $zero, 0xFF
    /* B7ACC 002B6ECC 14620011 */  bne        $v1, $v0, .L002B6F14
    /* B7AD0 002B6ED0 00803021 */   addu      $a2, $a0, $zero
    /* B7AD4 002B6ED4 90A30009 */  lbu        $v1, 0x9($a1)
    /* B7AD8 002B6ED8 24020051 */  addiu      $v0, $zero, 0x51
    /* B7ADC 002B6EDC 1462000D */  bne        $v1, $v0, .L002B6F14
    /* B7AE0 002B6EE0 00000000 */   nop
    /* B7AE4 002B6EE4 90A2000B */  lbu        $v0, 0xB($a1)
    /* B7AE8 002B6EE8 90A3000C */  lbu        $v1, 0xC($a1)
    /* B7AEC 002B6EEC 90A4000D */  lbu        $a0, 0xD($a1)
    /* B7AF0 002B6EF0 00021400 */  sll        $v0, $v0, 16
    /* B7AF4 002B6EF4 00031A00 */  sll        $v1, $v1, 8
    /* B7AF8 002B6EF8 00431025 */  or         $v0, $v0, $v1
    /* B7AFC 002B6EFC 00441025 */  or         $v0, $v0, $a0
    /* B7B00 002B6F00 44820000 */  mtc1       $v0, $fv0
    /* B7B04 002B6F04 46800020 */  cvt.s.w    $fv0, $fv0
    /* B7B08 002B6F08 44050000 */  mfc1       $a1, $fv0
    /* B7B0C 002B6F0C 0C0ADBC8 */  jal        func_002B6F20
    /* B7B10 002B6F10 00C02021 */   addu      $a0, $a2, $zero
  .L002B6F14:
    /* B7B14 002B6F14 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B7B18 002B6F18 03E00008 */  jr         $ra
    /* B7B1C 002B6F1C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B6EBC
