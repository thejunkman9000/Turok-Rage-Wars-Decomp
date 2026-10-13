.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BD1D4 */
glabel pad_1BD1D4
    /* 1BD1D4 */  .word      0x24040001
    /* 1BD1D8 */  .word      0x1064001A
    /* 1BD1DC */  .word      0x28620002
endlabel pad_1BD1D4
