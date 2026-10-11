.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B2F9C */
glabel pad_1B2F9C
    /* 1B2F9C */  .word      0x02002021
endlabel pad_1B2F9C
