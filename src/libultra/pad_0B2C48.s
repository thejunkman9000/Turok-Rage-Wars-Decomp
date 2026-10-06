.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB2C48 */
glabel pad_0B2C48
    /* B2C48 */  .word      0x03E00008
    /* B2C4C */  .word      0x24020001
endlabel pad_0B2C48
