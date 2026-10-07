.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x183C9C */
glabel pad_183C9C
    /* 183C9C */  .word      0x3C060802
endlabel pad_183C9C
