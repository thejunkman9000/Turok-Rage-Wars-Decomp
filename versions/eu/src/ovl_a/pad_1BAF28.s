.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BAF28 */
glabel pad_1BAF28
    /* 1BAF28 */  .word      0x54400006
    /* 1BAF2C */  .word      0x2486FFFD
endlabel pad_1BAF28
