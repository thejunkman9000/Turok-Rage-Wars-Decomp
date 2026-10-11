.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x561C8 */
glabel pad_0561C8
    /* 561C8 */  .word      0x0C0B08DC
    /* 561CC */  .word      0x00000000
endlabel pad_0561C8
