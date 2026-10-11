.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA3C8C */
glabel pad_0A3C8C
    /* A3C8C */  .word      0x8E060040
endlabel pad_0A3C8C
