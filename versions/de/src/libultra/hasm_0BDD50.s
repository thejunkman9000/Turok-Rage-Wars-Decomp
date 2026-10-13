.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDD50-0xBDD60 (VRAM 0x002BD150) */
.globl __osSetCompare
__osSetCompare:
    /* BDD50 002BD150 40845800 */  mtc0       $a0, $11 /* handwritten instruction */
    /* BDD54 002BD154 03E00008 */  jr         $ra
    /* BDD58 002BD158 00000000 */  nop
    /* BDD5C 002BD15C 00000000 */  nop
