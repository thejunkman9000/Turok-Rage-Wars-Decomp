.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFFFC */
glabel pad_0BFFFC
    /* BFFFC */  .word      0x00000000
endlabel pad_0BFFFC
