.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x190258 */
glabel pad_190258
    /* 190258 */  .word      0x27BD0018
    /* 19025C */  .word      0x27BDFFE8
endlabel pad_190258
