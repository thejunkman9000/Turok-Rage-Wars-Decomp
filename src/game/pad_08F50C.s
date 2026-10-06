.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x8F50C */
glabel pad_08F50C
    /* 8F50C */  .word      0x00000000
endlabel pad_08F50C
