.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBF098 */
glabel pad_0BF098
    /* BF098 */  .word      0x02202821
    /* BF09C */  .word      0x3C068015
endlabel pad_0BF098
