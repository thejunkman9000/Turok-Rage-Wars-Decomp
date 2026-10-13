.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAD8C */
glabel pad_0BAD8C
    /* BAD8C */  .word      0x03E00008
endlabel pad_0BAD8C
