.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBBFD0-0xBC048 (VRAM 0x002BB3D0) */
glabel func_002BB3D0
    /* BBFD0 002BB3D0 C4810010 */  lwc1       $fv0f, 0x10($a0)
    /* BBFD4 002BB3D4 44850000 */  mtc1       $a1, $fv0
    /* BBFD8 002BB3D8 46800020 */  cvt.s.w    $fv0, $fv0
    /* BBFDC 002BB3DC 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* BBFE0 002BB3E0 C4800014 */  lwc1       $fv0, 0x14($a0)
    /* BBFE4 002BB3E4 46010000 */  add.s      $fv0, $fv0, $fv0f
    /* BBFE8 002BB3E8 3C01800D */  lui        $at, %hi(D_800CCA28)
    /* BBFEC 002BB3EC C421CA28 */  lwc1       $fv0f, %lo(D_800CCA28)($at)
    /* BBFF0 002BB3F0 46000086 */  mov.s      $fv1, $fv0
    /* BBFF4 002BB3F4 4602083C */  c.lt.s     $fv0f, $fv1
    /* BBFF8 002BB3F8 00000000 */  nop
    /* BBFFC 002BB3FC 45000004 */  bc1f       .L002BB410
    /* BC000 002BB400 E4820014 */   swc1      $fv1, 0x14($a0)
    /* BC004 002BB404 3C01800D */  lui        $at, %hi(D_800CCA28 + 0x4)
    /* BC008 002BB408 C420CA2C */  lwc1       $fv0, %lo(D_800CCA28 + 0x4)($at)
    /* BC00C 002BB40C 46001081 */  sub.s      $fv1, $fv1, $fv0
  .L002BB410:
    /* BC010 002BB410 44800000 */  mtc1       $zero, $fv0
    /* BC014 002BB414 46001046 */  mov.s      $fv0f, $fv1
    /* BC018 002BB418 4600083C */  c.lt.s     $fv0f, $fv0
    /* BC01C 002BB41C 00000000 */  nop
    /* BC020 002BB420 45000002 */  bc1f       .L002BB42C
    /* BC024 002BB424 E4810014 */   swc1      $fv0f, 0x14($a0)
    /* BC028 002BB428 46000847 */  neg.s      $fv0f, $fv0f
  .L002BB42C:
    /* BC02C 002BB42C 3C01800D */  lui        $at, %hi(D_800CCA30)
    /* BC030 002BB430 C420CA30 */  lwc1       $fv0, %lo(D_800CCA30)($at)
    /* BC034 002BB434 46000841 */  sub.s      $fv0f, $fv0f, $fv0
    /* BC038 002BB438 C480001C */  lwc1       $fv0, 0x1C($a0)
    /* BC03C 002BB43C 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* BC040 002BB440 03E00008 */  jr         $ra
    /* BC044 002BB444 00000000 */   nop
endlabel func_002BB3D0
