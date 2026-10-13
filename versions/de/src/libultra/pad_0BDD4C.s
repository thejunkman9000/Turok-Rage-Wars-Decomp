.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDD4C */
glabel pad_0BDD4C
    /* BDD4C */  .word      0x8FA80024
endlabel pad_0BDD4C
