.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFE04 */
glabel pad_0BFE04
    /* BFE04 */  .word      0x2484CC50
    /* BFE08 */  .word      0x3C05800D
    /* BFE0C */  .word      0x24A5CC54
endlabel pad_0BFE04
