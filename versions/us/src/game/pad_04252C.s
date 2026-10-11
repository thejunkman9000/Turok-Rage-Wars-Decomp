.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x4252C */
glabel pad_04252C
    /* 4252C */  .word      0x49546172
endlabel pad_04252C
