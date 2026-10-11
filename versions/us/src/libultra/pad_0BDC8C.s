.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDC8C */
glabel pad_0BDC8C
    /* BDC8C */  .word      0x096D5F72
endlabel pad_0BDC8C
