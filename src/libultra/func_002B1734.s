.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2334-0xB2390 (VRAM 0x002B1734) */
glabel func_002B1734
    /* B2334 002B1734 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B2338 002B1738 AFB10014 */  sw         $s1, 0x14($sp)
    /* B233C 002B173C 00808821 */  addu       $s1, $a0, $zero
    /* B2340 002B1740 00112202 */  srl        $a0, $s1, 8
    /* B2344 002B1744 308400FF */  andi       $a0, $a0, 0xFF
    /* B2348 002B1748 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B234C 002B174C 0C0AB96B */  jal        func_002AE5AC
    /* B2350 002B1750 AFB00010 */   sw        $s0, 0x10($sp)
    /* B2354 002B1754 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2358 002B1758 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B235C 002B175C 14400006 */  bnez       $v0, .L002B1778
    /* B2360 002B1760 00008021 */   addu      $s0, $zero, $zero
    /* B2364 002B1764 0C0AB96B */  jal        func_002AE5AC
    /* B2368 002B1768 322400FF */   andi      $a0, $s1, 0xFF
    /* B236C 002B176C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2370 002B1770 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2374 002B1774 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B1778:
    /* B2378 002B1778 02001021 */  addu       $v0, $s0, $zero
    /* B237C 002B177C 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B2380 002B1780 8FB10014 */  lw         $s1, 0x14($sp)
    /* B2384 002B1784 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2388 002B1788 03E00008 */  jr         $ra
    /* B238C 002B178C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B1734
