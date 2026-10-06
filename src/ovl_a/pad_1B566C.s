.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B566C */
glabel pad_1B566C
    /* 1B566C */  .word      0x00C2102A
endlabel pad_1B566C
