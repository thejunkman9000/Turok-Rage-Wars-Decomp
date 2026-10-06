.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2A70-0xB2AC8 (VRAM 0x002B1E70) */
glabel func_002B1E70
    /* B2A70 002B1E70 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2A74 002B1E74 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B2A78 002B1E78 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B2A7C 002B1E7C 00042080 */  sll        $a0, $a0, 2
    /* B2A80 002B1E80 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2A84 002B1E84 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2A88 002B1E88 304200FB */  andi       $v0, $v0, 0xFB
    /* B2A8C 002B1E8C 00441025 */  or         $v0, $v0, $a0
    /* B2A90 002B1E90 00408021 */  addu       $s0, $v0, $zero
    /* B2A94 002B1E94 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B2A98 002B1E98 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B1E9C:
    /* B2A9C 002B1E9C 0C0AF7A8 */  jal        osPiGetStatus
    /* B2AA0 002B1EA0 00000000 */   nop
    /* B2AA4 002B1EA4 30420003 */  andi       $v0, $v0, 0x3
    /* B2AA8 002B1EA8 1440FFFC */  bnez       $v0, .L002B1E9C
    /* B2AAC 002B1EAC 320200FF */   andi      $v0, $s0, 0xFF
    /* B2AB0 002B1EB0 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2AB4 002B1EB4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2AB8 002B1EB8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B2ABC 002B1EBC A4220004 */  sh         $v0, %lo(D_B2000004)($at)
    /* B2AC0 002B1EC0 03E00008 */  jr         $ra
    /* B2AC4 002B1EC4 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B1E70
