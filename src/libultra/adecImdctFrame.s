.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC579C-0xC5B2C (VRAM 0x002C4B9C) */
glabel adecImdctFrame
    /* C579C 002C4B9C 27BDF7D0 */  addiu      $sp, $sp, -0x830
    /* C57A0 002C4BA0 AFB20820 */  sw         $s2, 0x820($sp)
    /* C57A4 002C4BA4 00809021 */  addu       $s2, $a0, $zero
    /* C57A8 002C4BA8 AFB00818 */  sw         $s0, 0x818($sp)
    /* C57AC 002C4BAC 3C10800E */  lui        $s0, %hi(D_800D94F0)
    /* C57B0 002C4BB0 261094F0 */  addiu      $s0, $s0, %lo(D_800D94F0)
    /* C57B4 002C4BB4 AFBF0824 */  sw         $ra, 0x824($sp)
    /* C57B8 002C4BB8 AFB1081C */  sw         $s1, 0x81C($sp)
    /* C57BC 002C4BBC F7B40828 */  sdc1       $fs0, 0x828($sp)
    /* C57C0 002C4BC0 86020000 */  lh         $v0, 0x0($s0)
    /* C57C4 002C4BC4 14400009 */  bnez       $v0, .L002C4BEC
    /* C57C8 002C4BC8 00A08821 */   addu      $s1, $a1, $zero
    /* C57CC 002C4BCC 0C0B1181 */  jal        mdctInitTwiddles
    /* C57D0 002C4BD0 00000000 */   nop
    /* C57D4 002C4BD4 0C0B11DB */  jal        mdctFftInit
    /* C57D8 002C4BD8 24040080 */   addiu     $a0, $zero, 0x80
    /* C57DC 002C4BDC 3C018015 */  lui        $at, %hi(D_80151AC0)
    /* C57E0 002C4BE0 AC221AC0 */  sw         $v0, %lo(D_80151AC0)($at)
    /* C57E4 002C4BE4 24020001 */  addiu      $v0, $zero, 0x1
    /* C57E8 002C4BE8 A6020000 */  sh         $v0, 0x0($s0)
  .L002C4BEC:
    /* C57EC 002C4BEC 3C01800D */  lui        $at, %hi(D_800CCF28)
    /* C57F0 002C4BF0 C434CF28 */  lwc1       $fs0, %lo(D_800CCF28)($at)
    /* C57F4 002C4BF4 27B00418 */  addiu      $s0, $sp, 0x418
    /* C57F8 002C4BF8 02002021 */  addu       $a0, $s0, $zero
    /* C57FC 002C4BFC 0C0B123D */  jal        adecDequantize
    /* C5800 002C4C00 26250018 */   addiu     $a1, $s1, 0x18
    /* C5804 002C4C04 27A60018 */  addiu      $a2, $sp, 0x18
    /* C5808 002C4C08 00002821 */  addu       $a1, $zero, $zero
    /* C580C 002C4C0C 240700FF */  addiu      $a3, $zero, 0xFF
  .L002C4C10:
    /* C5810 002C4C10 00051C00 */  sll        $v1, $a1, 16
    /* C5814 002C4C14 00031C03 */  sra        $v1, $v1, 16
    /* C5818 002C4C18 000320C0 */  sll        $a0, $v1, 3
    /* C581C 002C4C1C 00901021 */  addu       $v0, $a0, $s0
    /* C5820 002C4C20 00862021 */  addu       $a0, $a0, $a2
    /* C5824 002C4C24 00031840 */  sll        $v1, $v1, 1
    /* C5828 002C4C28 00E31823 */  subu       $v1, $a3, $v1
    /* C582C 002C4C2C 00031880 */  sll        $v1, $v1, 2
    /* C5830 002C4C30 00701821 */  addu       $v1, $v1, $s0
    /* C5834 002C4C34 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C5838 002C4C38 24A20001 */  addiu      $v0, $a1, 0x1
    /* C583C 002C4C3C 00402821 */  addu       $a1, $v0, $zero
    /* C5840 002C4C40 00021400 */  sll        $v0, $v0, 16
    /* C5844 002C4C44 00021403 */  sra        $v0, $v0, 16
    /* C5848 002C4C48 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C584C 002C4C4C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C5850 002C4C50 28420080 */  slti       $v0, $v0, 0x80
    /* C5854 002C4C54 1440FFEE */  bnez       $v0, .L002C4C10
    /* C5858 002C4C58 E4800004 */   swc1      $fv0, 0x4($a0)
    /* C585C 002C4C5C 27A60018 */  addiu      $a2, $sp, 0x18
    /* C5860 002C4C60 3C088015 */  lui        $t0, %hi(D_801510C0)
    /* C5864 002C4C64 250810C0 */  addiu      $t0, $t0, %lo(D_801510C0)
    /* C5868 002C4C68 3C078015 */  lui        $a3, %hi(D_801512C0)
    /* C586C 002C4C6C 24E712C0 */  addiu      $a3, $a3, %lo(D_801512C0)
    /* C5870 002C4C70 00002821 */  addu       $a1, $zero, $zero
  .L002C4C74:
    /* C5874 002C4C74 00051400 */  sll        $v0, $a1, 16
    /* C5878 002C4C78 00021403 */  sra        $v0, $v0, 16
    /* C587C 002C4C7C 000220C0 */  sll        $a0, $v0, 3
    /* C5880 002C4C80 00862021 */  addu       $a0, $a0, $a2
    /* C5884 002C4C84 00021080 */  sll        $v0, $v0, 2
    /* C5888 002C4C88 00481821 */  addu       $v1, $v0, $t0
    /* C588C 002C4C8C C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C5890 002C4C90 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C5894 002C4C94 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C5898 002C4C98 00471021 */  addu       $v0, $v0, $a3
    /* C589C 002C4C9C C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C58A0 002C4CA0 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C58A4 002C4CA4 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C58A8 002C4CA8 00000000 */  nop
    /* C58AC 002C4CAC 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C58B0 002C4CB0 00000000 */  nop
    /* C58B4 002C4CB4 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C58B8 002C4CB8 24A20001 */  addiu      $v0, $a1, 0x1
    /* C58BC 002C4CBC 00402821 */  addu       $a1, $v0, $zero
    /* C58C0 002C4CC0 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C58C4 002C4CC4 00021400 */  sll        $v0, $v0, 16
    /* C58C8 002C4CC8 00021403 */  sra        $v0, $v0, 16
    /* C58CC 002C4CCC 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C58D0 002C4CD0 28420080 */  slti       $v0, $v0, 0x80
    /* C58D4 002C4CD4 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C58D8 002C4CD8 1440FFE6 */  bnez       $v0, .L002C4C74
    /* C58DC 002C4CDC E4820004 */   swc1      $fv1, 0x4($a0)
    /* C58E0 002C4CE0 3C038015 */  lui        $v1, %hi(D_80151AC0)
    /* C58E4 002C4CE4 8C631AC0 */  lw         $v1, %lo(D_80151AC0)($v1)
    /* C58E8 002C4CE8 8C620004 */  lw         $v0, 0x4($v1)
    /* C58EC 002C4CEC 27B00018 */  addiu      $s0, $sp, 0x18
    /* C58F0 002C4CF0 AFA20010 */  sw         $v0, 0x10($sp)
    /* C58F4 002C4CF4 8C620008 */  lw         $v0, 0x8($v1)
    /* C58F8 002C4CF8 02002021 */  addu       $a0, $s0, $zero
    /* C58FC 002C4CFC AFA20014 */  sw         $v0, 0x14($sp)
    /* C5900 002C4D00 8C65000C */  lw         $a1, 0xC($v1)
    /* C5904 002C4D04 8C670000 */  lw         $a3, 0x0($v1)
    /* C5908 002C4D08 0C0B1286 */  jal        mdctFft
    /* C590C 002C4D0C 2406FFFF */   addiu     $a2, $zero, -0x1
    /* C5910 002C4D10 3C078015 */  lui        $a3, %hi(D_801514C0)
    /* C5914 002C4D14 24E714C0 */  addiu      $a3, $a3, %lo(D_801514C0)
    /* C5918 002C4D18 3C068015 */  lui        $a2, %hi(D_801516C0)
    /* C591C 002C4D1C 24C616C0 */  addiu      $a2, $a2, %lo(D_801516C0)
    /* C5920 002C4D20 00002821 */  addu       $a1, $zero, $zero
  .L002C4D24:
    /* C5924 002C4D24 00051400 */  sll        $v0, $a1, 16
    /* C5928 002C4D28 00021403 */  sra        $v0, $v0, 16
    /* C592C 002C4D2C 000220C0 */  sll        $a0, $v0, 3
    /* C5930 002C4D30 00902021 */  addu       $a0, $a0, $s0
    /* C5934 002C4D34 00021080 */  sll        $v0, $v0, 2
    /* C5938 002C4D38 00471821 */  addu       $v1, $v0, $a3
    /* C593C 002C4D3C C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C5940 002C4D40 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C5944 002C4D44 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C5948 002C4D48 00461021 */  addu       $v0, $v0, $a2
    /* C594C 002C4D4C C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C5950 002C4D50 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C5954 002C4D54 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C5958 002C4D58 00000000 */  nop
    /* C595C 002C4D5C 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C5960 002C4D60 00000000 */  nop
    /* C5964 002C4D64 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C5968 002C4D68 24A20001 */  addiu      $v0, $a1, 0x1
    /* C596C 002C4D6C 00402821 */  addu       $a1, $v0, $zero
    /* C5970 002C4D70 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C5974 002C4D74 00021400 */  sll        $v0, $v0, 16
    /* C5978 002C4D78 00021403 */  sra        $v0, $v0, 16
    /* C597C 002C4D7C 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C5980 002C4D80 28420080 */  slti       $v0, $v0, 0x80
    /* C5984 002C4D84 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C5988 002C4D88 1440FFE6 */  bnez       $v0, .L002C4D24
    /* C598C 002C4D8C E4820004 */   swc1      $fv1, 0x4($a0)
    /* C5990 002C4D90 00003821 */  addu       $a3, $zero, $zero
    /* C5994 002C4D94 3C0C8015 */  lui        $t4, %hi(D_801518C0)
    /* C5998 002C4D98 258C18C0 */  addiu      $t4, $t4, %lo(D_801518C0)
    /* C599C 002C4D9C 3C0B8015 */  lui        $t3, %hi(D_801510C0)
    /* C59A0 002C4DA0 256B10C0 */  addiu      $t3, $t3, %lo(D_801510C0)
    /* C59A4 002C4DA4 27A80018 */  addiu      $t0, $sp, 0x18
    /* C59A8 002C4DA8 3C0A8015 */  lui        $t2, %hi(D_801512C0)
    /* C59AC 002C4DAC 254A12C0 */  addiu      $t2, $t2, %lo(D_801512C0)
    /* C59B0 002C4DB0 240900FF */  addiu      $t1, $zero, 0xFF
    /* C59B4 002C4DB4 44804800 */  mtc1       $zero, $ft2f
    /* C59B8 002C4DB8 3C01800D */  lui        $at, %hi(D_800CCF2C)
    /* C59BC 002C4DBC C428CF2C */  lwc1       $ft2, %lo(D_800CCF2C)($at)
    /* C59C0 002C4DC0 3C01800D */  lui        $at, %hi(D_800CCF30)
    /* C59C4 002C4DC4 C427CF30 */  lwc1       $ft1f, %lo(D_800CCF30)($at)
    /* C59C8 002C4DC8 3C01800D */  lui        $at, %hi(D_800CCF30 + 0x4)
    /* C59CC 002C4DCC C426CF34 */  lwc1       $ft1, %lo(D_800CCF30 + 0x4)($at)
    /* C59D0 002C4DD0 00071C00 */  sll        $v1, $a3, 16
  .L002C4DD4:
    /* C59D4 002C4DD4 00031C03 */  sra        $v1, $v1, 16
    /* C59D8 002C4DD8 00032080 */  sll        $a0, $v1, 2
    /* C59DC 002C4DDC 008C3021 */  addu       $a2, $a0, $t4
    /* C59E0 002C4DE0 008B2821 */  addu       $a1, $a0, $t3
    /* C59E4 002C4DE4 000310C0 */  sll        $v0, $v1, 3
    /* C59E8 002C4DE8 34420004 */  ori        $v0, $v0, 0x4
    /* C59EC 002C4DEC C4C40000 */  lwc1       $ft0, 0x0($a2)
    /* C59F0 002C4DF0 C4A50000 */  lwc1       $ft0f, 0x0($a1)
    /* C59F4 002C4DF4 01021021 */  addu       $v0, $t0, $v0
    /* C59F8 002C4DF8 46052042 */  mul.s      $fv0f, $ft0, $ft0f
    /* C59FC 002C4DFC 008A2021 */  addu       $a0, $a0, $t2
    /* C5A00 002C4E00 C4430000 */  lwc1       $fv1f, 0x0($v0)
    /* C5A04 002C4E04 C4800000 */  lwc1       $fv0, 0x0($a0)
    /* C5A08 002C4E08 46001882 */  mul.s      $fv1, $fv1f, $fv0
    /* C5A0C 002C4E0C 00000000 */  nop
    /* C5A10 002C4E10 46002102 */  mul.s      $ft0, $ft0, $fv0
    /* C5A14 002C4E14 00000000 */  nop
    /* C5A18 002C4E18 460518C2 */  mul.s      $fv1f, $fv1f, $ft0f
    /* C5A1C 002C4E1C 46020840 */  add.s      $fv0f, $fv0f, $fv1
    /* C5A20 002C4E20 4601A042 */  mul.s      $fv0f, $fs0, $fv0f
    /* C5A24 002C4E24 000318C0 */  sll        $v1, $v1, 3
    /* C5A28 002C4E28 01031821 */  addu       $v1, $t0, $v1
    /* C5A2C 002C4E2C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C5A30 002C4E30 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C5A34 002C4E34 E4C00000 */  swc1       $fv0, 0x0($a2)
    /* C5A38 002C4E38 4601483E */  c.le.s     $ft2f, $fv0f
    /* C5A3C 002C4E3C 00000000 */  nop
    /* C5A40 002C4E40 45000008 */  bc1f       .L002C4E64
    /* C5A44 002C4E44 46000806 */   mov.s     $fv0, $fv0f
    /* C5A48 002C4E48 46080800 */  add.s      $fv0, $fv0f, $ft2
    /* C5A4C 002C4E4C 4600383C */  c.lt.s     $ft1f, $fv0
    /* C5A50 002C4E50 00000000 */  nop
    /* C5A54 002C4E54 45030008 */  bc1tl      .L002C4E78
    /* C5A58 002C4E58 46003806 */   mov.s     $fv0, $ft1f
    /* C5A5C 002C4E5C 080B139E */  j          .L002C4E78
    /* C5A60 002C4E60 00000000 */   nop
  .L002C4E64:
    /* C5A64 002C4E64 46080001 */  sub.s      $fv0, $fv0, $ft2
    /* C5A68 002C4E68 4606003C */  c.lt.s     $fv0, $ft1
    /* C5A6C 002C4E6C 00000000 */  nop
    /* C5A70 002C4E70 45030001 */  bc1tl      .L002C4E78
    /* C5A74 002C4E74 46003006 */   mov.s     $fv0, $ft1
  .L002C4E78:
    /* C5A78 002C4E78 4600028D */  trunc.w.s  $ft3, $fv0
    /* C5A7C 002C4E7C 44035000 */  mfc1       $v1, $ft3
    /* C5A80 002C4E80 4604A102 */  mul.s      $ft0, $fs0, $ft0
    /* C5A84 002C4E84 00071400 */  sll        $v0, $a3, 16
    /* C5A88 002C4E88 00021383 */  sra        $v0, $v0, 14
    /* C5A8C 002C4E8C 00521021 */  addu       $v0, $v0, $s2
    /* C5A90 002C4E90 A4430000 */  sh         $v1, 0x0($v0)
    /* C5A94 002C4E94 4604483E */  c.le.s     $ft2f, $ft0
    /* C5A98 002C4E98 00000000 */  nop
    /* C5A9C 002C4E9C 45000008 */  bc1f       .L002C4EC0
    /* C5AA0 002C4EA0 46002006 */   mov.s     $fv0, $ft0
    /* C5AA4 002C4EA4 46082100 */  add.s      $ft0, $ft0, $ft2
    /* C5AA8 002C4EA8 4604383C */  c.lt.s     $ft1f, $ft0
    /* C5AAC 002C4EAC 00000000 */  nop
    /* C5AB0 002C4EB0 45030008 */  bc1tl      .L002C4ED4
    /* C5AB4 002C4EB4 46003906 */   mov.s     $ft0, $ft1f
    /* C5AB8 002C4EB8 080B13B5 */  j          .L002C4ED4
    /* C5ABC 002C4EBC 00000000 */   nop
  .L002C4EC0:
    /* C5AC0 002C4EC0 46080101 */  sub.s      $ft0, $fv0, $ft2
    /* C5AC4 002C4EC4 4606203C */  c.lt.s     $ft0, $ft1
    /* C5AC8 002C4EC8 00000000 */  nop
    /* C5ACC 002C4ECC 45030001 */  bc1tl      .L002C4ED4
    /* C5AD0 002C4ED0 46003106 */   mov.s     $ft0, $ft1
  .L002C4ED4:
    /* C5AD4 002C4ED4 4600228D */  trunc.w.s  $ft3, $ft0
    /* C5AD8 002C4ED8 44035000 */  mfc1       $v1, $ft3
    /* C5ADC 002C4EDC 00071400 */  sll        $v0, $a3, 16
    /* C5AE0 002C4EE0 000213C3 */  sra        $v0, $v0, 15
    /* C5AE4 002C4EE4 01221023 */  subu       $v0, $t1, $v0
    /* C5AE8 002C4EE8 00021040 */  sll        $v0, $v0, 1
    /* C5AEC 002C4EEC 00521021 */  addu       $v0, $v0, $s2
    /* C5AF0 002C4EF0 A4430000 */  sh         $v1, 0x0($v0)
    /* C5AF4 002C4EF4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C5AF8 002C4EF8 00403821 */  addu       $a3, $v0, $zero
    /* C5AFC 002C4EFC 00021400 */  sll        $v0, $v0, 16
    /* C5B00 002C4F00 00021403 */  sra        $v0, $v0, 16
    /* C5B04 002C4F04 28420080 */  slti       $v0, $v0, 0x80
    /* C5B08 002C4F08 5440FFB2 */  bnel       $v0, $zero, .L002C4DD4
    /* C5B0C 002C4F0C 00071C00 */   sll       $v1, $a3, 16
    /* C5B10 002C4F10 8FBF0824 */  lw         $ra, 0x824($sp)
    /* C5B14 002C4F14 8FB20820 */  lw         $s2, 0x820($sp)
    /* C5B18 002C4F18 8FB1081C */  lw         $s1, 0x81C($sp)
    /* C5B1C 002C4F1C 8FB00818 */  lw         $s0, 0x818($sp)
    /* C5B20 002C4F20 D7B40828 */  ldc1       $fs0, 0x828($sp)
    /* C5B24 002C4F24 03E00008 */  jr         $ra
    /* C5B28 002C4F28 27BD0830 */   addiu     $sp, $sp, 0x830
endlabel adecImdctFrame
