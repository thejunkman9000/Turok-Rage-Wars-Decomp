.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5ACC-0xB5B00 (VRAM 0x002B4ECC) */
glabel func_002B4ECC
    /* B5ACC 002B4ECC 8C820018 */  lw         $v0, 0x18($a0)
    /* B5AD0 002B4ED0 44850800 */  mtc1       $a1, $fv0f
    /* B5AD4 002B4ED4 50400007 */  beql       $v0, $zero, .L002B4EF4
    /* B5AD8 002B4ED8 240201E8 */   addiu     $v0, $zero, 0x1E8
    /* B5ADC 002B4EDC C4400008 */  lwc1       $fv0, 0x8($v0)
    /* B5AE0 002B4EE0 46000802 */  mul.s      $fv0, $fv0f, $fv0
    /* B5AE4 002B4EE4 4600008D */  trunc.w.s  $fv1, $fv0
    /* B5AE8 002B4EE8 E4820024 */  swc1       $fv1, 0x24($a0)
    /* B5AEC 002B4EEC 03E00008 */  jr         $ra
    /* B5AF0 002B4EF0 00000000 */   nop
  .L002B4EF4:
    /* B5AF4 002B4EF4 03E00008 */  jr         $ra
    /* B5AF8 002B4EF8 AC820024 */   sw        $v0, 0x24($a0)


    /* B5AFC 002B4EFC A2200035 */  .word      0xA2200035 /* linker padding */
endlabel func_002B4ECC
