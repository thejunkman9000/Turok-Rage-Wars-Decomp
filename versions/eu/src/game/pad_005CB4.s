.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5CB4 */
glabel pad_005CB4
    /* 5CB4 */  .word      0x00000000
    /* 5CB8 */  .word      0x00000000
    /* 5CBC */  .word      0x00000000
endlabel pad_005CB4
