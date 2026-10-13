.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFC4C */
glabel pad_0BFC4C
    /* BFC4C */  .word      0xAFBF0018
endlabel pad_0BFC4C
