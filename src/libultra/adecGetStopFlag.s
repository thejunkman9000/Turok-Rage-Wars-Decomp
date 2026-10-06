.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5EFC-0xC5F0C (VRAM 0x002C52FC) */
glabel adecGetStopFlag
    /* C5EFC 002C52FC 3C028015 */  lui        $v0, %hi(D_80151CD8)
    /* C5F00 002C5300 8C421CD8 */  lw         $v0, %lo(D_80151CD8)($v0)
    /* C5F04 002C5304 03E00008 */  jr         $ra
    /* C5F08 002C5308 00000000 */   nop
endlabel adecGetStopFlag
