.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB22B4-0xB2334 (VRAM 0x002B16B4) */
glabel func_002B16B4
    /* B22B4 002B16B4 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B22B8 002B16B8 AFB20020 */  sw         $s2, 0x20($sp)
    /* B22BC 002B16BC 00809021 */  addu       $s2, $a0, $zero
    /* B22C0 002B16C0 AFB30024 */  sw         $s3, 0x24($sp)
    /* B22C4 002B16C4 00A09821 */  addu       $s3, $a1, $zero
    /* B22C8 002B16C8 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B22CC 002B16CC 00008821 */  addu       $s1, $zero, $zero
    /* B22D0 002B16D0 AFB00018 */  sw         $s0, 0x18($sp)
    /* B22D4 002B16D4 02208021 */  addu       $s0, $s1, $zero
    /* B22D8 002B16D8 AFBF0028 */  sw         $ra, 0x28($sp)
  .L002B16DC:
    /* B22DC 002B16DC 0C0AB8E0 */  jal        func_002AE380
    /* B22E0 002B16E0 27A40010 */   addiu     $a0, $sp, 0x10
    /* B22E4 002B16E4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B22E8 002B16E8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B22EC 002B16EC 14400009 */  bnez       $v0, .L002B1714
    /* B22F0 002B16F0 0213102A */   slt       $v0, $s0, $s3
    /* B22F4 002B16F4 10400003 */  beqz       $v0, .L002B1704
    /* B22F8 002B16F8 02501021 */   addu      $v0, $s2, $s0
    /* B22FC 002B16FC 93A30010 */  lbu        $v1, 0x10($sp)
    /* B2300 002B1700 A0430000 */  sb         $v1, 0x0($v0)
  .L002B1704:
    /* B2304 002B1704 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2308 002B1708 1440FFF4 */  bnez       $v0, .L002B16DC
    /* B230C 002B170C 26100001 */   addiu     $s0, $s0, 0x1
    /* B2310 002B1710 24110001 */  addiu      $s1, $zero, 0x1
  .L002B1714:
    /* B2314 002B1714 02201021 */  addu       $v0, $s1, $zero
    /* B2318 002B1718 8FBF0028 */  lw         $ra, 0x28($sp)
    /* B231C 002B171C 8FB30024 */  lw         $s3, 0x24($sp)
    /* B2320 002B1720 8FB20020 */  lw         $s2, 0x20($sp)
    /* B2324 002B1724 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B2328 002B1728 8FB00018 */  lw         $s0, 0x18($sp)
    /* B232C 002B172C 03E00008 */  jr         $ra
    /* B2330 002B1730 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002B16B4
