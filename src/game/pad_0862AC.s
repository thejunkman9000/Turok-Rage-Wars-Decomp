.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x862AC */
glabel pad_0862AC
    /* 862AC */  .word      0x26310008
endlabel pad_0862AC
