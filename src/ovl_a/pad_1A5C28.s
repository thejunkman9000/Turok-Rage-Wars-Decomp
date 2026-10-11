.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A5C28 */
glabel pad_1A5C28
    /* 1A5C28 */  .word      0x0810E315
    /* 1A5C2C */  .word      0x00000000
endlabel pad_1A5C28
