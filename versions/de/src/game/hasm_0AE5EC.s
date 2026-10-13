.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE5EC-0xAEC28 (VRAM 0x002AD9EC) */
.globl rncUnpackMethod2Body
rncUnpackMethod2Body:
    /* AE5EC 002AD9EC 00A08821 */  addu       $s1, $a1, $zero
    /* AE5F0 002AD9F0 240D0000 */  addiu      $t5, $zero, 0x0
    /* AE5F4 002AD9F4 3C0B8014 */  lui        $t3, %hi(D_auto_80147190)
    /* AE5F8 002AD9F8 256B7190 */  addiu      $t3, $t3, %lo(D_auto_80147190)
    /* AE5FC 002AD9FC 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE600 002ADA00 91CD0000 */  lbu        $t5, 0x0($t6)
    /* AE604 002ADA04 91CC0001 */  lbu        $t4, 0x1($t6)
    /* AE608 002ADA08 91D20002 */  lbu        $s2, 0x2($t6)
    /* AE60C 002ADA0C 91CF0003 */  lbu        $t7, 0x3($t6)
    /* AE610 002ADA10 000D6E00 */  sll        $t5, $t5, 24
    /* AE614 002ADA14 000C6400 */  sll        $t4, $t4, 16
    /* AE618 002ADA18 00129200 */  sll        $s2, $s2, 8
    /* AE61C 002ADA1C 01AC6825 */  or         $t5, $t5, $t4
    /* AE620 002ADA20 01B26825 */  or         $t5, $t5, $s2
    /* AE624 002ADA24 01AF6825 */  or         $t5, $t5, $t7
    /* AE628 002ADA28 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE62C 002ADA2C AD6D0000 */  sw         $t5, 0x0($t3)
    /* AE630 002ADA30 01C01821 */  addu       $v1, $t6, $zero
    /* AE634 002ADA34 2063000A */  addi       $v1, $v1, 0xA /* handwritten instruction */
    /* AE638 002ADA38 02202821 */  addu       $a1, $s1, $zero
    /* AE63C 002ADA3C 00A03021 */  addu       $a2, $a1, $zero
    /* AE640 002ADA40 00CD3021 */  addu       $a2, $a2, $t5
    /* AE644 002ADA44 91CD0000 */  lbu        $t5, 0x0($t6)
    /* AE648 002ADA48 91CC0001 */  lbu        $t4, 0x1($t6)
    /* AE64C 002ADA4C 91D20002 */  lbu        $s2, 0x2($t6)
    /* AE650 002ADA50 91CF0003 */  lbu        $t7, 0x3($t6)
    /* AE654 002ADA54 000D6E00 */  sll        $t5, $t5, 24
    /* AE658 002ADA58 000C6400 */  sll        $t4, $t4, 16
    /* AE65C 002ADA5C 00129200 */  sll        $s2, $s2, 8
    /* AE660 002ADA60 01AC6825 */  or         $t5, $t5, $t4
    /* AE664 002ADA64 01B26825 */  or         $t5, $t5, $s2
    /* AE668 002ADA68 01AF6825 */  or         $t5, $t5, $t7
    /* AE66C 002ADA6C 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE670 002ADA70 00602021 */  addu       $a0, $v1, $zero
    /* AE674 002ADA74 008D2020 */  add        $a0, $a0, $t5 /* handwritten instruction */
    /* AE678 002ADA78 216BFFFE */  addi       $t3, $t3, -0x2 /* handwritten instruction */
    /* AE67C 002ADA7C A5600000 */  sh         $zero, 0x0($t3)
    /* AE680 002ADA80 3C0AFFFF */  lui        $t2, (0xFFFFFF00 >> 16)
    /* AE684 002ADA84 354AFF00 */  ori        $t2, $t2, (0xFFFFFF00 & 0xFFFF)
    /* AE688 002ADA88 240F0001 */  addiu      $t7, $zero, 0x1
    /* AE68C 002ADA8C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE690 002ADA90 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE694 002ADA94 014A5021 */  addu       $t2, $t2, $t2
    /* AE698 002ADA98 014F5021 */  addu       $t2, $t2, $t7
    /* AE69C 002ADA9C 014A5021 */  addu       $t2, $t2, $t2
    /* AE6A0 002ADAA0 000A7A02 */  srl        $t7, $t2, 8
    /* AE6A4 002ADAA4 080AB780 */  .word 0x080AB780
    /* AE6A8 002ADAA8 31EF0001 */  andi      $t7, $t7, 0x1
    /* AE6AC 002ADAAC 2402FFFF */  addiu      $v0, $zero, -0x1
    /* AE6B0 002ADAB0 03E00008 */  jr         $ra
    /* AE6B4 002ADAB4 00000000 */  nop
    /* AE6B8 002ADAB8 2402FFFE */  addiu      $v0, $zero, -0x2
    /* AE6BC 002ADABC 03E00008 */  jr         $ra
    /* AE6C0 002ADAC0 00000000 */  nop
.Lauto_002ADAC4:
    /* AE6C4 002ADAC4 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE6C8 002ADAC8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE6CC 002ADACC 014A5021 */  addu       $t2, $t2, $t2
    /* AE6D0 002ADAD0 014F5021 */  addu       $t2, $t2, $t7
    /* AE6D4 002ADAD4 000A7A02 */  srl        $t7, $t2, 8
    /* AE6D8 002ADAD8 080AB6F0 */  .word 0x080AB6F0
    /* AE6DC 002ADADC 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADAE0:
    /* AE6E0 002ADAE0 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE6E4 002ADAE4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE6E8 002ADAE8 014A5021 */  addu       $t2, $t2, $t2
    /* AE6EC 002ADAEC 014F5021 */  addu       $t2, $t2, $t7
    /* AE6F0 002ADAF0 000A7A02 */  srl        $t7, $t2, 8
    /* AE6F4 002ADAF4 080AB70C */  .word 0x080AB70C
    /* AE6F8 002ADAF8 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADAFC:
    /* AE6FC 002ADAFC 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE700 002ADB00 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE704 002ADB04 014A5021 */  addu       $t2, $t2, $t2
    /* AE708 002ADB08 014F5021 */  addu       $t2, $t2, $t7
    /* AE70C 002ADB0C 000A7A02 */  srl        $t7, $t2, 8
    /* AE710 002ADB10 080AB714 */  .word 0x080AB714
    /* AE714 002ADB14 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADB18:
    /* AE718 002ADB18 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE71C 002ADB1C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE720 002ADB20 014A5021 */  addu       $t2, $t2, $t2
    /* AE724 002ADB24 014F5021 */  addu       $t2, $t2, $t7
    /* AE728 002ADB28 000A7A02 */  srl        $t7, $t2, 8
    /* AE72C 002ADB2C 080AB71D */  .word 0x080AB71D
    /* AE730 002ADB30 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADB34:
    /* AE734 002ADB34 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE738 002ADB38 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE73C 002ADB3C 014A5021 */  addu       $t2, $t2, $t2
    /* AE740 002ADB40 014F5021 */  addu       $t2, $t2, $t7
    /* AE744 002ADB44 000A7A02 */  srl        $t7, $t2, 8
    /* AE748 002ADB48 080AB72A */  .word 0x080AB72A
    /* AE74C 002ADB4C 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADB50:
    /* AE750 002ADB50 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE754 002ADB54 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE758 002ADB58 014A5021 */  addu       $t2, $t2, $t2
    /* AE75C 002ADB5C 014F5021 */  addu       $t2, $t2, $t7
    /* AE760 002ADB60 000A7A02 */  srl        $t7, $t2, 8
    /* AE764 002ADB64 080AB732 */  .word 0x080AB732
    /* AE768 002ADB68 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADB6C:
    /* AE76C 002ADB6C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE770 002ADB70 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE774 002ADB74 014A5021 */  addu       $t2, $t2, $t2
    /* AE778 002ADB78 014F5021 */  addu       $t2, $t2, $t7
    /* AE77C 002ADB7C 000A7A02 */  srl        $t7, $t2, 8
    /* AE780 002ADB80 080AB73A */  .word 0x080AB73A
    /* AE784 002ADB84 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADB88:
    /* AE788 002ADB88 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE78C 002ADB8C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE790 002ADB90 014A5021 */  addu       $t2, $t2, $t2
    /* AE794 002ADB94 014F5021 */  addu       $t2, $t2, $t7
    /* AE798 002ADB98 000A7A02 */  srl        $t7, $t2, 8
    /* AE79C 002ADB9C 080AB745 */  .word 0x080AB745
    /* AE7A0 002ADBA0 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADBA4:
    /* AE7A4 002ADBA4 24080003 */  addiu      $t0, $zero, 0x3
.Lauto_002ADBA8:
    /* AE7A8 002ADBA8 014A5021 */  addu       $t2, $t2, $t2
    /* AE7AC 002ADBAC 000A7A02 */  srl        $t7, $t2, 8
    /* AE7B0 002ADBB0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE7B4 002ADBB4 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE7B8 002ADBB8 100AFFC2 */  .word 0x100AFFC2
    /* AE7BC 002ADBBC 00000000 */  nop
.Lauto_002ADBC0:
    /* AE7C0 002ADBC0 01294821 */  addu       $t1, $t1, $t1
    /* AE7C4 002ADBC4 012F4821 */  addu       $t1, $t1, $t7
    /* AE7C8 002ADBC8 00097C02 */  srl        $t7, $t1, 16
    /* AE7CC 002ADBCC 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE7D0 002ADBD0 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE7D4 002ADBD4 0501FFF4 */  .word 0x0501FFF4
    /* AE7D8 002ADBD8 00000000 */  nop
    /* AE7DC 002ADBDC 21290002 */  addi       $t1, $t1, 0x2 /* handwritten instruction */
.Lauto_002ADBE0:
    /* AE7E0 002ADBE0 906C0000 */  lbu        $t4, 0x0($v1)
    /* AE7E4 002ADBE4 90720001 */  lbu        $s2, 0x1($v1)
    /* AE7E8 002ADBE8 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE7EC 002ADBEC A0B20001 */  sb         $s2, 0x1($a1)
    /* AE7F0 002ADBF0 906C0002 */  lbu        $t4, 0x2($v1)
    /* AE7F4 002ADBF4 90720003 */  lbu        $s2, 0x3($v1)
    /* AE7F8 002ADBF8 A0AC0002 */  sb         $t4, 0x2($a1)
    /* AE7FC 002ADBFC A0B20003 */  sb         $s2, 0x3($a1)
    /* AE800 002ADC00 24630004 */  addiu      $v1, $v1, 0x4
    /* AE804 002ADC04 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* AE808 002ADC08 0521FFF5 */  .word 0x0521FFF5
    /* AE80C 002ADC0C 20A50004 */  addi      $a1, $a1, 0x4 /* handwritten instruction */
    /* AE810 002ADC10 080AB780 */  .word 0x080AB780
    /* AE814 002ADC14 00000000 */  nop
.Lauto_002ADC18:
    /* AE818 002ADC18 014A5021 */  addu       $t2, $t2, $t2
    /* AE81C 002ADC1C 000A7A02 */  srl        $t7, $t2, 8
    /* AE820 002ADC20 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE824 002ADC24 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE828 002ADC28 100AFFAD */  .word 0x100AFFAD
    /* AE82C 002ADC2C 00000000 */  nop
.Lauto_002ADC30:
    /* AE830 002ADC30 01084021 */  addu       $t0, $t0, $t0
    /* AE834 002ADC34 010F4021 */  addu       $t0, $t0, $t7
    /* AE838 002ADC38 014A5021 */  addu       $t2, $t2, $t2
    /* AE83C 002ADC3C 000A7A02 */  srl        $t7, $t2, 8
    /* AE840 002ADC40 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE844 002ADC44 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE848 002ADC48 100AFFAC */  .word 0x100AFFAC
    /* AE84C 002ADC4C 00000000 */  nop
.Lauto_002ADC50:
    /* AE850 002ADC50 100F000F */  .word 0x100F000F
    /* AE854 002ADC54 00000000 */  nop
    /* AE858 002ADC58 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE85C 002ADC5C 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* AE860 002ADC60 000A7A02 */  srl        $t7, $t2, 8
    /* AE864 002ADC64 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE868 002ADC68 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE86C 002ADC6C 100AFFAA */  .word 0x100AFFAA
    /* AE870 002ADC70 00000000 */  nop
.Lauto_002ADC74:
    /* AE874 002ADC74 01084021 */  addu       $t0, $t0, $t0
    /* AE878 002ADC78 010F4021 */  addu       $t0, $t0, $t7
    /* AE87C 002ADC7C 00087C02 */  srl        $t7, $t0, 16
    /* AE880 002ADC80 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE884 002ADC84 210CFFF7 */  addi       $t4, $t0, -0x9 /* handwritten instruction */
    /* AE888 002ADC88 100CFFC6 */  .word 0x100CFFC6
    /* AE88C 002ADC8C 00000000 */  nop
.Lauto_002ADC90:
    /* AE890 002ADC90 014A5021 */  addu       $t2, $t2, $t2
    /* AE894 002ADC94 000A7A02 */  srl        $t7, $t2, 8
    /* AE898 002ADC98 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE89C 002ADC9C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE8A0 002ADCA0 100AFFA4 */  .word 0x100AFFA4
    /* AE8A4 002ADCA4 00000000 */  nop
.Lauto_002ADCA8:
    /* AE8A8 002ADCA8 100F0022 */  .word 0x100F0022
    /* AE8AC 002ADCAC 00000000 */  nop
    /* AE8B0 002ADCB0 014A5021 */  addu       $t2, $t2, $t2
    /* AE8B4 002ADCB4 000A7A02 */  srl        $t7, $t2, 8
    /* AE8B8 002ADCB8 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE8BC 002ADCBC 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE8C0 002ADCC0 100AFFA3 */  .word 0x100AFFA3
    /* AE8C4 002ADCC4 00000000 */  nop
.Lauto_002ADCC8:
    /* AE8C8 002ADCC8 01294821 */  addu       $t1, $t1, $t1
    /* AE8CC 002ADCCC 012F4821 */  addu       $t1, $t1, $t7
    /* AE8D0 002ADCD0 014A5021 */  addu       $t2, $t2, $t2
    /* AE8D4 002ADCD4 000A7A02 */  srl        $t7, $t2, 8
    /* AE8D8 002ADCD8 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE8DC 002ADCDC 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE8E0 002ADCE0 100AFFA2 */  .word 0x100AFFA2
    /* AE8E4 002ADCE4 00000000 */  nop
.Lauto_002ADCE8:
    /* AE8E8 002ADCE8 140F0078 */  .word 0x140F0078
    /* AE8EC 002ADCEC 00000000 */  nop
    /* AE8F0 002ADCF0 1409000C */  .word 0x1409000C
    /* AE8F4 002ADCF4 00000000 */  nop
    /* AE8F8 002ADCF8 21290001 */  addi       $t1, $t1, 0x1 /* handwritten instruction */
.Lauto_002ADCFC:
    /* AE8FC 002ADCFC 014A5021 */  addu       $t2, $t2, $t2
    /* AE900 002ADD00 000A7A02 */  srl        $t7, $t2, 8
    /* AE904 002ADD04 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE908 002ADD08 314A00FF */  andi       $t2, $t2, 0xFF
    /* AE90C 002ADD0C 100AFF9E */  .word 0x100AFF9E
    /* AE910 002ADD10 00000000 */  nop
.Lauto_002ADD14:
    /* AE914 002ADD14 01294821 */  addu       $t1, $t1, $t1
    /* AE918 002ADD18 012F4821 */  addu       $t1, $t1, $t7
    /* AE91C 002ADD1C 00097C02 */  srl        $t7, $t1, 16
    /* AE920 002ADD20 31EF0001 */  andi       $t7, $t7, 0x1
.Lauto_002ADD24:
    /* AE924 002ADD24 00096200 */  sll        $t4, $t1, 8
    /* AE928 002ADD28 318CFF00 */  andi       $t4, $t4, 0xFF00
    /* AE92C 002ADD2C 00094A02 */  srl        $t1, $t1, 8
    /* AE930 002ADD30 012C4825 */  or         $t1, $t1, $t4
.Lauto_002ADD34:
    /* AE934 002ADD34 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* AE938 002ADD38 90690000 */  lbu        $t1, 0x0($v1)
    /* AE93C 002ADD3C 24630001 */  addiu      $v1, $v1, 0x1
    /* AE940 002ADD40 01334825 */  or         $t1, $t1, $s3
    /* AE944 002ADD44 00A07021 */  addu       $t6, $a1, $zero
    /* AE948 002ADD48 01C97022 */  sub        $t6, $t6, $t1 /* handwritten instruction */
    /* AE94C 002ADD4C 21CEFFFF */  addi       $t6, $t6, -0x1 /* handwritten instruction */
    /* AE950 002ADD50 310F0001 */  andi       $t7, $t0, 0x1
    /* AE954 002ADD54 00084042 */  srl        $t0, $t0, 1
    /* AE958 002ADD58 100F0005 */  .word 0x100F0005
    /* AE95C 002ADD5C 00000000 */  nop
    /* AE960 002ADD60 91CC0000 */  lbu        $t4, 0x0($t6)
    /* AE964 002ADD64 21CE0001 */  addi       $t6, $t6, 0x1 /* handwritten instruction */
    /* AE968 002ADD68 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE96C 002ADD6C 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
.Lauto_002ADD70:
    /* AE970 002ADD70 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE974 002ADD74 1409000C */  .word 0x1409000C
    /* AE978 002ADD78 00000000 */  nop
    /* AE97C 002ADD7C 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* AE980 002ADD80 91C90000 */  lbu        $t1, 0x0($t6)
    /* AE984 002ADD84 00000000 */  nop
    /* AE988 002ADD88 01334825 */  or         $t1, $t1, $s3
.Lauto_002ADD8C:
    /* AE98C 002ADD8C A0A90000 */  sb         $t1, 0x0($a1)
    /* AE990 002ADD90 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE994 002ADD94 A0A90001 */  sb         $t1, 0x1($a1)
    /* AE998 002ADD98 0501FFFC */  .word 0x0501FFFC
    /* AE99C 002ADD9C 20A50002 */  addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* AE9A0 002ADDA0 080AB780 */  .word 0x080AB780
    /* AE9A4 002ADDA4 00000000 */  nop
.Lauto_002ADDA8:
    /* AE9A8 002ADDA8 91D20001 */  lbu        $s2, 0x1($t6)
    /* AE9AC 002ADDAC 91CC0000 */  lbu        $t4, 0x0($t6)
    /* AE9B0 002ADDB0 A0B20001 */  sb         $s2, 0x1($a1)
    /* AE9B4 002ADDB4 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE9B8 002ADDB8 21CE0002 */  addi       $t6, $t6, 0x2 /* handwritten instruction */
    /* AE9BC 002ADDBC 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AE9C0 002ADDC0 0501FFF9 */  .word 0x0501FFF9
    /* AE9C4 002ADDC4 20A50002 */  addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* AE9C8 002ADDC8 080AB780 */  .word 0x080AB780
    /* AE9CC 002ADDCC 00000000 */  nop
.Lauto_002ADDD0:
    /* AE9D0 002ADDD0 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE9D4 002ADDD4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9D8 002ADDD8 014A5021 */  addu       $t2, $t2, $t2
    /* AE9DC 002ADDDC 014F5021 */  addu       $t2, $t2, $t7
    /* AE9E0 002ADDE0 000A7A02 */  srl        $t7, $t2, 8
    /* AE9E4 002ADDE4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AE9E8 002ADDE8 140F0016 */  .word 0x140F0016
    /* AE9EC 002ADDEC 00000000 */  nop
.Lauto_002ADDF0:
    /* AE9F0 002ADDF0 906C0000 */  lbu        $t4, 0x0($v1)
    /* AE9F4 002ADDF4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9F8 002ADDF8 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AE9FC 002ADDFC 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
.Lauto_002ADE00:
    /* AEA00 002ADE00 014A5021 */  addu       $t2, $t2, $t2
    /* AEA04 002ADE04 000A7A02 */  srl        $t7, $t2, 8
    /* AEA08 002ADE08 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA0C 002ADE0C 140F000A */  .word 0x140F000A
    /* AEA10 002ADE10 00000000 */  nop
    /* AEA14 002ADE14 906C0000 */  lbu        $t4, 0x0($v1)
    /* AEA18 002ADE18 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEA1C 002ADE1C A0AC0000 */  sb         $t4, 0x0($a1)
    /* AEA20 002ADE20 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* AEA24 002ADE24 014A5021 */  addu       $t2, $t2, $t2
    /* AEA28 002ADE28 000A7A02 */  srl        $t7, $t2, 8
    /* AEA2C 002ADE2C 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA30 002ADE30 100FFFEF */  .word 0x100FFFEF
    /* AEA34 002ADE34 00000000 */  nop
.Lauto_002ADE38:
    /* AEA38 002ADE38 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEA3C 002ADE3C 100AFFE4 */  .word 0x100AFFE4
    /* AEA40 002ADE40 00000000 */  nop
.Lauto_002ADE44:
    /* AEA44 002ADE44 24080002 */  addiu      $t0, $zero, 0x2
    /* AEA48 002ADE48 24090000 */  addiu      $t1, $zero, 0x0
    /* AEA4C 002ADE4C 014A5021 */  addu       $t2, $t2, $t2
    /* AEA50 002ADE50 000A7A02 */  srl        $t7, $t2, 8
    /* AEA54 002ADE54 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA58 002ADE58 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEA5C 002ADE5C 100A0030 */  .word 0x100A0030
    /* AEA60 002ADE60 00000000 */  nop
.Lauto_002ADE64:
    /* AEA64 002ADE64 100FFF6C */  .word 0x100FFF6C
    /* AEA68 002ADE68 00000000 */  nop
    /* AEA6C 002ADE6C 014A5021 */  addu       $t2, $t2, $t2
    /* AEA70 002ADE70 000A7A02 */  srl        $t7, $t2, 8
    /* AEA74 002ADE74 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA78 002ADE78 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEA7C 002ADE7C 100A002F */  .word 0x100A002F
    /* AEA80 002ADE80 00000000 */  nop
.Lauto_002ADE84:
    /* AEA84 002ADE84 100FFFAB */  .word 0x100FFFAB
    /* AEA88 002ADE88 00000000 */  nop
    /* AEA8C 002ADE8C 21080001 */  addi       $t0, $t0, 0x1 /* handwritten instruction */
    /* AEA90 002ADE90 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* AEA94 002ADE94 000A7A02 */  srl        $t7, $t2, 8
    /* AEA98 002ADE98 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA9C 002ADE9C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEAA0 002ADEA0 100A002D */  .word 0x100A002D
    /* AEAA4 002ADEA4 00000000 */  nop
.Lauto_002ADEA8:
    /* AEAA8 002ADEA8 100FFF79 */  .word 0x100FFF79
    /* AEAAC 002ADEAC 00000000 */  nop
    /* AEAB0 002ADEB0 90680000 */  lbu        $t0, 0x0($v1)
    /* AEAB4 002ADEB4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEAB8 002ADEB8 00000000 */  nop
    /* AEABC 002ADEBC 1008003B */  .word 0x1008003B
    /* AEAC0 002ADEC0 21080008 */  addi      $t0, $t0, 0x8 /* handwritten instruction */
    /* AEAC4 002ADEC4 080AB724 */  .word 0x080AB724
    /* AEAC8 002ADEC8 00000000 */  nop
.Lauto_002ADECC:
    /* AEACC 002ADECC 014A5021 */  addu       $t2, $t2, $t2
    /* AEAD0 002ADED0 000A7A02 */  srl        $t7, $t2, 8
    /* AEAD4 002ADED4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEAD8 002ADED8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEADC 002ADEDC 100A0025 */  .word 0x100A0025
    /* AEAE0 002ADEE0 00000000 */  nop
.Lauto_002ADEE4:
    /* AEAE4 002ADEE4 01294821 */  addu       $t1, $t1, $t1
    /* AEAE8 002ADEE8 012F4821 */  addu       $t1, $t1, $t7
    /* AEAEC 002ADEEC 00097C02 */  srl        $t7, $t1, 16
    /* AEAF0 002ADEF0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEAF4 002ADEF4 35290004 */  ori        $t1, $t1, 0x4
    /* AEAF8 002ADEF8 014A5021 */  addu       $t2, $t2, $t2
    /* AEAFC 002ADEFC 000A7A02 */  srl        $t7, $t2, 8
    /* AEB00 002ADF00 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEB04 002ADF04 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEB08 002ADF08 100A0021 */  .word 0x100A0021
    /* AEB0C 002ADF0C 00000000 */  nop
.Lauto_002ADF10:
    /* AEB10 002ADF10 140FFF84 */  .word 0x140FFF84
    /* AEB14 002ADF14 00000000 */  nop
    /* AEB18 002ADF18 080AB73F */  .word 0x080AB73F
    /* AEB1C 002ADF1C 00000000 */  nop
.Lauto_002ADF20:
    /* AEB20 002ADF20 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEB24 002ADF24 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEB28 002ADF28 014A5021 */  addu       $t2, $t2, $t2
    /* AEB2C 002ADF2C 014F5021 */  addu       $t2, $t2, $t7
    /* AEB30 002ADF30 000A7A02 */  srl        $t7, $t2, 8
    /* AEB34 002ADF34 080AB799 */  .word 0x080AB799
    /* AEB38 002ADF38 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADF3C:
    /* AEB3C 002ADF3C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEB40 002ADF40 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEB44 002ADF44 014A5021 */  addu       $t2, $t2, $t2
    /* AEB48 002ADF48 014F5021 */  addu       $t2, $t2, $t7
    /* AEB4C 002ADF4C 000A7A02 */  srl        $t7, $t2, 8
    /* AEB50 002ADF50 080AB7A1 */  .word 0x080AB7A1
    /* AEB54 002ADF54 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADF58:
    /* AEB58 002ADF58 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEB5C 002ADF5C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEB60 002ADF60 014A5021 */  addu       $t2, $t2, $t2
    /* AEB64 002ADF64 014F5021 */  addu       $t2, $t2, $t7
    /* AEB68 002ADF68 000A7A02 */  srl        $t7, $t2, 8
    /* AEB6C 002ADF6C 080AB7AA */  .word 0x080AB7AA
    /* AEB70 002ADF70 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADF74:
    /* AEB74 002ADF74 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEB78 002ADF78 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEB7C 002ADF7C 014A5021 */  addu       $t2, $t2, $t2
    /* AEB80 002ADF80 014F5021 */  addu       $t2, $t2, $t7
    /* AEB84 002ADF84 000A7A02 */  srl        $t7, $t2, 8
    /* AEB88 002ADF88 080AB7B9 */  .word 0x080AB7B9
    /* AEB8C 002ADF8C 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADF90:
    /* AEB90 002ADF90 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEB94 002ADF94 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEB98 002ADF98 014A5021 */  addu       $t2, $t2, $t2
    /* AEB9C 002ADF9C 014F5021 */  addu       $t2, $t2, $t7
    /* AEBA0 002ADFA0 000A7A02 */  srl        $t7, $t2, 8
    /* AEBA4 002ADFA4 080AB7C4 */  .word 0x080AB7C4
    /* AEBA8 002ADFA8 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADFAC:
    /* AEBAC 002ADFAC 014A5021 */  addu       $t2, $t2, $t2
    /* AEBB0 002ADFB0 000A7A02 */  srl        $t7, $t2, 8
    /* AEBB4 002ADFB4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEBB8 002ADFB8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEBBC 002ADFBC 140A0007 */  .word 0x140A0007
    /* AEBC0 002ADFC0 00000000 */  nop
    /* AEBC4 002ADFC4 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEBC8 002ADFC8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEBCC 002ADFCC 014A5021 */  addu       $t2, $t2, $t2
    /* AEBD0 002ADFD0 014F5021 */  addu       $t2, $t2, $t7
    /* AEBD4 002ADFD4 000A7A02 */  srl        $t7, $t2, 8
    /* AEBD8 002ADFD8 31EF0001 */  andi       $t7, $t7, 0x1
.Lauto_002ADFDC:
    /* AEBDC 002ADFDC 140FFF88 */  .word 0x140FFF88
    /* AEBE0 002ADFE0 00000000 */  nop
    /* AEBE4 002ADFE4 956D0000 */  lhu        $t5, 0x0($t3)
    /* AEBE8 002ADFE8 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* AEBEC 002ADFEC 100D0008 */  .word 0x100D0008
    /* AEBF0 002ADFF0 00000000 */  nop
.Lauto_002ADFF4:
    /* AEBF4 002ADFF4 85700000 */  lh         $s0, 0x0($t3)
    /* AEBF8 002ADFF8 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* AEBFC 002ADFFC A0B00000 */  sb         $s0, 0x0($a1)
    /* AEC00 002AE000 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* AEC04 002AE004 21ADFFFF */  addi       $t5, $t5, -0x1 /* handwritten instruction */
    /* AEC08 002AE008 140DFFFA */  .word 0x140DFFFA
    /* AEC0C 002AE00C 00000000 */  nop
.Lauto_002AE010:
    /* AEC10 002AE010 080AB807 */  .word 0x080AB807
    /* AEC14 002AE014 00000000 */  nop
    /* AEC18 002AE018 AD700000 */  sw         $s0, 0x0($t3)
.Lauto_002AE01C:
    /* AEC1C 002AE01C 24020000 */  addiu      $v0, $zero, 0x0
    /* AEC20 002AE020 03E00008 */  jr         $ra
    /* AEC24 002AE024 00000000 */  nop
