.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBCABC */
glabel pad_0BCABC
    /* BCABC */  .word      0x54430001
endlabel pad_0BCABC
