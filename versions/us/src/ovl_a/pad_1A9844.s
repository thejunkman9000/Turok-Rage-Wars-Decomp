.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A9844 */
glabel pad_1A9844
    /* 1A9844 */  .word      0x65520000
    /* 1A9848 */  .word      0x00000000
    /* 1A984C */  .word      0x08000500
endlabel pad_1A9844
