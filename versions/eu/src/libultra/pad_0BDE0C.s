.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDE0C */
glabel pad_0BDE0C
    /* BDE0C */  .word      0x88A80004
endlabel pad_0BDE0C
