.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1823D8 */
glabel pad_1823D8
    /* 1823D8 */  .word      0x8C50FFFC
    /* 1823DC */  .word      0x06400014
endlabel pad_1823D8
