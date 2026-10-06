.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB99A0-0xB99E0 (VRAM 0x002B8DA0) */
glabel _timeToSamplesNoRound
    /* B99A0 002B8DA0 44850000 */  mtc1       $a1, $fv0
    /* B99A4 002B8DA4 46800020 */  cvt.s.w    $fv0, $fv0
    /* B99A8 002B8DA8 C4810044 */  lwc1       $fv0f, 0x44($a0)
    /* B99AC 002B8DAC 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* B99B0 002B8DB0 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B99B4 002B8DB4 3C01800D */  lui        $at, %hi(D_800CC7D8)
    /* B99B8 002B8DB8 C421C7D8 */  lwc1       $fv0f, %lo(D_800CC7D8)($at)
    /* B99BC 002B8DBC 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B99C0 002B8DC0 3C01800D */  lui        $at, %hi(D_800CC7D8 + 0x4)
    /* B99C4 002B8DC4 C421C7DC */  lwc1       $fv0f, %lo(D_800CC7D8 + 0x4)($at)
    /* B99C8 002B8DC8 46010000 */  add.s      $fv0, $fv0, $fv0f
    /* B99CC 002B8DCC 2402FFF0 */  addiu      $v0, $zero, -0x10
    /* B99D0 002B8DD0 4600008D */  trunc.w.s  $fv1, $fv0
    /* B99D4 002B8DD4 44031000 */  mfc1       $v1, $fv1
    /* B99D8 002B8DD8 03E00008 */  jr         $ra
    /* B99DC 002B8DDC 00621024 */   and       $v0, $v1, $v0
endlabel _timeToSamplesNoRound
