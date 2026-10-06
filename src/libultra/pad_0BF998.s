.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF998 */
glabel pad_0BF998
    /* BF998 */  .word      0x2484185C
    /* BF99C */  .word      0x00801821
endlabel pad_0BF998
