.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7DF0-0xB7E78 (VRAM 0x002B71F0) */
glabel func_002B71F0
    /* B7DF0 002B71F0 84820018 */  lh         $v0, 0x18($a0)
    /* B7DF4 002B71F4 3C01800D */  lui        $at, %hi(D_800CC740 + 0x4)
    /* B7DF8 002B71F8 C421C744 */  lwc1       $fv0f, %lo(D_800CC740 + 0x4)($at)
    /* B7DFC 002B71FC 44820000 */  mtc1       $v0, $fv0
    /* B7E00 002B7200 46800020 */  cvt.s.w    $fv0, $fv0
    /* B7E04 002B7204 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B7E08 002B7208 44851800 */  mtc1       $a1, $fv1f
    /* B7E0C 002B720C 44860800 */  mtc1       $a2, $fv0f
    /* B7E10 002B7210 46800861 */  cvt.d.w    $fv0f, $fv0f
    /* B7E14 002B7214 46001882 */  mul.s      $fv1, $fv1f, $fv0
    /* B7E18 002B7218 04C30005 */  bgezl      $a2, .L002B7230
    /* B7E1C 002B721C 46200820 */   cvt.s.d   $fv0, $fv0f
    /* B7E20 002B7220 3C01800D */  lui        $at, %hi(D_800CC748)
    /* B7E24 002B7224 D420C748 */  ldc1       $fv0, %lo(D_800CC748)($at)
    /* B7E28 002B7228 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B7E2C 002B722C 46200820 */  cvt.s.d    $fv0, $fv0f
  .L002B7230:
    /* B7E30 002B7230 3C01800D */  lui        $at, %hi(D_800CC750)
    /* B7E34 002B7234 C421C750 */  lwc1       $fv0f, %lo(D_800CC750)($at)
    /* B7E38 002B7238 46001003 */  div.s      $fv0, $fv1, $fv0
    /* B7E3C 002B723C 4600083E */  c.le.s     $fv0f, $fv0
    /* B7E40 002B7240 00000000 */  nop
    /* B7E44 002B7244 45030005 */  bc1tl      .L002B725C
    /* B7E48 002B7248 46010001 */   sub.s     $fv0, $fv0, $fv0f
    /* B7E4C 002B724C 460000CD */  trunc.w.s  $fv1f, $fv0
    /* B7E50 002B7250 44051800 */  mfc1       $a1, $fv1f
    /* B7E54 002B7254 03E00008 */  jr         $ra
    /* B7E58 002B7258 00A01021 */   addu      $v0, $a1, $zero
  .L002B725C:
    /* B7E5C 002B725C 3C028000 */  lui        $v0, (0x80000000 >> 16)
    /* B7E60 002B7260 460000CD */  trunc.w.s  $fv1f, $fv0
    /* B7E64 002B7264 44051800 */  mfc1       $a1, $fv1f
    /* B7E68 002B7268 00A22825 */  or         $a1, $a1, $v0
    /* B7E6C 002B726C 00A01021 */  addu       $v0, $a1, $zero
    /* B7E70 002B7270 03E00008 */  jr         $ra
    /* B7E74 002B7274 00000000 */   nop
endlabel func_002B71F0
