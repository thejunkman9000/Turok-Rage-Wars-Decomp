.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x63DC8 */
glabel pad_063DC8
    /* 63DC8 */  .word      0x00000000
    /* 63DCC */  .word      0x02002021
endlabel pad_063DC8
