.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDE74 */
glabel pad_0BDE74
    /* BDE74 */  .word      0x240B2000
    /* BDE78 */  .word      0x00AB082B
    /* BDE7C */  .word      0x1020000D
endlabel pad_0BDE74
