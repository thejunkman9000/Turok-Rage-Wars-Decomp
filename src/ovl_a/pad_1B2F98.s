.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B2F98 */
glabel pad_1B2F98
    /* 1B2F98 */  .word      0x00000000
endlabel pad_1B2F98
