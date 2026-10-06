.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2C40-0xC2C60 (VRAM 0x002C2040) */
glabel __osRestoreInt
    /* C2C40 002C2040 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* C2C44 002C2044 01044025 */  or         $t0, $t0, $a0
    /* C2C48 002C2048 40886000 */  mtc0       $t0, $12 /* handwritten instruction */
    /* C2C4C 002C204C 00000000 */  nop
    /* C2C50 002C2050 00000000 */  nop
    /* C2C54 002C2054 03E00008 */  jr         $ra
    /* C2C58 002C2058 00000000 */   nop
    /* C2C5C 002C205C A0430010 */  .word      0xA0430010 /* linker padding */
endlabel __osRestoreInt
