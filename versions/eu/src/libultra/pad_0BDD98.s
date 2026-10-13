.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDD98 */
glabel pad_0BDD98
    /* BDD98 */  .word      0x88AA000C
    /* BDD9C */  .word      0x98AA000F
endlabel pad_0BDD98
