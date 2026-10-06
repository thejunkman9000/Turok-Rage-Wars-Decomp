.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAFA48-0xAFB84 (VRAM 0x002AEE48) */
glabel dbgLinkCmdCallHook
    /* AFA48 002AEE48 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* AFA4C 002AEE4C AFB1001C */  sw         $s1, 0x1C($sp)
    /* AFA50 002AEE50 27B10014 */  addiu      $s1, $sp, 0x14
    /* AFA54 002AEE54 02202021 */  addu       $a0, $s1, $zero
    /* AFA58 002AEE58 AFBF0024 */  sw         $ra, 0x24($sp)
    /* AFA5C 002AEE5C AFB20020 */  sw         $s2, 0x20($sp)
    /* AFA60 002AEE60 AFB00018 */  sw         $s0, 0x18($sp)
    /* AFA64 002AEE64 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFA68 002AEE68 AFA00010 */   sw        $zero, 0x10($sp)
    /* AFA6C 002AEE6C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFA70 002AEE70 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFA74 002AEE74 1440003C */  bnez       $v0, .L002AEF68
    /* AFA78 002AEE78 00009021 */   addu      $s2, $zero, $zero
    /* AFA7C 002AEE7C 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFA80 002AEE80 02202021 */  addu       $a0, $s1, $zero
    /* AFA84 002AEE84 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFA88 002AEE88 00028200 */   sll       $s0, $v0, 8
    /* AFA8C 002AEE8C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFA90 002AEE90 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFA94 002AEE94 14400035 */  bnez       $v0, .L002AEF6C
    /* AFA98 002AEE98 00001021 */   addu      $v0, $zero, $zero
    /* AFA9C 002AEE9C 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFAA0 002AEEA0 02202021 */  addu       $a0, $s1, $zero
    /* AFAA4 002AEEA4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFAA8 002AEEA8 02028025 */   or        $s0, $s0, $v0
    /* AFAAC 002AEEAC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFAB0 002AEEB0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFAB4 002AEEB4 1440002C */  bnez       $v0, .L002AEF68
    /* AFAB8 002AEEB8 00108200 */   sll       $s0, $s0, 8
    /* AFABC 002AEEBC 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFAC0 002AEEC0 02202021 */  addu       $a0, $s1, $zero
    /* AFAC4 002AEEC4 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFAC8 002AEEC8 02028025 */   or        $s0, $s0, $v0
    /* AFACC 002AEECC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFAD0 002AEED0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFAD4 002AEED4 14400024 */  bnez       $v0, .L002AEF68
    /* AFAD8 002AEED8 00108200 */   sll       $s0, $s0, 8
    /* AFADC 002AEEDC 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFAE0 002AEEE0 3C03800D */  lui        $v1, %hi(D_800D364C)
    /* AFAE4 002AEEE4 8C63364C */  lw         $v1, %lo(D_800D364C)($v1)
    /* AFAE8 002AEEE8 02028025 */  or         $s0, $s0, $v0
    /* AFAEC 002AEEEC 10600004 */  beqz       $v1, .L002AEF00
    /* AFAF0 002AEEF0 AFB00010 */   sw        $s0, 0x10($sp)
    /* AFAF4 002AEEF4 0060F809 */  jalr       $v1
    /* AFAF8 002AEEF8 02002021 */   addu      $a0, $s0, $zero
    /* AFAFC 002AEEFC 00409021 */  addu       $s2, $v0, $zero
  .L002AEF00:
    /* AFB00 002AEF00 0C0AB96B */  jal        dbgLinkSendByte
    /* AFB04 002AEF04 00122602 */   srl       $a0, $s2, 24
    /* AFB08 002AEF08 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFB0C 002AEF0C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFB10 002AEF10 14400011 */  bnez       $v0, .L002AEF58
    /* AFB14 002AEF14 00000000 */   nop
    /* AFB18 002AEF18 00122402 */  srl        $a0, $s2, 16
    /* AFB1C 002AEF1C 0C0AB96B */  jal        dbgLinkSendByte
    /* AFB20 002AEF20 308400FF */   andi      $a0, $a0, 0xFF
    /* AFB24 002AEF24 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFB28 002AEF28 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFB2C 002AEF2C 1440000A */  bnez       $v0, .L002AEF58
    /* AFB30 002AEF30 00000000 */   nop
    /* AFB34 002AEF34 00122202 */  srl        $a0, $s2, 8
    /* AFB38 002AEF38 0C0AB96B */  jal        dbgLinkSendByte
    /* AFB3C 002AEF3C 308400FF */   andi      $a0, $a0, 0xFF
    /* AFB40 002AEF40 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFB44 002AEF44 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFB48 002AEF48 14400003 */  bnez       $v0, .L002AEF58
    /* AFB4C 002AEF4C 00000000 */   nop
    /* AFB50 002AEF50 0C0AB96B */  jal        dbgLinkSendByte
    /* AFB54 002AEF54 324400FF */   andi      $a0, $s2, 0xFF
  .L002AEF58:
    /* AFB58 002AEF58 3C038015 */  lui        $v1, %hi(D_8014D3E8)
    /* AFB5C 002AEF5C 8C63D3E8 */  lw         $v1, %lo(D_8014D3E8)($v1)
    /* AFB60 002AEF60 10600002 */  beqz       $v1, .L002AEF6C
    /* AFB64 002AEF64 24020001 */   addiu     $v0, $zero, 0x1
  .L002AEF68:
    /* AFB68 002AEF68 00001021 */  addu       $v0, $zero, $zero
  .L002AEF6C:
    /* AFB6C 002AEF6C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* AFB70 002AEF70 8FB20020 */  lw         $s2, 0x20($sp)
    /* AFB74 002AEF74 8FB1001C */  lw         $s1, 0x1C($sp)
    /* AFB78 002AEF78 8FB00018 */  lw         $s0, 0x18($sp)
    /* AFB7C 002AEF7C 03E00008 */  jr         $ra
    /* AFB80 002AEF80 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel dbgLinkCmdCallHook
