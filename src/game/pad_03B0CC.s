.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3B0CC */
glabel pad_03B0CC
    /* 3B0CC */  .word      0xAC4A0018
endlabel pad_03B0CC
