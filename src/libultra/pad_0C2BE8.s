.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC2BE8 */
glabel pad_0C2BE8
    /* C2BE8 */  .word      0x5A800025
    /* C2BEC */  .word      0x27A50010
endlabel pad_0C2BE8
