.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x7A664 */
glabel pad_07A664
    /* 7A664 */  .word      0x0C09C622
    /* 7A668 */  .word      0x26450174
    /* 7A66C */  .word      0xC641001C
endlabel pad_07A664
