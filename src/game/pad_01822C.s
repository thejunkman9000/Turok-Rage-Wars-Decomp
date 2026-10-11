.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1822C */
glabel pad_01822C
    /* 1822C */  .word      0xC6810008
endlabel pad_01822C
