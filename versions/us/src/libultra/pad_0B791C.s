.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB791C */
glabel pad_0B791C
    /* B791C */  .word      0x73520000
endlabel pad_0B791C
