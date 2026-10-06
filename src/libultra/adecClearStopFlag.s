.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5F0C-0xC5F20 (VRAM 0x002C530C) */
glabel adecClearStopFlag
    /* C5F0C 002C530C 3C018015 */  lui        $at, %hi(D_80151CD8)
    /* C5F10 002C5310 AC201CD8 */  sw         $zero, %lo(D_80151CD8)($at)
    /* C5F14 002C5314 03E00008 */  jr         $ra
    /* C5F18 002C5318 00000000 */   nop


    /* C5F1C 002C531C 00031C00 */  .word      0x00031C00 /* linker padding */
endlabel adecClearStopFlag
