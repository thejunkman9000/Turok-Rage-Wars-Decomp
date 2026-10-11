.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x180EA8 */
glabel pad_180EA8
    /* 180EA8 */  .word      0x35657175
    /* 180EAC */  .word      0xD60F0000
endlabel pad_180EA8
