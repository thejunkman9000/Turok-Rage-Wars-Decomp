.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBEF58 */
glabel pad_0BEF58
    /* BEF58 */  .word      0xAE220004
    /* BEF5C */  .word      0x96020018
endlabel pad_0BEF58
