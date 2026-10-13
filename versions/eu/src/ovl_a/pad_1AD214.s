.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1AD214 */
glabel pad_1AD214
    /* 1AD214 */  .word      0x000210C0
    /* 1AD218 */  .word      0x00521021
    /* 1AD21C */  .word      0x00021880
endlabel pad_1AD214
