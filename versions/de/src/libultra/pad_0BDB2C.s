.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDB2C */
glabel pad_0BDB2C
    /* BDB2C */  .word      0x40896000
endlabel pad_0BDB2C
