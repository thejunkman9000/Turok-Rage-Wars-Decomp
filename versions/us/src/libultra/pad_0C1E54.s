.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC1E54 */
glabel pad_0C1E54
    /* C1E54 */  .word      0x00660000
    /* C1E58 */  .word      0x00040000
    /* C1E5C */  .word      0x00000009
endlabel pad_0C1E54
