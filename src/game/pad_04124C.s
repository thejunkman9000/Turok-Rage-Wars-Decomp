.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x4124C */
glabel pad_04124C
    /* 4124C */  .word      0x00001021
endlabel pad_04124C
