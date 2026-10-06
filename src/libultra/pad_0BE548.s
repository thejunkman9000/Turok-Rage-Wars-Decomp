.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE548 */
glabel pad_0BE548
    /* BE548 */  .word      0x3C03A000
    /* BE54C */  .word      0x00451025
endlabel pad_0BE548
