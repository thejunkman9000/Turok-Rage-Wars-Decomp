.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x66A28 */
glabel pad_066A28
    /* 66A28 */  .word      0xAE4305E4
    /* 66A2C */  .word      0x00601021
endlabel pad_066A28
