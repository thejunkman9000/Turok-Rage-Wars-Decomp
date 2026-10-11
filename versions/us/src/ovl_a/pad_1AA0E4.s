.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AA0E4 */
glabel pad_1AA0E4
    /* 1AA0E4 */  .word      0x04000000
    /* 1AA0E8 */  .word      0x082E3136
    /* 1AA0EC */  .word      0x3266616B
endlabel pad_1AA0E4
