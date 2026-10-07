.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x13A04 */
glabel pad_013A04
    /* 13A04 */  .word      0x0C09CA6D
    /* 13A08 */  .word      0x24070001
    /* 13A0C */  .word      0x02202021
endlabel pad_013A04
