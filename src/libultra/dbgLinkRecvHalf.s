.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB216C-0xB21EC (VRAM 0x002B156C) */
glabel dbgLinkRecvHalf
    /* B216C 002B156C 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B2170 002B1570 AFB20020 */  sw         $s2, 0x20($sp)
    /* B2174 002B1574 00809021 */  addu       $s2, $a0, $zero
    /* B2178 002B1578 AFB00018 */  sw         $s0, 0x18($sp)
    /* B217C 002B157C 27B00010 */  addiu      $s0, $sp, 0x10
    /* B2180 002B1580 02002021 */  addu       $a0, $s0, $zero
    /* B2184 002B1584 AFBF0024 */  sw         $ra, 0x24($sp)
    /* B2188 002B1588 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B218C 002B158C AFB1001C */   sw        $s1, 0x1C($sp)
    /* B2190 002B1590 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2194 002B1594 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2198 002B1598 1440000D */  bnez       $v0, .L002B15D0
    /* B219C 002B159C 00008821 */   addu      $s1, $zero, $zero
    /* B21A0 002B15A0 93A20010 */  lbu        $v0, 0x10($sp)
    /* B21A4 002B15A4 02002021 */  addu       $a0, $s0, $zero
    /* B21A8 002B15A8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B21AC 002B15AC 00028200 */   sll       $s0, $v0, 8
    /* B21B0 002B15B0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B21B4 002B15B4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B21B8 002B15B8 14400006 */  bnez       $v0, .L002B15D4
    /* B21BC 002B15BC 02201021 */   addu      $v0, $s1, $zero
    /* B21C0 002B15C0 93A20010 */  lbu        $v0, 0x10($sp)
    /* B21C4 002B15C4 24110001 */  addiu      $s1, $zero, 0x1
    /* B21C8 002B15C8 02021025 */  or         $v0, $s0, $v0
    /* B21CC 002B15CC A6420000 */  sh         $v0, 0x0($s2)
  .L002B15D0:
    /* B21D0 002B15D0 02201021 */  addu       $v0, $s1, $zero
  .L002B15D4:
    /* B21D4 002B15D4 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B21D8 002B15D8 8FB20020 */  lw         $s2, 0x20($sp)
    /* B21DC 002B15DC 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B21E0 002B15E0 8FB00018 */  lw         $s0, 0x18($sp)
    /* B21E4 002B15E4 03E00008 */  jr         $ra
    /* B21E8 002B15E8 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel dbgLinkRecvHalf
