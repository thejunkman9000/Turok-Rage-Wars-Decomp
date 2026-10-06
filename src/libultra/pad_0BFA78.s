.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFA78 */
glabel pad_0BFA78
    /* BFA78 */  .word      0x3C04800E
    /* BFA7C */  .word      0x8C8492A0
endlabel pad_0BFA78
