.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB4C0-0xBB864 (VRAM 0x002BA8C0) */
glabel func_002BA8C0
    /* BB4C0 002BA8C0 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* BB4C4 002BA8C4 AFB40030 */  sw         $s4, 0x30($sp)
    /* BB4C8 002BA8C8 00A0A021 */  addu       $s4, $a1, $zero
    /* BB4CC 002BA8CC AFB7003C */  sw         $s7, 0x3C($sp)
    /* BB4D0 002BA8D0 00C0B821 */  addu       $s7, $a2, $zero
    /* BB4D4 002BA8D4 AFB50034 */  sw         $s5, 0x34($sp)
    /* BB4D8 002BA8D8 00E0A821 */  addu       $s5, $a3, $zero
    /* BB4DC 002BA8DC AFB20028 */  sw         $s2, 0x28($sp)
    /* BB4E0 002BA8E0 AFB3002C */  sw         $s3, 0x2C($sp)
    /* BB4E4 002BA8E4 00809821 */  addu       $s3, $a0, $zero
    /* BB4E8 002BA8E8 AFBF0044 */  sw         $ra, 0x44($sp)
    /* BB4EC 002BA8EC AFBE0040 */  sw         $fp, 0x40($sp)
    /* BB4F0 002BA8F0 AFB60038 */  sw         $s6, 0x38($sp)
    /* BB4F4 002BA8F4 AFB10024 */  sw         $s1, 0x24($sp)
    /* BB4F8 002BA8F8 AFB00020 */  sw         $s0, 0x20($sp)
    /* BB4FC 002BA8FC 8E700000 */  lw         $s0, 0x0($s3)
    /* BB500 002BA900 8FB10058 */  lw         $s1, 0x58($sp)
    /* BB504 002BA904 16000007 */  bnez       $s0, .L002BA924
    /* BB508 002BA908 00009021 */   addu      $s2, $zero, $zero
    /* BB50C 002BA90C 3C04800D */  lui        $a0, %hi(D_800CC9D0)
    /* BB510 002BA910 2484C9D0 */  addiu      $a0, $a0, %lo(D_800CC9D0)
    /* BB514 002BA914 3C05800D */  lui        $a1, %hi(D_800CC9D4)
    /* BB518 002BA918 24A5C9D4 */  addiu      $a1, $a1, %lo(D_800CC9D4)
    /* BB51C 002BA91C 0C0AFF50 */  jal        __assert
    /* BB520 002BA920 2406004B */   addiu     $a2, $zero, 0x4B
  .L002BA924:
    /* BB524 002BA924 02002021 */  addu       $a0, $s0, $zero
    /* BB528 002BA928 02802821 */  addu       $a1, $s4, $zero
    /* BB52C 002BA92C 02E03021 */  addu       $a2, $s7, $zero
    /* BB530 002BA930 02A03821 */  addu       $a3, $s5, $zero
    /* BB534 002BA934 0000B021 */  addu       $s6, $zero, $zero
    /* BB538 002BA938 AFB10010 */  sw         $s1, 0x10($sp)
    /* BB53C 002BA93C 8C820004 */  lw         $v0, 0x4($a0)
    /* BB540 002BA940 24150140 */  addiu      $s5, $zero, 0x140
    /* BB544 002BA944 0040F809 */  jalr       $v0
    /* BB548 002BA948 A7A0001E */   sh        $zero, 0x1E($sp)
    /* BB54C 002BA94C 00408821 */  addu       $s1, $v0, $zero
    /* BB550 002BA950 02204021 */  addu       $t0, $s1, $zero
    /* BB554 002BA954 26310008 */  addiu      $s1, $s1, 0x8
    /* BB558 002BA958 02204821 */  addu       $t1, $s1, $zero
    /* BB55C 002BA95C 26310008 */  addiu      $s1, $s1, 0x8
    /* BB560 002BA960 3C0B0C00 */  lui        $t3, (0xC00DA83 >> 16)
    /* BB564 002BA964 356BDA83 */  ori        $t3, $t3, (0xC00DA83 & 0xFFFF)
    /* BB568 002BA968 3C0A06C0 */  lui        $t2, (0x6C006C0 >> 16)
    /* BB56C 002BA96C 354A06C0 */  ori        $t2, $t2, (0x6C006C0 & 0xFFFF)
    /* BB570 002BA970 02201821 */  addu       $v1, $s1, $zero
    /* BB574 002BA974 26310008 */  addiu      $s1, $s1, 0x8
    /* BB578 002BA978 3C070C00 */  lui        $a3, (0xC005A82 >> 16)
    /* BB57C 002BA97C 34E75A82 */  ori        $a3, $a3, (0xC005A82 & 0xFFFF)
    /* BB580 002BA980 3C050800 */  lui        $a1, (0x80006C0 >> 16)
    /* BB584 002BA984 34A506C0 */  ori        $a1, $a1, (0x80006C0 & 0xFFFF)
    /* BB588 002BA988 02602021 */  addu       $a0, $s3, $zero
    /* BB58C 002BA98C 240606C0 */  addiu      $a2, $zero, 0x6C0
    /* BB590 002BA990 3C020800 */  lui        $v0, (0x8000000 >> 16)
    /* BB594 002BA994 00178040 */  sll        $s0, $s7, 1
    /* BB598 002BA998 AD020000 */  sw         $v0, 0x0($t0)
    /* BB59C 002BA99C 3202FFFF */  andi       $v0, $s0, 0xFFFF
    /* BB5A0 002BA9A0 AD020004 */  sw         $v0, 0x4($t0)
    /* BB5A4 002BA9A4 AD2B0000 */  sw         $t3, 0x0($t1)
    /* BB5A8 002BA9A8 AD2A0004 */  sw         $t2, 0x4($t1)
    /* BB5AC 002BA9AC AC670000 */  sw         $a3, 0x0($v1)
    /* BB5B0 002BA9B0 AC650004 */  sw         $a1, 0x4($v1)
    /* BB5B4 002BA9B4 AFB10010 */  sw         $s1, 0x10($sp)
    /* BB5B8 002BA9B8 8E650018 */  lw         $a1, 0x18($s3)
    /* BB5BC 002BA9BC 0C0AEC0E */  jal        func_002BB038
    /* BB5C0 002BA9C0 02E03821 */   addu      $a3, $s7, $zero
    /* BB5C4 002BA9C4 00408821 */  addu       $s1, $v0, $zero
    /* BB5C8 002BA9C8 02201821 */  addu       $v1, $s1, $zero
    /* BB5CC 002BA9CC 3C020200 */  lui        $v0, (0x2000800 >> 16)
    /* BB5D0 002BA9D0 34420800 */  ori        $v0, $v0, (0x2000800 & 0xFFFF)
    /* BB5D4 002BA9D4 AC620000 */  sw         $v0, 0x0($v1)
    /* BB5D8 002BA9D8 AC700004 */  sw         $s0, 0x4($v1)
    /* BB5DC 002BA9DC 92620024 */  lbu        $v0, 0x24($s3)
    /* BB5E0 002BA9E0 0242102A */  slt        $v0, $s2, $v0
    /* BB5E4 002BA9E4 1040007B */  beqz       $v0, .L002BABD4
    /* BB5E8 002BA9E8 26310008 */   addiu     $s1, $s1, 0x8
  .L002BA9EC:
    /* BB5EC 002BA9EC 97AC001E */  lhu        $t4, 0x1E($sp)
    /* BB5F0 002BA9F0 8E640018 */  lw         $a0, 0x18($s3)
    /* BB5F4 002BA9F4 000C1400 */  sll        $v0, $t4, 16
    /* BB5F8 002BA9F8 00021403 */  sra        $v0, $v0, 16
    /* BB5FC 002BA9FC 00021880 */  sll        $v1, $v0, 2
    /* BB600 002BAA00 00621821 */  addu       $v1, $v1, $v0
    /* BB604 002BAA04 8E620020 */  lw         $v0, 0x20($s3)
    /* BB608 002BAA08 000318C0 */  sll        $v1, $v1, 3
    /* BB60C 002BAA0C 00438021 */  addu       $s0, $v0, $v1
    /* BB610 002BAA10 8E030000 */  lw         $v1, 0x0($s0)
    /* BB614 002BAA14 8E020004 */  lw         $v0, 0x4($s0)
    /* BB618 002BAA18 00031840 */  sll        $v1, $v1, 1
    /* BB61C 002BAA1C 0083A023 */  subu       $s4, $a0, $v1
    /* BB620 002BAA20 00021040 */  sll        $v0, $v0, 1
    /* BB624 002BAA24 16920005 */  bne        $s4, $s2, .L002BAA3C
    /* BB628 002BAA28 0082F023 */   subu      $fp, $a0, $v0
    /* BB62C 002BAA2C 02A01021 */  addu       $v0, $s5, $zero
    /* BB630 002BAA30 02C0A821 */  addu       $s5, $s6, $zero
    /* BB634 002BAA34 080AEA97 */  j          .L002BAA5C
    /* BB638 002BAA38 0040B021 */   addu      $s6, $v0, $zero
  .L002BAA3C:
    /* BB63C 002BAA3C AFB10010 */  sw         $s1, 0x10($sp)
    /* BB640 002BAA40 02602021 */  addu       $a0, $s3, $zero
    /* BB644 002BAA44 02802821 */  addu       $a1, $s4, $zero
    /* BB648 002BAA48 00163400 */  sll        $a2, $s6, 16
    /* BB64C 002BAA4C 00063403 */  sra        $a2, $a2, 16
    /* BB650 002BAA50 0C0AEC6F */  jal        func_002BB1BC
    /* BB654 002BAA54 02E03821 */   addu      $a3, $s7, $zero
    /* BB658 002BAA58 00408821 */  addu       $s1, $v0, $zero
  .L002BAA5C:
    /* BB65C 002BAA5C 02602021 */  addu       $a0, $s3, $zero
    /* BB660 002BAA60 02002821 */  addu       $a1, $s0, $zero
    /* BB664 002BAA64 00151400 */  sll        $v0, $s5, 16
    /* BB668 002BAA68 00029403 */  sra        $s2, $v0, 16
    /* BB66C 002BAA6C 02403021 */  addu       $a2, $s2, $zero
    /* BB670 002BAA70 02E03821 */  addu       $a3, $s7, $zero
    /* BB674 002BAA74 0C0AEB90 */  jal        func_002BAE40
    /* BB678 002BAA78 AFB10010 */   sw        $s1, 0x10($sp)
    /* BB67C 002BAA7C 86030008 */  lh         $v1, 0x8($s0)
    /* BB680 002BAA80 10600016 */  beqz       $v1, .L002BAADC
    /* BB684 002BAA84 00408821 */   addu      $s1, $v0, $zero
    /* BB688 002BAA88 02202821 */  addu       $a1, $s1, $zero
    /* BB68C 002BAA8C 00161400 */  sll        $v0, $s6, 16
    /* BB690 002BAA90 3244FFFF */  andi       $a0, $s2, 0xFFFF
    /* BB694 002BAA94 00441025 */  or         $v0, $v0, $a0
    /* BB698 002BAA98 96030008 */  lhu        $v1, 0x8($s0)
    /* BB69C 002BAA9C 3C0C0C00 */  lui        $t4, (0xC000000 >> 16)
    /* BB6A0 002BAAA0 ACA20004 */  sw         $v0, 0x4($a1)
    /* BB6A4 002BAAA4 006C1825 */  or         $v1, $v1, $t4
    /* BB6A8 002BAAA8 ACA30000 */  sw         $v1, 0x0($a1)
    /* BB6AC 002BAAAC 8E020024 */  lw         $v0, 0x24($s0)
    /* BB6B0 002BAAB0 1440000A */  bnez       $v0, .L002BAADC
    /* BB6B4 002BAAB4 26310008 */   addiu     $s1, $s1, 0x8
    /* BB6B8 002BAAB8 8E020020 */  lw         $v0, 0x20($s0)
    /* BB6BC 002BAABC 14400007 */  bnez       $v0, .L002BAADC
    /* BB6C0 002BAAC0 02602021 */   addu      $a0, $s3, $zero
    /* BB6C4 002BAAC4 AFB10010 */  sw         $s1, 0x10($sp)
    /* BB6C8 002BAAC8 03C02821 */  addu       $a1, $fp, $zero
    /* BB6CC 002BAACC 02403021 */  addu       $a2, $s2, $zero
    /* BB6D0 002BAAD0 0C0AEC0E */  jal        func_002BB038
    /* BB6D4 002BAAD4 02E03821 */   addu      $a3, $s7, $zero
    /* BB6D8 002BAAD8 00408821 */  addu       $s1, $v0, $zero
  .L002BAADC:
    /* BB6DC 002BAADC 8602000A */  lh         $v0, 0xA($s0)
    /* BB6E0 002BAAE0 10400012 */  beqz       $v0, .L002BAB2C
    /* BB6E4 002BAAE4 02204821 */   addu      $t1, $s1, $zero
    /* BB6E8 002BAAE8 26310008 */  addiu      $s1, $s1, 0x8
    /* BB6EC 002BAAEC 02602021 */  addu       $a0, $s3, $zero
    /* BB6F0 002BAAF0 02802821 */  addu       $a1, $s4, $zero
    /* BB6F4 002BAAF4 00163400 */  sll        $a2, $s6, 16
    /* BB6F8 002BAAF8 00063403 */  sra        $a2, $a2, 16
    /* BB6FC 002BAAFC 02E03821 */  addu       $a3, $s7, $zero
    /* BB700 002BAB00 00151400 */  sll        $v0, $s5, 16
    /* BB704 002BAB04 30C8FFFF */  andi       $t0, $a2, 0xFFFF
    /* BB708 002BAB08 00481025 */  or         $v0, $v0, $t0
    /* BB70C 002BAB0C 9603000A */  lhu        $v1, 0xA($s0)
    /* BB710 002BAB10 3C0C0C00 */  lui        $t4, (0xC000000 >> 16)
    /* BB714 002BAB14 AD220004 */  sw         $v0, 0x4($t1)
    /* BB718 002BAB18 006C1825 */  or         $v1, $v1, $t4
    /* BB71C 002BAB1C AD230000 */  sw         $v1, 0x0($t1)
    /* BB720 002BAB20 0C0AEC0E */  jal        func_002BB038
    /* BB724 002BAB24 AFB10010 */   sw        $s1, 0x10($sp)
    /* BB728 002BAB28 00408821 */  addu       $s1, $v0, $zero
  .L002BAB2C:
    /* BB72C 002BAB2C 8E040020 */  lw         $a0, 0x20($s0)
    /* BB730 002BAB30 10800006 */  beqz       $a0, .L002BAB4C
    /* BB734 002BAB34 00152C00 */   sll       $a1, $s5, 16
    /* BB738 002BAB38 00052C03 */  sra        $a1, $a1, 16
    /* BB73C 002BAB3C 02E03021 */  addu       $a2, $s7, $zero
    /* BB740 002BAB40 0C0AECCB */  jal        func_002BB32C
    /* BB744 002BAB44 02203821 */   addu      $a3, $s1, $zero
    /* BB748 002BAB48 00408821 */  addu       $s1, $v0, $zero
  .L002BAB4C:
    /* BB74C 002BAB4C 8E020024 */  lw         $v0, 0x24($s0)
    /* BB750 002BAB50 14400008 */  bnez       $v0, .L002BAB74
    /* BB754 002BAB54 02602021 */   addu      $a0, $s3, $zero
    /* BB758 002BAB58 AFB10010 */  sw         $s1, 0x10($sp)
    /* BB75C 002BAB5C 03C02821 */  addu       $a1, $fp, $zero
    /* BB760 002BAB60 00153400 */  sll        $a2, $s5, 16
    /* BB764 002BAB64 00063403 */  sra        $a2, $a2, 16
    /* BB768 002BAB68 0C0AEC0E */  jal        func_002BB038
    /* BB76C 002BAB6C 02E03821 */   addu      $a3, $s7, $zero
    /* BB770 002BAB70 00408821 */  addu       $s1, $v0, $zero
  .L002BAB74:
    /* BB774 002BAB74 8602000C */  lh         $v0, 0xC($s0)
    /* BB778 002BAB78 10400009 */  beqz       $v0, .L002BABA0
    /* BB77C 002BAB7C 02201021 */   addu      $v0, $s1, $zero
    /* BB780 002BAB80 26310008 */  addiu      $s1, $s1, 0x8
    /* BB784 002BAB84 00151C00 */  sll        $v1, $s5, 16
    /* BB788 002BAB88 34630800 */  ori        $v1, $v1, 0x800
    /* BB78C 002BAB8C 9604000C */  lhu        $a0, 0xC($s0)
    /* BB790 002BAB90 3C0C0C00 */  lui        $t4, (0xC000000 >> 16)
    /* BB794 002BAB94 AC430004 */  sw         $v1, 0x4($v0)
    /* BB798 002BAB98 008C2025 */  or         $a0, $a0, $t4
    /* BB79C 002BAB9C AC440000 */  sw         $a0, 0x0($v0)
  .L002BABA0:
    /* BB7A0 002BABA0 97AC001E */  lhu        $t4, 0x1E($sp)
    /* BB7A4 002BABA4 25830001 */  addiu      $v1, $t4, 0x1
    /* BB7A8 002BABA8 A7A3001E */  sh         $v1, 0x1E($sp)
    /* BB7AC 002BABAC 00031C00 */  sll        $v1, $v1, 16
    /* BB7B0 002BABB0 8E020004 */  lw         $v0, 0x4($s0)
    /* BB7B4 002BABB4 8E640018 */  lw         $a0, 0x18($s3)
    /* BB7B8 002BABB8 00021040 */  sll        $v0, $v0, 1
    /* BB7BC 002BABBC 00829021 */  addu       $s2, $a0, $v0
    /* BB7C0 002BABC0 92620024 */  lbu        $v0, 0x24($s3)
    /* BB7C4 002BABC4 00031C03 */  sra        $v1, $v1, 16
    /* BB7C8 002BABC8 0062182A */  slt        $v1, $v1, $v0
    /* BB7CC 002BABCC 1460FF87 */  bnez       $v1, .L002BA9EC
    /* BB7D0 002BABD0 00000000 */   nop
  .L002BABD4:
    /* BB7D4 002BABD4 00173040 */  sll        $a2, $s7, 1
    /* BB7D8 002BABD8 8E620018 */  lw         $v0, 0x18($s3)
    /* BB7DC 002BABDC 8E63001C */  lw         $v1, 0x1C($s3)
    /* BB7E0 002BABE0 00462021 */  addu       $a0, $v0, $a2
    /* BB7E4 002BABE4 8E620014 */  lw         $v0, 0x14($s3)
    /* BB7E8 002BABE8 00031840 */  sll        $v1, $v1, 1
    /* BB7EC 002BABEC 00431021 */  addu       $v0, $v0, $v1
    /* BB7F0 002BABF0 0044102B */  sltu       $v0, $v0, $a0
    /* BB7F4 002BABF4 10400003 */  beqz       $v0, .L002BAC04
    /* BB7F8 002BABF8 AE640018 */   sw        $a0, 0x18($s3)
    /* BB7FC 002BABFC 00831023 */  subu       $v0, $a0, $v1
    /* BB800 002BAC00 AE620018 */  sw         $v0, 0x18($s3)
  .L002BAC04:
    /* BB804 002BAC04 26220008 */  addiu      $v0, $s1, 0x8
    /* BB808 002BAC08 02202821 */  addu       $a1, $s1, $zero
    /* BB80C 002BAC0C 24030800 */  addiu      $v1, $zero, 0x800
    /* BB810 002BAC10 00031C00 */  sll        $v1, $v1, 16
    /* BB814 002BAC14 00031C02 */  srl        $v1, $v1, 16
    /* BB818 002BAC18 3C040A00 */  lui        $a0, (0xA000000 >> 16)
    /* BB81C 002BAC1C 00641825 */  or         $v1, $v1, $a0
    /* BB820 002BAC20 ACA30000 */  sw         $v1, 0x0($a1)
    /* BB824 002BAC24 30C3FFFF */  andi       $v1, $a2, 0xFFFF
    /* BB828 002BAC28 3C0406C0 */  lui        $a0, (0x6C00000 >> 16)
    /* BB82C 002BAC2C 00641825 */  or         $v1, $v1, $a0
    /* BB830 002BAC30 ACA30004 */  sw         $v1, 0x4($a1)
    /* BB834 002BAC34 8FBF0044 */  lw         $ra, 0x44($sp)
    /* BB838 002BAC38 8FBE0040 */  lw         $fp, 0x40($sp)
    /* BB83C 002BAC3C 8FB7003C */  lw         $s7, 0x3C($sp)
    /* BB840 002BAC40 8FB60038 */  lw         $s6, 0x38($sp)
    /* BB844 002BAC44 8FB50034 */  lw         $s5, 0x34($sp)
    /* BB848 002BAC48 8FB40030 */  lw         $s4, 0x30($sp)
    /* BB84C 002BAC4C 8FB3002C */  lw         $s3, 0x2C($sp)
    /* BB850 002BAC50 8FB20028 */  lw         $s2, 0x28($sp)
    /* BB854 002BAC54 8FB10024 */  lw         $s1, 0x24($sp)
    /* BB858 002BAC58 8FB00020 */  lw         $s0, 0x20($sp)
    /* BB85C 002BAC5C 03E00008 */  jr         $ra
    /* BB860 002BAC60 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel func_002BA8C0
