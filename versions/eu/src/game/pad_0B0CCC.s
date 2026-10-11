.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB0CCC */
glabel pad_0B0CCC
    /* B0CCC */  .word      0x4407B800
endlabel pad_0B0CCC
