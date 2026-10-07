.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1ABD2C */
glabel pad_1ABD2C
    /* 1ABD2C */  .word      0x0810FB52
endlabel pad_1ABD2C
