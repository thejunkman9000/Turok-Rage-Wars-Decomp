.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AA72C */
glabel pad_1AA72C
    /* 1AA72C */  .word      0x00431024
endlabel pad_1AA72C
