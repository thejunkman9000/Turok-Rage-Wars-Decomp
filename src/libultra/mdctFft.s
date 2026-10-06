.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5618-0xC579C (VRAM 0x002C4A18) */
glabel mdctFft
    /* C5618 002C4A18 8FB80010 */  lw         $t8, 0x10($sp)
    /* C561C 002C4A1C 18A0001F */  blez       $a1, .L002C4A9C
    /* C5620 002C4A20 00005021 */   addu      $t2, $zero, $zero
    /* C5624 002C4A24 8FA90014 */  lw         $t1, 0x14($sp)
    /* C5628 002C4A28 00804021 */  addu       $t0, $a0, $zero
  .L002C4A2C:
    /* C562C 002C4A2C 8D230000 */  lw         $v1, 0x0($t1)
    /* C5630 002C4A30 0143102A */  slt        $v0, $t2, $v1
    /* C5634 002C4A34 50400015 */  beql       $v0, $zero, .L002C4A8C
    /* C5638 002C4A38 25290004 */   addiu     $t1, $t1, 0x4
    /* C563C 002C4A3C 000310C0 */  sll        $v0, $v1, 3
    /* C5640 002C4A40 00441021 */  addu       $v0, $v0, $a0
    /* C5644 002C4A44 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C5648 002C4A48 C5030000 */  lwc1       $fv1f, 0x0($t0)
    /* C564C 002C4A4C E5000000 */  swc1       $fv0, 0x0($t0)
    /* C5650 002C4A50 8D220000 */  lw         $v0, 0x0($t1)
    /* C5654 002C4A54 000210C0 */  sll        $v0, $v0, 3
    /* C5658 002C4A58 00441021 */  addu       $v0, $v0, $a0
    /* C565C 002C4A5C E4430000 */  swc1       $fv1f, 0x0($v0)
    /* C5660 002C4A60 8D220000 */  lw         $v0, 0x0($t1)
    /* C5664 002C4A64 C5030004 */  lwc1       $fv1f, 0x4($t0)
    /* C5668 002C4A68 000210C0 */  sll        $v0, $v0, 3
    /* C566C 002C4A6C 00441021 */  addu       $v0, $v0, $a0
    /* C5670 002C4A70 C4400004 */  lwc1       $fv0, 0x4($v0)
    /* C5674 002C4A74 E5000004 */  swc1       $fv0, 0x4($t0)
    /* C5678 002C4A78 8D220000 */  lw         $v0, 0x0($t1)
    /* C567C 002C4A7C 000210C0 */  sll        $v0, $v0, 3
    /* C5680 002C4A80 00441021 */  addu       $v0, $v0, $a0
    /* C5684 002C4A84 E4430004 */  swc1       $fv1f, 0x4($v0)
    /* C5688 002C4A88 25290004 */  addiu      $t1, $t1, 0x4
  .L002C4A8C:
    /* C568C 002C4A8C 254A0001 */  addiu      $t2, $t2, 0x1
    /* C5690 002C4A90 0145102A */  slt        $v0, $t2, $a1
    /* C5694 002C4A94 1440FFE5 */  bnez       $v0, .L002C4A2C
    /* C5698 002C4A98 25080008 */   addiu     $t0, $t0, 0x8
  .L002C4A9C:
    /* C569C 002C4A9C 240E0002 */  addiu      $t6, $zero, 0x2
    /* C56A0 002C4AA0 240F0001 */  addiu      $t7, $zero, 0x1
    /* C56A4 002C4AA4 01E56807 */  srav       $t5, $a1, $t7
    /* C56A8 002C4AA8 19A0003A */  blez       $t5, .L002C4B94
    /* C56AC 002C4AAC 01E52804 */   sllv      $a1, $a1, $t7
  .L002C4AB0:
    /* C56B0 002C4AB0 19E00034 */  blez       $t7, .L002C4B84
    /* C56B4 002C4AB4 00004821 */   addu      $t1, $zero, $zero
    /* C56B8 002C4AB8 44863000 */  mtc1       $a2, $ft1
    /* C56BC 002C4ABC 468031A0 */  cvt.s.w    $ft1, $ft1
    /* C56C0 002C4AC0 000E6040 */  sll        $t4, $t6, 1
    /* C56C4 002C4AC4 03005821 */  addu       $t3, $t8, $zero
    /* C56C8 002C4AC8 00E05021 */  addu       $t2, $a3, $zero
    /* C56CC 002C4ACC 00094040 */  sll        $t0, $t1, 1
  .L002C4AD0:
    /* C56D0 002C4AD0 0105102A */  slt        $v0, $t0, $a1
    /* C56D4 002C4AD4 C5600000 */  lwc1       $fv0, 0x0($t3)
    /* C56D8 002C4AD8 C5440000 */  lwc1       $ft0, 0x0($t2)
    /* C56DC 002C4ADC 46003142 */  mul.s      $ft0f, $ft1, $fv0
    /* C56E0 002C4AE0 10400021 */  beqz       $v0, .L002C4B68
    /* C56E4 002C4AE4 000910C0 */   sll       $v0, $t1, 3
    /* C56E8 002C4AE8 00441821 */  addu       $v1, $v0, $a0
    /* C56EC 002C4AEC 010E1021 */  addu       $v0, $t0, $t6
  .L002C4AF0:
    /* C56F0 002C4AF0 00021080 */  sll        $v0, $v0, 2
    /* C56F4 002C4AF4 00441021 */  addu       $v0, $v0, $a0
    /* C56F8 002C4AF8 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C56FC 002C4AFC 460120C2 */  mul.s      $fv1f, $ft0, $fv0f
    /* C5700 002C4B00 C4420004 */  lwc1       $fv1, 0x4($v0)
    /* C5704 002C4B04 46022802 */  mul.s      $fv0, $ft0f, $fv1
    /* C5708 002C4B08 00000000 */  nop
    /* C570C 002C4B0C 46022082 */  mul.s      $fv1, $ft0, $fv1
    /* C5710 002C4B10 00000000 */  nop
    /* C5714 002C4B14 46012842 */  mul.s      $fv0f, $ft0f, $fv0f
    /* C5718 002C4B18 460018C1 */  sub.s      $fv1f, $fv1f, $fv0
    /* C571C 002C4B1C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C5720 002C4B20 46030001 */  sub.s      $fv0, $fv0, $fv1f
    /* C5724 002C4B24 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C5728 002C4B28 E4400000 */  swc1       $fv0, 0x0($v0)
    /* C572C 002C4B2C C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C5730 002C4B30 46020001 */  sub.s      $fv0, $fv0, $fv1
    /* C5734 002C4B34 E4400004 */  swc1       $fv0, 0x4($v0)
    /* C5738 002C4B38 C4610000 */  lwc1       $fv0f, 0x0($v1)
    /* C573C 002C4B3C 46030840 */  add.s      $fv0f, $fv0f, $fv1f
    /* C5740 002C4B40 C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C5744 002C4B44 010C4021 */  addu       $t0, $t0, $t4
    /* C5748 002C4B48 46020000 */  add.s      $fv0, $fv0, $fv1
    /* C574C 002C4B4C 000C1080 */  sll        $v0, $t4, 2
    /* C5750 002C4B50 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C5754 002C4B54 E4600004 */  swc1       $fv0, 0x4($v1)
    /* C5758 002C4B58 00621821 */  addu       $v1, $v1, $v0
    /* C575C 002C4B5C 0105102A */  slt        $v0, $t0, $a1
    /* C5760 002C4B60 1440FFE3 */  bnez       $v0, .L002C4AF0
    /* C5764 002C4B64 010E1021 */   addu      $v0, $t0, $t6
  .L002C4B68:
    /* C5768 002C4B68 000D1080 */  sll        $v0, $t5, 2
    /* C576C 002C4B6C 01625821 */  addu       $t3, $t3, $v0
    /* C5770 002C4B70 01425021 */  addu       $t2, $t2, $v0
    /* C5774 002C4B74 25290001 */  addiu      $t1, $t1, 0x1
    /* C5778 002C4B78 012F102A */  slt        $v0, $t1, $t7
    /* C577C 002C4B7C 5440FFD4 */  bnel       $v0, $zero, .L002C4AD0
    /* C5780 002C4B80 00094040 */   sll       $t0, $t1, 1
  .L002C4B84:
    /* C5784 002C4B84 000D6843 */  sra        $t5, $t5, 1
    /* C5788 002C4B88 000F7840 */  sll        $t7, $t7, 1
    /* C578C 002C4B8C 1DA0FFC8 */  bgtz       $t5, .L002C4AB0
    /* C5790 002C4B90 000E7040 */   sll       $t6, $t6, 1
  .L002C4B94:
    /* C5794 002C4B94 03E00008 */  jr         $ra
    /* C5798 002C4B98 00000000 */   nop
endlabel mdctFft
