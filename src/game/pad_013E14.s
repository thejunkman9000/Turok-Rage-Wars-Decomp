.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13E14 */
glabel pad_013E14
    /* 13E14 */  .word      0x03E00008
    /* 13E18 */  .word      0x27BD0018
endlabel pad_013E14
