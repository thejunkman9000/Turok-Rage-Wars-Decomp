.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD0C8 */
glabel pad_0BD0C8
    /* BD0C8 */  .word      0xB8890007
    /* BD0CC */  .word      0xA88A0008
endlabel pad_0BD0C8
