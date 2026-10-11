.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3898 */
glabel pad_003898
    /* 3898 */  .word      0xAFB20018
    /* 389C */  .word      0x00C09021
endlabel pad_003898
