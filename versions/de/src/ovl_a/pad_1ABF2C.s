.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1ABF2C */
glabel pad_1ABF2C
    /* 1ABF2C */  .word      0x03E00008
endlabel pad_1ABF2C
