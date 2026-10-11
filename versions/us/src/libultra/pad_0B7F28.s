.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7F28 */
glabel pad_0B7F28
    /* B7F28 */  .word      0x00B80000
    /* B7F2C */  .word      0x00080006
endlabel pad_0B7F28
