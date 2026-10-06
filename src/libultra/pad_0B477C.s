.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB477C */
glabel pad_0B477C
    /* B477C */  .word      0x32C200FF
endlabel pad_0B477C
