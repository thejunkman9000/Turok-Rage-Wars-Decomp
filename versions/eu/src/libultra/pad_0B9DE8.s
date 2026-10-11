.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB9DE8 */
glabel pad_0B9DE8
    /* B9DE8 */  .word      0xAFB1001C
    /* B9DEC */  .word      0xAFB00018
endlabel pad_0B9DE8
