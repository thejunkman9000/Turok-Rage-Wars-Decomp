.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2F68-0xB2F78 (VRAM 0x002B2368) */
glabel padding_002B2368
    /* B2F68 002B2368 00A0A821 */  addu       $s5, $a1, $zero
    /* B2F6C 002B236C AFB70134 */  sw         $s7, 0x134($sp)
    /* B2F70 002B2370 03E00008 */  jr         $ra
    /* B2F74 002B2374 00000000 */   nop
endlabel padding_002B2368
