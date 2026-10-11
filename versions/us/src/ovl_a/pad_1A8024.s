.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A8024 */
glabel pad_1A8024
    /* 1A8024 */  .word      0x00000010
    /* 1A8028 */  .word      0x000B0000
    /* 1A802C */  .word      0x0000000A
endlabel pad_1A8024
