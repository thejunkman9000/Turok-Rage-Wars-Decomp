.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2C50-0xB2D34 (VRAM 0x002B2050) */
glabel func_002B2050
    /* B2C50 002B2050 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B2C54 002B2054 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B2C58 002B2058 27B10014 */  addiu      $s1, $sp, 0x14
    /* B2C5C 002B205C 02202021 */  addu       $a0, $s1, $zero
    /* B2C60 002B2060 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B2C64 002B2064 AFB20020 */  sw         $s2, 0x20($sp)
    /* B2C68 002B2068 0C0AB8E0 */  jal        func_002AE380
    /* B2C6C 002B206C AFB00018 */   sw        $s0, 0x18($sp)
    /* B2C70 002B2070 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2C74 002B2074 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2C78 002B2078 14400027 */  bnez       $v0, .L002B2118
    /* B2C7C 002B207C 00009021 */   addu      $s2, $zero, $zero
    /* B2C80 002B2080 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2C84 002B2084 02202021 */  addu       $a0, $s1, $zero
    /* B2C88 002B2088 0C0AB8E0 */  jal        func_002AE380
    /* B2C8C 002B208C 00028200 */   sll       $s0, $v0, 8
    /* B2C90 002B2090 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2C94 002B2094 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2C98 002B2098 14400020 */  bnez       $v0, .L002B211C
    /* B2C9C 002B209C 02401021 */   addu      $v0, $s2, $zero
    /* B2CA0 002B20A0 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2CA4 002B20A4 02202021 */  addu       $a0, $s1, $zero
    /* B2CA8 002B20A8 0C0AB8E0 */  jal        func_002AE380
    /* B2CAC 002B20AC 02028025 */   or        $s0, $s0, $v0
    /* B2CB0 002B20B0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2CB4 002B20B4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2CB8 002B20B8 14400017 */  bnez       $v0, .L002B2118
    /* B2CBC 002B20BC 00108200 */   sll       $s0, $s0, 8
    /* B2CC0 002B20C0 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2CC4 002B20C4 02202021 */  addu       $a0, $s1, $zero
    /* B2CC8 002B20C8 0C0AB8E0 */  jal        func_002AE380
    /* B2CCC 002B20CC 02028025 */   or        $s0, $s0, $v0
    /* B2CD0 002B20D0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2CD4 002B20D4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2CD8 002B20D8 1440000F */  bnez       $v0, .L002B2118
    /* B2CDC 002B20DC 00108200 */   sll       $s0, $s0, 8
    /* B2CE0 002B20E0 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2CE4 002B20E4 02028025 */  or         $s0, $s0, $v0
    /* B2CE8 002B20E8 1200000A */  beqz       $s0, .L002B2114
    /* B2CEC 002B20EC AFB00010 */   sw        $s0, 0x10($sp)
    /* B2CF0 002B20F0 0C0B0898 */  jal        osSetIntMask
    /* B2CF4 002B20F4 24040001 */   addiu     $a0, $zero, 0x1
    /* B2CF8 002B20F8 0C0B08F8 */  jal        osWritebackDCacheAll
    /* B2CFC 002B20FC 00000000 */   nop
    /* B2D00 002B2100 3C048000 */  lui        $a0, (0x80000000 >> 16)
    /* B2D04 002B2104 0C0B0840 */  jal        osInvalICache
    /* B2D08 002B2108 3C050080 */   lui       $a1, (0x800000 >> 16)
    /* B2D0C 002B210C 0200F809 */  jalr       $s0
    /* B2D10 002B2110 00000000 */   nop
  .L002B2114:
    /* B2D14 002B2114 24120001 */  addiu      $s2, $zero, 0x1
  .L002B2118:
    /* B2D18 002B2118 02401021 */  addu       $v0, $s2, $zero
  .L002B211C:
    /* B2D1C 002B211C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B2D20 002B2120 8FB20020 */  lw         $s2, 0x20($sp)
    /* B2D24 002B2124 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B2D28 002B2128 8FB00018 */  lw         $s0, 0x18($sp)
    /* B2D2C 002B212C 03E00008 */  jr         $ra
    /* B2D30 002B2130 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B2050
