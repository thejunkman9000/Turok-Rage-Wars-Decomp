.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1874A8 */
glabel pad_1874A8
    /* 1874A8 */  .word      0x03E00008
    /* 1874AC */  .word      0x27BD0018
endlabel pad_1874A8
