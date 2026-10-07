.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13BD4 */
glabel pad_013BD4
    /* 13BD4 */  .word      0xA2220035
    /* 13BD8 */  .word      0x822300CA
    /* 13BDC */  .word      0x10650004
endlabel pad_013BD4
