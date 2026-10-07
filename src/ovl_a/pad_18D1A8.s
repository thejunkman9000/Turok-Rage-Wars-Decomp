.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18D1A8 */
glabel pad_18D1A8
    /* 18D1A8 */  .word      0x00000000
endlabel pad_18D1A8
