.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAFF3C-0xB0024 (VRAM 0x002AF33C) */
glabel dbgLinkCmdReadHalf
    /* AFF3C 002AF33C 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* AFF40 002AF340 AFB1001C */  sw         $s1, 0x1C($sp)
    /* AFF44 002AF344 27B10014 */  addiu      $s1, $sp, 0x14
    /* AFF48 002AF348 02202021 */  addu       $a0, $s1, $zero
    /* AFF4C 002AF34C AFBF0024 */  sw         $ra, 0x24($sp)
    /* AFF50 002AF350 AFB20020 */  sw         $s2, 0x20($sp)
    /* AFF54 002AF354 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFF58 002AF358 AFB00018 */   sw        $s0, 0x18($sp)
    /* AFF5C 002AF35C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFF60 002AF360 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFF64 002AF364 14400028 */  bnez       $v0, .L002AF408
    /* AFF68 002AF368 00009021 */   addu      $s2, $zero, $zero
    /* AFF6C 002AF36C 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFF70 002AF370 02202021 */  addu       $a0, $s1, $zero
    /* AFF74 002AF374 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFF78 002AF378 00028200 */   sll       $s0, $v0, 8
    /* AFF7C 002AF37C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFF80 002AF380 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFF84 002AF384 14400021 */  bnez       $v0, .L002AF40C
    /* AFF88 002AF388 02401021 */   addu      $v0, $s2, $zero
    /* AFF8C 002AF38C 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFF90 002AF390 02202021 */  addu       $a0, $s1, $zero
    /* AFF94 002AF394 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFF98 002AF398 02028025 */   or        $s0, $s0, $v0
    /* AFF9C 002AF39C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFFA0 002AF3A0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFFA4 002AF3A4 14400018 */  bnez       $v0, .L002AF408
    /* AFFA8 002AF3A8 00108200 */   sll       $s0, $s0, 8
    /* AFFAC 002AF3AC 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFFB0 002AF3B0 02202021 */  addu       $a0, $s1, $zero
    /* AFFB4 002AF3B4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFFB8 002AF3B8 02028025 */   or        $s0, $s0, $v0
    /* AFFBC 002AF3BC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFFC0 002AF3C0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFFC4 002AF3C4 14400010 */  bnez       $v0, .L002AF408
    /* AFFC8 002AF3C8 00108200 */   sll       $s0, $s0, 8
    /* AFFCC 002AF3CC 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFFD0 002AF3D0 02028025 */  or         $s0, $s0, $v0
    /* AFFD4 002AF3D4 AFB00010 */  sw         $s0, 0x10($sp)
    /* AFFD8 002AF3D8 96100000 */  lhu        $s0, 0x0($s0)
    /* AFFDC 002AF3DC 0C0AB96B */  jal        dbgLinkSendByte
    /* AFFE0 002AF3E0 00102202 */   srl       $a0, $s0, 8
    /* AFFE4 002AF3E4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFFE8 002AF3E8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFFEC 002AF3EC 14400007 */  bnez       $v0, .L002AF40C
    /* AFFF0 002AF3F0 02401021 */   addu      $v0, $s2, $zero
    /* AFFF4 002AF3F4 0C0AB96B */  jal        dbgLinkSendByte
    /* AFFF8 002AF3F8 320400FF */   andi      $a0, $s0, 0xFF
    /* AFFFC 002AF3FC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0000 002AF400 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0004 002AF404 2C520001 */  sltiu      $s2, $v0, 0x1
  .L002AF408:
    /* B0008 002AF408 02401021 */  addu       $v0, $s2, $zero
  .L002AF40C:
    /* B000C 002AF40C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B0010 002AF410 8FB20020 */  lw         $s2, 0x20($sp)
    /* B0014 002AF414 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B0018 002AF418 8FB00018 */  lw         $s0, 0x18($sp)
    /* B001C 002AF41C 03E00008 */  jr         $ra
    /* B0020 002AF420 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel dbgLinkCmdReadHalf
