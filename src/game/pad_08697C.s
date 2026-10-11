.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x8697C */
glabel pad_08697C
    /* 8697C */  .word      0x02602021
endlabel pad_08697C
