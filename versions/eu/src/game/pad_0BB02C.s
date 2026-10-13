.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBB02C */
glabel pad_0BB02C
    /* BB02C */  .word      0x46800020
endlabel pad_0BB02C
