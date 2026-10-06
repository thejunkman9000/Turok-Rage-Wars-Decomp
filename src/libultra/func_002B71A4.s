.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7DA4-0xB7DF0 (VRAM 0x002B71A4) */
glabel func_002B71A4
    /* B7DA4 002B71A4 44860800 */  mtc1       $a2, $fv0f
    /* B7DA8 002B71A8 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* B7DAC 002B71AC 44851000 */  mtc1       $a1, $fv1
    /* B7DB0 002B71B0 468010A0 */  cvt.s.w    $fv1, $fv1
    /* B7DB4 002B71B4 04C30005 */  bgezl      $a2, .L002B71CC
    /* B7DB8 002B71B8 46200860 */   cvt.s.d   $fv0f, $fv0f
    /* B7DBC 002B71BC 3C01800D */  lui        $at, %hi(D_800CC738)
    /* B7DC0 002B71C0 D420C738 */  ldc1       $fv0, %lo(D_800CC738)($at)
    /* B7DC4 002B71C4 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B7DC8 002B71C8 46200860 */  cvt.s.d    $fv0f, $fv0f
  .L002B71CC:
    /* B7DCC 002B71CC 46011042 */  mul.s      $fv0f, $fv1, $fv0f
    /* B7DD0 002B71D0 84820018 */  lh         $v0, 0x18($a0)
    /* B7DD4 002B71D4 3C01800D */  lui        $at, %hi(D_800CC740)
    /* B7DD8 002B71D8 C422C740 */  lwc1       $fv1, %lo(D_800CC740)($at)
    /* B7DDC 002B71DC 44820000 */  mtc1       $v0, $fv0
    /* B7DE0 002B71E0 46800020 */  cvt.s.w    $fv0, $fv0
    /* B7DE4 002B71E4 46020002 */  mul.s      $fv0, $fv0, $fv1
    /* B7DE8 002B71E8 03E00008 */  jr         $ra
    /* B7DEC 002B71EC 46000803 */   div.s     $fv0, $fv0f, $fv0
endlabel func_002B71A4
