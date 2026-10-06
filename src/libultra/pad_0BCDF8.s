.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBCDF8 */
glabel pad_0BCDF8
    /* BCDF8 */  .word      0x080AF558
    /* BCDFC */  .word      0x2402000B
endlabel pad_0BCDF8
