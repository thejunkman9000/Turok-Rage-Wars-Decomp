.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8B9C */
glabel pad_0B8B9C
    /* B8B9C */  .word      0x8FB00018
endlabel pad_0B8B9C
