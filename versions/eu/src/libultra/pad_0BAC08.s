.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAC08 */
glabel pad_0BAC08
    /* BAC08 */  .word      0x00031C00
    /* BAC0C */  .word      0x24420800
endlabel pad_0BAC08
