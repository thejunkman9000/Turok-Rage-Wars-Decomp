.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAF6B4-0xAFA48 (VRAM 0x002AEAB4) */
glabel dbgLinkSendBlock
    /* AF6B4 002AEAB4 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* AF6B8 002AEAB8 AFB10014 */  sw         $s1, 0x14($sp)
    /* AF6BC 002AEABC 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF6C0 002AEAC0 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF6C4 002AEAC4 AFB3001C */  sw         $s3, 0x1C($sp)
    /* AF6C8 002AEAC8 00809821 */  addu       $s3, $a0, $zero
    /* AF6CC 002AEACC AFB20018 */  sw         $s2, 0x18($sp)
    /* AF6D0 002AEAD0 00A09021 */  addu       $s2, $a1, $zero
    /* AF6D4 002AEAD4 AFB60028 */  sw         $s6, 0x28($sp)
    /* AF6D8 002AEAD8 0000B021 */  addu       $s6, $zero, $zero
    /* AF6DC 002AEADC AFB50024 */  sw         $s5, 0x24($sp)
    /* AF6E0 002AEAE0 24150040 */  addiu      $s5, $zero, 0x40
    /* AF6E4 002AEAE4 AFB00010 */  sw         $s0, 0x10($sp)
    /* AF6E8 002AEAE8 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* AF6EC 002AEAEC AFB40020 */  sw         $s4, 0x20($sp)
    /* AF6F0 002AEAF0 24140040 */  addiu      $s4, $zero, 0x40
    /* AF6F4 002AEAF4 AFBF002C */  sw         $ra, 0x2C($sp)
  .L002AEAF8:
    /* AF6F8 002AEAF8 0C0AF7A8 */  jal        osPiGetStatus
    /* AF6FC 002AEAFC 00000000 */   nop
    /* AF700 002AEB00 30420003 */  andi       $v0, $v0, 0x3
    /* AF704 002AEB04 1440FFFC */  bnez       $v0, .L002AEAF8
    /* AF708 002AEB08 00000000 */   nop
    /* AF70C 002AEB0C 3C02B200 */  lui        $v0, %hi(D_B2000011)
    /* AF710 002AEB10 90420011 */  lbu        $v0, %lo(D_B2000011)($v0)
    /* AF714 002AEB14 00551024 */  and        $v0, $v0, $s5
    /* AF718 002AEB18 10540009 */  beq        $v0, $s4, .L002AEB40
    /* AF71C 002AEB1C 02001021 */   addu      $v0, $s0, $zero
    /* AF720 002AEB20 14400003 */  bnez       $v0, .L002AEB30
    /* AF724 002AEB24 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF728 002AEB28 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF72C 002AEB2C 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AEB30:
    /* AF730 002AEB30 1E20FFF1 */  bgtz       $s1, .L002AEAF8
    /* AF734 002AEB34 24020001 */   addiu     $v0, $zero, 0x1
    /* AF738 002AEB38 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF73C 002AEB3C AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AEB40:
    /* AF740 002AEB40 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF744 002AEB44 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF748 002AEB48 1440008E */  bnez       $v0, .L002AED84
    /* AF74C 002AEB4C 00000000 */   nop
    /* AF750 002AEB50 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF754 002AEB54 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF758 002AEB58 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF75C 002AEB5C 34420001 */  ori        $v0, $v0, 0x1
    /* AF760 002AEB60 00408021 */  addu       $s0, $v0, $zero
    /* AF764 002AEB64 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF768 002AEB68 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AEB6C:
    /* AF76C 002AEB6C 0C0AF7A8 */  jal        osPiGetStatus
    /* AF770 002AEB70 00000000 */   nop
    /* AF774 002AEB74 30420003 */  andi       $v0, $v0, 0x3
    /* AF778 002AEB78 1440FFFC */  bnez       $v0, .L002AEB6C
    /* AF77C 002AEB7C 00000000 */   nop
    /* AF780 002AEB80 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* AF784 002AEB84 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* AF788 002AEB88 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF78C 002AEB8C A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AF790 002AEB90 34420002 */  ori        $v0, $v0, 0x2
    /* AF794 002AEB94 00408021 */  addu       $s0, $v0, $zero
    /* AF798 002AEB98 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* AF79C 002AEB9C A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002AEBA0:
    /* AF7A0 002AEBA0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF7A4 002AEBA4 00000000 */   nop
    /* AF7A8 002AEBA8 30420003 */  andi       $v0, $v0, 0x3
    /* AF7AC 002AEBAC 1440FFFC */  bnez       $v0, .L002AEBA0
    /* AF7B0 002AEBB0 00000000 */   nop
    /* AF7B4 002AEBB4 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* AF7B8 002AEBB8 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* AF7BC 002AEBBC 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* AF7C0 002AEBC0 A4300008 */  sh         $s0, %lo(D_B2000008)($at)
    /* AF7C4 002AEBC4 34420001 */  ori        $v0, $v0, 0x1
    /* AF7C8 002AEBC8 00408021 */  addu       $s0, $v0, $zero
    /* AF7CC 002AEBCC 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* AF7D0 002AEBD0 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AEBD4:
    /* AF7D4 002AEBD4 0C0AF7A8 */  jal        osPiGetStatus
    /* AF7D8 002AEBD8 00000000 */   nop
    /* AF7DC 002AEBDC 30420003 */  andi       $v0, $v0, 0x3
    /* AF7E0 002AEBE0 1440FFFC */  bnez       $v0, .L002AEBD4
    /* AF7E4 002AEBE4 00000000 */   nop
    /* AF7E8 002AEBE8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* AF7EC 002AEBEC A4300004 */  sh         $s0, %lo(D_B2000004)($at)
  .L002AEBF0:
    /* AF7F0 002AEBF0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF7F4 002AEBF4 00000000 */   nop
    /* AF7F8 002AEBF8 30420003 */  andi       $v0, $v0, 0x3
    /* AF7FC 002AEBFC 1440FFFC */  bnez       $v0, .L002AEBF0
    /* AF800 002AEC00 02401021 */   addu      $v0, $s2, $zero
    /* AF804 002AEC04 3C01B200 */  lui        $at, %hi(D_B2000014)
    /* AF808 002AEC08 A4200014 */  sh         $zero, %lo(D_B2000014)($at)
    /* AF80C 002AEC0C 10400028 */  beqz       $v0, .L002AECB0
    /* AF810 002AEC10 2652FFFF */   addiu     $s2, $s2, -0x1
    /* AF814 002AEC14 24150040 */  addiu      $s5, $zero, 0x40
    /* AF818 002AEC18 24140040 */  addiu      $s4, $zero, 0x40
  .L002AEC1C:
    /* AF81C 002AEC1C 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF820 002AEC20 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF824 002AEC24 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AEC28:
    /* AF828 002AEC28 0C0AF7A8 */  jal        osPiGetStatus
    /* AF82C 002AEC2C 00000000 */   nop
    /* AF830 002AEC30 30420003 */  andi       $v0, $v0, 0x3
    /* AF834 002AEC34 1440FFFC */  bnez       $v0, .L002AEC28
    /* AF838 002AEC38 00000000 */   nop
    /* AF83C 002AEC3C 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF840 002AEC40 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF844 002AEC44 00551024 */  and        $v0, $v0, $s5
    /* AF848 002AEC48 10540009 */  beq        $v0, $s4, .L002AEC70
    /* AF84C 002AEC4C 02001021 */   addu      $v0, $s0, $zero
    /* AF850 002AEC50 14400003 */  bnez       $v0, .L002AEC60
    /* AF854 002AEC54 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF858 002AEC58 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF85C 002AEC5C 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AEC60:
    /* AF860 002AEC60 1E20FFF1 */  bgtz       $s1, .L002AEC28
    /* AF864 002AEC64 24020001 */   addiu     $v0, $zero, 0x1
    /* AF868 002AEC68 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF86C 002AEC6C AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AEC70:
    /* AF870 002AEC70 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF874 002AEC74 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF878 002AEC78 14400042 */  bnez       $v0, .L002AED84
    /* AF87C 002AEC7C 00000000 */   nop
    /* AF880 002AEC80 92700000 */  lbu        $s0, 0x0($s3)
    /* AF884 002AEC84 26730001 */  addiu      $s3, $s3, 0x1
  .L002AEC88:
    /* AF888 002AEC88 0C0AF7A8 */  jal        osPiGetStatus
    /* AF88C 002AEC8C 00000000 */   nop
    /* AF890 002AEC90 30420003 */  andi       $v0, $v0, 0x3
    /* AF894 002AEC94 1440FFFC */  bnez       $v0, .L002AEC88
    /* AF898 002AEC98 320200FF */   andi      $v0, $s0, 0xFF
    /* AF89C 002AEC9C 3C01B200 */  lui        $at, %hi(D_B2000020)
    /* AF8A0 002AECA0 A4220020 */  sh         $v0, %lo(D_B2000020)($at)
    /* AF8A4 002AECA4 02401021 */  addu       $v0, $s2, $zero
    /* AF8A8 002AECA8 1440FFDC */  bnez       $v0, .L002AEC1C
    /* AF8AC 002AECAC 2652FFFF */   addiu     $s2, $s2, -0x1
  .L002AECB0:
    /* AF8B0 002AECB0 24130040 */  addiu      $s3, $zero, 0x40
    /* AF8B4 002AECB4 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF8B8 002AECB8 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF8BC 002AECBC 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* AF8C0 002AECC0 24120040 */  addiu      $s2, $zero, 0x40
  .L002AECC4:
    /* AF8C4 002AECC4 0C0AF7A8 */  jal        osPiGetStatus
    /* AF8C8 002AECC8 00000000 */   nop
    /* AF8CC 002AECCC 30420003 */  andi       $v0, $v0, 0x3
    /* AF8D0 002AECD0 1440FFFC */  bnez       $v0, .L002AECC4
    /* AF8D4 002AECD4 00000000 */   nop
    /* AF8D8 002AECD8 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF8DC 002AECDC 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF8E0 002AECE0 00531024 */  and        $v0, $v0, $s3
    /* AF8E4 002AECE4 10520009 */  beq        $v0, $s2, .L002AED0C
    /* AF8E8 002AECE8 02001021 */   addu      $v0, $s0, $zero
    /* AF8EC 002AECEC 14400003 */  bnez       $v0, .L002AECFC
    /* AF8F0 002AECF0 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF8F4 002AECF4 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF8F8 002AECF8 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AECFC:
    /* AF8FC 002AECFC 1E20FFF1 */  bgtz       $s1, .L002AECC4
    /* AF900 002AED00 24020001 */   addiu     $v0, $zero, 0x1
    /* AF904 002AED04 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF908 002AED08 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AED0C:
    /* AF90C 002AED0C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF910 002AED10 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF914 002AED14 1440001B */  bnez       $v0, .L002AED84
    /* AF918 002AED18 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* AF91C 002AED1C 24130040 */  addiu      $s3, $zero, 0x40
    /* AF920 002AED20 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF924 002AED24 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF928 002AED28 00009021 */  addu       $s2, $zero, $zero
  .L002AED2C:
    /* AF92C 002AED2C 0C0AF7A8 */  jal        osPiGetStatus
    /* AF930 002AED30 00000000 */   nop
    /* AF934 002AED34 30420003 */  andi       $v0, $v0, 0x3
    /* AF938 002AED38 1440FFFC */  bnez       $v0, .L002AED2C
    /* AF93C 002AED3C 00000000 */   nop
    /* AF940 002AED40 3C02B200 */  lui        $v0, %hi(D_B2000011)
    /* AF944 002AED44 90420011 */  lbu        $v0, %lo(D_B2000011)($v0)
    /* AF948 002AED48 00531024 */  and        $v0, $v0, $s3
    /* AF94C 002AED4C 10520009 */  beq        $v0, $s2, .L002AED74
    /* AF950 002AED50 02001021 */   addu      $v0, $s0, $zero
    /* AF954 002AED54 14400003 */  bnez       $v0, .L002AED64
    /* AF958 002AED58 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF95C 002AED5C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF960 002AED60 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AED64:
    /* AF964 002AED64 1E20FFF1 */  bgtz       $s1, .L002AED2C
    /* AF968 002AED68 24020001 */   addiu     $v0, $zero, 0x1
    /* AF96C 002AED6C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF970 002AED70 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AED74:
    /* AF974 002AED74 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF978 002AED78 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF97C 002AED7C 50400001 */  beql       $v0, $zero, .L002AED84
    /* AF980 002AED80 24160001 */   addiu     $s6, $zero, 0x1
  .L002AED84:
    /* AF984 002AED84 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* AF988 002AED88 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* AF98C 002AED8C 304200FE */  andi       $v0, $v0, 0xFE
    /* AF990 002AED90 00408021 */  addu       $s0, $v0, $zero
    /* AF994 002AED94 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* AF998 002AED98 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AED9C:
    /* AF99C 002AED9C 0C0AF7A8 */  jal        osPiGetStatus
    /* AF9A0 002AEDA0 00000000 */   nop
    /* AF9A4 002AEDA4 30420003 */  andi       $v0, $v0, 0x3
    /* AF9A8 002AEDA8 1440FFFC */  bnez       $v0, .L002AED9C
    /* AF9AC 002AEDAC 00000000 */   nop
    /* AF9B0 002AEDB0 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* AF9B4 002AEDB4 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* AF9B8 002AEDB8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* AF9BC 002AEDBC A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* AF9C0 002AEDC0 304200FD */  andi       $v0, $v0, 0xFD
    /* AF9C4 002AEDC4 00408021 */  addu       $s0, $v0, $zero
    /* AF9C8 002AEDC8 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* AF9CC 002AEDCC A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002AEDD0:
    /* AF9D0 002AEDD0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF9D4 002AEDD4 00000000 */   nop
    /* AF9D8 002AEDD8 30420003 */  andi       $v0, $v0, 0x3
    /* AF9DC 002AEDDC 1440FFFC */  bnez       $v0, .L002AEDD0
    /* AF9E0 002AEDE0 00000000 */   nop
    /* AF9E4 002AEDE4 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF9E8 002AEDE8 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF9EC 002AEDEC 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* AF9F0 002AEDF0 A4300008 */  sh         $s0, %lo(D_B2000008)($at)
    /* AF9F4 002AEDF4 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF9F8 002AEDF8 00408021 */  addu       $s0, $v0, $zero
    /* AF9FC 002AEDFC 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AFA00 002AEE00 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AEE04:
    /* AFA04 002AEE04 0C0AF7A8 */  jal        osPiGetStatus
    /* AFA08 002AEE08 00000000 */   nop
    /* AFA0C 002AEE0C 30420003 */  andi       $v0, $v0, 0x3
    /* AFA10 002AEE10 1440FFFC */  bnez       $v0, .L002AEE04
    /* AFA14 002AEE14 02C01021 */   addu      $v0, $s6, $zero
    /* AFA18 002AEE18 8FBF002C */  lw         $ra, 0x2C($sp)
    /* AFA1C 002AEE1C 8FB60028 */  lw         $s6, 0x28($sp)
    /* AFA20 002AEE20 8FB50024 */  lw         $s5, 0x24($sp)
    /* AFA24 002AEE24 8FB40020 */  lw         $s4, 0x20($sp)
    /* AFA28 002AEE28 8FB3001C */  lw         $s3, 0x1C($sp)
    /* AFA2C 002AEE2C 8FB20018 */  lw         $s2, 0x18($sp)
    /* AFA30 002AEE30 8FB10014 */  lw         $s1, 0x14($sp)
    /* AFA34 002AEE34 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AFA38 002AEE38 A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AFA3C 002AEE3C 8FB00010 */  lw         $s0, 0x10($sp)
    /* AFA40 002AEE40 03E00008 */  jr         $ra
    /* AFA44 002AEE44 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel dbgLinkSendBlock
