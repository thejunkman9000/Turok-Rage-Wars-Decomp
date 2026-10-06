.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0038 */
glabel pad_0C0038
    /* C0038 */  .word      0x0007000D
    /* C003C */  .word      0x2401FFFF
endlabel pad_0C0038
