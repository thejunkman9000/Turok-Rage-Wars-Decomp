.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18965C */
glabel pad_18965C
    /* 18965C */  .word      0x00000000
endlabel pad_18965C
