.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB6094-0xB6224 (VRAM 0x002B5494) */
glabel alSeqpNew
    /* B6094 002B5494 00431021 */  addu       $v0, $v0, $v1
    /* B6098 002B5498 A050000A */  sb         $s0, 0xA($v0)
    /* B609C 002B549C 8E510064 */  lw         $s1, 0x64($s2)
    /* B60A0 002B54A0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B60A4 002B54A4 AFB00018 */  sw         $s0, 0x18($sp)
    /* B60A8 002B54A8 00808021 */  addu       $s0, $a0, $zero
    /* B60AC 002B54AC AFB1001C */  sw         $s1, 0x1C($sp)
    /* B60B0 002B54B0 00A08821 */  addu       $s1, $a1, $zero
    /* B60B4 002B54B4 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B60B8 002B54B8 AFB20020 */  sw         $s2, 0x20($sp)
    /* B60BC 002B54BC 8E32000C */  lw         $s2, 0xC($s1)
    /* B60C0 002B54C0 3C03800E */  lui        $v1, %hi(alGlobalsp)
    /* B60C4 002B54C4 8C6380A0 */  lw         $v1, %lo(alGlobalsp)($v1)
    /* B60C8 002B54C8 240200FF */  addiu      $v0, $zero, 0xFF
    /* B60CC 002B54CC A6020030 */  sh         $v0, 0x30($s0)
    /* B60D0 002B54D0 240201E8 */  addiu      $v0, $zero, 0x1E8
    /* B60D4 002B54D4 AE020024 */  sw         $v0, 0x24($s0)
    /* B60D8 002B54D8 24027FFF */  addiu      $v0, $zero, 0x7FFF
    /* B60DC 002B54DC AE000020 */  sw         $zero, 0x20($s0)
    /* B60E0 002B54E0 AE000018 */  sw         $zero, 0x18($s0)
    /* B60E4 002B54E4 AE000028 */  sw         $zero, 0x28($s0)
    /* B60E8 002B54E8 AE00002C */  sw         $zero, 0x2C($s0)
    /* B60EC 002B54EC A6020032 */  sh         $v0, 0x32($s0)
    /* B60F0 002B54F0 AE030014 */  sw         $v1, 0x14($s0)
    /* B60F4 002B54F4 92230009 */  lbu        $v1, 0x9($s1)
    /* B60F8 002B54F8 24023E80 */  addiu      $v0, $zero, 0x3E80
    /* B60FC 002B54FC AE02005C */  sw         $v0, 0x5C($s0)
    /* B6100 002B5500 AE00001C */  sw         $zero, 0x1C($s0)
    /* B6104 002B5504 A2030035 */  sb         $v1, 0x35($s0)
    /* B6108 002B5508 8E220010 */  lw         $v0, 0x10($s1)
    /* B610C 002B550C 00002021 */  addu       $a0, $zero, $zero
    /* B6110 002B5510 AE020070 */  sw         $v0, 0x70($s0)
    /* B6114 002B5514 8E220014 */  lw         $v0, 0x14($s1)
    /* B6118 002B5518 00802821 */  addu       $a1, $a0, $zero
    /* B611C 002B551C AE020074 */  sw         $v0, 0x74($s0)
    /* B6120 002B5520 8E230018 */  lw         $v1, 0x18($s1)
    /* B6124 002B5524 24020009 */  addiu      $v0, $zero, 0x9
    /* B6128 002B5528 AE00007C */  sw         $zero, 0x7C($s0)
    /* B612C 002B552C AE000080 */  sw         $zero, 0x80($s0)
    /* B6130 002B5530 AE000084 */  sw         $zero, 0x84($s0)
    /* B6134 002B5534 A6020038 */  sh         $v0, 0x38($s0)
    /* B6138 002B5538 AE030078 */  sw         $v1, 0x78($s0)
    /* B613C 002B553C 92220008 */  lbu        $v0, 0x8($s1)
    /* B6140 002B5540 02403021 */  addu       $a2, $s2, $zero
    /* B6144 002B5544 A2020034 */  sb         $v0, 0x34($s0)
    /* B6148 002B5548 92270008 */  lbu        $a3, 0x8($s1)
    /* B614C 002B554C 24020010 */  addiu      $v0, $zero, 0x10
    /* B6150 002B5550 0C0AD504 */  jal        alHeapDBAlloc
    /* B6154 002B5554 AFA20010 */   sw        $v0, 0x10($sp)
    /* B6158 002B5558 02002021 */  addu       $a0, $s0, $zero
    /* B615C 002B555C 0C0ADA98 */  jal        __initChanState
    /* B6160 002B5560 AE020060 */   sw        $v0, 0x60($s0)
    /* B6164 002B5564 00002021 */  addu       $a0, $zero, $zero
    /* B6168 002B5568 00802821 */  addu       $a1, $a0, $zero
    /* B616C 002B556C 24020038 */  addiu      $v0, $zero, 0x38
    /* B6170 002B5570 AFA20010 */  sw         $v0, 0x10($sp)
    /* B6174 002B5574 8E270000 */  lw         $a3, 0x0($s1)
    /* B6178 002B5578 0C0AD504 */  jal        alHeapDBAlloc
    /* B617C 002B557C 02403021 */   addu      $a2, $s2, $zero
    /* B6180 002B5580 AE00006C */  sw         $zero, 0x6C($s0)
    /* B6184 002B5584 8E230000 */  lw         $v1, 0x0($s1)
    /* B6188 002B5588 1860000A */  blez       $v1, .L002B55B4
    /* B618C 002B558C 00002021 */   addu      $a0, $zero, $zero
    /* B6190 002B5590 00401821 */  addu       $v1, $v0, $zero
  .L002B5594:
    /* B6194 002B5594 8E02006C */  lw         $v0, 0x6C($s0)
    /* B6198 002B5598 24840001 */  addiu      $a0, $a0, 0x1
    /* B619C 002B559C AC620000 */  sw         $v0, 0x0($v1)
    /* B61A0 002B55A0 AE03006C */  sw         $v1, 0x6C($s0)
    /* B61A4 002B55A4 8E220000 */  lw         $v0, 0x0($s1)
    /* B61A8 002B55A8 0082102A */  slt        $v0, $a0, $v0
    /* B61AC 002B55AC 1440FFF9 */  bnez       $v0, .L002B5594
    /* B61B0 002B55B0 24630038 */   addiu     $v1, $v1, 0x38
  .L002B55B4:
    /* B61B4 002B55B4 00002021 */  addu       $a0, $zero, $zero
    /* B61B8 002B55B8 00802821 */  addu       $a1, $a0, $zero
    /* B61BC 002B55BC 2402001C */  addiu      $v0, $zero, 0x1C
    /* B61C0 002B55C0 AE000064 */  sw         $zero, 0x64($s0)
    /* B61C4 002B55C4 AE000068 */  sw         $zero, 0x68($s0)
    /* B61C8 002B55C8 AFA20010 */  sw         $v0, 0x10($sp)
    /* B61CC 002B55CC 8E270004 */  lw         $a3, 0x4($s1)
    /* B61D0 002B55D0 0C0AD504 */  jal        alHeapDBAlloc
    /* B61D4 002B55D4 02403021 */   addu      $a2, $s2, $zero
    /* B61D8 002B55D8 26040048 */  addiu      $a0, $s0, 0x48
    /* B61DC 002B55DC 8E260004 */  lw         $a2, 0x4($s1)
    /* B61E0 002B55E0 0C0AD424 */  jal        alEvtqNew
    /* B61E4 002B55E4 00402821 */   addu      $a1, $v0, $zero
    /* B61E8 002B55E8 02002821 */  addu       $a1, $s0, $zero
    /* B61EC 002B55EC 3C04800E */  lui        $a0, %hi(alGlobalsp)
    /* B61F0 002B55F0 8C8480A0 */  lw         $a0, %lo(alGlobalsp)($a0)
    /* B61F4 002B55F4 3C02002B */  lui        $v0, %hi(__voiceHandler)
    /* B61F8 002B55F8 24425624 */  addiu      $v0, $v0, %lo(__voiceHandler)
    /* B61FC 002B55FC ACA00000 */  sw         $zero, 0x0($a1)
    /* B6200 002B5600 ACA20008 */  sw         $v0, 0x8($a1)
    /* B6204 002B5604 0C0AE020 */  jal        alSynAddPlayer
    /* B6208 002B5608 ACA50004 */   sw        $a1, 0x4($a1)
    /* B620C 002B560C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B6210 002B5610 8FB20020 */  lw         $s2, 0x20($sp)
    /* B6214 002B5614 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B6218 002B5618 8FB00018 */  lw         $s0, 0x18($sp)
    /* B621C 002B561C 03E00008 */  jr         $ra
    /* B6220 002B5620 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alSeqpNew
