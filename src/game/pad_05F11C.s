.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5F11C */
glabel pad_05F11C
    /* 5F11C */  .word      0x4600083E
endlabel pad_05F11C
