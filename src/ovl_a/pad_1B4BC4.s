.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B4BC4 */
glabel pad_1B4BC4
    /* 1B4BC4 */  .word      0xAFB30064
    /* 1B4BC8 */  .word      0x00C09821
    /* 1B4BCC */  .word      0xAFBF0068
endlabel pad_1B4BC4
