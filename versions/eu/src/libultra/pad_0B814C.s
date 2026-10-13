.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB814C */
glabel pad_0B814C
    /* B814C */  .word      0x8FB1002C
endlabel pad_0B814C
