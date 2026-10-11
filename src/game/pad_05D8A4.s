.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5D8A4 */
glabel pad_05D8A4
    /* 5D8A4 */  .word      0x27BD0020
    /* 5D8A8 */  .word      0x27BDFFE0
    /* 5D8AC */  .word      0xAFB00010
endlabel pad_05D8A4
