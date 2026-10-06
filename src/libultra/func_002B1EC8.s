.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2AC8-0xB2B20 (VRAM 0x002B1EC8) */
glabel func_002B1EC8
    /* B2AC8 002B1EC8 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2ACC 002B1ECC 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B2AD0 002B1ED0 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B2AD4 002B1ED4 00042040 */  sll        $a0, $a0, 1
    /* B2AD8 002B1ED8 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2ADC 002B1EDC AFB00010 */  sw         $s0, 0x10($sp)
    /* B2AE0 002B1EE0 304200FD */  andi       $v0, $v0, 0xFD
    /* B2AE4 002B1EE4 00441025 */  or         $v0, $v0, $a0
    /* B2AE8 002B1EE8 00408021 */  addu       $s0, $v0, $zero
    /* B2AEC 002B1EEC 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B2AF0 002B1EF0 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1EF4:
    /* B2AF4 002B1EF4 0C0AF7A8 */  jal        osPiGetStatus
    /* B2AF8 002B1EF8 00000000 */   nop
    /* B2AFC 002B1EFC 30420003 */  andi       $v0, $v0, 0x3
    /* B2B00 002B1F00 1440FFFC */  bnez       $v0, .L002B1EF4
    /* B2B04 002B1F04 320200FF */   andi      $v0, $s0, 0xFF
    /* B2B08 002B1F08 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2B0C 002B1F0C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2B10 002B1F10 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B2B14 002B1F14 A4220004 */  sh         $v0, %lo(D_B2000004)($at)
    /* B2B18 002B1F18 03E00008 */  jr         $ra
    /* B2B1C 002B1F1C 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B1EC8
