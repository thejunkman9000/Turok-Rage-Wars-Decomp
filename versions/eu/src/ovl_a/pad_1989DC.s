.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1989DC */
glabel pad_1989DC
    /* 1989DC */  .word      0x02331021
endlabel pad_1989DC
