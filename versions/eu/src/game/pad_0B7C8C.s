.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7C8C */
glabel pad_0B7C8C
    /* B7C8C */  .word      0x27BDFFD8
endlabel pad_0B7C8C
