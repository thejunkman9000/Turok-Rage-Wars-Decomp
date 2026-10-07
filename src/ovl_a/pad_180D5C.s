.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x180D5C */
glabel pad_180D5C
    /* 180D5C */  .word      0x27BD0018
endlabel pad_180D5C
