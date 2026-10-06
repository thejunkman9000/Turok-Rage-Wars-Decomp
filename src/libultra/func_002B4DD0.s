.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB59D0-0xB5A3C (VRAM 0x002B4DD0) */
glabel func_002B4DD0
    /* B59D0 002B4DD0 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B59D4 002B4DD4 AFB00028 */  sw         $s0, 0x28($sp)
    /* B59D8 002B4DD8 00808021 */  addu       $s0, $a0, $zero
    /* B59DC 002B4DDC AFBF002C */  sw         $ra, 0x2C($sp)
    /* B59E0 002B4DE0 8E03002C */  lw         $v1, 0x2C($s0)
    /* B59E4 002B4DE4 24020001 */  addiu      $v0, $zero, 0x1
    /* B59E8 002B4DE8 14620010 */  bne        $v1, $v0, .L002B4E2C
    /* B59EC 002B4DEC 00000000 */   nop
    /* B59F0 002B4DF0 8E040018 */  lw         $a0, 0x18($s0)
    /* B59F4 002B4DF4 1080000D */  beqz       $a0, .L002B4E2C
    /* B59F8 002B4DF8 00000000 */   nop
    /* B59FC 002B4DFC 0C0ACEA0 */  jal        __alCSeqNextDelta
    /* B5A00 002B4E00 27A50020 */   addiu     $a1, $sp, 0x20
    /* B5A04 002B4E04 304200FF */  andi       $v0, $v0, 0xFF
    /* B5A08 002B4E08 10400008 */  beqz       $v0, .L002B4E2C
    /* B5A0C 002B4E0C 26040048 */   addiu     $a0, $s0, 0x48
    /* B5A10 002B4E10 8FA20020 */  lw         $v0, 0x20($sp)
    /* B5A14 002B4E14 A7A00010 */  sh         $zero, 0x10($sp)
    /* B5A18 002B4E18 8E060024 */  lw         $a2, 0x24($s0)
    /* B5A1C 002B4E1C 00460018 */  mult       $v0, $a2
    /* B5A20 002B4E20 00003012 */  mflo       $a2
    /* B5A24 002B4E24 0C0AD469 */  jal        func_002B51A4
    /* B5A28 002B4E28 27A50010 */   addiu     $a1, $sp, 0x10
  .L002B4E2C:
    /* B5A2C 002B4E2C 8FBF002C */  lw         $ra, 0x2C($sp)
    /* B5A30 002B4E30 8FB00028 */  lw         $s0, 0x28($sp)
    /* B5A34 002B4E34 03E00008 */  jr         $ra
    /* B5A38 002B4E38 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002B4DD0
