.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBBAEC */
glabel pad_0BBAEC
    /* BBAEC */  .word      0x8C830020
endlabel pad_0BBAEC
