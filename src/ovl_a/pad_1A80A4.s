.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A80A4 */
glabel pad_1A80A4
    /* 1A80A4 */  .word      0x00009821
    /* 1A80A8 */  .word      0x0260B021
    /* 1A80AC */  .word      0x8CB404B4
endlabel pad_1A80A4
