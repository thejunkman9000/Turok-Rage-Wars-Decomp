.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA94C-0xBAC38 (VRAM 0x002B9D4C) */
glabel func_002B9D4C
    /* BA94C 002B9D4C 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* BA950 002B9D50 AFB5002C */  sw         $s5, 0x2C($sp)
    /* BA954 002B9D54 00A0A821 */  addu       $s5, $a1, $zero
    /* BA958 002B9D58 AFB30024 */  sw         $s3, 0x24($sp)
    /* BA95C 002B9D5C 00C09821 */  addu       $s3, $a2, $zero
    /* BA960 002B9D60 AFB40028 */  sw         $s4, 0x28($sp)
    /* BA964 002B9D64 AFB1001C */  sw         $s1, 0x1C($sp)
    /* BA968 002B9D68 00808821 */  addu       $s1, $a0, $zero
    /* BA96C 002B9D6C AFB20020 */  sw         $s2, 0x20($sp)
    /* BA970 002B9D70 8FB2004C */  lw         $s2, 0x4C($sp)
    /* BA974 002B9D74 24030001 */  addiu      $v1, $zero, 0x1
    /* BA978 002B9D78 AFBF0030 */  sw         $ra, 0x30($sp)
    /* BA97C 002B9D7C AFB00018 */  sw         $s0, 0x18($sp)
    /* BA980 002B9D80 8E220048 */  lw         $v0, 0x48($s1)
    /* BA984 002B9D84 8E300000 */  lw         $s0, 0x0($s1)
    /* BA988 002B9D88 14430003 */  bne        $v0, $v1, .L002B9D98
    /* BA98C 002B9D8C 00E0A021 */   addu      $s4, $a3, $zero
    /* BA990 002B9D90 16800003 */  bnez       $s4, .L002B9DA0
    /* BA994 002B9D94 00000000 */   nop
  .L002B9D98:
    /* BA998 002B9D98 080AE805 */  j          .L002BA014
    /* BA99C 002B9D9C 02401021 */   addu      $v0, $s2, $zero
  .L002B9DA0:
    /* BA9A0 002B9DA0 16000008 */  bnez       $s0, .L002B9DC4
    /* BA9A4 002B9DA4 02002021 */   addu      $a0, $s0, $zero
    /* BA9A8 002B9DA8 3C04800D */  lui        $a0, %hi(D_800CC850)
    /* BA9AC 002B9DAC 2484C850 */  addiu      $a0, $a0, %lo(D_800CC850)
    /* BA9B0 002B9DB0 3C05800D */  lui        $a1, %hi(D_800CC854)
    /* BA9B4 002B9DB4 24A5C854 */  addiu      $a1, $a1, %lo(D_800CC854)
    /* BA9B8 002B9DB8 0C0AFF50 */  jal        __assert
    /* BA9BC 002B9DBC 2406016E */   addiu     $a2, $zero, 0x16E
    /* BA9C0 002B9DC0 02002021 */  addu       $a0, $s0, $zero
  .L002B9DC4:
    /* BA9C4 002B9DC4 02A02821 */  addu       $a1, $s5, $zero
    /* BA9C8 002B9DC8 AFB20010 */  sw         $s2, 0x10($sp)
    /* BA9CC 002B9DCC 8C820004 */  lw         $v0, 0x4($a0)
    /* BA9D0 002B9DD0 8FA70048 */  lw         $a3, 0x48($sp)
    /* BA9D4 002B9DD4 0040F809 */  jalr       $v0
    /* BA9D8 002B9DD8 02803021 */   addu      $a2, $s4, $zero
    /* BA9DC 002B9DDC 00409021 */  addu       $s2, $v0, $zero
    /* BA9E0 002B9DE0 02402021 */  addu       $a0, $s2, $zero
    /* BA9E4 002B9DE4 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* BA9E8 002B9DE8 96A20000 */  lhu        $v0, 0x0($s5)
    /* BA9EC 002B9DEC 26520008 */  addiu      $s2, $s2, 0x8
    /* BA9F0 002B9DF0 00431025 */  or         $v0, $v0, $v1
    /* BA9F4 002B9DF4 AC820000 */  sw         $v0, 0x0($a0)
    /* BA9F8 002B9DF8 00141040 */  sll        $v0, $s4, 1
    /* BA9FC 002B9DFC 86630000 */  lh         $v1, 0x0($s3)
    /* BAA00 002B9E00 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BAA04 002B9E04 24630440 */  addiu      $v1, $v1, 0x440
    /* BAA08 002B9E08 00031C00 */  sll        $v1, $v1, 16
    /* BAA0C 002B9E0C 00621825 */  or         $v1, $v1, $v0
    /* BAA10 002B9E10 AC830004 */  sw         $v1, 0x4($a0)
    /* BAA14 002B9E14 02402021 */  addu       $a0, $s2, $zero
    /* BAA18 002B9E18 86620000 */  lh         $v0, 0x0($s3)
    /* BAA1C 002B9E1C 3C030808 */  lui        $v1, (0x8080000 >> 16)
    /* BAA20 002B9E20 24420580 */  addiu      $v0, $v0, 0x580
    /* BAA24 002B9E24 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BAA28 002B9E28 00431025 */  or         $v0, $v0, $v1
    /* BAA2C 002B9E2C AC820000 */  sw         $v0, 0x0($a0)
    /* BAA30 002B9E30 86620000 */  lh         $v0, 0x0($s3)
    /* BAA34 002B9E34 244306C0 */  addiu      $v1, $v0, 0x6C0
    /* BAA38 002B9E38 00031C00 */  sll        $v1, $v1, 16
    /* BAA3C 002B9E3C 24420800 */  addiu      $v0, $v0, 0x800
    /* BAA40 002B9E40 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BAA44 002B9E44 00621825 */  or         $v1, $v1, $v0
    /* BAA48 002B9E48 AC830004 */  sw         $v1, 0x4($a0)
    /* BAA4C 002B9E4C 8E220038 */  lw         $v0, 0x38($s1)
    /* BAA50 002B9E50 10400061 */  beqz       $v0, .L002B9FD8
    /* BAA54 002B9E54 26520008 */   addiu     $s2, $s2, 0x8
    /* BAA58 002B9E58 86220018 */  lh         $v0, 0x18($s1)
    /* BAA5C 002B9E5C 8623001A */  lh         $v1, 0x1A($s1)
    /* BAA60 002B9E60 AE200038 */  sw         $zero, 0x38($s1)
    /* BAA64 002B9E64 00021040 */  sll        $v0, $v0, 1
    /* BAA68 002B9E68 3C01800E */  lui        $at, %hi(D_800D8240)
    /* BAA6C 002B9E6C 00220821 */  addu       $at, $at, $v0
    /* BAA70 002B9E70 84228240 */  lh         $v0, %lo(D_800D8240)($at)
    /* BAA74 002B9E74 00620018 */  mult       $v1, $v0
    /* BAA78 002B9E78 8622001C */  lh         $v0, 0x1C($s1)
    /* BAA7C 002B9E7C 8E230034 */  lw         $v1, 0x34($s1)
    /* BAA80 002B9E80 44826000 */  mtc1       $v0, $fa0
    /* BAA84 002B9E84 46806321 */  cvt.d.w    $fa0, $fa0
    /* BAA88 002B9E88 00004012 */  mflo       $t0
    /* BAA8C 002B9E8C 000823C3 */  sra        $a0, $t0, 15
    /* BAA90 002B9E90 00041400 */  sll        $v0, $a0, 16
    /* BAA94 002B9E94 00021403 */  sra        $v0, $v0, 16
    /* BAA98 002B9E98 44827000 */  mtc1       $v0, $fa1
    /* BAA9C 002B9E9C 468073A1 */  cvt.d.w    $fa1, $fa1
    /* BAAA0 002B9EA0 26220024 */  addiu      $v0, $s1, 0x24
    /* BAAA4 002B9EA4 A6240028 */  sh         $a0, 0x28($s1)
    /* BAAA8 002B9EA8 AFA30010 */  sw         $v1, 0x10($sp)
    /* BAAAC 002B9EAC 0C0AE80E */  jal        func_002BA038
    /* BAAB0 002B9EB0 AFA20014 */   sw        $v0, 0x14($sp)
    /* BAAB4 002B9EB4 86230018 */  lh         $v1, 0x18($s1)
    /* BAAB8 002B9EB8 A6220026 */  sh         $v0, 0x26($s1)
    /* BAABC 002B9EBC 2402007F */  addiu      $v0, $zero, 0x7F
    /* BAAC0 002B9EC0 00431023 */  subu       $v0, $v0, $v1
    /* BAAC4 002B9EC4 00021040 */  sll        $v0, $v0, 1
    /* BAAC8 002B9EC8 8623001A */  lh         $v1, 0x1A($s1)
    /* BAACC 002B9ECC 3C01800E */  lui        $at, %hi(D_800D8240)
    /* BAAD0 002B9ED0 00220821 */  addu       $at, $at, $v0
    /* BAAD4 002B9ED4 84228240 */  lh         $v0, %lo(D_800D8240)($at)
    /* BAAD8 002B9ED8 00620018 */  mult       $v1, $v0
    /* BAADC 002B9EDC 8622001E */  lh         $v0, 0x1E($s1)
    /* BAAE0 002B9EE0 8E230034 */  lw         $v1, 0x34($s1)
    /* BAAE4 002B9EE4 44826000 */  mtc1       $v0, $fa0
    /* BAAE8 002B9EE8 46806321 */  cvt.d.w    $fa0, $fa0
    /* BAAEC 002B9EEC 00004012 */  mflo       $t0
    /* BAAF0 002B9EF0 000823C3 */  sra        $a0, $t0, 15
    /* BAAF4 002B9EF4 00041400 */  sll        $v0, $a0, 16
    /* BAAF8 002B9EF8 00021403 */  sra        $v0, $v0, 16
    /* BAAFC 002B9EFC 44827000 */  mtc1       $v0, $fa1
    /* BAB00 002B9F00 468073A1 */  cvt.d.w    $fa1, $fa1
    /* BAB04 002B9F04 2622002A */  addiu      $v0, $s1, 0x2A
    /* BAB08 002B9F08 A624002E */  sh         $a0, 0x2E($s1)
    /* BAB0C 002B9F0C AFA30010 */  sw         $v1, 0x10($sp)
    /* BAB10 002B9F10 0C0AE80E */  jal        func_002BA038
    /* BAB14 002B9F14 AFA20014 */   sw        $v0, 0x14($sp)
    /* BAB18 002B9F18 02402021 */  addu       $a0, $s2, $zero
    /* BAB1C 002B9F1C 26520008 */  addiu      $s2, $s2, 0x8
    /* BAB20 002B9F20 02402821 */  addu       $a1, $s2, $zero
    /* BAB24 002B9F24 26520008 */  addiu      $s2, $s2, 0x8
    /* BAB28 002B9F28 02403021 */  addu       $a2, $s2, $zero
    /* BAB2C 002B9F2C 9623001C */  lhu        $v1, 0x1C($s1)
    /* BAB30 002B9F30 26520008 */  addiu      $s2, $s2, 0x8
    /* BAB34 002B9F34 A622002C */  sh         $v0, 0x2C($s1)
    /* BAB38 002B9F38 3C020906 */  lui        $v0, (0x9060000 >> 16)
    /* BAB3C 002B9F3C AC800004 */  sw         $zero, 0x4($a0)
    /* BAB40 002B9F40 00621825 */  or         $v1, $v1, $v0
    /* BAB44 002B9F44 AC830000 */  sw         $v1, 0x0($a0)
    /* BAB48 002B9F48 02402021 */  addu       $a0, $s2, $zero
    /* BAB4C 002B9F4C 26520008 */  addiu      $s2, $s2, 0x8
    /* BAB50 002B9F50 9623001E */  lhu        $v1, 0x1E($s1)
    /* BAB54 002B9F54 3C020904 */  lui        $v0, (0x9040000 >> 16)
    /* BAB58 002B9F58 ACA00004 */  sw         $zero, 0x4($a1)
    /* BAB5C 002B9F5C 00621825 */  or         $v1, $v1, $v0
    /* BAB60 002B9F60 ACA30000 */  sw         $v1, 0x0($a1)
    /* BAB64 002B9F64 96220028 */  lhu        $v0, 0x28($s1)
    /* BAB68 002B9F68 3C030902 */  lui        $v1, (0x9020000 >> 16)
    /* BAB6C 002B9F6C 00431025 */  or         $v0, $v0, $v1
    /* BAB70 002B9F70 ACC20000 */  sw         $v0, 0x0($a2)
    /* BAB74 002B9F74 96220026 */  lhu        $v0, 0x26($s1)
    /* BAB78 002B9F78 96230024 */  lhu        $v1, 0x24($s1)
    /* BAB7C 002B9F7C 00021400 */  sll        $v0, $v0, 16
    /* BAB80 002B9F80 00431025 */  or         $v0, $v0, $v1
    /* BAB84 002B9F84 ACC20004 */  sw         $v0, 0x4($a2)
    /* BAB88 002B9F88 9622002E */  lhu        $v0, 0x2E($s1)
    /* BAB8C 002B9F8C 3C030900 */  lui        $v1, (0x9000000 >> 16)
    /* BAB90 002B9F90 00431025 */  or         $v0, $v0, $v1
    /* BAB94 002B9F94 AC820000 */  sw         $v0, 0x0($a0)
    /* BAB98 002B9F98 9622002C */  lhu        $v0, 0x2C($s1)
    /* BAB9C 002B9F9C 9623002A */  lhu        $v1, 0x2A($s1)
    /* BABA0 002B9FA0 00021400 */  sll        $v0, $v0, 16
    /* BABA4 002B9FA4 00431025 */  or         $v0, $v0, $v1
    /* BABA8 002B9FA8 AC820004 */  sw         $v0, 0x4($a0)
    /* BABAC 002B9FAC 02402021 */  addu       $a0, $s2, $zero
    /* BABB0 002B9FB0 3C030908 */  lui        $v1, (0x9080000 >> 16)
    /* BABB4 002B9FB4 96220020 */  lhu        $v0, 0x20($s1)
    /* BABB8 002B9FB8 26520008 */  addiu      $s2, $s2, 0x8
    /* BABBC 002B9FBC 00431025 */  or         $v0, $v0, $v1
    /* BABC0 002B9FC0 AC820000 */  sw         $v0, 0x0($a0)
    /* BABC4 002B9FC4 96220022 */  lhu        $v0, 0x22($s1)
    /* BABC8 002B9FC8 02408021 */  addu       $s0, $s2, $zero
    /* BABCC 002B9FCC AC820004 */  sw         $v0, 0x4($a0)
    /* BABD0 002B9FD0 080AE7F8 */  j          .L002B9FE0
    /* BABD4 002B9FD4 3C020309 */   lui       $v0, (0x3090000 >> 16)
  .L002B9FD8:
    /* BABD8 002B9FD8 02408021 */  addu       $s0, $s2, $zero
    /* BABDC 002B9FDC 3C020308 */  lui        $v0, (0x3080000 >> 16)
  .L002B9FE0:
    /* BABE0 002B9FE0 AE020000 */  sw         $v0, 0x0($s0)
    /* BABE4 002B9FE4 8E240014 */  lw         $a0, 0x14($s1)
    /* BABE8 002B9FE8 0C0B032C */  jal        osVirtualToPhysical
    /* BABEC 002B9FEC 26520008 */   addiu     $s2, $s2, 0x8
    /* BABF0 002B9FF0 AE020004 */  sw         $v0, 0x4($s0)
    /* BABF4 002B9FF4 96A20000 */  lhu        $v0, 0x0($s5)
    /* BABF8 002B9FF8 00141840 */  sll        $v1, $s4, 1
    /* BABFC 002B9FFC 00431021 */  addu       $v0, $v0, $v1
    /* BAC00 002BA000 A6A20000 */  sh         $v0, 0x0($s5)
    /* BAC04 002BA004 8E230030 */  lw         $v1, 0x30($s1)
    /* BAC08 002BA008 02401021 */  addu       $v0, $s2, $zero
    /* BAC0C 002BA00C 00741821 */  addu       $v1, $v1, $s4
    /* BAC10 002BA010 AE230030 */  sw         $v1, 0x30($s1)
  .L002BA014:
    /* BAC14 002BA014 8FBF0030 */  lw         $ra, 0x30($sp)
    /* BAC18 002BA018 8FB5002C */  lw         $s5, 0x2C($sp)
    /* BAC1C 002BA01C 8FB40028 */  lw         $s4, 0x28($sp)
    /* BAC20 002BA020 8FB30024 */  lw         $s3, 0x24($sp)
    /* BAC24 002BA024 8FB20020 */  lw         $s2, 0x20($sp)
    /* BAC28 002BA028 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BAC2C 002BA02C 8FB00018 */  lw         $s0, 0x18($sp)
    /* BAC30 002BA030 03E00008 */  jr         $ra
    /* BAC34 002BA034 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_002B9D4C
