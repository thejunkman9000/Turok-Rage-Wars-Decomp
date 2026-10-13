.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7DDC */
glabel pad_0B7DDC
    /* B7DDC */  .word      0x5F426F73
endlabel pad_0B7DDC
