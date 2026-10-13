.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBB84C */
glabel pad_0BB84C
    /* BB84C */  .word      0x00000000
endlabel pad_0BB84C
