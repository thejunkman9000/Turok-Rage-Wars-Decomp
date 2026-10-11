.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x8BF8 */
glabel pad_008BF8
    /* 8BF8 */  .word      0x00000800
    /* 8BFC */  .word      0x04000000
endlabel pad_008BF8
