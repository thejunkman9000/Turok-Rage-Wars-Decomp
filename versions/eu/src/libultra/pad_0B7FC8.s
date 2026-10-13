.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7FC8 */
glabel pad_0B7FC8
    /* B7FC8 */  .word      0xC42180E4
    /* B7FCC */  .word      0x44820000
endlabel pad_0B7FC8
