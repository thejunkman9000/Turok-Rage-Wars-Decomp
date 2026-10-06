.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8114 */
glabel pad_0B8114
    /* B8114 */  .word      0x8C44000C
    /* B8118 */  .word      0x8C820008
    /* B811C */  .word      0x0040F809
endlabel pad_0B8114
