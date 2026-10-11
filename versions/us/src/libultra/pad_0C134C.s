.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC134C */
glabel pad_0C134C
    /* C134C */  .word      0x00000800
endlabel pad_0C134C
