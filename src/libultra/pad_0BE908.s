.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE908 */
glabel pad_0BE908
    /* BE908 */  .word      0x3C03800E
    /* BE90C */  .word      0x246383D0
endlabel pad_0BE908
