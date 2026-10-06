.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0AAC */
glabel pad_0C0AAC
    /* C0AAC */  .word      0x0369D825
endlabel pad_0C0AAC
