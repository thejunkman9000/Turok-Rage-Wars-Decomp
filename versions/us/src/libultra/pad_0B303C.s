.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB303C */
glabel pad_0B303C
    /* B303C */  .word      0x00000D70
endlabel pad_0B303C
