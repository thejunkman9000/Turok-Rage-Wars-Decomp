.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AA09C */
glabel pad_1AA09C
    /* 1AA09C */  .word      0x43436163
endlabel pad_1AA09C
