.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BC8AC */
glabel pad_1BC8AC
    /* 1BC8AC */  .word      0x004421D4
endlabel pad_1BC8AC
