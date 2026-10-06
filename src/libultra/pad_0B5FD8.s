.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB5FD8 */
glabel pad_0B5FD8
    /* B5FD8 */  .word      0x080AD96F
    /* B5FDC */  .word      0xA0500008
endlabel pad_0B5FD8
