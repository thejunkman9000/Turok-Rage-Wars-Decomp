.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDA4C */
glabel pad_0BDA4C
    /* BDA4C */  .word      0x0000000A
endlabel pad_0BDA4C
