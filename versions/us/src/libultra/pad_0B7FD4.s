.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7FD4 */
glabel pad_0B7FD4
    /* B7FD4 */  .word      0x08003800
    /* B7FD8 */  .word      0x00010000
    /* B7FDC */  .word      0x01000001
endlabel pad_0B7FD4
