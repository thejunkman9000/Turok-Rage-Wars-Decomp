.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xFB54 */
glabel pad_00FB54
    /* FB54 */  .word      0x20050000
    /* FB58 */  .word      0x08003C00
    /* FB5C */  .word      0x04000000
endlabel pad_00FB54
