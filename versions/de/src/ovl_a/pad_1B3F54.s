.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B3F54 */
glabel pad_1B3F54
    /* 1B3F54 */  .word      0x26457534
    /* 1B3F58 */  .word      0x2406001C
    /* 1B3F5C */  .word      0x0C09E56C
endlabel pad_1B3F54
