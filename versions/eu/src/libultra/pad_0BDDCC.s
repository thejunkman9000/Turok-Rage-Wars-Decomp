.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDDCC */
glabel pad_0BDDCC
    /* BDDCC */  .word      0x080AE081
endlabel pad_0BDDCC
