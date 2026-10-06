.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBFE94 */
glabel pad_0BFE94
    /* BFE94 */  .word      0x24130001
    /* BFE98 */  .word      0x24120008
    /* BFE9C */  .word      0x12930005
endlabel pad_0BFE94
