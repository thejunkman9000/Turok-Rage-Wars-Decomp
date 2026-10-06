.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8120-0xB8150 (VRAM 0x002B7520) */
glabel func_002B7520
    /* B8120 002B7520 8C830000 */  lw         $v1, 0x0($a0)
    /* B8124 002B7524 10600003 */  beqz       $v1, .L002B7534
    /* B8128 002B7528 00000000 */   nop
    /* B812C 002B752C 8C820004 */  lw         $v0, 0x4($a0)
    /* B8130 002B7530 AC620004 */  sw         $v0, 0x4($v1)
  .L002B7534:
    /* B8134 002B7534 8C830004 */  lw         $v1, 0x4($a0)
    /* B8138 002B7538 10600003 */  beqz       $v1, .L002B7548
    /* B813C 002B753C 00000000 */   nop
    /* B8140 002B7540 8C820000 */  lw         $v0, 0x0($a0)
    /* B8144 002B7544 AC620000 */  sw         $v0, 0x0($v1)
  .L002B7548:
    /* B8148 002B7548 03E00008 */  jr         $ra
    /* B814C 002B754C 00000000 */   nop
endlabel func_002B7520
