.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B7914-0x1B7970 (VRAM 0x00449914) */
glabel __osPfsSelectBank
    /* 1B7914 00449914 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* 1B7918 00449918 AFBF0038 */  sw         $ra, 0x38($sp)
    /* 1B791C 0044991C 00803821 */  addu       $a3, $a0, $zero
    /* 1B7920 00449920 00002021 */  addu       $a0, $zero, $zero
    /* 1B7924 00449924 27A50018 */  addiu      $a1, $sp, 0x18
    /* 1B7928 00449928 00A41821 */  addu       $v1, $a1, $a0
  .L0044992C:
    /* 1B792C 0044992C 90E20065 */  lbu        $v0, 0x65($a3)
    /* 1B7930 00449930 24840001 */  addiu      $a0, $a0, 0x1
    /* 1B7934 00449934 A0620000 */  sb         $v0, 0x0($v1)
    /* 1B7938 00449938 28820020 */  slti       $v0, $a0, 0x20
    /* 1B793C 0044993C 1440FFFB */  bnez       $v0, .L0044992C
    /* 1B7940 00449940 00A41821 */   addu      $v1, $a1, $a0
    /* 1B7944 00449944 24060400 */  addiu      $a2, $zero, 0x400
    /* 1B7948 00449948 AFA00010 */  sw         $zero, 0x10($sp)
    /* 1B794C 0044994C 8CE40004 */  lw         $a0, 0x4($a3)
    /* 1B7950 00449950 8CE50008 */  lw         $a1, 0x8($a3)
    /* 1B7954 00449954 0C0AF654 */  jal        __osContRamWrite
    /* 1B7958 00449958 27A70018 */   addiu     $a3, $sp, 0x18
    /* 1B795C 0044995C 8FBF0038 */  lw         $ra, 0x38($sp)
    /* 1B7960 00449960 03E00008 */  jr         $ra
    /* 1B7964 00449964 27BD0040 */   addiu     $sp, $sp, 0x40


    /* 1B7968 00449968 AE0012C4 */  .word      0xAE0012C4 /* linker padding */
    /* 1B796C 0044996C AE0012C8 */  .word      0xAE0012C8 /* linker padding */
endlabel __osPfsSelectBank
