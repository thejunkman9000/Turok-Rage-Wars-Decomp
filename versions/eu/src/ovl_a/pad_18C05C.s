.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18C05C */
glabel pad_18C05C
    /* 18C05C */  .word      0x8602000C
endlabel pad_18C05C
