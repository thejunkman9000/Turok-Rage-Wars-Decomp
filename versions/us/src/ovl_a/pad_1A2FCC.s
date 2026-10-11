.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A2FCC */
glabel pad_1A2FCC
    /* 1A2FCC */  .word      0x544E5F32
endlabel pad_1A2FCC
