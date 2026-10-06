.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2C00-0xC2C10 (VRAM 0x002C2000) */
glabel __osGetFpcCsr
    /* C2C00 002C2000 4442F800 */  cfc1       $v0, $31
    /* C2C04 002C2004 03E00008 */  jr         $ra
    /* C2C08 002C2008 00000000 */   nop
    /* C2C0C 002C200C 0C0B14C8 */  .word      0x0C0B14C8 /* linker padding */
endlabel __osGetFpcCsr
