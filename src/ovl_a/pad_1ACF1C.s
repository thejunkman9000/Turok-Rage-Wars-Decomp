.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1ACF1C */
glabel pad_1ACF1C
    /* 1ACF1C */  .word      0x00431023
endlabel pad_1ACF1C
