.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BA244 */
glabel pad_1BA244
    /* 1BA244 */  .word      0x3C010002
    /* 1BA248 */  .word      0x01010821
    /* 1BA24C */  .word      0x8C30B40C
endlabel pad_1BA244
