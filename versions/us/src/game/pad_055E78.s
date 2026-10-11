.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x55E78 */
glabel pad_055E78
    /* 55E78 */  .word      0x08009500
    /* 55E7C */  .word      0x00000000
endlabel pad_055E78
