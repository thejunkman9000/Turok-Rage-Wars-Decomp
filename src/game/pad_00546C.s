.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x546C */
glabel pad_00546C
    /* 546C */  .word      0x3C048014
endlabel pad_00546C
