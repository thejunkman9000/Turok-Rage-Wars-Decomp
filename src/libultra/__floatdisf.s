.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC7600-0xC76B0 (VRAM 0x002C6A00) */
glabel __floatdisf
    /* C7600 002C6A00 00803021 */  addu       $a2, $a0, $zero
    /* C7604 002C6A04 00A03821 */  addu       $a3, $a1, $zero
    /* C7608 002C6A08 04C10006 */  bgez       $a2, .L002C6A24
    /* C760C 002C6A0C 00002821 */   addu      $a1, $zero, $zero
    /* C7610 002C6A10 00073823 */  negu       $a3, $a3
    /* C7614 002C6A14 00063023 */  negu       $a2, $a2
    /* C7618 002C6A18 0007102B */  sltu       $v0, $zero, $a3
    /* C761C 002C6A1C 00C23023 */  subu       $a2, $a2, $v0
    /* C7620 002C6A20 24050001 */  addiu      $a1, $zero, 0x1
  .L002C6A24:
    /* C7624 002C6A24 3C02001F */  lui        $v0, (0x1FFFFF >> 16)
    /* C7628 002C6A28 3442FFFF */  ori        $v0, $v0, (0x1FFFFF & 0xFFFF)
    /* C762C 002C6A2C 0046102B */  sltu       $v0, $v0, $a2
    /* C7630 002C6A30 10400007 */  beqz       $v0, .L002C6A50
    /* C7634 002C6A34 30E207FF */   andi      $v0, $a3, 0x7FF
    /* C7638 002C6A38 10400006 */  beqz       $v0, .L002C6A54
    /* C763C 002C6A3C 00061803 */   sra       $v1, $a2, 0
    /* C7640 002C6A40 24020000 */  addiu      $v0, $zero, 0x0
    /* C7644 002C6A44 24030800 */  addiu      $v1, $zero, 0x800
    /* C7648 002C6A48 00C23025 */  or         $a2, $a2, $v0
    /* C764C 002C6A4C 00E33825 */  or         $a3, $a3, $v1
  .L002C6A50:
    /* C7650 002C6A50 00061803 */  sra        $v1, $a2, 0
  .L002C6A54:
    /* C7654 002C6A54 44831000 */  mtc1       $v1, $fv1
    /* C7658 002C6A58 468010A1 */  cvt.d.w    $fv1, $fv1
    /* C765C 002C6A5C 04610004 */  bgez       $v1, .L002C6A70
    /* C7660 002C6A60 000617C3 */   sra       $v0, $a2, 31
    /* C7664 002C6A64 3C01800D */  lui        $at, %hi(D_800CD370)
    /* C7668 002C6A68 D420D370 */  ldc1       $fv0, %lo(D_800CD370)($at)
    /* C766C 002C6A6C 46201080 */  add.d      $fv1, $fv1, $fv0
  .L002C6A70:
    /* C7670 002C6A70 3C01800D */  lui        $at, %hi(D_800CD378)
    /* C7674 002C6A74 D420D378 */  ldc1       $fv0, %lo(D_800CD378)($at)
    /* C7678 002C6A78 46201082 */  mul.d      $fv1, $fv1, $fv0
    /* C767C 002C6A7C 44872000 */  mtc1       $a3, $ft0
    /* C7680 002C6A80 46802121 */  cvt.d.w    $ft0, $ft0
    /* C7684 002C6A84 46201082 */  mul.d      $fv1, $fv1, $fv0
    /* C7688 002C6A88 04E10004 */  bgez       $a3, .L002C6A9C
    /* C768C 002C6A8C 00000000 */   nop
    /* C7690 002C6A90 3C01800D */  lui        $at, %hi(D_800CD380)
    /* C7694 002C6A94 D420D380 */  ldc1       $fv0, %lo(D_800CD380)($at)
    /* C7698 002C6A98 46202100 */  add.d      $ft0, $ft0, $fv0
  .L002C6A9C:
    /* C769C 002C6A9C 10A00002 */  beqz       $a1, .L002C6AA8
    /* C76A0 002C6AA0 46241000 */   add.d     $fv0, $fv1, $ft0
    /* C76A4 002C6AA4 46200007 */  neg.d      $fv0, $fv0
  .L002C6AA8:
    /* C76A8 002C6AA8 03E00008 */  jr         $ra
    /* C76AC 002C6AAC 46200020 */   cvt.s.d   $fv0, $fv0
endlabel __floatdisf
