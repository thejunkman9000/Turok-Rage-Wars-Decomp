.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC143C */
glabel pad_0C143C
    /* C143C */  .word      0x3C1AA430
endlabel pad_0C143C
