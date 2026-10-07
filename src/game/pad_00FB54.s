.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xFB54 */
glabel pad_00FB54
    /* FB54 */  .word      0x1C400025
    /* FB58 */  .word      0x00000000
    /* FB5C */  .word      0x0C09D151
endlabel pad_00FB54
