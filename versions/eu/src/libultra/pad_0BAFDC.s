.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAFDC */
glabel pad_0BAFDC
    /* BAFDC */  .word      0x10800009
endlabel pad_0BAFDC
