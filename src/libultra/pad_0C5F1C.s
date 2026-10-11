.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC5F1C */
glabel pad_0C5F1C
    /* C5F1C */  .word      0x00031C00
endlabel pad_0C5F1C
