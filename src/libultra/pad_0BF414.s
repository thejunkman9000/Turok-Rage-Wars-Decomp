.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF414 */
glabel pad_0BF414
    /* BF414 */  .word      0x3C03800E
    /* BF418 */  .word      0x8C638444
    /* BF41C */  .word      0x8C62000C
endlabel pad_0BF414
