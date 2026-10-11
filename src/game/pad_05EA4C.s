.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5EA4C */
glabel pad_05EA4C
    /* 5EA4C */  .word      0x468010A0
endlabel pad_05EA4C
