.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19C4E4 */
glabel pad_19C4E4
    /* 19C4E4 */  .word      0x2404005C
    /* 19C4E8 */  .word      0x0C106C44
    /* 19C4EC */  .word      0xAC620000
endlabel pad_19C4E4
