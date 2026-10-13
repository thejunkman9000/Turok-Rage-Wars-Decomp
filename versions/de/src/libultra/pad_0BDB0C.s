.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDB0C */
glabel pad_0BDB0C
    /* BDB0C */  .word      0xAFB3002C
endlabel pad_0BDB0C
