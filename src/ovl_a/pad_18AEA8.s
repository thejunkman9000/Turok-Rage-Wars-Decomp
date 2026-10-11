.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18AEA8 */
glabel pad_18AEA8
    /* 18AEA8 */  .word      0x0C107674
    /* 18AEAC */  .word      0x00000000
endlabel pad_18AEA8
