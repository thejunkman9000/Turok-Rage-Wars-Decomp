.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAFDF0-0xAFF3C (VRAM 0x002AF1F0) */
glabel dbgLinkCmdWriteWord
    /* AFDF0 002AF1F0 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* AFDF4 002AF1F4 AFB10024 */  sw         $s1, 0x24($sp)
    /* AFDF8 002AF1F8 27B10014 */  addiu      $s1, $sp, 0x14
    /* AFDFC 002AF1FC 02202021 */  addu       $a0, $s1, $zero
    /* AFE00 002AF200 AFBF002C */  sw         $ra, 0x2C($sp)
    /* AFE04 002AF204 AFB20028 */  sw         $s2, 0x28($sp)
    /* AFE08 002AF208 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFE0C 002AF20C AFB00020 */   sw        $s0, 0x20($sp)
    /* AFE10 002AF210 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFE14 002AF214 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFE18 002AF218 14400041 */  bnez       $v0, .L002AF320
    /* AFE1C 002AF21C 00009021 */   addu      $s2, $zero, $zero
    /* AFE20 002AF220 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFE24 002AF224 02202021 */  addu       $a0, $s1, $zero
    /* AFE28 002AF228 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFE2C 002AF22C 00028200 */   sll       $s0, $v0, 8
    /* AFE30 002AF230 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFE34 002AF234 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFE38 002AF238 1440003A */  bnez       $v0, .L002AF324
    /* AFE3C 002AF23C 02401021 */   addu      $v0, $s2, $zero
    /* AFE40 002AF240 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFE44 002AF244 02202021 */  addu       $a0, $s1, $zero
    /* AFE48 002AF248 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFE4C 002AF24C 02028025 */   or        $s0, $s0, $v0
    /* AFE50 002AF250 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFE54 002AF254 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFE58 002AF258 14400031 */  bnez       $v0, .L002AF320
    /* AFE5C 002AF25C 00108200 */   sll       $s0, $s0, 8
    /* AFE60 002AF260 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFE64 002AF264 02202021 */  addu       $a0, $s1, $zero
    /* AFE68 002AF268 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFE6C 002AF26C 02028025 */   or        $s0, $s0, $v0
    /* AFE70 002AF270 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFE74 002AF274 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFE78 002AF278 14400029 */  bnez       $v0, .L002AF320
    /* AFE7C 002AF27C 00108200 */   sll       $s0, $s0, 8
    /* AFE80 002AF280 27B1001C */  addiu      $s1, $sp, 0x1C
    /* AFE84 002AF284 93A20014 */  lbu        $v0, 0x14($sp)
    /* AFE88 002AF288 02202021 */  addu       $a0, $s1, $zero
    /* AFE8C 002AF28C 02028025 */  or         $s0, $s0, $v0
    /* AFE90 002AF290 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFE94 002AF294 AFB00010 */   sw        $s0, 0x10($sp)
    /* AFE98 002AF298 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFE9C 002AF29C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFEA0 002AF2A0 14400020 */  bnez       $v0, .L002AF324
    /* AFEA4 002AF2A4 02401021 */   addu      $v0, $s2, $zero
    /* AFEA8 002AF2A8 93A2001C */  lbu        $v0, 0x1C($sp)
    /* AFEAC 002AF2AC 02202021 */  addu       $a0, $s1, $zero
    /* AFEB0 002AF2B0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFEB4 002AF2B4 00028200 */   sll       $s0, $v0, 8
    /* AFEB8 002AF2B8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFEBC 002AF2BC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFEC0 002AF2C0 14400018 */  bnez       $v0, .L002AF324
    /* AFEC4 002AF2C4 02401021 */   addu      $v0, $s2, $zero
    /* AFEC8 002AF2C8 93A2001C */  lbu        $v0, 0x1C($sp)
    /* AFECC 002AF2CC 02202021 */  addu       $a0, $s1, $zero
    /* AFED0 002AF2D0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFED4 002AF2D4 02028025 */   or        $s0, $s0, $v0
    /* AFED8 002AF2D8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFEDC 002AF2DC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFEE0 002AF2E0 1440000F */  bnez       $v0, .L002AF320
    /* AFEE4 002AF2E4 00108200 */   sll       $s0, $s0, 8
    /* AFEE8 002AF2E8 93A2001C */  lbu        $v0, 0x1C($sp)
    /* AFEEC 002AF2EC 02202021 */  addu       $a0, $s1, $zero
    /* AFEF0 002AF2F0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* AFEF4 002AF2F4 02028025 */   or        $s0, $s0, $v0
    /* AFEF8 002AF2F8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AFEFC 002AF2FC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AFF00 002AF300 14400007 */  bnez       $v0, .L002AF320
    /* AFF04 002AF304 00108200 */   sll       $s0, $s0, 8
    /* AFF08 002AF308 24120001 */  addiu      $s2, $zero, 0x1
    /* AFF0C 002AF30C 93A2001C */  lbu        $v0, 0x1C($sp)
    /* AFF10 002AF310 8FA30010 */  lw         $v1, 0x10($sp)
    /* AFF14 002AF314 02028025 */  or         $s0, $s0, $v0
    /* AFF18 002AF318 AFB00018 */  sw         $s0, 0x18($sp)
    /* AFF1C 002AF31C AC700000 */  sw         $s0, 0x0($v1)
  .L002AF320:
    /* AFF20 002AF320 02401021 */  addu       $v0, $s2, $zero
  .L002AF324:
    /* AFF24 002AF324 8FBF002C */  lw         $ra, 0x2C($sp)
    /* AFF28 002AF328 8FB20028 */  lw         $s2, 0x28($sp)
    /* AFF2C 002AF32C 8FB10024 */  lw         $s1, 0x24($sp)
    /* AFF30 002AF330 8FB00020 */  lw         $s0, 0x20($sp)
    /* AFF34 002AF334 03E00008 */  jr         $ra
    /* AFF38 002AF338 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel dbgLinkCmdWriteWord
