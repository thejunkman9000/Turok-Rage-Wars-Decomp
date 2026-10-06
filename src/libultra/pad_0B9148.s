.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB9148 */
glabel pad_0B9148
    /* B9148 */  .word      0x3C06002C
    /* B914C */  .word      0x24C6A610
endlabel pad_0B9148
