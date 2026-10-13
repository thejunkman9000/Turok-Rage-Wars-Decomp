.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDDF0-0xBDE0C (VRAM 0x002BD1F0) */
.globl __osRestoreInt
__osRestoreInt:
    /* BDDF0 002BD1F0 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* BDDF4 002BD1F4 01044025 */  or         $t0, $t0, $a0
    /* BDDF8 002BD1F8 40886000 */  mtc0       $t0, $12 /* handwritten instruction */
    /* BDDFC 002BD1FC 00000000 */  nop
    /* BDE00 002BD200 00000000 */  nop
    /* BDE04 002BD204 03E00008 */  jr         $ra
    /* BDE08 002BD208 00000000 */  nop
