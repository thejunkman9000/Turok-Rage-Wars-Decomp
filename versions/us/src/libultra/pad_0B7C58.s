.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7C58 */
glabel pad_0B7C58
    /* B7C58 */  .word      0x6D5F6E43
    /* B7C5C */  .word      0x68617250
endlabel pad_0B7C58
