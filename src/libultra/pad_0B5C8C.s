.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB5C8C */
glabel pad_0B5C8C
    /* B5C8C */  .word      0x10C0000C
endlabel pad_0B5C8C
