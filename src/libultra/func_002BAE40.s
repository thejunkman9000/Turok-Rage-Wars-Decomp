.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBBA40-0xBBC38 (VRAM 0x002BAE40) */
glabel func_002BAE40
    /* BBA40 002BAE40 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* BBA44 002BAE44 AFB5002C */  sw         $s5, 0x2C($sp)
    /* BBA48 002BAE48 0080A821 */  addu       $s5, $a0, $zero
    /* BBA4C 002BAE4C AFB30024 */  sw         $s3, 0x24($sp)
    /* BBA50 002BAE50 00A09821 */  addu       $s3, $a1, $zero
    /* BBA54 002BAE54 AFB60030 */  sw         $s6, 0x30($sp)
    /* BBA58 002BAE58 00C0B021 */  addu       $s6, $a2, $zero
    /* BBA5C 002BAE5C AFB40028 */  sw         $s4, 0x28($sp)
    /* BBA60 002BAE60 AFBF0034 */  sw         $ra, 0x34($sp)
    /* BBA64 002BAE64 AFB20020 */  sw         $s2, 0x20($sp)
    /* BBA68 002BAE68 AFB1001C */  sw         $s1, 0x1C($sp)
    /* BBA6C 002BAE6C AFB00018 */  sw         $s0, 0x18($sp)
    /* BBA70 002BAE70 F7B50040 */  sdc1       $fs0f, 0x40($sp)
    /* BBA74 002BAE74 F7B40038 */  sdc1       $fs0, 0x38($sp)
    /* BBA78 002BAE78 8E620024 */  lw         $v0, 0x24($s3)
    /* BBA7C 002BAE7C 8FB20058 */  lw         $s2, 0x58($sp)
    /* BBA80 002BAE80 10400056 */  beqz       $v0, .L002BAFDC
    /* BBA84 002BAE84 00E0A021 */   addu      $s4, $a3, $zero
    /* BBA88 002BAE88 02602021 */  addu       $a0, $s3, $zero
    /* BBA8C 002BAE8C 8E700004 */  lw         $s0, 0x4($s3)
    /* BBA90 002BAE90 8E620000 */  lw         $v0, 0x0($s3)
    /* BBA94 002BAE94 02802821 */  addu       $a1, $s4, $zero
    /* BBA98 002BAE98 0C0AECF4 */  jal        func_002BB3D0
    /* BBA9C 002BAE9C 02028023 */   subu      $s0, $s0, $v0
    /* BBAA0 002BAEA0 44900800 */  mtc1       $s0, $fv0f
    /* BBAA4 002BAEA4 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BBAA8 002BAEA8 3C01800D */  lui        $at, %hi(D_800CCA18 + 0x4)
    /* BBAAC 002BAEAC C435CA1C */  lwc1       $fs0f, %lo(D_800CCA18 + 0x4)($at)
    /* BBAB0 002BAEB0 46010043 */  div.s      $fv0f, $fv0, $fv0f
    /* BBAB4 002BAEB4 46150802 */  mul.s      $fv0, $fv0f, $fs0f
    /* BBAB8 002BAEB8 4600008D */  trunc.w.s  $fv1, $fv0
    /* BBABC 002BAEBC 44021000 */  mfc1       $v0, $fv1
    /* BBAC0 002BAEC0 3C01800D */  lui        $at, %hi(D_800CCA20)
    /* BBAC4 002BAEC4 C420CA20 */  lwc1       $fv0, %lo(D_800CCA20)($at)
    /* BBAC8 002BAEC8 44820800 */  mtc1       $v0, $fv0f
    /* BBACC 002BAECC 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BBAD0 002BAED0 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* BBAD4 002BAED4 3C01800D */  lui        $at, %hi(D_800CCA24)
    /* BBAD8 002BAED8 C434CA24 */  lwc1       $fs0, %lo(D_800CCA24)($at)
    /* BBADC 002BAEDC 4601A501 */  sub.s      $fs0, $fs0, $fv0f
    /* BBAE0 002BAEE0 44940800 */  mtc1       $s4, $fv0f
    /* BBAE4 002BAEE4 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BBAE8 002BAEE8 4601A042 */  mul.s      $fv0f, $fs0, $fv0f
    /* BBAEC 002BAEEC 8E620024 */  lw         $v0, 0x24($s3)
    /* BBAF0 002BAEF0 C4400020 */  lwc1       $fv0, 0x20($v0)
    /* BBAF4 002BAEF4 46010000 */  add.s      $fv0, $fv0, $fv0f
    /* BBAF8 002BAEF8 4600008D */  trunc.w.s  $fv1, $fv0
    /* BBAFC 002BAEFC 44111000 */  mfc1       $s1, $fv1
    /* BBB00 002BAF00 44910800 */  mtc1       $s1, $fv0f
    /* BBB04 002BAF04 46800860 */  cvt.s.w    $fv0f, $fv0f
    /* BBB08 002BAF08 46010001 */  sub.s      $fv0, $fv0, $fv0f
    /* BBB0C 002BAF0C 02A02021 */  addu       $a0, $s5, $zero
    /* BBB10 002BAF10 E4400020 */  swc1       $fv0, 0x20($v0)
    /* BBB14 002BAF14 8E620018 */  lw         $v0, 0x18($s3)
    /* BBB18 002BAF18 8E630004 */  lw         $v1, 0x4($s3)
    /* BBB1C 002BAF1C 8C850018 */  lw         $a1, 0x18($a0)
    /* BBB20 002BAF20 24060280 */  addiu      $a2, $zero, 0x280
    /* BBB24 002BAF24 AFB20010 */  sw         $s2, 0x10($sp)
    /* BBB28 002BAF28 00431023 */  subu       $v0, $v0, $v1
    /* BBB2C 002BAF2C 00021040 */  sll        $v0, $v0, 1
    /* BBB30 002BAF30 00A22821 */  addu       $a1, $a1, $v0
    /* BBB34 002BAF34 30A70007 */  andi       $a3, $a1, 0x7
    /* BBB38 002BAF38 00073843 */  sra        $a3, $a3, 1
    /* BBB3C 002BAF3C 00078040 */  sll        $s0, $a3, 1
    /* BBB40 002BAF40 00B02823 */  subu       $a1, $a1, $s0
    /* BBB44 002BAF44 0C0AEC6F */  jal        func_002BB1BC
    /* BBB48 002BAF48 02273821 */   addu      $a3, $s1, $a3
    /* BBB4C 002BAF4C 00409021 */  addu       $s2, $v0, $zero
    /* BBB50 002BAF50 02402021 */  addu       $a0, $s2, $zero
    /* BBB54 002BAF54 26520008 */  addiu      $s2, $s2, 0x8
    /* BBB58 002BAF58 3C020800 */  lui        $v0, (0x8000280 >> 16)
    /* BBB5C 002BAF5C 34420280 */  ori        $v0, $v0, (0x8000280 & 0xFFFF)
    /* BBB60 002BAF60 02028025 */  or         $s0, $s0, $v0
    /* BBB64 002BAF64 00161C00 */  sll        $v1, $s6, 16
    /* BBB68 002BAF68 00141040 */  sll        $v0, $s4, 1
    /* BBB6C 002BAF6C 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BBB70 002BAF70 00621825 */  or         $v1, $v1, $v0
    /* BBB74 002BAF74 4615A502 */  mul.s      $fs0, $fs0, $fs0f
    /* BBB78 002BAF78 AC900000 */  sw         $s0, 0x0($a0)
    /* BBB7C 002BAF7C AC830004 */  sw         $v1, 0x4($a0)
    /* BBB80 002BAF80 8E620024 */  lw         $v0, 0x24($s3)
    /* BBB84 002BAF84 02408021 */  addu       $s0, $s2, $zero
    /* BBB88 002BAF88 90440027 */  lbu        $a0, 0x27($v0)
    /* BBB8C 002BAF8C 3C020500 */  lui        $v0, (0x5000000 >> 16)
    /* BBB90 002BAF90 00042400 */  sll        $a0, $a0, 16
    /* BBB94 002BAF94 4600A08D */  trunc.w.s  $fv1, $fs0
    /* BBB98 002BAF98 44031000 */  mfc1       $v1, $fv1
    /* BBB9C 002BAF9C 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* BBBA0 002BAFA0 00621825 */  or         $v1, $v1, $v0
    /* BBBA4 002BAFA4 00832025 */  or         $a0, $a0, $v1
    /* BBBA8 002BAFA8 AE040000 */  sw         $a0, 0x0($s0)
    /* BBBAC 002BAFAC 8E620024 */  lw         $v0, 0x24($s3)
    /* BBBB0 002BAFB0 8C440014 */  lw         $a0, 0x14($v0)
    /* BBBB4 002BAFB4 0C0B032C */  jal        osVirtualToPhysical
    /* BBBB8 002BAFB8 26520008 */   addiu     $s2, $s2, 0x8
    /* BBBBC 002BAFBC AE020004 */  sw         $v0, 0x4($s0)
    /* BBBC0 002BAFC0 8E620024 */  lw         $v0, 0x24($s3)
    /* BBBC4 002BAFC4 AC400024 */  sw         $zero, 0x24($v0)
    /* BBBC8 002BAFC8 8E620018 */  lw         $v0, 0x18($s3)
    /* BBBCC 002BAFCC 02348823 */  subu       $s1, $s1, $s4
    /* BBBD0 002BAFD0 00511021 */  addu       $v0, $v0, $s1
    /* BBBD4 002BAFD4 080AEC01 */  j          .L002BB004
    /* BBBD8 002BAFD8 AE620018 */   sw        $v0, 0x18($s3)
  .L002BAFDC:
    /* BBBDC 002BAFDC 02A02021 */  addu       $a0, $s5, $zero
    /* BBBE0 002BAFE0 02C03021 */  addu       $a2, $s6, $zero
    /* BBBE4 002BAFE4 8E650004 */  lw         $a1, 0x4($s3)
    /* BBBE8 002BAFE8 8C820018 */  lw         $v0, 0x18($a0)
    /* BBBEC 002BAFEC 02803821 */  addu       $a3, $s4, $zero
    /* BBBF0 002BAFF0 AFB20010 */  sw         $s2, 0x10($sp)
    /* BBBF4 002BAFF4 00052840 */  sll        $a1, $a1, 1
    /* BBBF8 002BAFF8 0C0AEC6F */  jal        func_002BB1BC
    /* BBBFC 002BAFFC 00452823 */   subu      $a1, $v0, $a1
    /* BBC00 002BB000 00409021 */  addu       $s2, $v0, $zero
  .L002BB004:
    /* BBC04 002BB004 02401021 */  addu       $v0, $s2, $zero
    /* BBC08 002BB008 8FBF0034 */  lw         $ra, 0x34($sp)
    /* BBC0C 002BB00C 8FB60030 */  lw         $s6, 0x30($sp)
    /* BBC10 002BB010 8FB5002C */  lw         $s5, 0x2C($sp)
    /* BBC14 002BB014 8FB40028 */  lw         $s4, 0x28($sp)
    /* BBC18 002BB018 8FB30024 */  lw         $s3, 0x24($sp)
    /* BBC1C 002BB01C 8FB20020 */  lw         $s2, 0x20($sp)
    /* BBC20 002BB020 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BBC24 002BB024 8FB00018 */  lw         $s0, 0x18($sp)
    /* BBC28 002BB028 D7B50040 */  ldc1       $fs0f, 0x40($sp)
    /* BBC2C 002BB02C D7B40038 */  ldc1       $fs0, 0x38($sp)
    /* BBC30 002BB030 03E00008 */  jr         $ra
    /* BBC34 002BB034 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel func_002BAE40
