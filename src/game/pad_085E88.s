.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x85E88 */
glabel pad_085E88
    /* 85E88 */  .word      0x8C930E50
    /* 85E8C */  .word      0x1A600020
endlabel pad_085E88
