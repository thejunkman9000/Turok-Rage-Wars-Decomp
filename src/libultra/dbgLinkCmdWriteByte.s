.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2D34-0xB2E14 (VRAM 0x002B2134) */
glabel dbgLinkCmdWriteByte
    /* B2D34 002B2134 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B2D38 002B2138 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B2D3C 002B213C 27B10014 */  addiu      $s1, $sp, 0x14
    /* B2D40 002B2140 02202021 */  addu       $a0, $s1, $zero
    /* B2D44 002B2144 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B2D48 002B2148 AFB20020 */  sw         $s2, 0x20($sp)
    /* B2D4C 002B214C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B2D50 002B2150 AFB00018 */   sw        $s0, 0x18($sp)
    /* B2D54 002B2154 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2D58 002B2158 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2D5C 002B215C 14400026 */  bnez       $v0, .L002B21F8
    /* B2D60 002B2160 00009021 */   addu      $s2, $zero, $zero
    /* B2D64 002B2164 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2D68 002B2168 02202021 */  addu       $a0, $s1, $zero
    /* B2D6C 002B216C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B2D70 002B2170 00028200 */   sll       $s0, $v0, 8
    /* B2D74 002B2174 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2D78 002B2178 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2D7C 002B217C 1440001F */  bnez       $v0, .L002B21FC
    /* B2D80 002B2180 02401021 */   addu      $v0, $s2, $zero
    /* B2D84 002B2184 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2D88 002B2188 02202021 */  addu       $a0, $s1, $zero
    /* B2D8C 002B218C 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B2D90 002B2190 02028025 */   or        $s0, $s0, $v0
    /* B2D94 002B2194 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2D98 002B2198 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2D9C 002B219C 14400016 */  bnez       $v0, .L002B21F8
    /* B2DA0 002B21A0 00108200 */   sll       $s0, $s0, 8
    /* B2DA4 002B21A4 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2DA8 002B21A8 02202021 */  addu       $a0, $s1, $zero
    /* B2DAC 002B21AC 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B2DB0 002B21B0 02028025 */   or        $s0, $s0, $v0
    /* B2DB4 002B21B4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2DB8 002B21B8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2DBC 002B21BC 1440000E */  bnez       $v0, .L002B21F8
    /* B2DC0 002B21C0 00108200 */   sll       $s0, $s0, 8
    /* B2DC4 002B21C4 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2DC8 002B21C8 27A40015 */  addiu      $a0, $sp, 0x15
    /* B2DCC 002B21CC 02028025 */  or         $s0, $s0, $v0
    /* B2DD0 002B21D0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B2DD4 002B21D4 AFB00010 */   sw        $s0, 0x10($sp)
    /* B2DD8 002B21D8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2DDC 002B21DC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2DE0 002B21E0 14400006 */  bnez       $v0, .L002B21FC
    /* B2DE4 002B21E4 02401021 */   addu      $v0, $s2, $zero
    /* B2DE8 002B21E8 8FA30010 */  lw         $v1, 0x10($sp)
    /* B2DEC 002B21EC 93A20015 */  lbu        $v0, 0x15($sp)
    /* B2DF0 002B21F0 24120001 */  addiu      $s2, $zero, 0x1
    /* B2DF4 002B21F4 A0620000 */  sb         $v0, 0x0($v1)
  .L002B21F8:
    /* B2DF8 002B21F8 02401021 */  addu       $v0, $s2, $zero
  .L002B21FC:
    /* B2DFC 002B21FC 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B2E00 002B2200 8FB20020 */  lw         $s2, 0x20($sp)
    /* B2E04 002B2204 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B2E08 002B2208 8FB00018 */  lw         $s0, 0x18($sp)
    /* B2E0C 002B220C 03E00008 */  jr         $ra
    /* B2E10 002B2210 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel dbgLinkCmdWriteByte
