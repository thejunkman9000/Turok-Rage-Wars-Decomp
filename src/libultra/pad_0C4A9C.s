.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC4A9C */
glabel pad_0C4A9C
    /* C4A9C */  .word      0x45000008
endlabel pad_0C4A9C
