.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5E068 */
glabel pad_05E068
    /* 5E068 */  .word      0x3C048011
    /* 5E06C */  .word      0x2484C080
endlabel pad_05E068
