.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA1604 */
glabel pad_0A1604
    /* A1604 */  .word      0x00000000
    /* A1608 */  .word      0x18474144
    /* A160C */  .word      0x4745545F
endlabel pad_0A1604
