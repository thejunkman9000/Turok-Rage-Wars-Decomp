.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBEBE8 */
glabel pad_0BEBE8
    /* BEBE8 */  .word      0x494F5200
    /* BEBEC */  .word      0x00010000
endlabel pad_0BEBE8
