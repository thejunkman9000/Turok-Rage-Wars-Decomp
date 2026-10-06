.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB72A0-0xB7350 (VRAM 0x002B66A0) */
glabel __voiceNeedsNoteKillOff
    /* B72A0 002B66A0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B72A4 002B66A4 AFB20018 */  sw         $s2, 0x18($sp)
    /* B72A8 002B66A8 00809021 */  addu       $s2, $a0, $zero
    /* B72AC 002B66AC 00003821 */  addu       $a3, $zero, $zero
    /* B72B0 002B66B0 AFBF001C */  sw         $ra, 0x1C($sp)
    /* B72B4 002B66B4 AFB10014 */  sw         $s1, 0x14($sp)
    /* B72B8 002B66B8 AFB00010 */  sw         $s0, 0x10($sp)
    /* B72BC 002B66BC 8E500050 */  lw         $s0, 0x50($s2)
    /* B72C0 002B66C0 1200001C */  beqz       $s0, .L002B6734
    /* B72C4 002B66C4 24110001 */   addiu     $s1, $zero, 0x1
    /* B72C8 002B66C8 24080005 */  addiu      $t0, $zero, 0x5
  .L002B66CC:
    /* B72CC 002B66CC 8E040008 */  lw         $a0, 0x8($s0)
    /* B72D0 002B66D0 8602000C */  lh         $v0, 0xC($s0)
    /* B72D4 002B66D4 8E030000 */  lw         $v1, 0x0($s0)
    /* B72D8 002B66D8 14480013 */  bne        $v0, $t0, .L002B6728
    /* B72DC 002B66DC 00E43821 */   addu      $a3, $a3, $a0
    /* B72E0 002B66E0 8E020010 */  lw         $v0, 0x10($s0)
    /* B72E4 002B66E4 54450011 */  bnel       $v0, $a1, .L002B672C
    /* B72E8 002B66E8 00608021 */   addu      $s0, $v1, $zero
    /* B72EC 002B66EC 00C7102A */  slt        $v0, $a2, $a3
    /* B72F0 002B66F0 50400010 */  beql       $v0, $zero, .L002B6734
    /* B72F4 002B66F4 00008821 */   addu      $s1, $zero, $zero
    /* B72F8 002B66F8 10600004 */  beqz       $v1, .L002B670C
    /* B72FC 002B66FC 00000000 */   nop
    /* B7300 002B6700 8C620008 */  lw         $v0, 0x8($v1)
    /* B7304 002B6704 00441021 */  addu       $v0, $v0, $a0
    /* B7308 002B6708 AC620008 */  sw         $v0, 0x8($v1)
  .L002B670C:
    /* B730C 002B670C 0C0ADD48 */  jal        alUnlink
    /* B7310 002B6710 02002021 */   addu      $a0, $s0, $zero
    /* B7314 002B6714 02002021 */  addu       $a0, $s0, $zero
    /* B7318 002B6718 0C0ADD54 */  jal        alLink
    /* B731C 002B671C 26450048 */   addiu     $a1, $s2, 0x48
    /* B7320 002B6720 080AD9CE */  j          .L002B6738
    /* B7324 002B6724 02201021 */   addu      $v0, $s1, $zero
  .L002B6728:
    /* B7328 002B6728 00608021 */  addu       $s0, $v1, $zero
  .L002B672C:
    /* B732C 002B672C 1600FFE7 */  bnez       $s0, .L002B66CC
    /* B7330 002B6730 00000000 */   nop
  .L002B6734:
    /* B7334 002B6734 02201021 */  addu       $v0, $s1, $zero
  .L002B6738:
    /* B7338 002B6738 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B733C 002B673C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B7340 002B6740 8FB10014 */  lw         $s1, 0x14($sp)
    /* B7344 002B6744 8FB00010 */  lw         $s0, 0x10($sp)
    /* B7348 002B6748 03E00008 */  jr         $ra
    /* B734C 002B674C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel __voiceNeedsNoteKillOff
