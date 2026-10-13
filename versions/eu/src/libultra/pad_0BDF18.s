.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDF18 */
glabel pad_0BDF18
    /* BDF18 */  .word      0x0C0AE1D8
    /* BDF1C */  .word      0x27A70018
endlabel pad_0BDF18
