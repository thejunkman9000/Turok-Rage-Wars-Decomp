.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0B2C */
glabel pad_0C0B2C
    /* C0B2C */  .word      0xF74A0158
endlabel pad_0C0B2C
