.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B31F4 */
glabel pad_1B31F4
    /* 1B31F4 */  .word      0xAC83000C
    /* 1B31F8 */  .word      0x2403FFFF
    /* 1B31FC */  .word      0xAC830010
endlabel pad_1B31F4
