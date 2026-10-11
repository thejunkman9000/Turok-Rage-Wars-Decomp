.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13F3C */
glabel pad_013F3C
    /* 13F3C */  .word      0xF7B60110
endlabel pad_013F3C
