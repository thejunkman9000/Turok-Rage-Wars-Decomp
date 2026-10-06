.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B6468 */
glabel pad_1B6468
    /* 1B6468 */  .word      0x1440FFFA
    /* 1B646C */  .word      0x02241821
endlabel pad_1B6468
