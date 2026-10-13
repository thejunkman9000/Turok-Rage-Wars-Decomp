.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBE114 */
glabel pad_0BE114
    /* BE114 */  .word      0xA8C90004
    /* BE118 */  .word      0xB8C90007
    /* BE11C */  .word      0xA8CA0008
endlabel pad_0BE114
