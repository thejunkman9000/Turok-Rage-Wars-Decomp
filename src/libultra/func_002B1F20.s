.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2B20-0xB2B74 (VRAM 0x002B1F20) */
glabel func_002B1F20
    /* B2B20 002B1F20 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B2B24 002B1F24 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B2B28 002B1F28 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2B2C 002B1F2C AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2B30 002B1F30 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2B34 002B1F34 304200FE */  andi       $v0, $v0, 0xFE
    /* B2B38 002B1F38 00822025 */  or         $a0, $a0, $v0
    /* B2B3C 002B1F3C 00808021 */  addu       $s0, $a0, $zero
    /* B2B40 002B1F40 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B2B44 002B1F44 A024D3E1 */  sb         $a0, %lo(D_8014D3E1)($at)
  .L002B1F48:
    /* B2B48 002B1F48 0C0AF7A8 */  jal        osPiGetStatus
    /* B2B4C 002B1F4C 00000000 */   nop
    /* B2B50 002B1F50 30420003 */  andi       $v0, $v0, 0x3
    /* B2B54 002B1F54 1440FFFC */  bnez       $v0, .L002B1F48
    /* B2B58 002B1F58 320200FF */   andi      $v0, $s0, 0xFF
    /* B2B5C 002B1F5C 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2B60 002B1F60 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2B64 002B1F64 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B2B68 002B1F68 A4220004 */  sh         $v0, %lo(D_B2000004)($at)
    /* B2B6C 002B1F6C 03E00008 */  jr         $ra
    /* B2B70 002B1F70 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B1F20
