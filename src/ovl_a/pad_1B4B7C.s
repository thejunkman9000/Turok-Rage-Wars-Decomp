.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B4B7C */
glabel pad_1B4B7C
    /* 1B4B7C */  .word      0x304200C0
endlabel pad_1B4B7C
