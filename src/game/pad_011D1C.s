.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x11D1C */
glabel pad_011D1C
    /* 11D1C */  .word      0x8E03031C
endlabel pad_011D1C
