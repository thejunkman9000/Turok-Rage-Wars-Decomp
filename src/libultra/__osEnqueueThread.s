.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC21F8-0xC2248 (VRAM 0x002C15F8) */
glabel __osEnqueueThread
    /* C21F8 002C15F8 0080C821 */  addu       $t9, $a0, $zero
    /* C21FC 002C15FC 8C980000 */  lw         $t8, 0x0($a0)
    /* C2200 002C1600 8CAF0004 */  lw         $t7, 0x4($a1)
    /* C2204 002C1604 8F0E0004 */  lw         $t6, 0x4($t8)
    /* C2208 002C1608 00000000 */  nop
    /* C220C 002C160C 01CF082A */  slt        $at, $t6, $t7
    /* C2210 002C1610 14200008 */  bnez       $at, .L002C1634
    /* C2214 002C1614 00000000 */   nop
  .L002C1618:
    /* C2218 002C1618 0300C821 */  addu       $t9, $t8, $zero
    /* C221C 002C161C 8F180000 */  lw         $t8, 0x0($t8)
    /* C2220 002C1620 00000000 */  nop
    /* C2224 002C1624 8F0E0004 */  lw         $t6, 0x4($t8)
    /* C2228 002C1628 00000000 */  nop
    /* C222C 002C162C 01CF082A */  slt        $at, $t6, $t7
    /* C2230 002C1630 1020FFF9 */  beqz       $at, .L002C1618
  .L002C1634:
    /* C2234 002C1634 8F380000 */   lw        $t8, 0x0($t9)
    /* C2238 002C1638 AF250000 */  sw         $a1, 0x0($t9)
    /* C223C 002C163C ACB80000 */  sw         $t8, 0x0($a1)
    /* C2240 002C1640 03E00008 */  jr         $ra
    /* C2244 002C1644 ACA40008 */   sw        $a0, 0x8($a1)
endlabel __osEnqueueThread
