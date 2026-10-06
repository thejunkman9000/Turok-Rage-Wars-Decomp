.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC54F4-0xC5618 (VRAM 0x002C48F4) */
glabel adecDequantize
    /* C54F4 002C48F4 00806021 */  addu       $t4, $a0, $zero
    /* C54F8 002C48F8 00A05821 */  addu       $t3, $a1, $zero
    /* C54FC 002C48FC 00001821 */  addu       $v1, $zero, $zero
    /* C5500 002C4900 256A00A0 */  addiu      $t2, $t3, 0xA0
    /* C5504 002C4904 00603821 */  addu       $a3, $v1, $zero
    /* C5508 002C4908 3C09800E */  lui        $t1, %hi(D_800D93C8)
    /* C550C 002C490C 252993C8 */  addiu      $t1, $t1, %lo(D_800D93C8)
    /* C5510 002C4910 3C0D800E */  lui        $t5, %hi(D_800D93E8)
    /* C5514 002C4914 25AD93E8 */  addiu      $t5, $t5, %lo(D_800D93E8)
    /* C5518 002C4918 3C01800D */  lui        $at, %hi(D_800CCF24)
    /* C551C 002C491C C422CF24 */  lwc1       $fv1, %lo(D_800CCF24)($at)
    /* C5520 002C4920 00603021 */  addu       $a2, $v1, $zero
  .L002C4924:
    /* C5524 002C4924 00074400 */  sll        $t0, $a3, 16
    /* C5528 002C4928 00081BC3 */  sra        $v1, $t0, 15
    /* C552C 002C492C 00691821 */  addu       $v1, $v1, $t1
    /* C5530 002C4930 94630000 */  lhu        $v1, 0x0($v1)
    /* C5534 002C4934 080B1265 */  j          .L002C4994
    /* C5538 002C4938 00061400 */   sll       $v0, $a2, 16
  .L002C493C:
    /* C553C 002C493C 00031C03 */  sra        $v1, $v1, 16
    /* C5540 002C4940 00032040 */  sll        $a0, $v1, 1
    /* C5544 002C4944 00082BC3 */  sra        $a1, $t0, 15
    /* C5548 002C4948 01651021 */  addu       $v0, $t3, $a1
    /* C554C 002C494C 008A2021 */  addu       $a0, $a0, $t2
    /* C5550 002C4950 00031880 */  sll        $v1, $v1, 2
    /* C5554 002C4954 006C1821 */  addu       $v1, $v1, $t4
    /* C5558 002C4958 84420000 */  lh         $v0, 0x0($v0)
    /* C555C 002C495C 84840000 */  lh         $a0, 0x0($a0)
    /* C5560 002C4960 00021080 */  sll        $v0, $v0, 2
    /* C5564 002C4964 004D1021 */  addu       $v0, $v0, $t5
    /* C5568 002C4968 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C556C 002C496C 44840000 */  mtc1       $a0, $fv0
    /* C5570 002C4970 46800020 */  cvt.s.w    $fv0, $fv0
    /* C5574 002C4974 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* C5578 002C4978 46020002 */  mul.s      $fv0, $fv0, $fv1
    /* C557C 002C497C 00A92821 */  addu       $a1, $a1, $t1
    /* C5580 002C4980 24C20001 */  addiu      $v0, $a2, 0x1
    /* C5584 002C4984 00403021 */  addu       $a2, $v0, $zero
    /* C5588 002C4988 00021400 */  sll        $v0, $v0, 16
    /* C558C 002C498C E4600000 */  swc1       $fv0, 0x0($v1)
    /* C5590 002C4990 94A30000 */  lhu        $v1, 0x0($a1)
  .L002C4994:
    /* C5594 002C4994 00021403 */  sra        $v0, $v0, 16
    /* C5598 002C4998 0043102A */  slt        $v0, $v0, $v1
    /* C559C 002C499C 1440FFE7 */  bnez       $v0, .L002C493C
    /* C55A0 002C49A0 00061C00 */   sll       $v1, $a2, 16
    /* C55A4 002C49A4 00071400 */  sll        $v0, $a3, 16
    /* C55A8 002C49A8 000213C3 */  sra        $v0, $v0, 15
    /* C55AC 002C49AC 00491021 */  addu       $v0, $v0, $t1
    /* C55B0 002C49B0 94430000 */  lhu        $v1, 0x0($v0)
    /* C55B4 002C49B4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C55B8 002C49B8 00403821 */  addu       $a3, $v0, $zero
    /* C55BC 002C49BC 00021400 */  sll        $v0, $v0, 16
    /* C55C0 002C49C0 00021403 */  sra        $v0, $v0, 16
    /* C55C4 002C49C4 28420010 */  slti       $v0, $v0, 0x10
    /* C55C8 002C49C8 5440FFD6 */  bnel       $v0, $zero, .L002C4924
    /* C55CC 002C49CC 00603021 */   addu      $a2, $v1, $zero
    /* C55D0 002C49D0 3C02800E */  lui        $v0, %hi(D_800D93E6)
    /* C55D4 002C49D4 844293E6 */  lh         $v0, %lo(D_800D93E6)($v0)
    /* C55D8 002C49D8 00403821 */  addu       $a3, $v0, $zero
    /* C55DC 002C49DC 28420100 */  slti       $v0, $v0, 0x100
    /* C55E0 002C49E0 1040000B */  beqz       $v0, .L002C4A10
    /* C55E4 002C49E4 00071400 */   sll       $v0, $a3, 16
  .L002C49E8:
    /* C55E8 002C49E8 00021383 */  sra        $v0, $v0, 14
    /* C55EC 002C49EC 004C1021 */  addu       $v0, $v0, $t4
    /* C55F0 002C49F0 AC400000 */  sw         $zero, 0x0($v0)
    /* C55F4 002C49F4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C55F8 002C49F8 00403821 */  addu       $a3, $v0, $zero
    /* C55FC 002C49FC 00021400 */  sll        $v0, $v0, 16
    /* C5600 002C4A00 00021403 */  sra        $v0, $v0, 16
    /* C5604 002C4A04 28420100 */  slti       $v0, $v0, 0x100
    /* C5608 002C4A08 1440FFF7 */  bnez       $v0, .L002C49E8
    /* C560C 002C4A0C 00071400 */   sll       $v0, $a3, 16
  .L002C4A10:
    /* C5610 002C4A10 03E00008 */  jr         $ra
    /* C5614 002C4A14 24020001 */   addiu     $v0, $zero, 0x1
endlabel adecDequantize
