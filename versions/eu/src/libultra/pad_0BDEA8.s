.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDEA8 */
glabel pad_0BDEA8
    /* BDEA8 */  .word      0xAFB20068
    /* BDEAC */  .word      0xAFB10064
endlabel pad_0BDEA8
