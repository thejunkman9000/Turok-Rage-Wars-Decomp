.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19EF0C */
glabel pad_19EF0C
    /* 19EF0C */  .word      0x0C106960
endlabel pad_19EF0C
