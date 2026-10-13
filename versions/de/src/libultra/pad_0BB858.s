.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBB858 */
glabel pad_0BB858
    /* BB858 */  .word      0xAC820000
    /* BB85C */  .word      0xAC820004
endlabel pad_0BB858
