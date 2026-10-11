.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BC904 */
glabel pad_1BC904
    /* 1BC904 */  .word      0x00000000
    /* 1BC908 */  .word      0x00010041
    /* 1BC90C */  .word      0x00000014
endlabel pad_1BC904
