.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2E14-0xB2EE4 (VRAM 0x002B2214) */
glabel func_002B2214
    /* B2E14 002B2214 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B2E18 002B2218 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B2E1C 002B221C 27B10014 */  addiu      $s1, $sp, 0x14
    /* B2E20 002B2220 02202021 */  addu       $a0, $s1, $zero
    /* B2E24 002B2224 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B2E28 002B2228 AFB20020 */  sw         $s2, 0x20($sp)
    /* B2E2C 002B222C 0C0AB8E0 */  jal        func_002AE380
    /* B2E30 002B2230 AFB00018 */   sw        $s0, 0x18($sp)
    /* B2E34 002B2234 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2E38 002B2238 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2E3C 002B223C 14400022 */  bnez       $v0, .L002B22C8
    /* B2E40 002B2240 00009021 */   addu      $s2, $zero, $zero
    /* B2E44 002B2244 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2E48 002B2248 02202021 */  addu       $a0, $s1, $zero
    /* B2E4C 002B224C 0C0AB8E0 */  jal        func_002AE380
    /* B2E50 002B2250 00028200 */   sll       $s0, $v0, 8
    /* B2E54 002B2254 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2E58 002B2258 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2E5C 002B225C 1440001B */  bnez       $v0, .L002B22CC
    /* B2E60 002B2260 02401021 */   addu      $v0, $s2, $zero
    /* B2E64 002B2264 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2E68 002B2268 02202021 */  addu       $a0, $s1, $zero
    /* B2E6C 002B226C 0C0AB8E0 */  jal        func_002AE380
    /* B2E70 002B2270 02028025 */   or        $s0, $s0, $v0
    /* B2E74 002B2274 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2E78 002B2278 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2E7C 002B227C 14400012 */  bnez       $v0, .L002B22C8
    /* B2E80 002B2280 00108200 */   sll       $s0, $s0, 8
    /* B2E84 002B2284 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2E88 002B2288 02202021 */  addu       $a0, $s1, $zero
    /* B2E8C 002B228C 0C0AB8E0 */  jal        func_002AE380
    /* B2E90 002B2290 02028025 */   or        $s0, $s0, $v0
    /* B2E94 002B2294 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2E98 002B2298 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2E9C 002B229C 1440000A */  bnez       $v0, .L002B22C8
    /* B2EA0 002B22A0 00108200 */   sll       $s0, $s0, 8
    /* B2EA4 002B22A4 93A20014 */  lbu        $v0, 0x14($sp)
    /* B2EA8 002B22A8 02028025 */  or         $s0, $s0, $v0
    /* B2EAC 002B22AC AFB00010 */  sw         $s0, 0x10($sp)
    /* B2EB0 002B22B0 92040000 */  lbu        $a0, 0x0($s0)
    /* B2EB4 002B22B4 0C0AB96B */  jal        func_002AE5AC
    /* B2EB8 002B22B8 00000000 */   nop
    /* B2EBC 002B22BC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2EC0 002B22C0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2EC4 002B22C4 2C520001 */  sltiu      $s2, $v0, 0x1
  .L002B22C8:
    /* B2EC8 002B22C8 02401021 */  addu       $v0, $s2, $zero
  .L002B22CC:
    /* B2ECC 002B22CC 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B2ED0 002B22D0 8FB20020 */  lw         $s2, 0x20($sp)
    /* B2ED4 002B22D4 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B2ED8 002B22D8 8FB00018 */  lw         $s0, 0x18($sp)
    /* B2EDC 002B22DC 03E00008 */  jr         $ra
    /* B2EE0 002B22E0 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B2214
