.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDFE8 */
glabel pad_0BDFE8
    /* BDFE8 */  .word      0x3C078015
    /* BDFEC */  .word      0x24E77330
endlabel pad_0BDFE8
