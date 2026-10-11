.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AF764 */
glabel pad_1AF764
    /* 1AF764 */  .word      0x616D6552
    /* 1AF768 */  .word      0x00000400
    /* 1AF76C */  .word      0x00000800
endlabel pad_1AF764
