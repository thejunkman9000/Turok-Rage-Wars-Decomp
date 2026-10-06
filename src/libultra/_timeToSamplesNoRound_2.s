.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9A88-0xB9AC4 (VRAM 0x002B8E88) */
glabel _timeToSamplesNoRound_2
    /* B9A88 002B8E88 44850000 */  mtc1       $a1, $fv0
    /* B9A8C 002B8E8C 46800020 */  cvt.s.w    $fv0, $fv0
    /* B9A90 002B8E90 C4810044 */  lwc1       $fv0f, 0x44($a0)
    /* B9A94 002B8E94 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* B9A98 002B8E98 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B9A9C 002B8E9C 3C01800D */  lui        $at, %hi(D_800CC7E0)
    /* B9AA0 002B8EA0 C421C7E0 */  lwc1       $fv0f, %lo(D_800CC7E0)($at)
    /* B9AA4 002B8EA4 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B9AA8 002B8EA8 3C01800D */  lui        $at, %hi(D_800CC7E0 + 0x4)
    /* B9AAC 002B8EAC C421C7E4 */  lwc1       $fv0f, %lo(D_800CC7E0 + 0x4)($at)
    /* B9AB0 002B8EB0 46010000 */  add.s      $fv0, $fv0, $fv0f
    /* B9AB4 002B8EB4 4600008D */  trunc.w.s  $fv1, $fv0
    /* B9AB8 002B8EB8 44021000 */  mfc1       $v0, $fv1
    /* B9ABC 002B8EBC 03E00008 */  jr         $ra
    /* B9AC0 002B8EC0 00000000 */   nop
endlabel _timeToSamplesNoRound_2
