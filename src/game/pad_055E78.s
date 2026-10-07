.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x55E78 */
glabel pad_055E78
    /* 55E78 */  .word      0x24050018
    /* 55E7C */  .word      0x0C095710
endlabel pad_055E78
