.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x8F63C */
glabel pad_08F63C
    /* 8F63C */  .word      0x27B10878
endlabel pad_08F63C
