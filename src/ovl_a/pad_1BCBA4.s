.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BCBA4 */
glabel pad_1BCBA4
    /* 1BCBA4 */  .word      0x800D7AE8
    /* 1BCBA8 */  .word      0x00000080
    /* 1BCBAC */  .word      0x00000001
endlabel pad_1BCBA4
