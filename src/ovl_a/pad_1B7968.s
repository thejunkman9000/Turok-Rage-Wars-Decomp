.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B7968 */
glabel pad_1B7968
    /* 1B7968 */  .word      0xAE0012C4
    /* 1B796C */  .word      0xAE0012C8
endlabel pad_1B7968
