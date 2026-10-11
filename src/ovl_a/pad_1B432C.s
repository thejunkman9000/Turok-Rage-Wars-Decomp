.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B432C */
glabel pad_1B432C
    /* 1B432C */  .word      0x1440002A
endlabel pad_1B432C
