.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAD3C */
glabel pad_0BAD3C
    /* BAD3C */  .word      0x0C0AE860
endlabel pad_0BAD3C
