.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A072C */
glabel pad_1A072C
    /* 1A072C */  .word      0x6B540000
endlabel pad_1A072C
