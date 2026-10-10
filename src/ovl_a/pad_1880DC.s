.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1880DC */
glabel pad_1880DC
    /* 1880DC */  .word      0x27BDFFE8
endlabel pad_1880DC
