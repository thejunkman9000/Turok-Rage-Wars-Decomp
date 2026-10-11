.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1C4F2C */
glabel pad_1C4F2C
    /* 1C4F2C */  .word      0x00803821
endlabel pad_1C4F2C
