.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B4A3C */
glabel pad_1B4A3C
    /* 1B4A3C */  .word      0x00000000
endlabel pad_1B4A3C
