.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18FA24 */
glabel pad_18FA24
    /* 18FA24 */  .word      0x3C01800E
    /* 18FA28 */  .word      0xAC220F00
    /* 18FA2C */  .word      0x0C106D84
endlabel pad_18FA24
