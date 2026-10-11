.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17F65C */
glabel pad_17F65C
    /* 17F65C */  .word      0x4D4F5645
endlabel pad_17F65C
