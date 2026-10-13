.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBB77C-0xBB790 (VRAM 0x002BAB7C) */
.globl D_auto_002BAB7C
D_auto_002BAB7C:
    /* BB77C 002BAB7C 003C0000 */  .word 0x003C0000
.globl __assert
__assert:
    /* BB780 002BAB80 03E00008 */  jr         $ra
    /* BB784 002BAB84 00000000 */  nop
.globl D_auto_002BAB88
D_auto_002BAB88:
    /* BB788 002BAB88 726C6179 */  .word 0x726C6179
    /* BB78C 002BAB8C 5F74126D */  .word 0x5F74126D
