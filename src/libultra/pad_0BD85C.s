.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD85C */
glabel pad_0BD85C
    /* BD85C */  .word      0xA8870000
endlabel pad_0BD85C
