.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB994C-0xB99A0 (VRAM 0x002B8D4C) */
glabel _collectPVoices
    /* B994C 002B8D4C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B9950 002B8D50 AFB10014 */  sw         $s1, 0x14($sp)
    /* B9954 002B8D54 00808821 */  addu       $s1, $a0, $zero
    /* B9958 002B8D58 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B995C 002B8D5C AFB00010 */  sw         $s0, 0x10($sp)
    /* B9960 002B8D60 8E300014 */  lw         $s0, 0x14($s1)
    /* B9964 002B8D64 12000009 */  beqz       $s0, .L002B8D8C
    /* B9968 002B8D68 00000000 */   nop
  .L002B8D6C:
    /* B996C 002B8D6C 0C0ADD48 */  jal        alUnlink
    /* B9970 002B8D70 02002021 */   addu      $a0, $s0, $zero
    /* B9974 002B8D74 02002021 */  addu       $a0, $s0, $zero
    /* B9978 002B8D78 0C0ADD54 */  jal        alLink
    /* B997C 002B8D7C 26250004 */   addiu     $a1, $s1, 0x4
    /* B9980 002B8D80 8E300014 */  lw         $s0, 0x14($s1)
    /* B9984 002B8D84 1600FFF9 */  bnez       $s0, .L002B8D6C
    /* B9988 002B8D88 00000000 */   nop
  .L002B8D8C:
    /* B998C 002B8D8C 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B9990 002B8D90 8FB10014 */  lw         $s1, 0x14($sp)
    /* B9994 002B8D94 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9998 002B8D98 03E00008 */  jr         $ra
    /* B999C 002B8D9C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel _collectPVoices
