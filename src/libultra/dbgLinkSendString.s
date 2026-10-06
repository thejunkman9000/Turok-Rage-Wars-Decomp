.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2420-0xB2488 (VRAM 0x002B1820) */
glabel dbgLinkSendString
    /* B2420 002B1820 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B2424 002B1824 AFB10014 */  sw         $s1, 0x14($sp)
    /* B2428 002B1828 00808821 */  addu       $s1, $a0, $zero
    /* B242C 002B182C AFB20018 */  sw         $s2, 0x18($sp)
    /* B2430 002B1830 00009021 */  addu       $s2, $zero, $zero
    /* B2434 002B1834 AFBF001C */  sw         $ra, 0x1C($sp)
    /* B2438 002B1838 AFB00010 */  sw         $s0, 0x10($sp)
  .L002B183C:
    /* B243C 002B183C 92220000 */  lbu        $v0, 0x0($s1)
    /* B2440 002B1840 26310001 */  addiu      $s1, $s1, 0x1
    /* B2444 002B1844 305000FF */  andi       $s0, $v0, 0xFF
    /* B2448 002B1848 0C0AB96B */  jal        dbgLinkSendByte
    /* B244C 002B184C 02002021 */   addu      $a0, $s0, $zero
    /* B2450 002B1850 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2454 002B1854 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2458 002B1858 14400005 */  bnez       $v0, .L002B1870
    /* B245C 002B185C 02401021 */   addu      $v0, $s2, $zero
    /* B2460 002B1860 1600FFF6 */  bnez       $s0, .L002B183C
    /* B2464 002B1864 00000000 */   nop
    /* B2468 002B1868 24120001 */  addiu      $s2, $zero, 0x1
    /* B246C 002B186C 02401021 */  addu       $v0, $s2, $zero
  .L002B1870:
    /* B2470 002B1870 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B2474 002B1874 8FB20018 */  lw         $s2, 0x18($sp)
    /* B2478 002B1878 8FB10014 */  lw         $s1, 0x14($sp)
    /* B247C 002B187C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2480 002B1880 03E00008 */  jr         $ra
    /* B2484 002B1884 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel dbgLinkSendString
