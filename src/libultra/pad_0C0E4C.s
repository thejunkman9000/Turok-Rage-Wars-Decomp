.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0E4C */
glabel pad_0C0E4C
    /* C0E4C */  .word      0x3C0A800E
endlabel pad_0C0E4C
