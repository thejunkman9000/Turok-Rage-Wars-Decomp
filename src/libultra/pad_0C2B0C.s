.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC2B0C */
glabel pad_0C2B0C
    /* C2B0C */  .word      0xAFB00038
endlabel pad_0C2B0C
