.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x988C8 */
glabel pad_0988C8
    /* 988C8 */  .word      0x00220821
    /* 988CC */  .word      0x8C22A7B8
endlabel pad_0988C8
