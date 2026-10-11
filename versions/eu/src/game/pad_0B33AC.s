.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB33AC */
glabel pad_0B33AC
    /* B33AC */  .word      0x8FB3000C
endlabel pad_0B33AC
