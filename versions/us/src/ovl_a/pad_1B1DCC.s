.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B1DCC */
glabel pad_1B1DCC
    /* 1B1DCC */  .word      0x48540000
endlabel pad_1B1DCC
