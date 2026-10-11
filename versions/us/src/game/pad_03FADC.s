.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3FADC */
glabel pad_03FADC
    /* 3FADC */  .word      0x0000000B
endlabel pad_03FADC
