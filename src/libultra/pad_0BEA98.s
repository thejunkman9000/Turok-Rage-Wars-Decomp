.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBEA98 */
glabel pad_0BEA98
    /* BEA98 */  .word      0x24060040
    /* BEA9C */  .word      0xAFBF0018
endlabel pad_0BEA98
