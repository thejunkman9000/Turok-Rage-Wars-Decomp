.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B49CC */
glabel pad_1B49CC
    /* 1B49CC */  .word      0x1622005B
endlabel pad_1B49CC
