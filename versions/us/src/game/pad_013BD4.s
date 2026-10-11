.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13BD4 */
glabel pad_013BD4
    /* 13BD4 */  .word      0x00000000
    /* 13BD8 */  .word      0x00175346
    /* 13BDC */  .word      0x585F4345
endlabel pad_013BD4
