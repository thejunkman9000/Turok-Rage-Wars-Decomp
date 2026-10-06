.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC7568 */
glabel pad_0C7568
    /* C7568 */  .word      0x41F00000
    /* C756C */  .word      0x3F7D70A4
endlabel pad_0C7568
