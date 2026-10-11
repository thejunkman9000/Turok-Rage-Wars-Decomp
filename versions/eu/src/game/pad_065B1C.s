.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x65B1C */
glabel pad_065B1C
    /* 65B1C */  .word      0x00000000
endlabel pad_065B1C
