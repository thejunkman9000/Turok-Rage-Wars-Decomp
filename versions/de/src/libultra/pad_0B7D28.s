.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7D28 */
glabel pad_0B7D28
    /* B7D28 */  .word      0x00021D83
    /* B7D2C */  .word      0x306301FF
endlabel pad_0B7D28
