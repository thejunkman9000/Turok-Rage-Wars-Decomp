.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x181FB4 */
glabel pad_181FB4
    /* 181FB4 */  .word      0x65717568
    /* 181FB8 */  .word      0x10000094
    /* 181FBC */  .word      0x10000B00
endlabel pad_181FB4
