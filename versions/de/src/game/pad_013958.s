.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13958 */
glabel pad_013958
    /* 13958 */  .word      0x26520001
    /* 1395C */  .word      0x2610FFFF
endlabel pad_013958
