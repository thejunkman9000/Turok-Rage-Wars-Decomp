.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDA28 */
glabel pad_0BDA28
    /* BDA28 */  .word      0x00000008
    /* BDA2C */  .word      0x000D0000
endlabel pad_0BDA28
