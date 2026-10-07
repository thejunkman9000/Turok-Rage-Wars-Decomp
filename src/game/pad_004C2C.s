.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x4C2C */
glabel pad_004C2C
    /* 4C2C */  .word      0x30420400
endlabel pad_004C2C
