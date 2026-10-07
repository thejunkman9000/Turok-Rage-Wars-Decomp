.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13958 */
glabel pad_013958
    /* 13958 */  .word      0xAFAA0030
    /* 1395C */  .word      0x0C0939B2
endlabel pad_013958
