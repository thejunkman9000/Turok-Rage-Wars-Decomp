.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDD48 */
glabel pad_0BDD48
    /* BDD48 */  .word      0x520000D8
    /* BDD4C */  .word      0x00000008
endlabel pad_0BDD48
