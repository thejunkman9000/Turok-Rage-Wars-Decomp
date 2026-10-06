.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFEFC */
glabel pad_0BFEFC
    /* BFEFC */  .word      0x14610004
endlabel pad_0BFEFC
