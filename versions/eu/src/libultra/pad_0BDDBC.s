.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDDBC */
glabel pad_0BDDBC
    /* BDDBC */  .word      0xB86A000F
endlabel pad_0BDDBC
