.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B3CB4 */
glabel pad_1B3CB4
    /* 1B3CB4 */  .word      0xA4A20014
    /* 1B3CB8 */  .word      0xA4A30018
    /* 1B3CBC */  .word      0xA4A0001A
endlabel pad_1B3CB4
