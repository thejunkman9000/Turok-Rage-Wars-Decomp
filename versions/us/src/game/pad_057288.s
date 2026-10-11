.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x57288 */
glabel pad_057288
    /* 57288 */  .word      0x00000000
    /* 5728C */  .word      0x0278320C
endlabel pad_057288
