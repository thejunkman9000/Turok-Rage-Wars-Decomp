.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFC98 */
glabel pad_0BFC98
    /* BFC98 */  .word      0xAC22FD90
    /* BFC9C */  .word      0x3C018015
endlabel pad_0BFC98
