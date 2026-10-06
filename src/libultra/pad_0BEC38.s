.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBEC38 */
glabel pad_0BEC38
    /* BEC38 */  .word      0x2411FFFF
    /* BEC3C */  .word      0x3C050400
endlabel pad_0BEC38
