.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDC08 */
glabel pad_0BDC08
    /* BDC08 */  .word      0x00AB082B
    /* BDC0C */  .word      0x1020000D
endlabel pad_0BDC08
