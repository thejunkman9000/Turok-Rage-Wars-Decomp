.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFE2C */
glabel pad_0BFE2C
    /* BFE2C */  .word      0x02021025
endlabel pad_0BFE2C
