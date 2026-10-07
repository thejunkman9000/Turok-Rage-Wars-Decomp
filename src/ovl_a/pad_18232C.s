.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18232C */
glabel pad_18232C
    /* 18232C */  .word      0x1060000F
endlabel pad_18232C
