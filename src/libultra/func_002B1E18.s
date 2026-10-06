.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2A18-0xB2A70 (VRAM 0x002B1E18) */
glabel func_002B1E18
    /* B2A18 002B1E18 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2A1C 002B1E1C 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B2A20 002B1E20 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B2A24 002B1E24 000420C0 */  sll        $a0, $a0, 3
    /* B2A28 002B1E28 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2A2C 002B1E2C AFB00010 */  sw         $s0, 0x10($sp)
    /* B2A30 002B1E30 304200F7 */  andi       $v0, $v0, 0xF7
    /* B2A34 002B1E34 00441025 */  or         $v0, $v0, $a0
    /* B2A38 002B1E38 00408021 */  addu       $s0, $v0, $zero
    /* B2A3C 002B1E3C 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B2A40 002B1E40 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1E44:
    /* B2A44 002B1E44 0C0AF7A8 */  jal        osPiGetStatus
    /* B2A48 002B1E48 00000000 */   nop
    /* B2A4C 002B1E4C 30420003 */  andi       $v0, $v0, 0x3
    /* B2A50 002B1E50 1440FFFC */  bnez       $v0, .L002B1E44
    /* B2A54 002B1E54 320200FF */   andi      $v0, $s0, 0xFF
    /* B2A58 002B1E58 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2A5C 002B1E5C 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2A60 002B1E60 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B2A64 002B1E64 A4220004 */  sh         $v0, %lo(D_B2000004)($at)
    /* B2A68 002B1E68 03E00008 */  jr         $ra
    /* B2A6C 002B1E6C 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B1E18
