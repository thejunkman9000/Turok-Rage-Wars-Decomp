.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB90B0-0xB9140 (VRAM 0x002B84B0) */
glabel func_002B84B0
    /* B90B0 002B84B0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B90B4 002B84B4 AFB10014 */  sw         $s1, 0x14($sp)
    /* B90B8 002B84B8 AFB00010 */  sw         $s0, 0x10($sp)
    /* B90BC 002B84BC 00A08021 */  addu       $s0, $a1, $zero
    /* B90C0 002B84C0 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B90C4 002B84C4 F7B40020 */  sdc1       $fs0, 0x20($sp)
    /* B90C8 002B84C8 8E020008 */  lw         $v0, 0x8($s0)
    /* B90CC 002B84CC 4486A000 */  mtc1       $a2, $fs0
    /* B90D0 002B84D0 10400014 */  beqz       $v0, .L002B8524
    /* B90D4 002B84D4 00808821 */   addu      $s1, $a0, $zero
    /* B90D8 002B84D8 0C0AE332 */  jal        func_002B8CC8
    /* B90DC 002B84DC 00000000 */   nop
    /* B90E0 002B84E0 00403021 */  addu       $a2, $v0, $zero
    /* B90E4 002B84E4 10C0000F */  beqz       $a2, .L002B8524
    /* B90E8 002B84E8 00000000 */   nop
    /* B90EC 002B84EC 8E020008 */  lw         $v0, 0x8($s0)
    /* B90F0 002B84F0 8E23001C */  lw         $v1, 0x1C($s1)
    /* B90F4 002B84F4 8C4400D8 */  lw         $a0, 0xD8($v0)
    /* B90F8 002B84F8 24020007 */  addiu      $v0, $zero, 0x7
    /* B90FC 002B84FC A4C20008 */  sh         $v0, 0x8($a2)
    /* B9100 002B8500 E4D4000C */  swc1       $fs0, 0xC($a2)
    /* B9104 002B8504 ACC00000 */  sw         $zero, 0x0($a2)
    /* B9108 002B8508 00641821 */  addu       $v1, $v1, $a0
    /* B910C 002B850C ACC30004 */  sw         $v1, 0x4($a2)
    /* B9110 002B8510 8E020008 */  lw         $v0, 0x8($s0)
    /* B9114 002B8514 8C44000C */  lw         $a0, 0xC($v0)
    /* B9118 002B8518 8C820008 */  lw         $v0, 0x8($a0)
    /* B911C 002B851C 0040F809 */  jalr       $v0
    /* B9120 002B8520 24050003 */   addiu     $a1, $zero, 0x3
  .L002B8524:
    /* B9124 002B8524 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B9128 002B8528 8FB10014 */  lw         $s1, 0x14($sp)
    /* B912C 002B852C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9130 002B8530 D7B40020 */  ldc1       $fs0, 0x20($sp)
    /* B9134 002B8534 03E00008 */  jr         $ra
    /* B9138 002B8538 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B913C 002B853C 00C08821 */  .word      0x00C08821 /* linker padding */
endlabel func_002B84B0
