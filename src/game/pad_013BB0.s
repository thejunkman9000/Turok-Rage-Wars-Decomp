.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13BB0 */
glabel pad_013BB0
    /* 13BB0 */  .word      0x8FB00010
    /* 13BB4 */  .word      0x03E00008
    /* 13BB8 */  .word      0x27BD0020
endlabel pad_013BB0
