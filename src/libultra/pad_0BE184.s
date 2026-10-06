.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE184 */
glabel pad_0BE184
    /* BE184 */  .word      0x92020005
    /* BE188 */  .word      0x10620003
    /* BE18C */  .word      0x3C03A460
endlabel pad_0BE184
