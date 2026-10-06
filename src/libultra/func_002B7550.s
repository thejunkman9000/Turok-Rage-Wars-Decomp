.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8150-0xB8170 (VRAM 0x002B7550) */
glabel func_002B7550
    /* B8150 002B7550 8CA20000 */  lw         $v0, 0x0($a1)
    /* B8154 002B7554 AC850004 */  sw         $a1, 0x4($a0)
    /* B8158 002B7558 AC820000 */  sw         $v0, 0x0($a0)
    /* B815C 002B755C 8CA20000 */  lw         $v0, 0x0($a1)
    /* B8160 002B7560 54400001 */  bnel       $v0, $zero, .L002B7568
    /* B8164 002B7564 AC440004 */   sw        $a0, 0x4($v0)
  .L002B7568:
    /* B8168 002B7568 03E00008 */  jr         $ra
    /* B816C 002B756C ACA40000 */   sw        $a0, 0x0($a1)
endlabel func_002B7550
