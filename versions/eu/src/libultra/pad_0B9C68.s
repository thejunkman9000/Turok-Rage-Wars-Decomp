.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB9C68 */
glabel pad_0B9C68
    /* B9C68 */  .word      0x46010002
    /* B9C6C */  .word      0x3C01800D
endlabel pad_0B9C68
