.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD15C */
glabel pad_0BD15C
    /* BD15C */  .word      0x00001021
endlabel pad_0BD15C
