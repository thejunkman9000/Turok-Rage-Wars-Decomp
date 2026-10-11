.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18247C */
glabel pad_18247C
    /* 18247C */  .word      0x24420004
endlabel pad_18247C
