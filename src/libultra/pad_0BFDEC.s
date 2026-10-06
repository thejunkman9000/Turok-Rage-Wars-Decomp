.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFDEC */
glabel pad_0BFDEC
    /* BFDEC */  .word      0xAFB10014
endlabel pad_0BFDEC
