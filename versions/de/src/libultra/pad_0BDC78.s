.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDC78 */
glabel pad_0BDC78
    /* BDC78 */  .word      0x310900FF
    /* BDC7C */  .word      0x2401E000
endlabel pad_0BDC78
