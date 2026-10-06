.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB296C-0xB29C0 (VRAM 0x002B1D6C) */
glabel dbgPortSetLineFormat
    /* B296C 002B1D6C 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* B2970 002B1D70 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* B2974 002B1D74 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2978 002B1D78 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B297C 002B1D7C AFB00010 */  sw         $s0, 0x10($sp)
    /* B2980 002B1D80 304200F8 */  andi       $v0, $v0, 0xF8
    /* B2984 002B1D84 00822025 */  or         $a0, $a0, $v0
    /* B2988 002B1D88 00808021 */  addu       $s0, $a0, $zero
    /* B298C 002B1D8C 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* B2990 002B1D90 A024D3E3 */  sb         $a0, %lo(D_8014D3E3)($at)
  .L002B1D94:
    /* B2994 002B1D94 0C0AF7A8 */  jal        osPiGetStatus
    /* B2998 002B1D98 00000000 */   nop
    /* B299C 002B1D9C 30420003 */  andi       $v0, $v0, 0x3
    /* B29A0 002B1DA0 1440FFFC */  bnez       $v0, .L002B1D94
    /* B29A4 002B1DA4 320200FF */   andi      $v0, $s0, 0xFF
    /* B29A8 002B1DA8 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B29AC 002B1DAC 8FB00010 */  lw         $s0, 0x10($sp)
    /* B29B0 002B1DB0 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* B29B4 002B1DB4 A422000C */  sh         $v0, %lo(D_B200000C)($at)
    /* B29B8 002B1DB8 03E00008 */  jr         $ra
    /* B29BC 002B1DBC 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel dbgPortSetLineFormat
