.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2E40-0xC2E50 (VRAM 0x002C2240) */
glabel __osSetCompare
    /* C2E40 002C2240 40845800 */  mtc0       $a0, $11 /* handwritten instruction */
    /* C2E44 002C2244 03E00008 */  jr         $ra
    /* C2E48 002C2248 00000000 */   nop


    /* C2E4C 002C224C 02A51021 */  .word      0x02A51021 /* linker padding */
endlabel __osSetCompare
