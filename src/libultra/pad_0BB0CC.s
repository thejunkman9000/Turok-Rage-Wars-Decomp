.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBB0CC */
glabel pad_0BB0CC
    /* BB0CC */  .word      0x02002821
endlabel pad_0BB0CC
