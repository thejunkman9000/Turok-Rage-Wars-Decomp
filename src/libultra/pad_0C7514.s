.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC7514 */
glabel pad_0C7514
    /* C7514 */  .word      0x3ECCCCCD
    /* C7518 */  .word      0x3F800000
    /* C751C */  .word      0x42960000
endlabel pad_0C7514
