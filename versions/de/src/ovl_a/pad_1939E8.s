.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1939E8 */
glabel pad_1939E8
    /* 1939E8 */  .word      0x8C6313D0
    /* 1939EC */  .word      0x00402021
endlabel pad_1939E8
