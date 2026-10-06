.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB5B7C */
glabel pad_0B5B7C
    /* B5B7C */  .word      0x00151100
endlabel pad_0B5B7C
