.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAA54 */
glabel pad_0BAA54
    /* BAA54 */  .word      0x00409821
    /* BAA58 */  .word      0x8E03003C
    /* BAA5C */  .word      0x8E020008
endlabel pad_0BAA54
