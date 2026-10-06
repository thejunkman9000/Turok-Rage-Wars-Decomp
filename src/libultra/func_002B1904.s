.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2504-0xB25C0 (VRAM 0x002B1904) */
glabel func_002B1904
    /* B2504 002B1904 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B2508 002B1908 AFB10014 */  sw         $s1, 0x14($sp)
    /* B250C 002B190C 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B2510 002B1910 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B2514 002B1914 AFB60028 */  sw         $s6, 0x28($sp)
    /* B2518 002B1918 0080B021 */  addu       $s6, $a0, $zero
    /* B251C 002B191C AFB50024 */  sw         $s5, 0x24($sp)
    /* B2520 002B1920 00A0A821 */  addu       $s5, $a1, $zero
    /* B2524 002B1924 AFB20018 */  sw         $s2, 0x18($sp)
    /* B2528 002B1928 00009021 */  addu       $s2, $zero, $zero
    /* B252C 002B192C AFB3001C */  sw         $s3, 0x1C($sp)
    /* B2530 002B1930 00E09821 */  addu       $s3, $a3, $zero
    /* B2534 002B1934 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2538 002B1938 02608021 */  addu       $s0, $s3, $zero
    /* B253C 002B193C AFB40020 */  sw         $s4, 0x20($sp)
    /* B2540 002B1940 30D400FF */  andi       $s4, $a2, 0xFF
    /* B2544 002B1944 AFBF002C */  sw         $ra, 0x2C($sp)
  .L002B1948:
    /* B2548 002B1948 0C0AF7A8 */  jal        osPiGetStatus
    /* B254C 002B194C 00000000 */   nop
    /* B2550 002B1950 30420003 */  andi       $v0, $v0, 0x3
    /* B2554 002B1954 1440FFFC */  bnez       $v0, .L002B1948
    /* B2558 002B1958 00000000 */   nop
    /* B255C 002B195C 92C20001 */  lbu        $v0, 0x1($s6)
    /* B2560 002B1960 02A21024 */  and        $v0, $s5, $v0
    /* B2564 002B1964 14540003 */  bne        $v0, $s4, .L002B1974
    /* B2568 002B1968 02001021 */   addu      $v0, $s0, $zero
    /* B256C 002B196C 080AC665 */  j          .L002B1994
    /* B2570 002B1970 24120001 */   addiu     $s2, $zero, 0x1
  .L002B1974:
    /* B2574 002B1974 14400003 */  bnez       $v0, .L002B1984
    /* B2578 002B1978 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B257C 002B197C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B2580 002B1980 02608021 */  addu       $s0, $s3, $zero
  .L002B1984:
    /* B2584 002B1984 1E20FFF0 */  bgtz       $s1, .L002B1948
    /* B2588 002B1988 24020001 */   addiu     $v0, $zero, 0x1
    /* B258C 002B198C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B2590 002B1990 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B1994:
    /* B2594 002B1994 02401021 */  addu       $v0, $s2, $zero
    /* B2598 002B1998 8FBF002C */  lw         $ra, 0x2C($sp)
    /* B259C 002B199C 8FB60028 */  lw         $s6, 0x28($sp)
    /* B25A0 002B19A0 8FB50024 */  lw         $s5, 0x24($sp)
    /* B25A4 002B19A4 8FB40020 */  lw         $s4, 0x20($sp)
    /* B25A8 002B19A8 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B25AC 002B19AC 8FB20018 */  lw         $s2, 0x18($sp)
    /* B25B0 002B19B0 8FB10014 */  lw         $s1, 0x14($sp)
    /* B25B4 002B19B4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B25B8 002B19B8 03E00008 */  jr         $ra
    /* B25BC 002B19BC 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002B1904
