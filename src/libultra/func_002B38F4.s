.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB44F4-0xB4598 (VRAM 0x002B38F4) */
glabel func_002B38F4
    /* B44F4 002B38F4 8C820000 */  lw         $v0, 0x0($a0)
    /* B44F8 002B38F8 8C420040 */  lw         $v0, 0x40($v0)
    /* B44FC 002B38FC 44851800 */  mtc1       $a1, $fv1f
    /* B4500 002B3900 44821000 */  mtc1       $v0, $fv1
    /* B4504 002B3904 468010A1 */  cvt.d.w    $fv1, $fv1
    /* B4508 002B3908 04410004 */  bgez       $v0, .L002B391C
    /* B450C 002B390C 00000000 */   nop
    /* B4510 002B3910 3C01800D */  lui        $at, %hi(D_800CC578)
    /* B4514 002B3914 D420C578 */  ldc1       $fv0, %lo(D_800CC578)($at)
    /* B4518 002B3918 46201080 */  add.d      $fv1, $fv1, $fv0
  .L002B391C:
    /* B451C 002B391C 3C01800D */  lui        $at, %hi(D_800CC580)
    /* B4520 002B3920 C421C580 */  lwc1       $fv0f, %lo(D_800CC580)($at)
    /* B4524 002B3924 46201020 */  cvt.s.d    $fv0, $fv1
    /* B4528 002B3928 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B452C 002B392C 44860800 */  mtc1       $a2, $fv0f
    /* B4530 002B3930 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* B4534 002B3934 46001882 */  mul.s      $fv1, $fv1f, $fv0
    /* B4538 002B3938 04C30005 */  bgezl      $a2, .L002B3950
    /* B453C 002B393C 46200820 */   cvt.s.d   $fv0, $fv0f
    /* B4540 002B3940 3C01800D */  lui        $at, %hi(D_800CC588)
    /* B4544 002B3944 D420C588 */  ldc1       $fv0, %lo(D_800CC588)($at)
    /* B4548 002B3948 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B454C 002B394C 46200820 */  cvt.s.d    $fv0, $fv0f
  .L002B3950:
    /* B4550 002B3950 3C01800D */  lui        $at, %hi(D_800CC590)
    /* B4554 002B3954 C421C590 */  lwc1       $fv0f, %lo(D_800CC590)($at)
    /* B4558 002B3958 46001003 */  div.s      $fv0, $fv1, $fv0
    /* B455C 002B395C 4600083E */  c.le.s     $fv0f, $fv0
    /* B4560 002B3960 00000000 */  nop
    /* B4564 002B3964 45030005 */  bc1tl      .L002B397C
    /* B4568 002B3968 46010001 */   sub.s     $fv0, $fv0, $fv0f
    /* B456C 002B396C 4600010D */  trunc.w.s  $ft0, $fv0
    /* B4570 002B3970 44052000 */  mfc1       $a1, $ft0
    /* B4574 002B3974 03E00008 */  jr         $ra
    /* B4578 002B3978 00A01021 */   addu      $v0, $a1, $zero
  .L002B397C:
    /* B457C 002B397C 3C028000 */  lui        $v0, (0x80000000 >> 16)
    /* B4580 002B3980 4600010D */  trunc.w.s  $ft0, $fv0
    /* B4584 002B3984 44052000 */  mfc1       $a1, $ft0
    /* B4588 002B3988 00A22825 */  or         $a1, $a1, $v0
    /* B458C 002B398C 00A01021 */  addu       $v0, $a1, $zero
    /* B4590 002B3990 03E00008 */  jr         $ra
    /* B4594 002B3994 00000000 */   nop
endlabel func_002B38F4
