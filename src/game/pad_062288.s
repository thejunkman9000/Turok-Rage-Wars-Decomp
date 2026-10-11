.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x62288 */
glabel pad_062288
    /* 62288 */  .word      0x44820000
    /* 6228C */  .word      0x46800020
endlabel pad_062288
