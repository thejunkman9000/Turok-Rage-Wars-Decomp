.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B342C */
glabel pad_1B342C
    /* 1B342C */  .word      0x3C03800F
endlabel pad_1B342C
