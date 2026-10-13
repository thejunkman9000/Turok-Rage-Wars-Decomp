.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7EAC */
glabel pad_0B7EAC
    /* B7EAC */  .word      0xAE250000
endlabel pad_0B7EAC
