.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2E50-0xC2E60 (VRAM 0x002C2250) */
glabel __osSetFpcCsr
    /* C2E50 002C2250 4442F800 */  cfc1       $v0, $31
    /* C2E54 002C2254 44C4F800 */  ctc1       $a0, $31
    /* C2E58 002C2258 03E00008 */  jr         $ra
    /* C2E5C 002C225C 00000000 */   nop
endlabel __osSetFpcCsr
