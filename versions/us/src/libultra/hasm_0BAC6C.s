.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBAC6C-0xBAC70 (VRAM 0x002BA06C) */
.globl D_auto_002BA06C
D_auto_002BA06C:
    /* BAC6C 002BA06C 7265644A */  .word 0x7265644A
