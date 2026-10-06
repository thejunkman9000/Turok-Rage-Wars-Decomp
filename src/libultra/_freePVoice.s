.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB990C-0xB994C (VRAM 0x002B8D0C) */
glabel _freePVoice
    /* B990C 002B8D0C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B9910 002B8D10 AFB10014 */  sw         $s1, 0x14($sp)
    /* B9914 002B8D14 00808821 */  addu       $s1, $a0, $zero
    /* B9918 002B8D18 AFB00010 */  sw         $s0, 0x10($sp)
    /* B991C 002B8D1C 00A08021 */  addu       $s0, $a1, $zero
    /* B9920 002B8D20 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B9924 002B8D24 0C0ADD48 */  jal        alUnlink
    /* B9928 002B8D28 02002021 */   addu      $a0, $s0, $zero
    /* B992C 002B8D2C 02002021 */  addu       $a0, $s0, $zero
    /* B9930 002B8D30 0C0ADD54 */  jal        alLink
    /* B9934 002B8D34 26250014 */   addiu     $a1, $s1, 0x14
    /* B9938 002B8D38 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B993C 002B8D3C 8FB10014 */  lw         $s1, 0x14($sp)
    /* B9940 002B8D40 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9944 002B8D44 03E00008 */  jr         $ra
    /* B9948 002B8D48 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel _freePVoice
