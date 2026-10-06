.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFDBC */
glabel pad_0BFDBC
    /* BFDBC */  .word      0x02021025
endlabel pad_0BFDBC
