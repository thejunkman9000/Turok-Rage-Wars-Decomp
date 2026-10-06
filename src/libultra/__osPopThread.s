.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2248-0xC2260 (VRAM 0x002C1648) */
glabel __osPopThread
    /* C2248 002C1648 8C820000 */  lw         $v0, 0x0($a0)
    /* C224C 002C164C 00000000 */  nop
    /* C2250 002C1650 8C590000 */  lw         $t9, 0x0($v0)
    /* C2254 002C1654 AC400000 */  sw         $zero, 0x0($v0)
    /* C2258 002C1658 03E00008 */  jr         $ra
    /* C225C 002C165C AC990000 */   sw        $t9, 0x0($a0)
endlabel __osPopThread
