.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC1554 */
glabel pad_0C1554
    /* C1554 */  .word      0x10400008
    /* C1558 */  .word      0x3C03A460
    /* C155C */  .word      0x34630010
endlabel pad_0C1554
