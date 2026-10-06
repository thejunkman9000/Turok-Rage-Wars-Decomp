.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5C90-0xB5D0C (VRAM 0x002B5090) */
glabel func_002B5090
    /* B5C90 002B5090 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5C94 002B5094 AFB20018 */  sw         $s2, 0x18($sp)
    /* B5C98 002B5098 00809021 */  addu       $s2, $a0, $zero
    /* B5C9C 002B509C 00A02021 */  addu       $a0, $a1, $zero
    /* B5CA0 002B50A0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B5CA4 002B50A4 00C09821 */  addu       $s3, $a2, $zero
    /* B5CA8 002B50A8 AFB10014 */  sw         $s1, 0x14($sp)
    /* B5CAC 002B50AC 00008821 */  addu       $s1, $zero, $zero
    /* B5CB0 002B50B0 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5CB4 002B50B4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B5CB8 002B50B8 AE400010 */  sw         $zero, 0x10($s2)
    /* B5CBC 002B50BC AE400008 */  sw         $zero, 0x8($s2)
  .L002B50C0:
    /* B5CC0 002B50C0 AE40000C */  sw         $zero, 0xC($s2)
    /* B5CC4 002B50C4 AE400000 */  sw         $zero, 0x0($s2)
    /* B5CC8 002B50C8 1A600009 */  blez       $s3, .L002B50F0
    /* B5CCC 002B50CC AE400004 */   sw        $zero, 0x4($s2)
    /* B5CD0 002B50D0 00808021 */  addu       $s0, $a0, $zero
  .L002B50D4:
    /* B5CD4 002B50D4 02002021 */  addu       $a0, $s0, $zero
    /* B5CD8 002B50D8 0C0ADD54 */  jal        func_002B7550
    /* B5CDC 002B50DC 02402821 */   addu      $a1, $s2, $zero
    /* B5CE0 002B50E0 26310001 */  addiu      $s1, $s1, 0x1
    /* B5CE4 002B50E4 0233102A */  slt        $v0, $s1, $s3
    /* B5CE8 002B50E8 1440FFFA */  bnez       $v0, .L002B50D4
    /* B5CEC 002B50EC 2610001C */   addiu     $s0, $s0, 0x1C
  .L002B50F0:
    /* B5CF0 002B50F0 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5CF4 002B50F4 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B5CF8 002B50F8 8FB20018 */  lw         $s2, 0x18($sp)
    /* B5CFC 002B50FC 8FB10014 */  lw         $s1, 0x14($sp)
    /* B5D00 002B5100 8FB00010 */  lw         $s0, 0x10($sp)
    /* B5D04 002B5104 03E00008 */  jr         $ra
    /* B5D08 002B5108 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B5090
