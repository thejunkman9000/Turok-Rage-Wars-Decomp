.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBEA6C */
glabel pad_0BEA6C
    /* BEA6C */  .word      0x30420003
endlabel pad_0BEA6C
