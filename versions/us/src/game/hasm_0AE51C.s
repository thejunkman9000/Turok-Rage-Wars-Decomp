.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE51C-0xAEB60 (VRAM 0x002AD91C) */
.globl rncUnpackMethod2Body
rncUnpackMethod2Body:
    /* AE51C 002AD91C 00A08821 */  addu       $s1, $a1, $zero
    /* AE520 002AD920 240D0000 */  addiu      $t5, $zero, 0x0
    /* AE524 002AD924 3C0B8014 */  lui        $t3, %hi(D_auto_80145190)
    /* AE528 002AD928 256B5190 */  addiu      $t3, $t3, %lo(D_auto_80145190)
    /* AE52C 002AD92C 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE530 002AD930 91CD0000 */  lbu        $t5, 0x0($t6)
    /* AE534 002AD934 91CC0001 */  lbu        $t4, 0x1($t6)
    /* AE538 002AD938 91D20002 */  lbu        $s2, 0x2($t6)
    /* AE53C 002AD93C 91CF0003 */  lbu        $t7, 0x3($t6)
    /* AE540 002AD940 000D6E00 */  sll        $t5, $t5, 24
    /* AE544 002AD944 000C6400 */  sll        $t4, $t4, 16
    /* AE548 002AD948 00129200 */  sll        $s2, $s2, 8
    /* AE54C 002AD94C 01AC6825 */  or         $t5, $t5, $t4
    /* AE550 002AD950 01B26825 */  or         $t5, $t5, $s2
    /* AE554 002AD954 01AF6825 */  or         $t5, $t5, $t7
    /* AE558 002AD958 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE55C 002AD95C AD6D0000 */  sw         $t5, 0x0($t3)
    /* AE560 002AD960 01C01821 */  addu       $v1, $t6, $zero
    /* AE564 002AD964 2063000A */  addi       $v1, $v1, 0xA /* handwritten instruction */
    /* AE568 002AD968 02202821 */  addu       $a1, $s1, $zero
    /* AE56C 002AD96C 00A03021 */  addu       $a2, $a1, $zero
    /* AE570 002AD970 00CD3021 */  addu       $a2, $a2, $t5
    /* AE574 002AD974 91CD0000 */  lbu        $t5, 0x0($t6)
    /* AE578 002AD978 91CC0001 */  lbu        $t4, 0x1($t6)
    /* AE57C 002AD97C 91D20002 */  lbu        $s2, 0x2($t6)
    /* AE580 002AD980 91CF0003 */  lbu        $t7, 0x3($t6)
    /* AE584 002AD984 000D6E00 */  sll        $t5, $t5, 24
    /* AE588 002AD988 000C6400 */  sll        $t4, $t4, 16
    /* AE58C 002AD98C 00129200 */  sll        $s2, $s2, 8
    /* AE590 002AD990 01AC6825 */  or         $t5, $t5, $t4
    /* AE594 002AD994 01B26825 */  or         $t5, $t5, $s2
    /* AE598 002AD998 01AF6825 */  or         $t5, $t5, $t7
    /* AE59C 002AD99C 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE5A0 002AD9A0 00602021 */  addu       $a0, $v1, $zero
    /* AE5A4 002AD9A4 008D2020 */  add        $a0, $a0, $t5 /* handwritten instruction */
    /* AE5A8 002AD9A8 216BFFFE */  addi       $t3, $t3, -0x2 /* handwritten instruction */
    /* AE5AC 002AD9AC A5600000 */  sh         $zero, 0x0($t3)
    /* AE5B0 002AD9B0 3C0AFFFF */  lui        $t2, (0xFFFFFF00 >> 16)
    /* AE5B4 002AD9B4 354AFF00 */  ori        $t2, $t2, (0xFFFFFF00 & 0xFFFF)
    /* AE5B8 002AD9B8 240F0001 */  addiu      $t7, $zero, 0x1
    /* AE5BC 002AD9BC 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE5C0 002AD9C0 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE5C4 002AD9C4 014A5021 */  addu       $t2, $t2, $t2
    /* AE5C8 002AD9C8 014F5021 */  addu       $t2, $t2, $t7
    /* AE5CC 002AD9CC 014A5021 */  addu       $t2, $t2, $t2
    /* AE5D0 002AD9D0 000A7A02 */  srl        $t7, $t2, 8
    /* AE5D4 002AD9D4 080AB74C */  .word 0x080AB74C
    /* AE5D8 002AD9D8 31EF0001 */  andi      $t7, $t7, 0x1
    /* AE5DC 002AD9DC 2402FFFF */  addiu      $v0, $zero, -0x1
    /* AE5E0 002AD9E0 03E00008 */  jr         $ra
    /* AE5E4 002AD9E4 00000000 */  nop
    /* AE5E8 002AD9E8 2402FFFE */  addiu      $v0, $zero, -0x2
    /* AE5EC 002AD9EC 03E00008 */  jr         $ra
    /* AE5F0 002AD9F0 00000000 */  nop
.Lauto_002AD9F4:
    /* AE5F4 002AD9F4 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE5F8 002AD9F8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE5FC 002AD9FC 014A5021 */  addu       $t2, $t2, $t2
    /* AE600 002ADA00 014F5021 */  addu       $t2, $t2, $t7
    /* AE604 002ADA04 000A7A02 */  srl        $t7, $t2, 8
    /* AE608 002ADA08 080AB6BC */  .word 0x080AB6BC
    /* AE60C 002ADA0C 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADA10:
    /* AE610 002ADA10 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE614 002ADA14 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE618 002ADA18 014A5021 */  addu       $t2, $t2, $t2
    /* AE61C 002ADA1C 014F5021 */  addu       $t2, $t2, $t7
    /* AE620 002ADA20 000A7A02 */  srl        $t7, $t2, 8
    /* AE624 002ADA24 080AB6D8 */  .word 0x080AB6D8
    /* AE628 002ADA28 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADA2C:
    /* AE62C 002ADA2C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE630 002ADA30 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE634 002ADA34 014A5021 */  addu       $t2, $t2, $t2
    /* AE638 002ADA38 014F5021 */  addu       $t2, $t2, $t7
    /* AE63C 002ADA3C 000A7A02 */  srl        $t7, $t2, 8
    /* AE640 002ADA40 080AB6E0 */  .word 0x080AB6E0
    /* AE644 002ADA44 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADA48:
    /* AE648 002ADA48 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE64C 002ADA4C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE650 002ADA50 014A5021 */  addu       $t2, $t2, $t2
    /* AE654 002ADA54 014F5021 */  addu       $t2, $t2, $t7
    /* AE658 002ADA58 000A7A02 */  srl        $t7, $t2, 8
    /* AE65C 002ADA5C 080AB6E9 */  .word 0x080AB6E9
    /* AE660 002ADA60 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADA64:
    /* AE664 002ADA64 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE668 002ADA68 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE66C 002ADA6C 014A5021 */  addu       $t2, $t2, $t2
    /* AE670 002ADA70 014F5021 */  addu       $t2, $t2, $t7
    /* AE674 002ADA74 000A7A02 */  srl        $t7, $t2, 8
    /* AE678 002ADA78 080AB6F6 */  .word 0x080AB6F6
    /* AE67C 002ADA7C 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADA80:
    /* AE680 002ADA80 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE684 002ADA84 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE688 002ADA88 014A5021 */  addu       $t2, $t2, $t2
    /* AE68C 002ADA8C 014F5021 */  addu       $t2, $t2, $t7
    /* AE690 002ADA90 000A7A02 */  srl        $t7, $t2, 8
    /* AE694 002ADA94 080AB6FE */  .word 0x080AB6FE
    /* AE698 002ADA98 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADA9C:
    /* AE69C 002ADA9C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE6A0 002ADAA0 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE6A4 002ADAA4 014A5021 */  addu       $t2, $t2, $t2
    /* AE6A8 002ADAA8 014F5021 */  addu       $t2, $t2, $t7
    /* AE6AC 002ADAAC 000A7A02 */  srl        $t7, $t2, 8
    /* AE6B0 002ADAB0 080AB706 */  .word 0x080AB706
    /* AE6B4 002ADAB4 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADAB8:
    /* AE6B8 002ADAB8 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE6BC 002ADABC 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE6C0 002ADAC0 014A5021 */  addu       $t2, $t2, $t2
    /* AE6C4 002ADAC4 014F5021 */  addu       $t2, $t2, $t7
    /* AE6C8 002ADAC8 000A7A02 */  srl        $t7, $t2, 8
    /* AE6CC 002ADACC 080AB711 */  .word 0x080AB711
    /* AE6D0 002ADAD0 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADAD4:
    /* AE6D4 002ADAD4 24080003 */  addiu      $t0, $zero, 0x3
.Lauto_002ADAD8:
    /* AE6D8 002ADAD8 014A5021 */  addu       $t2, $t2, $t2
    /* AE6DC 002ADADC 000A7A02 */  srl        $t7, $t2, 8
    /* AE6E0 002ADAE0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE6E4 002ADAE4 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE6E8 002ADAE8 100AFFC2 */  .word 0x100AFFC2
    /* AE6EC 002ADAEC 00000000 */  nop
.Lauto_002ADAF0:
    /* AE6F0 002ADAF0 01294821 */  addu       $t1, $t1, $t1
    /* AE6F4 002ADAF4 012F4821 */  addu       $t1, $t1, $t7
    /* AE6F8 002ADAF8 00097C02 */  srl        $t7, $t1, 16
    /* AE6FC 002ADAFC 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE700 002ADB00 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE704 002ADB04 0501FFF4 */  .word 0x0501FFF4
    /* AE708 002ADB08 00000000 */  nop
    /* AE70C 002ADB0C 21290002 */  addi       $t1, $t1, 0x2 /* handwritten instruction */
.Lauto_002ADB10:
    /* AE710 002ADB10 906C0000 */  lbu        $t4, 0x0($v1)
    /* AE714 002ADB14 90720001 */  lbu        $s2, 0x1($v1)
    /* AE718 002ADB18 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE71C 002ADB1C A0B20001 */  sb         $s2, 0x1($a1)
    /* AE720 002ADB20 906C0002 */  lbu        $t4, 0x2($v1)
    /* AE724 002ADB24 90720003 */  lbu        $s2, 0x3($v1)
    /* AE728 002ADB28 A0AC0002 */  sb         $t4, 0x2($a1)
    /* AE72C 002ADB2C A0B20003 */  sb         $s2, 0x3($a1)
    /* AE730 002ADB30 24630004 */  addiu      $v1, $v1, 0x4
    /* AE734 002ADB34 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* AE738 002ADB38 0521FFF5 */  .word 0x0521FFF5
    /* AE73C 002ADB3C 20A50004 */  addi      $a1, $a1, 0x4 /* handwritten instruction */
    /* AE740 002ADB40 080AB74C */  .word 0x080AB74C
    /* AE744 002ADB44 00000000 */  nop
.Lauto_002ADB48:
    /* AE748 002ADB48 014A5021 */  addu       $t2, $t2, $t2
    /* AE74C 002ADB4C 000A7A02 */  srl        $t7, $t2, 8
    /* AE750 002ADB50 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE754 002ADB54 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE758 002ADB58 100AFFAD */  .word 0x100AFFAD
    /* AE75C 002ADB5C 00000000 */  nop
.Lauto_002ADB60:
    /* AE760 002ADB60 01084021 */  addu       $t0, $t0, $t0
    /* AE764 002ADB64 010F4021 */  addu       $t0, $t0, $t7
    /* AE768 002ADB68 014A5021 */  addu       $t2, $t2, $t2
    /* AE76C 002ADB6C 000A7A02 */  srl        $t7, $t2, 8
    /* AE770 002ADB70 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE774 002ADB74 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE778 002ADB78 100AFFAC */  .word 0x100AFFAC
    /* AE77C 002ADB7C 00000000 */  nop
.Lauto_002ADB80:
    /* AE780 002ADB80 100F000F */  .word 0x100F000F
    /* AE784 002ADB84 00000000 */  nop
    /* AE788 002ADB88 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE78C 002ADB8C 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* AE790 002ADB90 000A7A02 */  srl        $t7, $t2, 8
    /* AE794 002ADB94 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE798 002ADB98 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE79C 002ADB9C 100AFFAA */  .word 0x100AFFAA
    /* AE7A0 002ADBA0 00000000 */  nop
.Lauto_002ADBA4:
    /* AE7A4 002ADBA4 01084021 */  addu       $t0, $t0, $t0
    /* AE7A8 002ADBA8 010F4021 */  addu       $t0, $t0, $t7
    /* AE7AC 002ADBAC 00087C02 */  srl        $t7, $t0, 16
    /* AE7B0 002ADBB0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE7B4 002ADBB4 210CFFF7 */  addi       $t4, $t0, -0x9 /* handwritten instruction */
    /* AE7B8 002ADBB8 100CFFC6 */  .word 0x100CFFC6
    /* AE7BC 002ADBBC 00000000 */  nop
.Lauto_002ADBC0:
    /* AE7C0 002ADBC0 014A5021 */  addu       $t2, $t2, $t2
    /* AE7C4 002ADBC4 000A7A02 */  srl        $t7, $t2, 8
    /* AE7C8 002ADBC8 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE7CC 002ADBCC 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE7D0 002ADBD0 100AFFA4 */  .word 0x100AFFA4
    /* AE7D4 002ADBD4 00000000 */  nop
.Lauto_002ADBD8:
    /* AE7D8 002ADBD8 100F0022 */  .word 0x100F0022
    /* AE7DC 002ADBDC 00000000 */  nop
    /* AE7E0 002ADBE0 014A5021 */  addu       $t2, $t2, $t2
    /* AE7E4 002ADBE4 000A7A02 */  srl        $t7, $t2, 8
    /* AE7E8 002ADBE8 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE7EC 002ADBEC 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE7F0 002ADBF0 100AFFA3 */  .word 0x100AFFA3
    /* AE7F4 002ADBF4 00000000 */  nop
.Lauto_002ADBF8:
    /* AE7F8 002ADBF8 01294821 */  addu       $t1, $t1, $t1
    /* AE7FC 002ADBFC 012F4821 */  addu       $t1, $t1, $t7
    /* AE800 002ADC00 014A5021 */  addu       $t2, $t2, $t2
    /* AE804 002ADC04 000A7A02 */  srl        $t7, $t2, 8
    /* AE808 002ADC08 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE80C 002ADC0C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE810 002ADC10 100AFFA2 */  .word 0x100AFFA2
    /* AE814 002ADC14 00000000 */  nop
.Lauto_002ADC18:
    /* AE818 002ADC18 140F0078 */  .word 0x140F0078
    /* AE81C 002ADC1C 00000000 */  nop
    /* AE820 002ADC20 1409000C */  .word 0x1409000C
    /* AE824 002ADC24 00000000 */  nop
    /* AE828 002ADC28 21290001 */  addi       $t1, $t1, 0x1 /* handwritten instruction */
.Lauto_002ADC2C:
    /* AE82C 002ADC2C 014A5021 */  addu       $t2, $t2, $t2
    /* AE830 002ADC30 000A7A02 */  srl        $t7, $t2, 8
    /* AE834 002ADC34 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE838 002ADC38 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE83C 002ADC3C 100AFF9E */  .word 0x100AFF9E
    /* AE840 002ADC40 00000000 */  nop
.Lauto_002ADC44:
    /* AE844 002ADC44 01294821 */  addu       $t1, $t1, $t1
    /* AE848 002ADC48 012F4821 */  addu       $t1, $t1, $t7
    /* AE84C 002ADC4C 00097C02 */  srl        $t7, $t1, 16
    /* AE850 002ADC50 31EF0001 */  andi       $t7, $t7, 0x1
.Lauto_002ADC54:
    /* AE854 002ADC54 00096200 */  sll        $t4, $t1, 8
    /* AE858 002ADC58 318CFF00 */  andi       $t4, $t4, 0xFF00
    /* AE85C 002ADC5C 00094A02 */  srl        $t1, $t1, 8
    /* AE860 002ADC60 012C4825 */  or         $t1, $t1, $t4
.Lauto_002ADC64:
    /* AE864 002ADC64 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* AE868 002ADC68 90690000 */  lbu        $t1, 0x0($v1)
    /* AE86C 002ADC6C 24630001 */  addiu      $v1, $v1, 0x1
    /* AE870 002ADC70 01334825 */  or         $t1, $t1, $s3
    /* AE874 002ADC74 00A07021 */  addu       $t6, $a1, $zero
    /* AE878 002ADC78 01C97022 */  sub        $t6, $t6, $t1 /* handwritten instruction */
    /* AE87C 002ADC7C 21CEFFFF */  addi       $t6, $t6, -0x1 /* handwritten instruction */
    /* AE880 002ADC80 310F0001 */  andi       $t7, $t0, 0x1
    /* AE884 002ADC84 00084042 */  srl        $t0, $t0, 1
    /* AE888 002ADC88 100F0005 */  .word 0x100F0005
    /* AE88C 002ADC8C 00000000 */  nop
    /* AE890 002ADC90 91CC0000 */  lbu        $t4, 0x0($t6)
    /* AE894 002ADC94 21CE0001 */  addi       $t6, $t6, 0x1 /* handwritten instruction */
    /* AE898 002ADC98 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE89C 002ADC9C 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
.Lauto_002ADCA0:
    /* AE8A0 002ADCA0 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE8A4 002ADCA4 1409000C */  .word 0x1409000C
    /* AE8A8 002ADCA8 00000000 */  nop
    /* AE8AC 002ADCAC 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* AE8B0 002ADCB0 91C90000 */  lbu        $t1, 0x0($t6)
    /* AE8B4 002ADCB4 00000000 */  nop
    /* AE8B8 002ADCB8 01334825 */  or         $t1, $t1, $s3
.Lauto_002ADCBC:
    /* AE8BC 002ADCBC A0A90000 */  sb         $t1, 0x0($a1)
    /* AE8C0 002ADCC0 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE8C4 002ADCC4 A0A90001 */  sb         $t1, 0x1($a1)
    /* AE8C8 002ADCC8 0501FFFC */  .word 0x0501FFFC
    /* AE8CC 002ADCCC 20A50002 */  addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* AE8D0 002ADCD0 080AB74C */  .word 0x080AB74C
    /* AE8D4 002ADCD4 00000000 */  nop
.Lauto_002ADCD8:
    /* AE8D8 002ADCD8 91D20001 */  lbu        $s2, 0x1($t6)
    /* AE8DC 002ADCDC 91CC0000 */  lbu        $t4, 0x0($t6)
    /* AE8E0 002ADCE0 A0B20001 */  sb         $s2, 0x1($a1)
    /* AE8E4 002ADCE4 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE8E8 002ADCE8 21CE0002 */  addi       $t6, $t6, 0x2 /* handwritten instruction */
    /* AE8EC 002ADCEC 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE8F0 002ADCF0 0501FFF9 */  .word 0x0501FFF9
    /* AE8F4 002ADCF4 20A50002 */  addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* AE8F8 002ADCF8 080AB74C */  .word 0x080AB74C
    /* AE8FC 002ADCFC 00000000 */  nop
.Lauto_002ADD00:
    /* AE900 002ADD00 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE904 002ADD04 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE908 002ADD08 014A5021 */  addu       $t2, $t2, $t2
    /* AE90C 002ADD0C 014F5021 */  addu       $t2, $t2, $t7
    /* AE910 002ADD10 000A7A02 */  srl        $t7, $t2, 8
    /* AE914 002ADD14 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE918 002ADD18 140F0016 */  .word 0x140F0016
    /* AE91C 002ADD1C 00000000 */  nop
.Lauto_002ADD20:
    /* AE920 002ADD20 906C0000 */  lbu        $t4, 0x0($v1)
    /* AE924 002ADD24 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE928 002ADD28 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE92C 002ADD2C 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
.Lauto_002ADD30:
    /* AE930 002ADD30 014A5021 */  addu       $t2, $t2, $t2
    /* AE934 002ADD34 000A7A02 */  srl        $t7, $t2, 8
    /* AE938 002ADD38 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE93C 002ADD3C 140F000A */  .word 0x140F000A
    /* AE940 002ADD40 00000000 */  nop
    /* AE944 002ADD44 906C0000 */  lbu        $t4, 0x0($v1)
    /* AE948 002ADD48 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE94C 002ADD4C A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE950 002ADD50 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* AE954 002ADD54 014A5021 */  addu       $t2, $t2, $t2
    /* AE958 002ADD58 000A7A02 */  srl        $t7, $t2, 8
    /* AE95C 002ADD5C 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE960 002ADD60 100FFFEF */  .word 0x100FFFEF
    /* AE964 002ADD64 00000000 */  nop
.Lauto_002ADD68:
    /* AE968 002ADD68 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE96C 002ADD6C 100AFFE4 */  .word 0x100AFFE4
    /* AE970 002ADD70 00000000 */  nop
.Lauto_002ADD74:
    /* AE974 002ADD74 24080002 */  addiu      $t0, $zero, 0x2
    /* AE978 002ADD78 24090000 */  addiu      $t1, $zero, 0x0
    /* AE97C 002ADD7C 014A5021 */  addu       $t2, $t2, $t2
    /* AE980 002ADD80 000A7A02 */  srl        $t7, $t2, 8
    /* AE984 002ADD84 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE988 002ADD88 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE98C 002ADD8C 100A0030 */  .word 0x100A0030
    /* AE990 002ADD90 00000000 */  nop
.Lauto_002ADD94:
    /* AE994 002ADD94 100FFF6C */  .word 0x100FFF6C
    /* AE998 002ADD98 00000000 */  nop
    /* AE99C 002ADD9C 014A5021 */  addu       $t2, $t2, $t2
    /* AE9A0 002ADDA0 000A7A02 */  srl        $t7, $t2, 8
    /* AE9A4 002ADDA4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE9A8 002ADDA8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE9AC 002ADDAC 100A002F */  .word 0x100A002F
    /* AE9B0 002ADDB0 00000000 */  nop
.Lauto_002ADDB4:
    /* AE9B4 002ADDB4 100FFFAB */  .word 0x100FFFAB
    /* AE9B8 002ADDB8 00000000 */  nop
    /* AE9BC 002ADDBC 21080001 */  addi       $t0, $t0, 0x1 /* handwritten instruction */
    /* AE9C0 002ADDC0 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* AE9C4 002ADDC4 000A7A02 */  srl        $t7, $t2, 8
    /* AE9C8 002ADDC8 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE9CC 002ADDCC 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE9D0 002ADDD0 100A002D */  .word 0x100A002D
    /* AE9D4 002ADDD4 00000000 */  nop
.Lauto_002ADDD8:
    /* AE9D8 002ADDD8 100FFF79 */  .word 0x100FFF79
    /* AE9DC 002ADDDC 00000000 */  nop
    /* AE9E0 002ADDE0 90680000 */  lbu        $t0, 0x0($v1)
    /* AE9E4 002ADDE4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9E8 002ADDE8 00000000 */  nop
    /* AE9EC 002ADDEC 1008003B */  .word 0x1008003B
    /* AE9F0 002ADDF0 21080008 */  addi      $t0, $t0, 0x8 /* handwritten instruction */
    /* AE9F4 002ADDF4 080AB6F0 */  .word 0x080AB6F0
    /* AE9F8 002ADDF8 00000000 */  nop
.Lauto_002ADDFC:
    /* AE9FC 002ADDFC 014A5021 */  addu       $t2, $t2, $t2
    /* AEA00 002ADE00 000A7A02 */  srl        $t7, $t2, 8
    /* AEA04 002ADE04 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA08 002ADE08 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEA0C 002ADE0C 100A0025 */  .word 0x100A0025
    /* AEA10 002ADE10 00000000 */  nop
.Lauto_002ADE14:
    /* AEA14 002ADE14 01294821 */  addu       $t1, $t1, $t1
    /* AEA18 002ADE18 012F4821 */  addu       $t1, $t1, $t7
    /* AEA1C 002ADE1C 00097C02 */  srl        $t7, $t1, 16
    /* AEA20 002ADE20 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA24 002ADE24 35290004 */  ori        $t1, $t1, 0x4
    /* AEA28 002ADE28 014A5021 */  addu       $t2, $t2, $t2
    /* AEA2C 002ADE2C 000A7A02 */  srl        $t7, $t2, 8
    /* AEA30 002ADE30 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA34 002ADE34 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEA38 002ADE38 100A0021 */  .word 0x100A0021
    /* AEA3C 002ADE3C 00000000 */  nop
.Lauto_002ADE40:
    /* AEA40 002ADE40 140FFF84 */  .word 0x140FFF84
    /* AEA44 002ADE44 00000000 */  nop
    /* AEA48 002ADE48 080AB70B */  .word 0x080AB70B
    /* AEA4C 002ADE4C 00000000 */  nop
.Lauto_002ADE50:
    /* AEA50 002ADE50 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEA54 002ADE54 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEA58 002ADE58 014A5021 */  addu       $t2, $t2, $t2
    /* AEA5C 002ADE5C 014F5021 */  addu       $t2, $t2, $t7
    /* AEA60 002ADE60 000A7A02 */  srl        $t7, $t2, 8
    /* AEA64 002ADE64 080AB765 */  .word 0x080AB765
    /* AEA68 002ADE68 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADE6C:
    /* AEA6C 002ADE6C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEA70 002ADE70 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEA74 002ADE74 014A5021 */  addu       $t2, $t2, $t2
    /* AEA78 002ADE78 014F5021 */  addu       $t2, $t2, $t7
    /* AEA7C 002ADE7C 000A7A02 */  srl        $t7, $t2, 8
    /* AEA80 002ADE80 080AB76D */  .word 0x080AB76D
    /* AEA84 002ADE84 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADE88:
    /* AEA88 002ADE88 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEA8C 002ADE8C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEA90 002ADE90 014A5021 */  addu       $t2, $t2, $t2
    /* AEA94 002ADE94 014F5021 */  addu       $t2, $t2, $t7
    /* AEA98 002ADE98 000A7A02 */  srl        $t7, $t2, 8
    /* AEA9C 002ADE9C 080AB776 */  .word 0x080AB776
    /* AEAA0 002ADEA0 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADEA4:
    /* AEAA4 002ADEA4 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEAA8 002ADEA8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEAAC 002ADEAC 014A5021 */  addu       $t2, $t2, $t2
    /* AEAB0 002ADEB0 014F5021 */  addu       $t2, $t2, $t7
    /* AEAB4 002ADEB4 000A7A02 */  srl        $t7, $t2, 8
    /* AEAB8 002ADEB8 080AB785 */  .word 0x080AB785
    /* AEABC 002ADEBC 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADEC0:
    /* AEAC0 002ADEC0 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEAC4 002ADEC4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEAC8 002ADEC8 014A5021 */  addu       $t2, $t2, $t2
    /* AEACC 002ADECC 014F5021 */  addu       $t2, $t2, $t7
    /* AEAD0 002ADED0 000A7A02 */  srl        $t7, $t2, 8
    /* AEAD4 002ADED4 080AB790 */  .word 0x080AB790
    /* AEAD8 002ADED8 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADEDC:
    /* AEADC 002ADEDC 014A5021 */  addu       $t2, $t2, $t2
    /* AEAE0 002ADEE0 000A7A02 */  srl        $t7, $t2, 8
    /* AEAE4 002ADEE4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEAE8 002ADEE8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEAEC 002ADEEC 140A0007 */  .word 0x140A0007
    /* AEAF0 002ADEF0 00000000 */  nop
    /* AEAF4 002ADEF4 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEAF8 002ADEF8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEAFC 002ADEFC 014A5021 */  addu       $t2, $t2, $t2
    /* AEB00 002ADF00 014F5021 */  addu       $t2, $t2, $t7
    /* AEB04 002ADF04 000A7A02 */  srl        $t7, $t2, 8
    /* AEB08 002ADF08 31EF0001 */  andi       $t7, $t7, 0x1
.Lauto_002ADF0C:
    /* AEB0C 002ADF0C 140FFF88 */  .word 0x140FFF88
    /* AEB10 002ADF10 00000000 */  nop
    /* AEB14 002ADF14 956D0000 */  lhu        $t5, 0x0($t3)
    /* AEB18 002ADF18 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* AEB1C 002ADF1C 100D0008 */  .word 0x100D0008
    /* AEB20 002ADF20 00000000 */  nop
.Lauto_002ADF24:
    /* AEB24 002ADF24 85700000 */  lh         $s0, 0x0($t3)
    /* AEB28 002ADF28 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* AEB2C 002ADF2C A0B00000 */  sb         $s0, 0x0($a1)
    /* AEB30 002ADF30 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* AEB34 002ADF34 21ADFFFF */  addi       $t5, $t5, -0x1 /* handwritten instruction */
    /* AEB38 002ADF38 140DFFFA */  .word 0x140DFFFA
    /* AEB3C 002ADF3C 00000000 */  nop
.Lauto_002ADF40:
    /* AEB40 002ADF40 080AB7D3 */  .word 0x080AB7D3
    /* AEB44 002ADF44 00000000 */  nop
    /* AEB48 002ADF48 AD700000 */  sw         $s0, 0x0($t3)
.Lauto_002ADF4C:
    /* AEB4C 002ADF4C 24020000 */  addiu      $v0, $zero, 0x0
    /* AEB50 002ADF50 03E00008 */  jr         $ra
    /* AEB54 002ADF54 00000000 */  nop
.globl D_auto_002ADF58
D_auto_002ADF58:
    /* AEB58 002ADF58 00175041 */  .word 0x00175041
    /* AEB5C 002ADF5C 52544943 */  .word 0x52544943
