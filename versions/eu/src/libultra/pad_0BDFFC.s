.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDFFC */
glabel pad_0BDFFC
    /* BDFFC */  .word      0x00871021
endlabel pad_0BDFFC
