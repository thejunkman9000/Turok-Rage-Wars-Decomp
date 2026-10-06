.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB9BDC */
glabel pad_0B9BDC
    /* B9BDC */  .word      0x3C020308
endlabel pad_0B9BDC
