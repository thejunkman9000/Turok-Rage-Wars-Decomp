.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A93B8 */
glabel pad_1A93B8
    /* 1A93B8 */  .word      0x3C048013
    /* 1A93BC */  .word      0x8C8471FC
endlabel pad_1A93B8
