.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x412BC */
glabel pad_0412BC
    /* 412BC */  .word      0xC4C20000
endlabel pad_0412BC
