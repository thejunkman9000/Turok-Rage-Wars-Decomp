.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B3C5C */
glabel pad_1B3C5C
    /* 1B3C5C */  .word      0x24020001
endlabel pad_1B3C5C
