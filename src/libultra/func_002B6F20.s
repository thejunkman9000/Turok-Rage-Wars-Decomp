.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7B20-0xB7B50 (VRAM 0x002B6F20) */
glabel func_002B6F20
    /* B7B20 002B6F20 8C820018 */  lw         $v0, 0x18($a0)
    /* B7B24 002B6F24 44850800 */  mtc1       $a1, $fv0f
    /* B7B28 002B6F28 50400007 */  beql       $v0, $zero, .L002B6F48
    /* B7B2C 002B6F2C 240201E8 */   addiu     $v0, $zero, 0x1E8
    /* B7B30 002B6F30 C4400014 */  lwc1       $fv0, 0x14($v0)
    /* B7B34 002B6F34 46000802 */  mul.s      $fv0, $fv0f, $fv0
    /* B7B38 002B6F38 4600008D */  trunc.w.s  $fv1, $fv0
    /* B7B3C 002B6F3C E4820024 */  swc1       $fv1, 0x24($a0)
    /* B7B40 002B6F40 03E00008 */  jr         $ra
    /* B7B44 002B6F44 00000000 */   nop
  .L002B6F48:
    /* B7B48 002B6F48 03E00008 */  jr         $ra
    /* B7B4C 002B6F4C AC820024 */   sw        $v0, 0x24($a0)
endlabel func_002B6F20
