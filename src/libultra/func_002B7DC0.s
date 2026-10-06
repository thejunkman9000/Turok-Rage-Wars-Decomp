.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB89C0-0xB8A50 (VRAM 0x002B7DC0) */
glabel func_002B7DC0
    /* B89C0 002B7DC0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B89C4 002B7DC4 F7B40018 */  sdc1       $fs0, 0x18($sp)
    /* B89C8 002B7DC8 4485A000 */  mtc1       $a1, $fs0
    /* B89CC 002B7DCC 44800000 */  mtc1       $zero, $fv0
    /* B89D0 002B7DD0 AFB00010 */  sw         $s0, 0x10($sp)
    /* B89D4 002B7DD4 00808021 */  addu       $s0, $a0, $zero
    /* B89D8 002B7DD8 4600A032 */  c.eq.s     $fs0, $fv0
    /* B89DC 002B7DDC 00000000 */  nop
    /* B89E0 002B7DE0 45000007 */  bc1f       .L002B7E00
    /* B89E4 002B7DE4 AFBF0014 */   sw        $ra, 0x14($sp)
    /* B89E8 002B7DE8 3C04800D */  lui        $a0, %hi(D_800CC798)
    /* B89EC 002B7DEC 2484C798 */  addiu      $a0, $a0, %lo(D_800CC798)
    /* B89F0 002B7DF0 3C05800D */  lui        $a1, %hi(D_800CC79C)
    /* B89F4 002B7DF4 24A5C79C */  addiu      $a1, $a1, %lo(D_800CC79C)
    /* B89F8 002B7DF8 0C0AFF50 */  jal        __assert
    /* B89FC 002B7DFC 2406011D */   addiu     $a2, $zero, 0x11D
  .L002B7E00:
    /* B8A00 002B7E00 3C027FFF */  lui        $v0, (0x7FFFFFFF >> 16)
    /* B8A04 002B7E04 44900000 */  mtc1       $s0, $fv0
    /* B8A08 002B7E08 46800020 */  cvt.s.w    $fv0, $fv0
    /* B8A0C 002B7E0C 46140003 */  div.s      $fv0, $fv0, $fs0
    /* B8A10 002B7E10 3C01800D */  lui        $at, %hi(D_800CC7B0)
    /* B8A14 002B7E14 D421C7B0 */  ldc1       $fv0f, %lo(D_800CC7B0)($at)
    /* B8A18 002B7E18 46000021 */  cvt.d.s    $fv0, $fv0
    /* B8A1C 002B7E1C 4620083C */  c.lt.d     $fv0f, $fv0
    /* B8A20 002B7E20 00000000 */  nop
    /* B8A24 002B7E24 45010003 */  bc1t       .L002B7E34
    /* B8A28 002B7E28 3442FFFF */   ori       $v0, $v0, (0x7FFFFFFF & 0xFFFF)
    /* B8A2C 002B7E2C 4620008D */  trunc.w.d  $fv1, $fv0
    /* B8A30 002B7E30 44021000 */  mfc1       $v0, $fv1
  .L002B7E34:
    /* B8A34 002B7E34 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B8A38 002B7E38 8FB00010 */  lw         $s0, 0x10($sp)
    /* B8A3C 002B7E3C D7B40018 */  ldc1       $fs0, 0x18($sp)
    /* B8A40 002B7E40 03E00008 */  jr         $ra
    /* B8A44 002B7E44 27BD0020 */   addiu     $sp, $sp, 0x20
    /* B8A48 002B7E48 00000000 */  .word      0x00000000 /* linker padding */


    /* B8A4C 002B7E4C AE440000 */  .word      0xAE440000 /* linker padding */
endlabel func_002B7DC0
