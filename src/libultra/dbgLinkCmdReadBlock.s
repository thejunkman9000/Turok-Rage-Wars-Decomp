.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB02A0-0xB03F8 (VRAM 0x002AF6A0) */
glabel dbgLinkCmdReadBlock
    /* B02A0 002AF6A0 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B02A4 002AF6A4 AFB10024 */  sw         $s1, 0x24($sp)
    /* B02A8 002AF6A8 27B10014 */  addiu      $s1, $sp, 0x14
    /* B02AC 002AF6AC 02202021 */  addu       $a0, $s1, $zero
    /* B02B0 002AF6B0 AFBF002C */  sw         $ra, 0x2C($sp)
    /* B02B4 002AF6B4 AFB20028 */  sw         $s2, 0x28($sp)
    /* B02B8 002AF6B8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B02BC 002AF6BC AFB00020 */   sw        $s0, 0x20($sp)
    /* B02C0 002AF6C0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B02C4 002AF6C4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B02C8 002AF6C8 14400044 */  bnez       $v0, .L002AF7DC
    /* B02CC 002AF6CC 00009021 */   addu      $s2, $zero, $zero
    /* B02D0 002AF6D0 93A20014 */  lbu        $v0, 0x14($sp)
    /* B02D4 002AF6D4 02202021 */  addu       $a0, $s1, $zero
    /* B02D8 002AF6D8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B02DC 002AF6DC 00028200 */   sll       $s0, $v0, 8
    /* B02E0 002AF6E0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B02E4 002AF6E4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B02E8 002AF6E8 1440003D */  bnez       $v0, .L002AF7E0
    /* B02EC 002AF6EC 02401021 */   addu      $v0, $s2, $zero
    /* B02F0 002AF6F0 93A20014 */  lbu        $v0, 0x14($sp)
    /* B02F4 002AF6F4 02202021 */  addu       $a0, $s1, $zero
    /* B02F8 002AF6F8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B02FC 002AF6FC 02028025 */   or        $s0, $s0, $v0
    /* B0300 002AF700 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0304 002AF704 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0308 002AF708 14400034 */  bnez       $v0, .L002AF7DC
    /* B030C 002AF70C 00108200 */   sll       $s0, $s0, 8
    /* B0310 002AF710 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0314 002AF714 02202021 */  addu       $a0, $s1, $zero
    /* B0318 002AF718 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B031C 002AF71C 02028025 */   or        $s0, $s0, $v0
    /* B0320 002AF720 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0324 002AF724 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0328 002AF728 1440002C */  bnez       $v0, .L002AF7DC
    /* B032C 002AF72C 00108200 */   sll       $s0, $s0, 8
    /* B0330 002AF730 27B1001C */  addiu      $s1, $sp, 0x1C
    /* B0334 002AF734 93A20014 */  lbu        $v0, 0x14($sp)
    /* B0338 002AF738 02202021 */  addu       $a0, $s1, $zero
    /* B033C 002AF73C 02028025 */  or         $s0, $s0, $v0
    /* B0340 002AF740 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0344 002AF744 AFB00010 */   sw        $s0, 0x10($sp)
    /* B0348 002AF748 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B034C 002AF74C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0350 002AF750 14400023 */  bnez       $v0, .L002AF7E0
    /* B0354 002AF754 02401021 */   addu      $v0, $s2, $zero
    /* B0358 002AF758 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B035C 002AF75C 02202021 */  addu       $a0, $s1, $zero
    /* B0360 002AF760 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0364 002AF764 00028200 */   sll       $s0, $v0, 8
    /* B0368 002AF768 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B036C 002AF76C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0370 002AF770 1440001B */  bnez       $v0, .L002AF7E0
    /* B0374 002AF774 02401021 */   addu      $v0, $s2, $zero
    /* B0378 002AF778 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B037C 002AF77C 02202021 */  addu       $a0, $s1, $zero
    /* B0380 002AF780 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0384 002AF784 02028025 */   or        $s0, $s0, $v0
    /* B0388 002AF788 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B038C 002AF78C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0390 002AF790 14400012 */  bnez       $v0, .L002AF7DC
    /* B0394 002AF794 00108200 */   sll       $s0, $s0, 8
    /* B0398 002AF798 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B039C 002AF79C 02202021 */  addu       $a0, $s1, $zero
    /* B03A0 002AF7A0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B03A4 002AF7A4 02028025 */   or        $s0, $s0, $v0
    /* B03A8 002AF7A8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B03AC 002AF7AC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B03B0 002AF7B0 1440000A */  bnez       $v0, .L002AF7DC
    /* B03B4 002AF7B4 00108200 */   sll       $s0, $s0, 8
    /* B03B8 002AF7B8 93A2001C */  lbu        $v0, 0x1C($sp)
    /* B03BC 002AF7BC 8FA40010 */  lw         $a0, 0x10($sp)
    /* B03C0 002AF7C0 02028025 */  or         $s0, $s0, $v0
    /* B03C4 002AF7C4 02002821 */  addu       $a1, $s0, $zero
    /* B03C8 002AF7C8 0C0ABAAD */  jal        dbgLinkSendBlock
    /* B03CC 002AF7CC AFB00018 */   sw        $s0, 0x18($sp)
    /* B03D0 002AF7D0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B03D4 002AF7D4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B03D8 002AF7D8 2C520001 */  sltiu      $s2, $v0, 0x1
  .L002AF7DC:
    /* B03DC 002AF7DC 02401021 */  addu       $v0, $s2, $zero
  .L002AF7E0:
    /* B03E0 002AF7E0 8FBF002C */  lw         $ra, 0x2C($sp)
    /* B03E4 002AF7E4 8FB20028 */  lw         $s2, 0x28($sp)
    /* B03E8 002AF7E8 8FB10024 */  lw         $s1, 0x24($sp)
    /* B03EC 002AF7EC 8FB00020 */  lw         $s0, 0x20($sp)
    /* B03F0 002AF7F0 03E00008 */  jr         $ra
    /* B03F4 002AF7F4 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel dbgLinkCmdReadBlock
