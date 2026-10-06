.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2C10-0xC2C20 (VRAM 0x002C2010) */
glabel __osGetSR
    /* C2C10 002C2010 40026000 */  mfc0       $v0, $12 /* handwritten instruction */
    /* C2C14 002C2014 03E00008 */  jr         $ra
    /* C2C18 002C2018 00000000 */   nop
    /* C2C1C 002C201C 02003021 */  .word      0x02003021 /* linker padding */
endlabel __osGetSR
