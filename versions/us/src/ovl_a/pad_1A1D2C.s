.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A1D2C */
glabel pad_1A1D2C
    /* 1A1D2C */  .word      0x00000000
endlabel pad_1A1D2C
