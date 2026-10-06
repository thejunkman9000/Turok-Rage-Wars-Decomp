.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBCFA4 */
glabel pad_0BCFA4
    /* BCFA4 */  .word      0x3C148015
    /* BCFA8 */  .word      0x2694D6E0
    /* BCFAC */  .word      0x00151980
endlabel pad_0BCFA4
