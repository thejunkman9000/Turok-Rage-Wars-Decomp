.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B1E24 */
glabel pad_1B1E24
    /* 1B1E24 */  .word      0x4C455348
    /* 1B1E28 */  .word      0x65717552
    /* 1B1E2C */  .word      0x00000500
endlabel pad_1B1E24
