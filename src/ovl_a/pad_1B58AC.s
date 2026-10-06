.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B58AC */
glabel pad_1B58AC
    /* 1B58AC */  .word      0x14400003
endlabel pad_1B58AC
