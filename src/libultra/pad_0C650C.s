.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC650C */
glabel pad_0C650C
    /* C650C */  .word      0x03E00008
endlabel pad_0C650C
