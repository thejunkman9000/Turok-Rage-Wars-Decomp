.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B6EA4 */
glabel pad_1B6EA4
    /* 1B6EA4 */  .word      0xC42273F4
    /* 1B6EA8 */  .word      0x3C01800C
    /* 1B6EAC */  .word      0xC42073F8
endlabel pad_1B6EA4
