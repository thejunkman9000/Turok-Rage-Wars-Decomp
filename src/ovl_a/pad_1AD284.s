.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AD284 */
glabel pad_1AD284
    /* 1AD284 */  .word      0x240400FF
    /* 1AD288 */  .word      0x00602021
    /* 1AD28C */  .word      0x92220016
endlabel pad_1AD284
