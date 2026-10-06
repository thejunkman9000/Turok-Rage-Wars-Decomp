.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC1108 */
glabel pad_0C1108
    /* C1108 */  .word      0x3C010400
    /* C110C */  .word      0x0361D824
endlabel pad_0C1108
