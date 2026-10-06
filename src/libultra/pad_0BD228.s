.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD228 */
glabel pad_0BD228
    /* BD228 */  .word      0x24060001
    /* BD22C */  .word      0x12800007
endlabel pad_0BD228
