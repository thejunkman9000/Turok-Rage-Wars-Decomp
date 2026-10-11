.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A79C8 */
glabel pad_1A79C8
    /* 1A79C8 */  .word      0xAC431358
    /* 1A79CC */  .word      0x24030004
endlabel pad_1A79C8
