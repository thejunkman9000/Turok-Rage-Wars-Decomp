.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18FB18 */
glabel pad_18FB18
    /* 18FB18 */  .word      0x0C103B2C
    /* 18FB1C */  .word      0x24050380
endlabel pad_18FB18
