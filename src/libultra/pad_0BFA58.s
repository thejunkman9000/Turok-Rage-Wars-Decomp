.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFA58 */
glabel pad_0BFA58
    /* BFA58 */  .word      0xFF500098
    /* BFA5C */  .word      0xFF5100A0
endlabel pad_0BFA58
