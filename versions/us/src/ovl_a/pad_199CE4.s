.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x199CE4 */
glabel pad_199CE4
    /* 199CE4 */  .word      0x67486472
    /* 199CE8 */  .word      0x52000000
    /* 199CEC */  .word      0x0000000A
endlabel pad_199CE4
