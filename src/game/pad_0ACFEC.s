.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xACFEC */
glabel pad_0ACFEC
    /* ACFEC */  .word      0x00431021
endlabel pad_0ACFEC
