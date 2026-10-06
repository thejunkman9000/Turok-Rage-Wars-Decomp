.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3190-0xB3200 (VRAM 0x002B2590) */
glabel rncUnpackMethod1
    /* B3190 002B2590 23BDFFD8 */  addi       $sp, $sp, -0x28 /* handwritten instruction */
    /* B3194 002B2594 AFB00000 */  sw         $s0, 0x0($sp)
    /* B3198 002B2598 AFB10004 */  sw         $s1, 0x4($sp)
    /* B319C 002B259C AFB20008 */  sw         $s2, 0x8($sp)
    /* B31A0 002B25A0 AFB3000C */  sw         $s3, 0xC($sp)
  .L002B25A4:
    /* B31A4 002B25A4 AFB40010 */  sw         $s4, 0x10($sp)
    /* B31A8 002B25A8 AFB50014 */  sw         $s5, 0x14($sp)
    /* B31AC 002B25AC AFB60018 */  sw         $s6, 0x18($sp)
    /* B31B0 002B25B0 AFB7001C */  sw         $s7, 0x1C($sp)
    /* B31B4 002B25B4 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B31B8 002B25B8 00808021 */  addu       $s0, $a0, $zero
    /* B31BC 002B25BC 00A08821 */  addu       $s1, $a1, $zero
    /* B31C0 002B25C0 00C09021 */  addu       $s2, $a2, $zero
    /* B31C4 002B25C4 00E09821 */  addu       $s3, $a3, $zero
    /* B31C8 002B25C8 0C0AC980 */  jal        rncUnpackMethod1Body
    /* B31CC 002B25CC 00000000 */   nop
    /* B31D0 002B25D0 8FB00000 */  lw         $s0, 0x0($sp)
    /* B31D4 002B25D4 8FB10004 */  lw         $s1, 0x4($sp)
    /* B31D8 002B25D8 8FB20008 */  lw         $s2, 0x8($sp)
    /* B31DC 002B25DC 8FB3000C */  lw         $s3, 0xC($sp)
    /* B31E0 002B25E0 8FB40010 */  lw         $s4, 0x10($sp)
    /* B31E4 002B25E4 8FB50014 */  lw         $s5, 0x14($sp)
    /* B31E8 002B25E8 8FB60018 */  lw         $s6, 0x18($sp)
    /* B31EC 002B25EC 8FB7001C */  lw         $s7, 0x1C($sp)
    /* B31F0 002B25F0 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B31F4 002B25F4 23BD0028 */  addi       $sp, $sp, 0x28 /* handwritten instruction */
    /* B31F8 002B25F8 03E00008 */  jr         $ra
    /* B31FC 002B25FC 00000000 */   nop
endlabel rncUnpackMethod1
