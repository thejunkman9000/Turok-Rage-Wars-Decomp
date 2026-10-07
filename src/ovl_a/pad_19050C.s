.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19050C */
glabel pad_19050C
    /* 19050C */  .word      0x24020001
endlabel pad_19050C
