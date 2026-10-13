.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x194F4C */
glabel pad_194F4C
    /* 194F4C */  .word      0x00003021
endlabel pad_194F4C
