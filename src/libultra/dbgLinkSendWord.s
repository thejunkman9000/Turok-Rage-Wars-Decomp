.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2390-0xB2420 (VRAM 0x002B1790) */
glabel dbgLinkSendWord
    /* B2390 002B1790 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B2394 002B1794 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2398 002B1798 00808021 */  addu       $s0, $a0, $zero
    /* B239C 002B179C 00102602 */  srl        $a0, $s0, 24
    /* B23A0 002B17A0 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B23A4 002B17A4 0C0AB96B */  jal        dbgLinkSendByte
    /* B23A8 002B17A8 AFB10014 */   sw        $s1, 0x14($sp)
    /* B23AC 002B17AC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B23B0 002B17B0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B23B4 002B17B4 14400014 */  bnez       $v0, .L002B1808
    /* B23B8 002B17B8 00008821 */   addu      $s1, $zero, $zero
    /* B23BC 002B17BC 00102402 */  srl        $a0, $s0, 16
    /* B23C0 002B17C0 0C0AB96B */  jal        dbgLinkSendByte
    /* B23C4 002B17C4 308400FF */   andi      $a0, $a0, 0xFF
    /* B23C8 002B17C8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B23CC 002B17CC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B23D0 002B17D0 1440000E */  bnez       $v0, .L002B180C
    /* B23D4 002B17D4 02201021 */   addu      $v0, $s1, $zero
    /* B23D8 002B17D8 00102202 */  srl        $a0, $s0, 8
    /* B23DC 002B17DC 0C0AB96B */  jal        dbgLinkSendByte
    /* B23E0 002B17E0 308400FF */   andi      $a0, $a0, 0xFF
    /* B23E4 002B17E4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B23E8 002B17E8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B23EC 002B17EC 14400007 */  bnez       $v0, .L002B180C
    /* B23F0 002B17F0 02201021 */   addu      $v0, $s1, $zero
    /* B23F4 002B17F4 0C0AB96B */  jal        dbgLinkSendByte
    /* B23F8 002B17F8 320400FF */   andi      $a0, $s0, 0xFF
    /* B23FC 002B17FC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2400 002B1800 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2404 002B1804 2C510001 */  sltiu      $s1, $v0, 0x1
  .L002B1808:
    /* B2408 002B1808 02201021 */  addu       $v0, $s1, $zero
  .L002B180C:
    /* B240C 002B180C 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B2410 002B1810 8FB10014 */  lw         $s1, 0x14($sp)
    /* B2414 002B1814 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2418 002B1818 03E00008 */  jr         $ra
    /* B241C 002B181C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel dbgLinkSendWord
