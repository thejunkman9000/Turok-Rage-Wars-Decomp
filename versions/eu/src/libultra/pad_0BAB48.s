.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAB48 */
glabel pad_0BAB48
    /* BAB48 */  .word      0xAFBF0030
    /* BAB4C */  .word      0xAFB00018
endlabel pad_0BAB48
