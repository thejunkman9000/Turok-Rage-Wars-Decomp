.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B9AB4 */
glabel pad_1B9AB4
    /* 1B9AB4 */  .word      0x00240821
    /* 1B9AB8 */  .word      0xA0220EEC
    /* 1B9ABC */  .word      0x3C010002
endlabel pad_1B9AB4
