.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BC91C */
glabel pad_1BC91C
    /* 1BC91C */  .word      0x46010001
endlabel pad_1BC91C
