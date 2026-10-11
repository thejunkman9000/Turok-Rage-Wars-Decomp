.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x59E78 */
glabel pad_059E78
    /* 59E78 */  .word      0xE6000084
    /* 59E7C */  .word      0x96440002
endlabel pad_059E78
