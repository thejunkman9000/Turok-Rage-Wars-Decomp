.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDB50-0xBDB6C (VRAM 0x002BCF50) */
.globl __osRestoreInt
__osRestoreInt:
    /* BDB50 002BCF50 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* BDB54 002BCF54 01044025 */  or         $t0, $t0, $a0
    /* BDB58 002BCF58 40886000 */  mtc0       $t0, $12 /* handwritten instruction */
    /* BDB5C 002BCF5C 00000000 */  nop
    /* BDB60 002BCF60 00000000 */  nop
    /* BDB64 002BCF64 03E00008 */  jr         $ra
    /* BDB68 002BCF68 00000000 */  nop
