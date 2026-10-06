.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9440-0xB9714 (VRAM 0x002B8840) */
glabel func_002B8840
    /* B9440 002B8840 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B9444 002B8844 AFB40028 */  sw         $s4, 0x28($sp)
    /* B9448 002B8848 0080A021 */  addu       $s4, $a0, $zero
    /* B944C 002B884C AFB60030 */  sw         $s6, 0x30($sp)
    /* B9450 002B8850 00A0B021 */  addu       $s6, $a1, $zero
    /* B9454 002B8854 00002021 */  addu       $a0, $zero, $zero
    /* B9458 002B8858 AFBF0038 */  sw         $ra, 0x38($sp)
    /* B945C 002B885C AFB70034 */  sw         $s7, 0x34($sp)
    /* B9460 002B8860 AFB5002C */  sw         $s5, 0x2C($sp)
    /* B9464 002B8864 AFB30024 */  sw         $s3, 0x24($sp)
    /* B9468 002B8868 AFB20020 */  sw         $s2, 0x20($sp)
    /* B946C 002B886C AFB1001C */  sw         $s1, 0x1C($sp)
    /* B9470 002B8870 AFB00018 */  sw         $s0, 0x18($sp)
    /* B9474 002B8874 8ED50014 */  lw         $s5, 0x14($s6)
    /* B9478 002B8878 00802821 */  addu       $a1, $a0, $zero
    /* B947C 002B887C AE800000 */  sw         $zero, 0x0($s4)
    /* B9480 002B8880 8EC20004 */  lw         $v0, 0x4($s6)
    /* B9484 002B8884 24070001 */  addiu      $a3, $zero, 0x1
    /* B9488 002B8888 AE800020 */  sw         $zero, 0x20($s4)
    /* B948C 002B888C AE80001C */  sw         $zero, 0x1C($s4)
    /* B9490 002B8890 AE82003C */  sw         $v0, 0x3C($s4)
    /* B9494 002B8894 8EC30018 */  lw         $v1, 0x18($s6)
    /* B9498 002B8898 240200A0 */  addiu      $v0, $zero, 0xA0
    /* B949C 002B889C AE820048 */  sw         $v0, 0x48($s4)
    /* B94A0 002B88A0 AE830044 */  sw         $v1, 0x44($s4)
    /* B94A4 002B88A4 8EC20010 */  lw         $v0, 0x10($s6)
    /* B94A8 002B88A8 02A03021 */  addu       $a2, $s5, $zero
    /* B94AC 002B88AC AE820024 */  sw         $v0, 0x24($s4)
    /* B94B0 002B88B0 2402001C */  addiu      $v0, $zero, 0x1C
    /* B94B4 002B88B4 0C0AD504 */  jal        func_002B5410
    /* B94B8 002B88B8 AFA20010 */   sw        $v0, 0x10($sp)
    /* B94BC 002B88BC 0040B821 */  addu       $s7, $v0, $zero
    /* B94C0 002B88C0 0C0AE59A */  jal        func_002B9668
    /* B94C4 002B88C4 02E02021 */   addu      $a0, $s7, $zero
    /* B94C8 002B88C8 00002021 */  addu       $a0, $zero, $zero
    /* B94CC 002B88CC 00802821 */  addu       $a1, $a0, $zero
    /* B94D0 002B88D0 02A03021 */  addu       $a2, $s5, $zero
    /* B94D4 002B88D4 24070001 */  addiu      $a3, $zero, 0x1
    /* B94D8 002B88D8 2402004C */  addiu      $v0, $zero, 0x4C
    /* B94DC 002B88DC AE970038 */  sw         $s7, 0x38($s4)
    /* B94E0 002B88E0 0C0AD504 */  jal        func_002B5410
    /* B94E4 002B88E4 AFA20010 */   sw        $v0, 0x10($sp)
    /* B94E8 002B88E8 00002021 */  addu       $a0, $zero, $zero
    /* B94EC 002B88EC 00802821 */  addu       $a1, $a0, $zero
    /* B94F0 002B88F0 AE820034 */  sw         $v0, 0x34($s4)
    /* B94F4 002B88F4 24020001 */  addiu      $v0, $zero, 0x1
    /* B94F8 002B88F8 24100004 */  addiu      $s0, $zero, 0x4
    /* B94FC 002B88FC AE820040 */  sw         $v0, 0x40($s4)
    /* B9500 002B8900 AFB00010 */  sw         $s0, 0x10($sp)
    /* B9504 002B8904 8EC70004 */  lw         $a3, 0x4($s6)
    /* B9508 002B8908 0C0AD504 */  jal        func_002B5410
    /* B950C 002B890C 02A03021 */   addu      $a2, $s5, $zero
    /* B9510 002B8910 8E840034 */  lw         $a0, 0x34($s4)
    /* B9514 002B8914 8EC60004 */  lw         $a2, 0x4($s6)
    /* B9518 002B8918 0C0AE560 */  jal        func_002B9580
    /* B951C 002B891C 00402821 */   addu      $a1, $v0, $zero
    /* B9520 002B8920 00002021 */  addu       $a0, $zero, $zero
    /* B9524 002B8924 00802821 */  addu       $a1, $a0, $zero
    /* B9528 002B8928 02A03021 */  addu       $a2, $s5, $zero
    /* B952C 002B892C 24070001 */  addiu      $a3, $zero, 0x1
    /* B9530 002B8930 24020020 */  addiu      $v0, $zero, 0x20
    /* B9534 002B8934 0C0AD504 */  jal        func_002B5410
    /* B9538 002B8938 AFA20010 */   sw        $v0, 0x10($sp)
    /* B953C 002B893C 00002021 */  addu       $a0, $zero, $zero
    /* B9540 002B8940 00802821 */  addu       $a1, $a0, $zero
    /* B9544 002B8944 AE820030 */  sw         $v0, 0x30($s4)
    /* B9548 002B8948 AFB00010 */  sw         $s0, 0x10($sp)
    /* B954C 002B894C 8EC70004 */  lw         $a3, 0x4($s6)
    /* B9550 002B8950 0C0AD504 */  jal        func_002B5410
    /* B9554 002B8954 02A03021 */   addu      $a2, $s5, $zero
    /* B9558 002B8958 8E840030 */  lw         $a0, 0x30($s4)
    /* B955C 002B895C 8EC60004 */  lw         $a2, 0x4($s6)
    /* B9560 002B8960 0C0AE549 */  jal        func_002B9524
    /* B9564 002B8964 00402821 */   addu      $a1, $v0, $zero
    /* B9568 002B8968 92C2001C */  lbu        $v0, 0x1C($s6)
    /* B956C 002B896C 10400007 */  beqz       $v0, .L002B898C
    /* B9570 002B8970 02802021 */   addu      $a0, $s4, $zero
    /* B9574 002B8974 00002821 */  addu       $a1, $zero, $zero
    /* B9578 002B8978 02C03021 */  addu       $a2, $s6, $zero
    /* B957C 002B897C 0C0AED64 */  jal        func_002BB590
    /* B9580 002B8980 02A03821 */   addu      $a3, $s5, $zero
    /* B9584 002B8984 080AE268 */  j          .L002B89A0
    /* B9588 002B8988 00002021 */   addu      $a0, $zero, $zero
  .L002B898C:
    /* B958C 002B898C 8E840030 */  lw         $a0, 0x30($s4)
    /* B9590 002B8990 8E860034 */  lw         $a2, 0x34($s4)
    /* B9594 002B8994 0C0AE984 */  jal        func_002BA610
    /* B9598 002B8998 24050002 */   addiu     $a1, $zero, 0x2
    /* B959C 002B899C 00002021 */  addu       $a0, $zero, $zero
  .L002B89A0:
    /* B95A0 002B89A0 00802821 */  addu       $a1, $a0, $zero
    /* B95A4 002B89A4 02A03021 */  addu       $a2, $s5, $zero
    /* B95A8 002B89A8 240200DC */  addiu      $v0, $zero, 0xDC
    /* B95AC 002B89AC AE800004 */  sw         $zero, 0x4($s4)
    /* B95B0 002B89B0 AE800008 */  sw         $zero, 0x8($s4)
    /* B95B4 002B89B4 AE800014 */  sw         $zero, 0x14($s4)
    /* B95B8 002B89B8 AE800018 */  sw         $zero, 0x18($s4)
    /* B95BC 002B89BC AE80000C */  sw         $zero, 0xC($s4)
    /* B95C0 002B89C0 AE800010 */  sw         $zero, 0x10($s4)
    /* B95C4 002B89C4 AFA20010 */  sw         $v0, 0x10($sp)
    /* B95C8 002B89C8 8EC70004 */  lw         $a3, 0x4($s6)
    /* B95CC 002B89CC 0C0AD504 */  jal        func_002B5410
    /* B95D0 002B89D0 00809821 */   addu      $s3, $a0, $zero
    /* B95D4 002B89D4 8EC30004 */  lw         $v1, 0x4($s6)
    /* B95D8 002B89D8 1860002A */  blez       $v1, .L002B8A84
    /* B95DC 002B89DC 02E02021 */   addu      $a0, $s7, $zero
    /* B95E0 002B89E0 00409021 */  addu       $s2, $v0, $zero
  .L002B89E4:
    /* B95E4 002B89E4 02402021 */  addu       $a0, $s2, $zero
    /* B95E8 002B89E8 0C0ADD54 */  jal        func_002B7550
    /* B95EC 002B89EC 26850004 */   addiu     $a1, $s4, 0x4
    /* B95F0 002B89F0 26500010 */  addiu      $s0, $s2, 0x10
    /* B95F4 002B89F4 02002021 */  addu       $a0, $s0, $zero
    /* B95F8 002B89F8 02A03021 */  addu       $a2, $s5, $zero
    /* B95FC 002B89FC AE400008 */  sw         $zero, 0x8($s2)
    /* B9600 002B8A00 8E850024 */  lw         $a1, 0x24($s4)
    /* B9604 002B8A04 0C0AE51D */  jal        func_002B9474
    /* B9608 002B8A08 26730001 */   addiu     $s3, $s3, 0x1
    /* B960C 002B8A0C 02002021 */  addu       $a0, $s0, $zero
    /* B9610 002B8A10 24050001 */  addiu      $a1, $zero, 0x1
    /* B9614 002B8A14 0C0B0EE5 */  jal        func_002C3B94
    /* B9618 002B8A18 00003021 */   addu      $a2, $zero, $zero
    /* B961C 002B8A1C 26510058 */  addiu      $s1, $s2, 0x58
    /* B9620 002B8A20 02202021 */  addu       $a0, $s1, $zero
    /* B9624 002B8A24 0C0AE577 */  jal        func_002B95DC
    /* B9628 002B8A28 02A02821 */   addu      $a1, $s5, $zero
    /* B962C 002B8A2C 02202021 */  addu       $a0, $s1, $zero
    /* B9630 002B8A30 24050001 */  addiu      $a1, $zero, 0x1
    /* B9634 002B8A34 0C0AEA00 */  jal        func_002BA800
    /* B9638 002B8A38 02003021 */   addu      $a2, $s0, $zero
    /* B963C 002B8A3C 2650008C */  addiu      $s0, $s2, 0x8C
    /* B9640 002B8A40 02002021 */  addu       $a0, $s0, $zero
    /* B9644 002B8A44 0C0AE5AB */  jal        func_002B96AC
    /* B9648 002B8A48 02A02821 */   addu      $a1, $s5, $zero
    /* B964C 002B8A4C 02002021 */  addu       $a0, $s0, $zero
    /* B9650 002B8A50 24050001 */  addiu      $a1, $zero, 0x1
    /* B9654 002B8A54 0C0AE8A2 */  jal        func_002BA288
    /* B9658 002B8A58 02203021 */   addu      $a2, $s1, $zero
    /* B965C 002B8A5C 24050002 */  addiu      $a1, $zero, 0x2
    /* B9660 002B8A60 8E840034 */  lw         $a0, 0x34($s4)
    /* B9664 002B8A64 0C0AE3EB */  jal        func_002B8FAC
    /* B9668 002B8A68 02003021 */   addu      $a2, $s0, $zero
    /* B966C 002B8A6C AE50000C */  sw         $s0, 0xC($s2)
    /* B9670 002B8A70 8EC20004 */  lw         $v0, 0x4($s6)
    /* B9674 002B8A74 0262102A */  slt        $v0, $s3, $v0
    /* B9678 002B8A78 1440FFDA */  bnez       $v0, .L002B89E4
    /* B967C 002B8A7C 265200DC */   addiu     $s2, $s2, 0xDC
    /* B9680 002B8A80 02E02021 */  addu       $a0, $s7, $zero
  .L002B8A84:
    /* B9684 002B8A84 24050001 */  addiu      $a1, $zero, 0x1
    /* B9688 002B8A88 8E860030 */  lw         $a2, 0x30($s4)
    /* B968C 002B8A8C 0C0AED54 */  jal        func_002BB550
    /* B9690 002B8A90 00009821 */   addu      $s3, $zero, $zero
    /* B9694 002B8A94 02602021 */  addu       $a0, $s3, $zero
    /* B9698 002B8A98 02602821 */  addu       $a1, $s3, $zero
    /* B969C 002B8A9C 2402001C */  addiu      $v0, $zero, 0x1C
    /* B96A0 002B8AA0 AFA20010 */  sw         $v0, 0x10($sp)
    /* B96A4 002B8AA4 8EC70008 */  lw         $a3, 0x8($s6)
    /* B96A8 002B8AA8 0C0AD504 */  jal        func_002B5410
    /* B96AC 002B8AAC 02A03021 */   addu      $a2, $s5, $zero
    /* B96B0 002B8AB0 AE80002C */  sw         $zero, 0x2C($s4)
    /* B96B4 002B8AB4 8EC30008 */  lw         $v1, 0x8($s6)
    /* B96B8 002B8AB8 5860000B */  blezl      $v1, .L002B8AE8
    /* B96BC 002B8ABC AE950028 */   sw        $s5, 0x28($s4)
    /* B96C0 002B8AC0 00401821 */  addu       $v1, $v0, $zero
  .L002B8AC4:
    /* B96C4 002B8AC4 8E82002C */  lw         $v0, 0x2C($s4)
    /* B96C8 002B8AC8 26730001 */  addiu      $s3, $s3, 0x1
    /* B96CC 002B8ACC AC620000 */  sw         $v0, 0x0($v1)
    /* B96D0 002B8AD0 AE83002C */  sw         $v1, 0x2C($s4)
    /* B96D4 002B8AD4 8EC20008 */  lw         $v0, 0x8($s6)
    /* B96D8 002B8AD8 0262102A */  slt        $v0, $s3, $v0
    /* B96DC 002B8ADC 1440FFF9 */  bnez       $v0, .L002B8AC4
    /* B96E0 002B8AE0 2463001C */   addiu     $v1, $v1, 0x1C
    /* B96E4 002B8AE4 AE950028 */  sw         $s5, 0x28($s4)
  .L002B8AE8:
    /* B96E8 002B8AE8 8FBF0038 */  lw         $ra, 0x38($sp)
    /* B96EC 002B8AEC 8FB70034 */  lw         $s7, 0x34($sp)
    /* B96F0 002B8AF0 8FB60030 */  lw         $s6, 0x30($sp)
    /* B96F4 002B8AF4 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B96F8 002B8AF8 8FB40028 */  lw         $s4, 0x28($sp)
    /* B96FC 002B8AFC 8FB30024 */  lw         $s3, 0x24($sp)
    /* B9700 002B8B00 8FB20020 */  lw         $s2, 0x20($sp)
    /* B9704 002B8B04 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B9708 002B8B08 8FB00018 */  lw         $s0, 0x18($sp)
    /* B970C 002B8B0C 03E00008 */  jr         $ra
    /* B9710 002B8B10 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel func_002B8840
