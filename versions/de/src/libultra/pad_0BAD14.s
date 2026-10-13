.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAD14 */
glabel pad_0BAD14
    /* BAD14 */  .word      0xAFBF0010
    /* BAD18 */  .word      0x0C0AE83C
    /* BAD1C */  .word      0x24040400
endlabel pad_0BAD14
