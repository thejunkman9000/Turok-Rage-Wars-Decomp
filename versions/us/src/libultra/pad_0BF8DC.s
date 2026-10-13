.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF8DC */
glabel pad_0BF8DC
    /* BF8DC */  .word      0x72696453
endlabel pad_0BF8DC
