.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3FAEC */
glabel pad_03FAEC
    /* 3FAEC */  .word      0x00000000
endlabel pad_03FAEC
