.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB448C-0xB44F4 (VRAM 0x002B388C) */
glabel func_002B388C
    /* B448C 002B388C 44860800 */  mtc1       $a2, $fv0f
    /* B4490 002B3890 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* B4494 002B3894 44851800 */  mtc1       $a1, $fv1f
    /* B4498 002B3898 468018E0 */  cvt.s.w    $fv1f, $fv1f
    /* B449C 002B389C 04C10004 */  bgez       $a2, .L002B38B0
    /* B44A0 002B38A0 00000000 */   nop
    /* B44A4 002B38A4 3C01800D */  lui        $at, %hi(D_800CC560)
    /* B44A8 002B38A8 D420C560 */  ldc1       $fv0, %lo(D_800CC560)($at)
    /* B44AC 002B38AC 46200840 */  add.d      $fv0f, $fv0f, $fv0
  .L002B38B0:
    /* B44B0 002B38B0 8C820000 */  lw         $v0, 0x0($a0)
    /* B44B4 002B38B4 46200820 */  cvt.s.d    $fv0, $fv0f
    /* B44B8 002B38B8 8C420040 */  lw         $v0, 0x40($v0)
    /* B44BC 002B38BC 460018C2 */  mul.s      $fv1f, $fv1f, $fv0
    /* B44C0 002B38C0 44821000 */  mtc1       $v0, $fv1
    /* B44C4 002B38C4 468010A1 */  cvt.d.w    $fv1, $fv1
    /* B44C8 002B38C8 04410004 */  bgez       $v0, .L002B38DC
    /* B44CC 002B38CC 00000000 */   nop
    /* B44D0 002B38D0 3C01800D */  lui        $at, %hi(D_800CC568)
    /* B44D4 002B38D4 D420C568 */  ldc1       $fv0, %lo(D_800CC568)($at)
    /* B44D8 002B38D8 46201080 */  add.d      $fv1, $fv1, $fv0
  .L002B38DC:
    /* B44DC 002B38DC 3C01800D */  lui        $at, %hi(D_800CC570)
    /* B44E0 002B38E0 C421C570 */  lwc1       $fv0f, %lo(D_800CC570)($at)
    /* B44E4 002B38E4 46201020 */  cvt.s.d    $fv0, $fv1
    /* B44E8 002B38E8 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B44EC 002B38EC 03E00008 */  jr         $ra
    /* B44F0 002B38F0 46001803 */   div.s     $fv0, $fv1f, $fv0
endlabel func_002B388C
