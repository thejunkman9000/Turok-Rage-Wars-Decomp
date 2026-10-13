.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBCA54 */
glabel pad_0BCA54
    /* BCA54 */  .word      0x28620004
    /* BCA58 */  .word      0x1440FFFA
    /* BCA5C */  .word      0x24A50004
endlabel pad_0BCA54
