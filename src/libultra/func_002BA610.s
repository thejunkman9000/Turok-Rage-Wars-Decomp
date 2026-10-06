.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB210-0xBB240 (VRAM 0x002BA610) */
glabel func_002BA610
    /* BB210 002BA610 8C87001C */  lw         $a3, 0x1C($a0)
    /* BB214 002BA614 24020002 */  addiu      $v0, $zero, 0x2
    /* BB218 002BA618 14A20007 */  bne        $a1, $v0, .L002BA638
    /* BB21C 002BA61C 00000000 */   nop
    /* BB220 002BA620 8C830014 */  lw         $v1, 0x14($a0)
    /* BB224 002BA624 00431004 */  sllv       $v0, $v1, $v0
    /* BB228 002BA628 24630001 */  addiu      $v1, $v1, 0x1
    /* BB22C 002BA62C 00471021 */  addu       $v0, $v0, $a3
    /* BB230 002BA630 AC460000 */  sw         $a2, 0x0($v0)
    /* BB234 002BA634 AC830014 */  sw         $v1, 0x14($a0)
  .L002BA638:
    /* BB238 002BA638 03E00008 */  jr         $ra
    /* BB23C 002BA63C 00001021 */   addu      $v0, $zero, $zero
endlabel func_002BA610
