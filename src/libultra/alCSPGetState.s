.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4770-0xB4780 (VRAM 0x002B3B70) */
glabel alCSPGetState
    /* B4770 002B3B70 8C82002C */  lw         $v0, 0x2C($a0)
    /* B4774 002B3B74 03E00008 */  jr         $ra
    /* B4778 002B3B78 00000000 */   nop


    /* B477C 002B3B7C 32C200FF */  .word      0x32C200FF /* linker padding */
endlabel alCSPGetState
