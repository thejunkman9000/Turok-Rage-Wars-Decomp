.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x95898 */
glabel pad_095898
    /* 95898 */  .word      0x8D620008
    /* 9589C */  .word      0x00028782
endlabel pad_095898
