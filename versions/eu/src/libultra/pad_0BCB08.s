.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBCB08 */
glabel pad_0BCB08
    /* BCB08 */  .word      0x27BD0040
    /* BCB0C */  .word      0x00003021
endlabel pad_0BCB08
