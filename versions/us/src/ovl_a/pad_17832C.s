.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17832C */
glabel pad_17832C
    /* 17832C */  .word      0x14050000
endlabel pad_17832C
