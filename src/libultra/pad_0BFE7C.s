.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFE7C */
glabel pad_0BFE7C
    /* BFE7C */  .word      0xAFB10014
endlabel pad_0BFE7C
