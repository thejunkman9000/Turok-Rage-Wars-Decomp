.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B59C8 */
glabel pad_1B59C8
    /* 1B59C8 */  .word      0x10620009
    /* 1B59CC */  .word      0x27B0013A
endlabel pad_1B59C8
