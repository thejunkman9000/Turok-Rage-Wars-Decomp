.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3DBB8 */
glabel pad_03DBB8
    /* 3DBB8 */  .word      0x0C09C7E9
    /* 3DBBC */  .word      0x02203021
endlabel pad_03DBB8
