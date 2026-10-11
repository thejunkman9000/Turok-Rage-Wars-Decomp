.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB86BC */
glabel pad_0B86BC
    /* B86BC */  .word      0x00000000
endlabel pad_0B86BC
