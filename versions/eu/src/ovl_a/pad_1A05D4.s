.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A05D4 */
glabel pad_1A05D4
    /* 1A05D4 */  .word      0x8FBF0018
    /* 1A05D8 */  .word      0x03E00008
    /* 1A05DC */  .word      0x27BD0020
endlabel pad_1A05D4
