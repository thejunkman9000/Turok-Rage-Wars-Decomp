.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDB6C */
glabel pad_0BDB6C
    /* BDB6C */  .word      0x00AB082B
endlabel pad_0BDB6C
