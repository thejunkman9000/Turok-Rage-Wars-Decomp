.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA35C-0xBA400 (VRAM 0x002B975C) */
glabel init_lpfilter
    /* BA35C 002B975C 24050007 */  addiu      $a1, $zero, 0x7
    /* BA360 002B9760 2486000E */  addiu      $a2, $a0, 0xE
    /* BA364 002B9764 84830000 */  lh         $v1, 0x0($a0)
    /* BA368 002B9768 24020001 */  addiu      $v0, $zero, 0x1
    /* BA36C 002B976C AC82002C */  sw         $v0, 0x2C($a0)
    /* BA370 002B9770 00431807 */  srav       $v1, $v1, $v0
    /* BA374 002B9774 00603821 */  addu       $a3, $v1, $zero
    /* BA378 002B9778 24024000 */  addiu      $v0, $zero, 0x4000
    /* BA37C 002B977C 00431023 */  subu       $v0, $v0, $v1
    /* BA380 002B9780 A4820002 */  sh         $v0, 0x2($a0)
  .L002B9784:
    /* BA384 002B9784 A4C00008 */  sh         $zero, 0x8($a2)
    /* BA388 002B9788 24A5FFFF */  addiu      $a1, $a1, -0x1
    /* BA38C 002B978C 04A1FFFD */  bgez       $a1, .L002B9784
    /* BA390 002B9790 24C6FFFE */   addiu     $a2, $a2, -0x2
    /* BA394 002B9794 00071400 */  sll        $v0, $a3, 16
    /* BA398 002B9798 00021403 */  sra        $v0, $v0, 16
    /* BA39C 002B979C 3C01800D */  lui        $at, %hi(D_800CC838)
    /* BA3A0 002B97A0 D421C838 */  ldc1       $fv0f, %lo(D_800CC838)($at)
    /* BA3A4 002B97A4 44820000 */  mtc1       $v0, $fv0
    /* BA3A8 002B97A8 46800021 */  cvt.d.w    $fv0, $fv0
    /* BA3AC 002B97AC 46210042 */  mul.d      $fv0f, $fv0, $fv0f
    /* BA3B0 002B97B0 24050009 */  addiu      $a1, $zero, 0x9
    /* BA3B4 002B97B4 3C01800D */  lui        $at, %hi(D_800CC840)
    /* BA3B8 002B97B8 D423C840 */  ldc1       $fv1f, %lo(D_800CC840)($at)
    /* BA3BC 002B97BC 24830012 */  addiu      $v1, $a0, 0x12
    /* BA3C0 002B97C0 A4870018 */  sh         $a3, 0x18($a0)
    /* BA3C4 002B97C4 46200886 */  mov.d      $fv1, $fv0f
  .L002B97C8:
    /* BA3C8 002B97C8 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* BA3CC 002B97CC 00000000 */  nop
    /* BA3D0 002B97D0 46230802 */  mul.d      $fv0, $fv0f, $fv1f
    /* BA3D4 002B97D4 24A50001 */  addiu      $a1, $a1, 0x1
    /* BA3D8 002B97D8 4620010D */  trunc.w.d  $ft0, $fv0
    /* BA3DC 002B97DC 44022000 */  mfc1       $v0, $ft0
    /* BA3E0 002B97E0 A4620008 */  sh         $v0, 0x8($v1)
    /* BA3E4 002B97E4 28A20010 */  slti       $v0, $a1, 0x10
    /* BA3E8 002B97E8 1440FFF7 */  bnez       $v0, .L002B97C8
    /* BA3EC 002B97EC 24630002 */   addiu     $v1, $v1, 0x2
    /* BA3F0 002B97F0 03E00008 */  jr         $ra
    /* BA3F4 002B97F4 00000000 */   nop


glabel func_002B97F8
    /* BA3F8 002B97F8 03E00008 */  jr         $ra
    /* BA3FC 002B97FC 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel init_lpfilter
