.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x63D48 */
glabel pad_063D48
    /* 63D48 */  .word      0x000B0000
    /* 63D4C */  .word      0x00000016
endlabel pad_063D48
