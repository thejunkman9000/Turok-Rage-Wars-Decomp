.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5468 */
glabel pad_005468
    /* 5468 */  .word      0x00000000
endlabel pad_005468
