.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB888C-0xB8918 (VRAM 0x002B7C8C) */
glabel func_002B7C8C
    /* B888C 002B7C8C 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B8890 002B7C90 AFB00020 */  sw         $s0, 0x20($sp)
    /* B8894 002B7C94 00808021 */  addu       $s0, $a0, $zero
    /* B8898 002B7C98 AFB10024 */  sw         $s1, 0x24($sp)
    /* B889C 002B7C9C 26110028 */  addiu      $s1, $s0, 0x28
    /* B88A0 002B7CA0 AFB20028 */  sw         $s2, 0x28($sp)
    /* B88A4 002B7CA4 24120005 */  addiu      $s2, $zero, 0x5
    /* B88A8 002B7CA8 AFBF002C */  sw         $ra, 0x2C($sp)
  .L002B7CAC:
    /* B88AC 002B7CAC 86020028 */  lh         $v0, 0x28($s0)
    /* B88B0 002B7CB0 14520008 */  bne        $v0, $s2, .L002B7CD4
    /* B88B4 002B7CB4 02002021 */   addu      $a0, $s0, $zero
    /* B88B8 002B7CB8 26040014 */  addiu      $a0, $s0, 0x14
    /* B88BC 002B7CBC A7A20010 */  sh         $v0, 0x10($sp)
    /* B88C0 002B7CC0 8E060048 */  lw         $a2, 0x48($s0)
    /* B88C4 002B7CC4 0C0AD469 */  jal        func_002B51A4
    /* B88C8 002B7CC8 27A50010 */   addiu     $a1, $sp, 0x10
    /* B88CC 002B7CCC 080ADF38 */  j          .L002B7CE0
    /* B88D0 002B7CD0 26040014 */   addiu     $a0, $s0, 0x14
  .L002B7CD4:
    /* B88D4 002B7CD4 0C0ADE14 */  jal        func_002B7850
    /* B88D8 002B7CD8 02202821 */   addu      $a1, $s1, $zero
    /* B88DC 002B7CDC 26040014 */  addiu      $a0, $s0, 0x14
  .L002B7CE0:
    /* B88E0 002B7CE0 0C0AD443 */  jal        func_002B510C
    /* B88E4 002B7CE4 26050028 */   addiu     $a1, $s0, 0x28
    /* B88E8 002B7CE8 00402021 */  addu       $a0, $v0, $zero
    /* B88EC 002B7CEC 1080FFEF */  beqz       $a0, .L002B7CAC
    /* B88F0 002B7CF0 AE04004C */   sw        $a0, 0x4C($s0)
    /* B88F4 002B7CF4 8E030050 */  lw         $v1, 0x50($s0)
    /* B88F8 002B7CF8 00641821 */  addu       $v1, $v1, $a0
    /* B88FC 002B7CFC AE030050 */  sw         $v1, 0x50($s0)
    /* B8900 002B7D00 8FBF002C */  lw         $ra, 0x2C($sp)
    /* B8904 002B7D04 8FB20028 */  lw         $s2, 0x28($sp)
    /* B8908 002B7D08 8FB10024 */  lw         $s1, 0x24($sp)
    /* B890C 002B7D0C 8FB00020 */  lw         $s0, 0x20($sp)
    /* B8910 002B7D10 03E00008 */  jr         $ra
    /* B8914 002B7D14 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002B7C8C
