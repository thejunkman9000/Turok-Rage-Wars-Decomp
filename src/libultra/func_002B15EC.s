.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB21EC-0xB22B4 (VRAM 0x002B15EC) */
glabel func_002B15EC
    /* B21EC 002B15EC 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* B21F0 002B15F0 AFB30024 */  sw         $s3, 0x24($sp)
    /* B21F4 002B15F4 00809821 */  addu       $s3, $a0, $zero
    /* B21F8 002B15F8 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B21FC 002B15FC 27B10010 */  addiu      $s1, $sp, 0x10
    /* B2200 002B1600 02202021 */  addu       $a0, $s1, $zero
    /* B2204 002B1604 AFBF0028 */  sw         $ra, 0x28($sp)
    /* B2208 002B1608 AFB20020 */  sw         $s2, 0x20($sp)
    /* B220C 002B160C 0C0AB8E0 */  jal        func_002AE380
    /* B2210 002B1610 AFB00018 */   sw        $s0, 0x18($sp)
    /* B2214 002B1614 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2218 002B1618 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B221C 002B161C 1440001D */  bnez       $v0, .L002B1694
    /* B2220 002B1620 00009021 */   addu      $s2, $zero, $zero
    /* B2224 002B1624 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2228 002B1628 02202021 */  addu       $a0, $s1, $zero
    /* B222C 002B162C 0C0AB8E0 */  jal        func_002AE380
    /* B2230 002B1630 00028200 */   sll       $s0, $v0, 8
    /* B2234 002B1634 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2238 002B1638 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B223C 002B163C 14400016 */  bnez       $v0, .L002B1698
    /* B2240 002B1640 02401021 */   addu      $v0, $s2, $zero
    /* B2244 002B1644 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2248 002B1648 02202021 */  addu       $a0, $s1, $zero
    /* B224C 002B164C 0C0AB8E0 */  jal        func_002AE380
    /* B2250 002B1650 02028025 */   or        $s0, $s0, $v0
    /* B2254 002B1654 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2258 002B1658 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B225C 002B165C 1440000D */  bnez       $v0, .L002B1694
    /* B2260 002B1660 00108200 */   sll       $s0, $s0, 8
    /* B2264 002B1664 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2268 002B1668 02202021 */  addu       $a0, $s1, $zero
    /* B226C 002B166C 0C0AB8E0 */  jal        func_002AE380
    /* B2270 002B1670 02028025 */   or        $s0, $s0, $v0
    /* B2274 002B1674 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2278 002B1678 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B227C 002B167C 14400005 */  bnez       $v0, .L002B1694
    /* B2280 002B1680 00108200 */   sll       $s0, $s0, 8
    /* B2284 002B1684 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2288 002B1688 24120001 */  addiu      $s2, $zero, 0x1
    /* B228C 002B168C 02028025 */  or         $s0, $s0, $v0
    /* B2290 002B1690 AE700000 */  sw         $s0, 0x0($s3)
  .L002B1694:
    /* B2294 002B1694 02401021 */  addu       $v0, $s2, $zero
  .L002B1698:
    /* B2298 002B1698 8FBF0028 */  lw         $ra, 0x28($sp)
    /* B229C 002B169C 8FB30024 */  lw         $s3, 0x24($sp)
    /* B22A0 002B16A0 8FB20020 */  lw         $s2, 0x20($sp)
    /* B22A4 002B16A4 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B22A8 002B16A8 8FB00018 */  lw         $s0, 0x18($sp)
    /* B22AC 002B16AC 03E00008 */  jr         $ra
    /* B22B0 002B16B0 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002B15EC
