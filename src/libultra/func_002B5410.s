.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB6010-0xB6060 (VRAM 0x002B5410) */
glabel func_002B5410
    /* B6010 002B5410 8FA20010 */  lw         $v0, 0x10($sp)
    /* B6014 002B5414 00E20018 */  mult       $a3, $v0
    /* B6018 002B5418 8CC50004 */  lw         $a1, 0x4($a2)
    /* B601C 002B541C 8CC40008 */  lw         $a0, 0x8($a2)
    /* B6020 002B5420 2402FFF0 */  addiu      $v0, $zero, -0x10
    /* B6024 002B5424 00004012 */  mflo       $t0
    /* B6028 002B5428 2503000F */  addiu      $v1, $t0, 0xF
    /* B602C 002B542C 00621824 */  and        $v1, $v1, $v0
    /* B6030 002B5430 8CC20000 */  lw         $v0, 0x0($a2)
    /* B6034 002B5434 00A31821 */  addu       $v1, $a1, $v1
    /* B6038 002B5438 00441021 */  addu       $v0, $v0, $a0
    /* B603C 002B543C 0043102B */  sltu       $v0, $v0, $v1
    /* B6040 002B5440 14400003 */  bnez       $v0, .L002B5450
    /* B6044 002B5444 00003821 */   addu      $a3, $zero, $zero
    /* B6048 002B5448 00A03821 */  addu       $a3, $a1, $zero
    /* B604C 002B544C ACC30004 */  sw         $v1, 0x4($a2)
  .L002B5450:
    /* B6050 002B5450 03E00008 */  jr         $ra
    /* B6054 002B5454 00E01021 */   addu      $v0, $a3, $zero
    /* B6058 002B5458 02402021 */  .word      0x02402021 /* linker padding */
    /* B605C 002B545C 8E220020 */  .word      0x8E220020 /* linker padding */
endlabel func_002B5410
