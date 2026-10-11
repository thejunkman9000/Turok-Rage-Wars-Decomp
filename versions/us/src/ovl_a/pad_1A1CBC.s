.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A1CBC */
glabel pad_1A1CBC
    /* 1A1CBC */  .word      0x6153697A
endlabel pad_1A1CBC
