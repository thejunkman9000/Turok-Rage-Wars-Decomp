.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC4588-0xC4794 (VRAM 0x002C3988) */
glabel func_002C3988
    /* C4588 002C3988 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* C458C 002C398C AFB10014 */  sw         $s1, 0x14($sp)
    /* C4590 002C3990 8FB10040 */  lw         $s1, 0x40($sp)
    /* C4594 002C3994 AFB50024 */  sw         $s5, 0x24($sp)
    /* C4598 002C3998 00C0A821 */  addu       $s5, $a2, $zero
    /* C459C 002C399C AFB40020 */  sw         $s4, 0x20($sp)
    /* C45A0 002C39A0 0080A021 */  addu       $s4, $a0, $zero
    /* C45A4 002C39A4 AFBF002C */  sw         $ra, 0x2C($sp)
    /* C45A8 002C39A8 AFB60028 */  sw         $s6, 0x28($sp)
    /* C45AC 002C39AC AFB3001C */  sw         $s3, 0x1C($sp)
    /* C45B0 002C39B0 AFB20018 */  sw         $s2, 0x18($sp)
    /* C45B4 002C39B4 AFB00010 */  sw         $s0, 0x10($sp)
    /* C45B8 002C39B8 8E820028 */  lw         $v0, 0x28($s4)
    /* C45BC 002C39BC 84B30000 */  lh         $s3, 0x0($a1)
    /* C45C0 002C39C0 8C420000 */  lw         $v0, 0x0($v0)
    /* C45C4 002C39C4 14400016 */  bnez       $v0, .L002C3A20
    /* C45C8 002C39C8 02202821 */   addu      $a1, $s1, $zero
    /* C45CC 002C39CC 3C0300FF */  lui        $v1, (0xFFFFFF >> 16)
    /* C45D0 002C39D0 3463FFFF */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* C45D4 002C39D4 26220008 */  addiu      $v0, $s1, 0x8
    /* C45D8 002C39D8 02631824 */  and        $v1, $s3, $v1
    /* C45DC 002C39DC 3C040200 */  lui        $a0, (0x2000000 >> 16)
    /* C45E0 002C39E0 00641825 */  or         $v1, $v1, $a0
    /* C45E4 002C39E4 ACA30000 */  sw         $v1, 0x0($a1)
    /* C45E8 002C39E8 00151840 */  sll        $v1, $s5, 1
    /* C45EC 002C39EC 080B0EDB */  j          .L002C3B6C
    /* C45F0 002C39F0 ACA30004 */   sw        $v1, 0x4($a1)
  .L002C39F4:
    /* C45F4 002C39F4 3C0400FF */  lui        $a0, (0xFFFFFF >> 16)
    /* C45F8 002C39F8 3484FFFF */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* C45FC 002C39FC 26220008 */  addiu      $v0, $s1, 0x8
    /* C4600 002C3A00 02202821 */  addu       $a1, $s1, $zero
    /* C4604 002C3A04 02642024 */  and        $a0, $s3, $a0
    /* C4608 002C3A08 3C030200 */  lui        $v1, (0x2000000 >> 16)
    /* C460C 002C3A0C 00832025 */  or         $a0, $a0, $v1
    /* C4610 002C3A10 00151840 */  sll        $v1, $s5, 1
    /* C4614 002C3A14 ACA40000 */  sw         $a0, 0x0($a1)
    /* C4618 002C3A18 080B0EDB */  j          .L002C3B6C
    /* C461C 002C3A1C ACA30004 */   sw        $v1, 0x4($a1)
  .L002C3A20:
    /* C4620 002C3A20 12A00051 */  beqz       $s5, .L002C3B68
    /* C4624 002C3A24 2630FFFC */   addiu     $s0, $s1, -0x4
    /* C4628 002C3A28 3C16800E */  lui        $s6, %hi(D_800D9360)
    /* C462C 002C3A2C 26D69360 */  addiu      $s6, $s6, %lo(D_800D9360)
  .L002C3A30:
    /* C4630 002C3A30 8E820038 */  lw         $v0, 0x38($s4)
    /* C4634 002C3A34 1440000B */  bnez       $v0, .L002C3A64
    /* C4638 002C3A38 02A09021 */   addu      $s2, $s5, $zero
    /* C463C 002C3A3C 0C0B1497 */  jal        func_002C525C
    /* C4640 002C3A40 00000000 */   nop
    /* C4644 002C3A44 3C01800E */  lui        $at, %hi(D_800D9360)
    /* C4648 002C3A48 AC229360 */  sw         $v0, %lo(D_800D9360)($at)
    /* C464C 002C3A4C 1040FFE9 */  beqz       $v0, .L002C39F4
    /* C4650 002C3A50 00402021 */   addu      $a0, $v0, $zero
    /* C4654 002C3A54 0C0B08DC */  jal        osWritebackDCache
    /* C4658 002C3A58 24050200 */   addiu     $a1, $zero, 0x200
    /* C465C 002C3A5C 24020100 */  addiu      $v0, $zero, 0x100
    /* C4660 002C3A60 AE820038 */  sw         $v0, 0x38($s4)
  .L002C3A64:
    /* C4664 002C3A64 8E830038 */  lw         $v1, 0x38($s4)
    /* C4668 002C3A68 0075102A */  slt        $v0, $v1, $s5
    /* C466C 002C3A6C 54400001 */  bnel       $v0, $zero, .L002C3A74
    /* C4670 002C3A70 00609021 */   addu      $s2, $v1, $zero
  .L002C3A74:
    /* C4674 002C3A74 3C02800E */  lui        $v0, %hi(D_800D9360)
    /* C4678 002C3A78 8C429360 */  lw         $v0, %lo(D_800D9360)($v0)
    /* C467C 002C3A7C 00122040 */  sll        $a0, $s2, 1
    /* C4680 002C3A80 32630007 */  andi       $v1, $s3, 0x7
    /* C4684 002C3A84 30460007 */  andi       $a2, $v0, 0x7
    /* C4688 002C3A88 10600004 */  beqz       $v1, .L002C3A9C
    /* C468C 002C3A8C 00862021 */   addu      $a0, $a0, $a2
    /* C4690 002C3A90 24020008 */  addiu      $v0, $zero, 0x8
    /* C4694 002C3A94 080B0EA8 */  j          .L002C3AA0
    /* C4698 002C3A98 00432823 */   subu      $a1, $v0, $v1
  .L002C3A9C:
    /* C469C 002C3A9C 00002821 */  addu       $a1, $zero, $zero
  .L002C3AA0:
    /* C46A0 002C3AA0 26100008 */  addiu      $s0, $s0, 0x8
    /* C46A4 002C3AA4 02651021 */  addu       $v0, $s3, $a1
    /* C46A8 002C3AA8 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C46AC 002C3AAC 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* C46B0 002C3AB0 00431025 */  or         $v0, $v0, $v1
    /* C46B4 002C3AB4 AE02FFFC */  sw         $v0, -0x4($s0)
    /* C46B8 002C3AB8 30820007 */  andi       $v0, $a0, 0x7
    /* C46BC 002C3ABC 2442FFF8 */  addiu      $v0, $v0, -0x8
    /* C46C0 002C3AC0 00821023 */  subu       $v0, $a0, $v0
    /* C46C4 002C3AC4 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C46C8 002C3AC8 AE020000 */  sw         $v0, 0x0($s0)
    /* C46CC 002C3ACC 26100008 */  addiu      $s0, $s0, 0x8
    /* C46D0 002C3AD0 26310010 */  addiu      $s1, $s1, 0x10
    /* C46D4 002C3AD4 3C041FFF */  lui        $a0, (0x1FFFFFFF >> 16)
    /* C46D8 002C3AD8 3484FFFF */  ori        $a0, $a0, (0x1FFFFFFF & 0xFFFF)
    /* C46DC 002C3ADC 3C03800E */  lui        $v1, %hi(D_800D9360)
    /* C46E0 002C3AE0 8C639360 */  lw         $v1, %lo(D_800D9360)($v1)
    /* C46E4 002C3AE4 3C020400 */  lui        $v0, (0x4000000 >> 16)
    /* C46E8 002C3AE8 AE02FFFC */  sw         $v0, -0x4($s0)
    /* C46EC 002C3AEC 00641824 */  and        $v1, $v1, $a0
    /* C46F0 002C3AF0 00661823 */  subu       $v1, $v1, $a2
    /* C46F4 002C3AF4 14C00003 */  bnez       $a2, .L002C3B04
    /* C46F8 002C3AF8 AE030000 */   sw        $v1, 0x0($s0)
    /* C46FC 002C3AFC 50A00011 */  beql       $a1, $zero, .L002C3B44
    /* C4700 002C3B00 02B2A823 */   subu      $s5, $s5, $s2
  .L002C3B04:
    /* C4704 002C3B04 26100008 */  addiu      $s0, $s0, 0x8
    /* C4708 002C3B08 26310008 */  addiu      $s1, $s1, 0x8
    /* C470C 002C3B0C 3C0300FF */  lui        $v1, (0xFFFFFF >> 16)
    /* C4710 002C3B10 3463FFFF */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* C4714 002C3B14 02661021 */  addu       $v0, $s3, $a2
    /* C4718 002C3B18 00451021 */  addu       $v0, $v0, $a1
    /* C471C 002C3B1C 00431024 */  and        $v0, $v0, $v1
    /* C4720 002C3B20 3C030A00 */  lui        $v1, (0xA000000 >> 16)
    /* C4724 002C3B24 00431025 */  or         $v0, $v0, $v1
    /* C4728 002C3B28 00131C00 */  sll        $v1, $s3, 16
    /* C472C 002C3B2C AE02FFFC */  sw         $v0, -0x4($s0)
    /* C4730 002C3B30 00121040 */  sll        $v0, $s2, 1
    /* C4734 002C3B34 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C4738 002C3B38 00621825 */  or         $v1, $v1, $v0
    /* C473C 002C3B3C AE030000 */  sw         $v1, 0x0($s0)
    /* C4740 002C3B40 02B2A823 */  subu       $s5, $s5, $s2
  .L002C3B44:
    /* C4744 002C3B44 00121040 */  sll        $v0, $s2, 1
    /* C4748 002C3B48 02629821 */  addu       $s3, $s3, $v0
    /* C474C 002C3B4C 8EC30000 */  lw         $v1, 0x0($s6)
    /* C4750 002C3B50 8E840038 */  lw         $a0, 0x38($s4)
    /* C4754 002C3B54 00621821 */  addu       $v1, $v1, $v0
    /* C4758 002C3B58 00922023 */  subu       $a0, $a0, $s2
    /* C475C 002C3B5C AEC30000 */  sw         $v1, 0x0($s6)
    /* C4760 002C3B60 16A0FFB3 */  bnez       $s5, .L002C3A30
    /* C4764 002C3B64 AE840038 */   sw        $a0, 0x38($s4)
  .L002C3B68:
    /* C4768 002C3B68 02201021 */  addu       $v0, $s1, $zero
  .L002C3B6C:
    /* C476C 002C3B6C 8FBF002C */  lw         $ra, 0x2C($sp)
    /* C4770 002C3B70 8FB60028 */  lw         $s6, 0x28($sp)
    /* C4774 002C3B74 8FB50024 */  lw         $s5, 0x24($sp)
    /* C4778 002C3B78 8FB40020 */  lw         $s4, 0x20($sp)
    /* C477C 002C3B7C 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C4780 002C3B80 8FB20018 */  lw         $s2, 0x18($sp)
    /* C4784 002C3B84 8FB10014 */  lw         $s1, 0x14($sp)
    /* C4788 002C3B88 8FB00010 */  lw         $s0, 0x10($sp)
    /* C478C 002C3B8C 03E00008 */  jr         $ra
    /* C4790 002C3B90 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002C3988
