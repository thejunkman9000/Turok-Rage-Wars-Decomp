.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAF434-0xAF6B4 (VRAM 0x002AE834) */
glabel dbgLinkRecvBlock
    /* AF434 002AE834 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* AF438 002AE838 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* AF43C 002AE83C 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* AF440 002AE840 AFB40020 */  sw         $s4, 0x20($sp)
    /* AF444 002AE844 0080A021 */  addu       $s4, $a0, $zero
    /* AF448 002AE848 AFB3001C */  sw         $s3, 0x1C($sp)
    /* AF44C 002AE84C 00A09821 */  addu       $s3, $a1, $zero
    /* AF450 002AE850 AFBE0030 */  sw         $fp, 0x30($sp)
    /* AF454 002AE854 00C0F021 */  addu       $fp, $a2, $zero
    /* AF458 002AE858 AFB7002C */  sw         $s7, 0x2C($sp)
    /* AF45C 002AE85C 0000B821 */  addu       $s7, $zero, $zero
    /* AF460 002AE860 AFB20018 */  sw         $s2, 0x18($sp)
    /* AF464 002AE864 02E09021 */  addu       $s2, $s7, $zero
    /* AF468 002AE868 AFBF0034 */  sw         $ra, 0x34($sp)
    /* AF46C 002AE86C AFB60028 */  sw         $s6, 0x28($sp)
    /* AF470 002AE870 AFB50024 */  sw         $s5, 0x24($sp)
    /* AF474 002AE874 AFB10014 */  sw         $s1, 0x14($sp)
    /* AF478 002AE878 AFB00010 */  sw         $s0, 0x10($sp)
    /* AF47C 002AE87C 34420008 */  ori        $v0, $v0, 0x8
    /* AF480 002AE880 00408021 */  addu       $s0, $v0, $zero
    /* AF484 002AE884 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* AF488 002AE888 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AE88C:
    /* AF48C 002AE88C 0C0AF7A8 */  jal        osPiGetStatus
    /* AF490 002AE890 00000000 */   nop
    /* AF494 002AE894 30420003 */  andi       $v0, $v0, 0x3
    /* AF498 002AE898 1440FFFC */  bnez       $v0, .L002AE88C
    /* AF49C 002AE89C 00000000 */   nop
    /* AF4A0 002AE8A0 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF4A4 002AE8A4 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF4A8 002AE8A8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* AF4AC 002AE8AC A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* AF4B0 002AE8B0 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF4B4 002AE8B4 00408021 */  addu       $s0, $v0, $zero
    /* AF4B8 002AE8B8 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF4BC 002AE8BC A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE8C0:
    /* AF4C0 002AE8C0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF4C4 002AE8C4 00000000 */   nop
    /* AF4C8 002AE8C8 30420003 */  andi       $v0, $v0, 0x3
    /* AF4CC 002AE8CC 1440FFFC */  bnez       $v0, .L002AE8C0
    /* AF4D0 002AE8D0 00000000 */   nop
    /* AF4D4 002AE8D4 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* AF4D8 002AE8D8 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* AF4DC 002AE8DC 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF4E0 002AE8E0 A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AF4E4 002AE8E4 34420002 */  ori        $v0, $v0, 0x2
    /* AF4E8 002AE8E8 00408021 */  addu       $s0, $v0, $zero
    /* AF4EC 002AE8EC 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* AF4F0 002AE8F0 A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002AE8F4:
    /* AF4F4 002AE8F4 0C0AF7A8 */  jal        osPiGetStatus
    /* AF4F8 002AE8F8 00000000 */   nop
    /* AF4FC 002AE8FC 30420003 */  andi       $v0, $v0, 0x3
    /* AF500 002AE900 1440FFFC */  bnez       $v0, .L002AE8F4
    /* AF504 002AE904 00000000 */   nop
    /* AF508 002AE908 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* AF50C 002AE90C A4300008 */  sh         $s0, %lo(D_B2000008)($at)
  .L002AE910:
    /* AF510 002AE910 0C0AF7A8 */  jal        osPiGetStatus
    /* AF514 002AE914 00000000 */   nop
    /* AF518 002AE918 30420003 */  andi       $v0, $v0, 0x3
    /* AF51C 002AE91C 1440FFFC */  bnez       $v0, .L002AE910
    /* AF520 002AE920 02601021 */   addu      $v0, $s3, $zero
    /* AF524 002AE924 3C01B200 */  lui        $at, %hi(D_B2000018)
    /* AF528 002AE928 A4200018 */  sh         $zero, %lo(D_B2000018)($at)
    /* AF52C 002AE92C 1040002C */  beqz       $v0, .L002AE9E0
    /* AF530 002AE930 2673FFFF */   addiu     $s3, $s3, -0x1
    /* AF534 002AE934 24160040 */  addiu      $s6, $zero, 0x40
    /* AF538 002AE938 24150040 */  addiu      $s5, $zero, 0x40
  .L002AE93C:
    /* AF53C 002AE93C 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF540 002AE940 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF544 002AE944 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AE948:
    /* AF548 002AE948 0C0AF7A8 */  jal        osPiGetStatus
    /* AF54C 002AE94C 00000000 */   nop
    /* AF550 002AE950 30420003 */  andi       $v0, $v0, 0x3
    /* AF554 002AE954 1440FFFC */  bnez       $v0, .L002AE948
    /* AF558 002AE958 00000000 */   nop
    /* AF55C 002AE95C 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF560 002AE960 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF564 002AE964 00561024 */  and        $v0, $v0, $s6
    /* AF568 002AE968 10550009 */  beq        $v0, $s5, .L002AE990
    /* AF56C 002AE96C 02001021 */   addu      $v0, $s0, $zero
    /* AF570 002AE970 14400003 */  bnez       $v0, .L002AE980
    /* AF574 002AE974 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF578 002AE978 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF57C 002AE97C 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AE980:
    /* AF580 002AE980 1E20FFF1 */  bgtz       $s1, .L002AE948
    /* AF584 002AE984 24020001 */   addiu     $v0, $zero, 0x1
    /* AF588 002AE988 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF58C 002AE98C AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AE990:
    /* AF590 002AE990 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF594 002AE994 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF598 002AE998 14400013 */  bnez       $v0, .L002AE9E8
    /* AF59C 002AE99C 00000000 */   nop
  .L002AE9A0:
    /* AF5A0 002AE9A0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF5A4 002AE9A4 00000000 */   nop
    /* AF5A8 002AE9A8 30420003 */  andi       $v0, $v0, 0x3
    /* AF5AC 002AE9AC 1440FFFC */  bnez       $v0, .L002AE9A0
    /* AF5B0 002AE9B0 00121840 */   sll       $v1, $s2, 1
    /* AF5B4 002AE9B4 001217C2 */  srl        $v0, $s2, 31
    /* AF5B8 002AE9B8 00629025 */  or         $s2, $v1, $v0
    /* AF5BC 002AE9BC 02601821 */  addu       $v1, $s3, $zero
    /* AF5C0 002AE9C0 3C02B200 */  lui        $v0, %hi(D_B2000021)
    /* AF5C4 002AE9C4 90420021 */  lbu        $v0, %lo(D_B2000021)($v0)
    /* AF5C8 002AE9C8 2673FFFF */  addiu      $s3, $s3, -0x1
    /* AF5CC 002AE9CC A2820000 */  sb         $v0, 0x0($s4)
    /* AF5D0 002AE9D0 26940001 */  addiu      $s4, $s4, 0x1
    /* AF5D4 002AE9D4 304200FF */  andi       $v0, $v0, 0xFF
    /* AF5D8 002AE9D8 1460FFD8 */  bnez       $v1, .L002AE93C
    /* AF5DC 002AE9DC 02429021 */   addu      $s2, $s2, $v0
  .L002AE9E0:
    /* AF5E0 002AE9E0 AFD20000 */  sw         $s2, 0x0($fp)
    /* AF5E4 002AE9E4 24170001 */  addiu      $s7, $zero, 0x1
  .L002AE9E8:
    /* AF5E8 002AE9E8 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* AF5EC 002AE9EC 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* AF5F0 002AE9F0 304200FD */  andi       $v0, $v0, 0xFD
    /* AF5F4 002AE9F4 00408021 */  addu       $s0, $v0, $zero
    /* AF5F8 002AE9F8 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* AF5FC 002AE9FC A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002AEA00:
    /* AF600 002AEA00 0C0AF7A8 */  jal        osPiGetStatus
    /* AF604 002AEA04 00000000 */   nop
    /* AF608 002AEA08 30420003 */  andi       $v0, $v0, 0x3
    /* AF60C 002AEA0C 1440FFFC */  bnez       $v0, .L002AEA00
    /* AF610 002AEA10 00000000 */   nop
    /* AF614 002AEA14 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* AF618 002AEA18 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* AF61C 002AEA1C 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* AF620 002AEA20 A4300008 */  sh         $s0, %lo(D_B2000008)($at)
    /* AF624 002AEA24 304200F7 */  andi       $v0, $v0, 0xF7
    /* AF628 002AEA28 00408021 */  addu       $s0, $v0, $zero
    /* AF62C 002AEA2C 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* AF630 002AEA30 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AEA34:
    /* AF634 002AEA34 0C0AF7A8 */  jal        osPiGetStatus
    /* AF638 002AEA38 00000000 */   nop
    /* AF63C 002AEA3C 30420003 */  andi       $v0, $v0, 0x3
    /* AF640 002AEA40 1440FFFC */  bnez       $v0, .L002AEA34
    /* AF644 002AEA44 00000000 */   nop
    /* AF648 002AEA48 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF64C 002AEA4C 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF650 002AEA50 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* AF654 002AEA54 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* AF658 002AEA58 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF65C 002AEA5C 00408021 */  addu       $s0, $v0, $zero
    /* AF660 002AEA60 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF664 002AEA64 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AEA68:
    /* AF668 002AEA68 0C0AF7A8 */  jal        osPiGetStatus
    /* AF66C 002AEA6C 00000000 */   nop
    /* AF670 002AEA70 30420003 */  andi       $v0, $v0, 0x3
    /* AF674 002AEA74 1440FFFC */  bnez       $v0, .L002AEA68
    /* AF678 002AEA78 02E01021 */   addu      $v0, $s7, $zero
    /* AF67C 002AEA7C 8FBF0034 */  lw         $ra, 0x34($sp)
    /* AF680 002AEA80 8FBE0030 */  lw         $fp, 0x30($sp)
    /* AF684 002AEA84 8FB7002C */  lw         $s7, 0x2C($sp)
    /* AF688 002AEA88 8FB60028 */  lw         $s6, 0x28($sp)
    /* AF68C 002AEA8C 8FB50024 */  lw         $s5, 0x24($sp)
    /* AF690 002AEA90 8FB40020 */  lw         $s4, 0x20($sp)
    /* AF694 002AEA94 8FB3001C */  lw         $s3, 0x1C($sp)
    /* AF698 002AEA98 8FB20018 */  lw         $s2, 0x18($sp)
    /* AF69C 002AEA9C 8FB10014 */  lw         $s1, 0x14($sp)
    /* AF6A0 002AEAA0 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF6A4 002AEAA4 A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AF6A8 002AEAA8 8FB00010 */  lw         $s0, 0x10($sp)
    /* AF6AC 002AEAAC 03E00008 */  jr         $ra
    /* AF6B0 002AEAB0 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel dbgLinkRecvBlock
