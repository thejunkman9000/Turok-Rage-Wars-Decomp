.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A3B4C */
glabel pad_1A3B4C
    /* 1A3B4C */  .word      0x02202021
endlabel pad_1A3B4C
