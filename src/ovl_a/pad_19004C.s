.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19004C */
glabel pad_19004C
    /* 19004C */  .word      0x8C440038
endlabel pad_19004C
