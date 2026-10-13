.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDAF8 */
glabel pad_0BDAF8
    /* BDAF8 */  .word      0x00000000
endlabel pad_0BDAF8
