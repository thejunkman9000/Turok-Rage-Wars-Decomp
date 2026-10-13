.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE88C-0xAEEC8 (VRAM 0x002ADC8C) */
.globl rncUnpackMethod2Body
rncUnpackMethod2Body:
    /* AE88C 002ADC8C 00A08821 */  addu       $s1, $a1, $zero
    /* AE890 002ADC90 240D0000 */  addiu      $t5, $zero, 0x0
    /* AE894 002ADC94 3C0B8015 */  lui        $t3, %hi(D_auto_80157190)
    /* AE898 002ADC98 256B7190 */  addiu      $t3, $t3, %lo(D_auto_80157190)
    /* AE89C 002ADC9C 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE8A0 002ADCA0 91CD0000 */  lbu        $t5, 0x0($t6)
    /* AE8A4 002ADCA4 91CC0001 */  lbu        $t4, 0x1($t6)
    /* AE8A8 002ADCA8 91D20002 */  lbu        $s2, 0x2($t6)
    /* AE8AC 002ADCAC 91CF0003 */  lbu        $t7, 0x3($t6)
    /* AE8B0 002ADCB0 000D6E00 */  sll        $t5, $t5, 24
    /* AE8B4 002ADCB4 000C6400 */  sll        $t4, $t4, 16
    /* AE8B8 002ADCB8 00129200 */  sll        $s2, $s2, 8
    /* AE8BC 002ADCBC 01AC6825 */  or         $t5, $t5, $t4
    /* AE8C0 002ADCC0 01B26825 */  or         $t5, $t5, $s2
    /* AE8C4 002ADCC4 01AF6825 */  or         $t5, $t5, $t7
    /* AE8C8 002ADCC8 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE8CC 002ADCCC AD6D0000 */  sw         $t5, 0x0($t3)
    /* AE8D0 002ADCD0 01C01821 */  addu       $v1, $t6, $zero
    /* AE8D4 002ADCD4 2063000A */  addi       $v1, $v1, 0xA /* handwritten instruction */
    /* AE8D8 002ADCD8 02202821 */  addu       $a1, $s1, $zero
    /* AE8DC 002ADCDC 00A03021 */  addu       $a2, $a1, $zero
    /* AE8E0 002ADCE0 00CD3021 */  addu       $a2, $a2, $t5
    /* AE8E4 002ADCE4 91CD0000 */  lbu        $t5, 0x0($t6)
    /* AE8E8 002ADCE8 91CC0001 */  lbu        $t4, 0x1($t6)
    /* AE8EC 002ADCEC 91D20002 */  lbu        $s2, 0x2($t6)
    /* AE8F0 002ADCF0 91CF0003 */  lbu        $t7, 0x3($t6)
    /* AE8F4 002ADCF4 000D6E00 */  sll        $t5, $t5, 24
    /* AE8F8 002ADCF8 000C6400 */  sll        $t4, $t4, 16
    /* AE8FC 002ADCFC 00129200 */  sll        $s2, $s2, 8
    /* AE900 002ADD00 01AC6825 */  or         $t5, $t5, $t4
    /* AE904 002ADD04 01B26825 */  or         $t5, $t5, $s2
    /* AE908 002ADD08 01AF6825 */  or         $t5, $t5, $t7
    /* AE90C 002ADD0C 25CE0004 */  addiu      $t6, $t6, 0x4
    /* AE910 002ADD10 00602021 */  addu       $a0, $v1, $zero
    /* AE914 002ADD14 008D2020 */  add        $a0, $a0, $t5 /* handwritten instruction */
    /* AE918 002ADD18 216BFFFE */  addi       $t3, $t3, -0x2 /* handwritten instruction */
    /* AE91C 002ADD1C A5600000 */  sh         $zero, 0x0($t3)
    /* AE920 002ADD20 3C0AFFFF */  lui        $t2, (0xFFFFFF00 >> 16)
    /* AE924 002ADD24 354AFF00 */  ori        $t2, $t2, (0xFFFFFF00 & 0xFFFF)
    /* AE928 002ADD28 240F0001 */  addiu      $t7, $zero, 0x1
    /* AE92C 002ADD2C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE930 002ADD30 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE934 002ADD34 014A5021 */  addu       $t2, $t2, $t2
    /* AE938 002ADD38 014F5021 */  addu       $t2, $t2, $t7
    /* AE93C 002ADD3C 014A5021 */  addu       $t2, $t2, $t2
    /* AE940 002ADD40 000A7A02 */  srl        $t7, $t2, 8
    /* AE944 002ADD44 080AB828 */  .word 0x080AB828
    /* AE948 002ADD48 31EF0001 */  andi      $t7, $t7, 0x1
    /* AE94C 002ADD4C 2402FFFF */  addiu      $v0, $zero, -0x1
    /* AE950 002ADD50 03E00008 */  jr         $ra
    /* AE954 002ADD54 00000000 */  nop
    /* AE958 002ADD58 2402FFFE */  addiu      $v0, $zero, -0x2
    /* AE95C 002ADD5C 03E00008 */  jr         $ra
    /* AE960 002ADD60 00000000 */  nop
.Lauto_002ADD64:
    /* AE964 002ADD64 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE968 002ADD68 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE96C 002ADD6C 014A5021 */  addu       $t2, $t2, $t2
    /* AE970 002ADD70 014F5021 */  addu       $t2, $t2, $t7
    /* AE974 002ADD74 000A7A02 */  srl        $t7, $t2, 8
    /* AE978 002ADD78 080AB798 */  .word 0x080AB798
    /* AE97C 002ADD7C 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADD80:
    /* AE980 002ADD80 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE984 002ADD84 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE988 002ADD88 014A5021 */  addu       $t2, $t2, $t2
    /* AE98C 002ADD8C 014F5021 */  addu       $t2, $t2, $t7
    /* AE990 002ADD90 000A7A02 */  srl        $t7, $t2, 8
    /* AE994 002ADD94 080AB7B4 */  .word 0x080AB7B4
    /* AE998 002ADD98 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADD9C:
    /* AE99C 002ADD9C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE9A0 002ADDA0 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9A4 002ADDA4 014A5021 */  addu       $t2, $t2, $t2
    /* AE9A8 002ADDA8 014F5021 */  addu       $t2, $t2, $t7
    /* AE9AC 002ADDAC 000A7A02 */  srl        $t7, $t2, 8
    /* AE9B0 002ADDB0 080AB7BC */  .word 0x080AB7BC
    /* AE9B4 002ADDB4 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADDB8:
    /* AE9B8 002ADDB8 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE9BC 002ADDBC 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9C0 002ADDC0 014A5021 */  addu       $t2, $t2, $t2
    /* AE9C4 002ADDC4 014F5021 */  addu       $t2, $t2, $t7
    /* AE9C8 002ADDC8 000A7A02 */  srl        $t7, $t2, 8
    /* AE9CC 002ADDCC 080AB7C5 */  .word 0x080AB7C5
    /* AE9D0 002ADDD0 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADDD4:
    /* AE9D4 002ADDD4 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE9D8 002ADDD8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9DC 002ADDDC 014A5021 */  addu       $t2, $t2, $t2
    /* AE9E0 002ADDE0 014F5021 */  addu       $t2, $t2, $t7
    /* AE9E4 002ADDE4 000A7A02 */  srl        $t7, $t2, 8
    /* AE9E8 002ADDE8 080AB7D2 */  .word 0x080AB7D2
    /* AE9EC 002ADDEC 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADDF0:
    /* AE9F0 002ADDF0 906A0000 */  lbu        $t2, 0x0($v1)
    /* AE9F4 002ADDF4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AE9F8 002ADDF8 014A5021 */  addu       $t2, $t2, $t2
    /* AE9FC 002ADDFC 014F5021 */  addu       $t2, $t2, $t7
    /* AEA00 002ADE00 000A7A02 */  srl        $t7, $t2, 8
    /* AEA04 002ADE04 080AB7DA */  .word 0x080AB7DA
    /* AEA08 002ADE08 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADE0C:
    /* AEA0C 002ADE0C 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEA10 002ADE10 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEA14 002ADE14 014A5021 */  addu       $t2, $t2, $t2
    /* AEA18 002ADE18 014F5021 */  addu       $t2, $t2, $t7
    /* AEA1C 002ADE1C 000A7A02 */  srl        $t7, $t2, 8
    /* AEA20 002ADE20 080AB7E2 */  .word 0x080AB7E2
    /* AEA24 002ADE24 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADE28:
    /* AEA28 002ADE28 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEA2C 002ADE2C 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEA30 002ADE30 014A5021 */  addu       $t2, $t2, $t2
    /* AEA34 002ADE34 014F5021 */  addu       $t2, $t2, $t7
    /* AEA38 002ADE38 000A7A02 */  srl        $t7, $t2, 8
    /* AEA3C 002ADE3C 080AB7ED */  .word 0x080AB7ED
    /* AEA40 002ADE40 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002ADE44:
    /* AEA44 002ADE44 24080003 */  addiu      $t0, $zero, 0x3
.Lauto_002ADE48:
    /* AEA48 002ADE48 014A5021 */  addu       $t2, $t2, $t2
    /* AEA4C 002ADE4C 000A7A02 */  srl        $t7, $t2, 8
    /* AEA50 002ADE50 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA54 002ADE54 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEA58 002ADE58 100AFFC2 */  .word 0x100AFFC2
    /* AEA5C 002ADE5C 00000000 */  nop
.Lauto_002ADE60:
    /* AEA60 002ADE60 01294821 */  addu       $t1, $t1, $t1
    /* AEA64 002ADE64 012F4821 */  addu       $t1, $t1, $t7
    /* AEA68 002ADE68 00097C02 */  srl        $t7, $t1, 16
    /* AEA6C 002ADE6C 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEA70 002ADE70 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AEA74 002ADE74 0501FFF4 */  .word 0x0501FFF4
    /* AEA78 002ADE78 00000000 */  nop
    /* AEA7C 002ADE7C 21290002 */  addi       $t1, $t1, 0x2 /* handwritten instruction */
.Lauto_002ADE80:
    /* AEA80 002ADE80 906C0000 */  lbu        $t4, 0x0($v1)
    /* AEA84 002ADE84 90720001 */  lbu        $s2, 0x1($v1)
    /* AEA88 002ADE88 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AEA8C 002ADE8C A0B20001 */  sb         $s2, 0x1($a1)
    /* AEA90 002ADE90 906C0002 */  lbu        $t4, 0x2($v1)
    /* AEA94 002ADE94 90720003 */  lbu        $s2, 0x3($v1)
    /* AEA98 002ADE98 A0AC0002 */  sb         $t4, 0x2($a1)
    /* AEA9C 002ADE9C A0B20003 */  sb         $s2, 0x3($a1)
    /* AEAA0 002ADEA0 24630004 */  addiu      $v1, $v1, 0x4
    /* AEAA4 002ADEA4 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* AEAA8 002ADEA8 0521FFF5 */  .word 0x0521FFF5
    /* AEAAC 002ADEAC 20A50004 */  addi      $a1, $a1, 0x4 /* handwritten instruction */
    /* AEAB0 002ADEB0 080AB828 */  .word 0x080AB828
    /* AEAB4 002ADEB4 00000000 */  nop
.Lauto_002ADEB8:
    /* AEAB8 002ADEB8 014A5021 */  addu       $t2, $t2, $t2
    /* AEABC 002ADEBC 000A7A02 */  srl        $t7, $t2, 8
    /* AEAC0 002ADEC0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEAC4 002ADEC4 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEAC8 002ADEC8 100AFFAD */  .word 0x100AFFAD
    /* AEACC 002ADECC 00000000 */  nop
.Lauto_002ADED0:
    /* AEAD0 002ADED0 01084021 */  addu       $t0, $t0, $t0
    /* AEAD4 002ADED4 010F4021 */  addu       $t0, $t0, $t7
    /* AEAD8 002ADED8 014A5021 */  addu       $t2, $t2, $t2
    /* AEADC 002ADEDC 000A7A02 */  srl        $t7, $t2, 8
    /* AEAE0 002ADEE0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEAE4 002ADEE4 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEAE8 002ADEE8 100AFFAC */  .word 0x100AFFAC
    /* AEAEC 002ADEEC 00000000 */  nop
.Lauto_002ADEF0:
    /* AEAF0 002ADEF0 100F000F */  .word 0x100F000F
    /* AEAF4 002ADEF4 00000000 */  nop
    /* AEAF8 002ADEF8 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AEAFC 002ADEFC 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* AEB00 002ADF00 000A7A02 */  srl        $t7, $t2, 8
    /* AEB04 002ADF04 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEB08 002ADF08 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEB0C 002ADF0C 100AFFAA */  .word 0x100AFFAA
    /* AEB10 002ADF10 00000000 */  nop
.Lauto_002ADF14:
    /* AEB14 002ADF14 01084021 */  addu       $t0, $t0, $t0
    /* AEB18 002ADF18 010F4021 */  addu       $t0, $t0, $t7
    /* AEB1C 002ADF1C 00087C02 */  srl        $t7, $t0, 16
    /* AEB20 002ADF20 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEB24 002ADF24 210CFFF7 */  addi       $t4, $t0, -0x9 /* handwritten instruction */
    /* AEB28 002ADF28 100CFFC6 */  .word 0x100CFFC6
    /* AEB2C 002ADF2C 00000000 */  nop
.Lauto_002ADF30:
    /* AEB30 002ADF30 014A5021 */  addu       $t2, $t2, $t2
    /* AEB34 002ADF34 000A7A02 */  srl        $t7, $t2, 8
    /* AEB38 002ADF38 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEB3C 002ADF3C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEB40 002ADF40 100AFFA4 */  .word 0x100AFFA4
    /* AEB44 002ADF44 00000000 */  nop
.Lauto_002ADF48:
    /* AEB48 002ADF48 100F0022 */  .word 0x100F0022
    /* AEB4C 002ADF4C 00000000 */  nop
    /* AEB50 002ADF50 014A5021 */  addu       $t2, $t2, $t2
    /* AEB54 002ADF54 000A7A02 */  srl        $t7, $t2, 8
    /* AEB58 002ADF58 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEB5C 002ADF5C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEB60 002ADF60 100AFFA3 */  .word 0x100AFFA3
    /* AEB64 002ADF64 00000000 */  nop
.Lauto_002ADF68:
    /* AEB68 002ADF68 01294821 */  addu       $t1, $t1, $t1
    /* AEB6C 002ADF6C 012F4821 */  addu       $t1, $t1, $t7
    /* AEB70 002ADF70 014A5021 */  addu       $t2, $t2, $t2
    /* AEB74 002ADF74 000A7A02 */  srl        $t7, $t2, 8
    /* AEB78 002ADF78 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEB7C 002ADF7C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEB80 002ADF80 100AFFA2 */  .word 0x100AFFA2
    /* AEB84 002ADF84 00000000 */  nop
.Lauto_002ADF88:
    /* AEB88 002ADF88 140F0078 */  .word 0x140F0078
    /* AEB8C 002ADF8C 00000000 */  nop
    /* AEB90 002ADF90 1409000C */  .word 0x1409000C
    /* AEB94 002ADF94 00000000 */  nop
    /* AEB98 002ADF98 21290001 */  addi       $t1, $t1, 0x1 /* handwritten instruction */
.Lauto_002ADF9C:
    /* AEB9C 002ADF9C 014A5021 */  addu       $t2, $t2, $t2
    /* AEBA0 002ADFA0 000A7A02 */  srl        $t7, $t2, 8
    /* AEBA4 002ADFA4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEBA8 002ADFA8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEBAC 002ADFAC 100AFF9E */  .word 0x100AFF9E
    /* AEBB0 002ADFB0 00000000 */  nop
.Lauto_002ADFB4:
    /* AEBB4 002ADFB4 01294821 */  addu       $t1, $t1, $t1
    /* AEBB8 002ADFB8 012F4821 */  addu       $t1, $t1, $t7
    /* AEBBC 002ADFBC 00097C02 */  srl        $t7, $t1, 16
    /* AEBC0 002ADFC0 31EF0001 */  andi       $t7, $t7, 0x1
.Lauto_002ADFC4:
    /* AEBC4 002ADFC4 00096200 */  sll        $t4, $t1, 8
    /* AEBC8 002ADFC8 318CFF00 */  andi       $t4, $t4, 0xFF00
    /* AEBCC 002ADFCC 00094A02 */  srl        $t1, $t1, 8
    /* AEBD0 002ADFD0 012C4825 */  or         $t1, $t1, $t4
.Lauto_002ADFD4:
    /* AEBD4 002ADFD4 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* AEBD8 002ADFD8 90690000 */  lbu        $t1, 0x0($v1)
    /* AEBDC 002ADFDC 24630001 */  addiu      $v1, $v1, 0x1
    /* AEBE0 002ADFE0 01334825 */  or         $t1, $t1, $s3
    /* AEBE4 002ADFE4 00A07021 */  addu       $t6, $a1, $zero
    /* AEBE8 002ADFE8 01C97022 */  sub        $t6, $t6, $t1 /* handwritten instruction */
    /* AEBEC 002ADFEC 21CEFFFF */  addi       $t6, $t6, -0x1 /* handwritten instruction */
    /* AEBF0 002ADFF0 310F0001 */  andi       $t7, $t0, 0x1
    /* AEBF4 002ADFF4 00084042 */  srl        $t0, $t0, 1
    /* AEBF8 002ADFF8 100F0005 */  .word 0x100F0005
    /* AEBFC 002ADFFC 00000000 */  nop
    /* AEC00 002AE000 91CC0000 */  lbu        $t4, 0x0($t6)
    /* AEC04 002AE004 21CE0001 */  addi       $t6, $t6, 0x1 /* handwritten instruction */
    /* AEC08 002AE008 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AEC0C 002AE00C 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
.Lauto_002AE010:
    /* AEC10 002AE010 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AEC14 002AE014 1409000C */  .word 0x1409000C
    /* AEC18 002AE018 00000000 */  nop
    /* AEC1C 002AE01C 3133FF00 */  andi       $s3, $t1, 0xFF00
    /* AEC20 002AE020 91C90000 */  lbu        $t1, 0x0($t6)
    /* AEC24 002AE024 00000000 */  nop
    /* AEC28 002AE028 01334825 */  or         $t1, $t1, $s3
.Lauto_002AE02C:
    /* AEC2C 002AE02C A0A90000 */  sb         $t1, 0x0($a1)
    /* AEC30 002AE030 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AEC34 002AE034 A0A90001 */  sb         $t1, 0x1($a1)
    /* AEC38 002AE038 0501FFFC */  .word 0x0501FFFC
    /* AEC3C 002AE03C 20A50002 */  addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* AEC40 002AE040 080AB828 */  .word 0x080AB828
    /* AEC44 002AE044 00000000 */  nop
.Lauto_002AE048:
    /* AEC48 002AE048 91D20001 */  lbu        $s2, 0x1($t6)
    /* AEC4C 002AE04C 91CC0000 */  lbu        $t4, 0x0($t6)
    /* AEC50 002AE050 A0B20001 */  sb         $s2, 0x1($a1)
    /* AEC54 002AE054 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AEC58 002AE058 21CE0002 */  addi       $t6, $t6, 0x2 /* handwritten instruction */
    /* AEC5C 002AE05C 2108FFFF */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* AEC60 002AE060 0501FFF9 */  .word 0x0501FFF9
    /* AEC64 002AE064 20A50002 */  addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* AEC68 002AE068 080AB828 */  .word 0x080AB828
    /* AEC6C 002AE06C 00000000 */  nop
.Lauto_002AE070:
    /* AEC70 002AE070 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEC74 002AE074 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEC78 002AE078 014A5021 */  addu       $t2, $t2, $t2
    /* AEC7C 002AE07C 014F5021 */  addu       $t2, $t2, $t7
    /* AEC80 002AE080 000A7A02 */  srl        $t7, $t2, 8
    /* AEC84 002AE084 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEC88 002AE088 140F0016 */  .word 0x140F0016
    /* AEC8C 002AE08C 00000000 */  nop
.Lauto_002AE090:
    /* AEC90 002AE090 906C0000 */  lbu        $t4, 0x0($v1)
    /* AEC94 002AE094 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEC98 002AE098 A0AC0000 */  sb         $t4, 0x0($a1)
    /* AEC9C 002AE09C 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
.Lauto_002AE0A0:
    /* AECA0 002AE0A0 014A5021 */  addu       $t2, $t2, $t2
    /* AECA4 002AE0A4 000A7A02 */  srl        $t7, $t2, 8
    /* AECA8 002AE0A8 31EF0001 */  andi       $t7, $t7, 0x1
    /* AECAC 002AE0AC 140F000A */  .word 0x140F000A
    /* AECB0 002AE0B0 00000000 */  nop
    /* AECB4 002AE0B4 906C0000 */  lbu        $t4, 0x0($v1)
    /* AECB8 002AE0B8 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AECBC 002AE0BC A0AC0000 */  sb         $t4, 0x0($a1)
    /* AECC0 002AE0C0 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* AECC4 002AE0C4 014A5021 */  addu       $t2, $t2, $t2
    /* AECC8 002AE0C8 000A7A02 */  srl        $t7, $t2, 8
    /* AECCC 002AE0CC 31EF0001 */  andi       $t7, $t7, 0x1
    /* AECD0 002AE0D0 100FFFEF */  .word 0x100FFFEF
    /* AECD4 002AE0D4 00000000 */  nop
.Lauto_002AE0D8:
    /* AECD8 002AE0D8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AECDC 002AE0DC 100AFFE4 */  .word 0x100AFFE4
    /* AECE0 002AE0E0 00000000 */  nop
.Lauto_002AE0E4:
    /* AECE4 002AE0E4 24080002 */  addiu      $t0, $zero, 0x2
    /* AECE8 002AE0E8 24090000 */  addiu      $t1, $zero, 0x0
    /* AECEC 002AE0EC 014A5021 */  addu       $t2, $t2, $t2
    /* AECF0 002AE0F0 000A7A02 */  srl        $t7, $t2, 8
    /* AECF4 002AE0F4 31EF0001 */  andi       $t7, $t7, 0x1
    /* AECF8 002AE0F8 314A00FF */  andi       $t2, $t2, 0xFF
    /* AECFC 002AE0FC 100A0030 */  .word 0x100A0030
    /* AED00 002AE100 00000000 */  nop
.Lauto_002AE104:
    /* AED04 002AE104 100FFF6C */  .word 0x100FFF6C
    /* AED08 002AE108 00000000 */  nop
    /* AED0C 002AE10C 014A5021 */  addu       $t2, $t2, $t2
    /* AED10 002AE110 000A7A02 */  srl        $t7, $t2, 8
    /* AED14 002AE114 31EF0001 */  andi       $t7, $t7, 0x1
    /* AED18 002AE118 314A00FF */  andi       $t2, $t2, 0xFF
    /* AED1C 002AE11C 100A002F */  .word 0x100A002F
    /* AED20 002AE120 00000000 */  nop
.Lauto_002AE124:
    /* AED24 002AE124 100FFFAB */  .word 0x100FFFAB
    /* AED28 002AE128 00000000 */  nop
    /* AED2C 002AE12C 21080001 */  addi       $t0, $t0, 0x1 /* handwritten instruction */
    /* AED30 002AE130 014A5020 */  add        $t2, $t2, $t2 /* handwritten instruction */
    /* AED34 002AE134 000A7A02 */  srl        $t7, $t2, 8
    /* AED38 002AE138 31EF0001 */  andi       $t7, $t7, 0x1
    /* AED3C 002AE13C 314A00FF */  andi       $t2, $t2, 0xFF
    /* AED40 002AE140 100A002D */  .word 0x100A002D
    /* AED44 002AE144 00000000 */  nop
.Lauto_002AE148:
    /* AED48 002AE148 100FFF79 */  .word 0x100FFF79
    /* AED4C 002AE14C 00000000 */  nop
    /* AED50 002AE150 90680000 */  lbu        $t0, 0x0($v1)
    /* AED54 002AE154 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AED58 002AE158 00000000 */  nop
    /* AED5C 002AE15C 1008003B */  .word 0x1008003B
    /* AED60 002AE160 21080008 */  addi      $t0, $t0, 0x8 /* handwritten instruction */
    /* AED64 002AE164 080AB7CC */  .word 0x080AB7CC
    /* AED68 002AE168 00000000 */  nop
.Lauto_002AE16C:
    /* AED6C 002AE16C 014A5021 */  addu       $t2, $t2, $t2
    /* AED70 002AE170 000A7A02 */  srl        $t7, $t2, 8
    /* AED74 002AE174 31EF0001 */  andi       $t7, $t7, 0x1
    /* AED78 002AE178 314A00FF */  andi       $t2, $t2, 0xFF
    /* AED7C 002AE17C 100A0025 */  .word 0x100A0025
    /* AED80 002AE180 00000000 */  nop
.Lauto_002AE184:
    /* AED84 002AE184 01294821 */  addu       $t1, $t1, $t1
    /* AED88 002AE188 012F4821 */  addu       $t1, $t1, $t7
    /* AED8C 002AE18C 00097C02 */  srl        $t7, $t1, 16
    /* AED90 002AE190 31EF0001 */  andi       $t7, $t7, 0x1
    /* AED94 002AE194 35290004 */  ori        $t1, $t1, 0x4
    /* AED98 002AE198 014A5021 */  addu       $t2, $t2, $t2
    /* AED9C 002AE19C 000A7A02 */  srl        $t7, $t2, 8
    /* AEDA0 002AE1A0 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEDA4 002AE1A4 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEDA8 002AE1A8 100A0021 */  .word 0x100A0021
    /* AEDAC 002AE1AC 00000000 */  nop
.Lauto_002AE1B0:
    /* AEDB0 002AE1B0 140FFF84 */  .word 0x140FFF84
    /* AEDB4 002AE1B4 00000000 */  nop
    /* AEDB8 002AE1B8 080AB7E7 */  .word 0x080AB7E7
    /* AEDBC 002AE1BC 00000000 */  nop
.Lauto_002AE1C0:
    /* AEDC0 002AE1C0 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEDC4 002AE1C4 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEDC8 002AE1C8 014A5021 */  addu       $t2, $t2, $t2
    /* AEDCC 002AE1CC 014F5021 */  addu       $t2, $t2, $t7
    /* AEDD0 002AE1D0 000A7A02 */  srl        $t7, $t2, 8
    /* AEDD4 002AE1D4 080AB841 */  .word 0x080AB841
    /* AEDD8 002AE1D8 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002AE1DC:
    /* AEDDC 002AE1DC 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEDE0 002AE1E0 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEDE4 002AE1E4 014A5021 */  addu       $t2, $t2, $t2
    /* AEDE8 002AE1E8 014F5021 */  addu       $t2, $t2, $t7
    /* AEDEC 002AE1EC 000A7A02 */  srl        $t7, $t2, 8
    /* AEDF0 002AE1F0 080AB849 */  .word 0x080AB849
    /* AEDF4 002AE1F4 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002AE1F8:
    /* AEDF8 002AE1F8 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEDFC 002AE1FC 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEE00 002AE200 014A5021 */  addu       $t2, $t2, $t2
    /* AEE04 002AE204 014F5021 */  addu       $t2, $t2, $t7
    /* AEE08 002AE208 000A7A02 */  srl        $t7, $t2, 8
    /* AEE0C 002AE20C 080AB852 */  .word 0x080AB852
    /* AEE10 002AE210 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002AE214:
    /* AEE14 002AE214 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEE18 002AE218 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEE1C 002AE21C 014A5021 */  addu       $t2, $t2, $t2
    /* AEE20 002AE220 014F5021 */  addu       $t2, $t2, $t7
    /* AEE24 002AE224 000A7A02 */  srl        $t7, $t2, 8
    /* AEE28 002AE228 080AB861 */  .word 0x080AB861
    /* AEE2C 002AE22C 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002AE230:
    /* AEE30 002AE230 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEE34 002AE234 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEE38 002AE238 014A5021 */  addu       $t2, $t2, $t2
    /* AEE3C 002AE23C 014F5021 */  addu       $t2, $t2, $t7
    /* AEE40 002AE240 000A7A02 */  srl        $t7, $t2, 8
    /* AEE44 002AE244 080AB86C */  .word 0x080AB86C
    /* AEE48 002AE248 31EF0001 */  andi      $t7, $t7, 0x1
.Lauto_002AE24C:
    /* AEE4C 002AE24C 014A5021 */  addu       $t2, $t2, $t2
    /* AEE50 002AE250 000A7A02 */  srl        $t7, $t2, 8
    /* AEE54 002AE254 31EF0001 */  andi       $t7, $t7, 0x1
    /* AEE58 002AE258 314A00FF */  andi       $t2, $t2, 0xFF
    /* AEE5C 002AE25C 140A0007 */  .word 0x140A0007
    /* AEE60 002AE260 00000000 */  nop
    /* AEE64 002AE264 906A0000 */  lbu        $t2, 0x0($v1)
    /* AEE68 002AE268 20630001 */  addi       $v1, $v1, 0x1 /* handwritten instruction */
    /* AEE6C 002AE26C 014A5021 */  addu       $t2, $t2, $t2
    /* AEE70 002AE270 014F5021 */  addu       $t2, $t2, $t7
    /* AEE74 002AE274 000A7A02 */  srl        $t7, $t2, 8
    /* AEE78 002AE278 31EF0001 */  andi       $t7, $t7, 0x1
.Lauto_002AE27C:
    /* AEE7C 002AE27C 140FFF88 */  .word 0x140FFF88
    /* AEE80 002AE280 00000000 */  nop
    /* AEE84 002AE284 956D0000 */  lhu        $t5, 0x0($t3)
    /* AEE88 002AE288 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* AEE8C 002AE28C 100D0008 */  .word 0x100D0008
    /* AEE90 002AE290 00000000 */  nop
.Lauto_002AE294:
    /* AEE94 002AE294 85700000 */  lh         $s0, 0x0($t3)
    /* AEE98 002AE298 216B0002 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* AEE9C 002AE29C A0B00000 */  sb         $s0, 0x0($a1)
    /* AEEA0 002AE2A0 20A50001 */  addi       $a1, $a1, 0x1 /* handwritten instruction */
    /* AEEA4 002AE2A4 21ADFFFF */  addi       $t5, $t5, -0x1 /* handwritten instruction */
    /* AEEA8 002AE2A8 140DFFFA */  .word 0x140DFFFA
    /* AEEAC 002AE2AC 00000000 */  nop
.Lauto_002AE2B0:
    /* AEEB0 002AE2B0 080AB8AF */  .word 0x080AB8AF
    /* AEEB4 002AE2B4 00000000 */  nop
    /* AEEB8 002AE2B8 AD700000 */  sw         $s0, 0x0($t3)
.Lauto_002AE2BC:
    /* AEEBC 002AE2BC 24020000 */  addiu      $v0, $zero, 0x0
    /* AEEC0 002AE2C0 03E00008 */  jr         $ra
    /* AEEC4 002AE2C4 00000000 */  nop
