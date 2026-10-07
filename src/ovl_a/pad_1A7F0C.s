.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A7F0C */
glabel pad_1A7F0C
    /* 1A7F0C */  .word      0xAFBF0028
endlabel pad_1A7F0C
