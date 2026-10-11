.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB095C */
glabel pad_0B095C
    /* B095C */  .word      0x6E540000
endlabel pad_0B095C
