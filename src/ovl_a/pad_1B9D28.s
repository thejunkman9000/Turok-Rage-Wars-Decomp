.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B9D28 */
glabel pad_1B9D28
    /* 1B9D28 */  .word      0x02002821
    /* 1B9D2C */  .word      0x14A0FFFB
endlabel pad_1B9D28
