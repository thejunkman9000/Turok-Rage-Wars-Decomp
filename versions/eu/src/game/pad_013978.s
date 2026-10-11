.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13978 */
glabel pad_013978
    /* 13978 */  .word      0x00448021
    /* 1397C */  .word      0x12000017
endlabel pad_013978
