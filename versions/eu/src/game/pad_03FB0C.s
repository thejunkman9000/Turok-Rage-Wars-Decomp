.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3FB0C */
glabel pad_03FB0C
    /* 3FB0C */  .word      0x10400005
endlabel pad_03FB0C
