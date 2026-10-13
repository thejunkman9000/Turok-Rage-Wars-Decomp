.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDEE8 */
glabel pad_0BDEE8
    /* BDEE8 */  .word      0x010A4821
    /* BDEEC */  .word      0x2529FFF0
endlabel pad_0BDEE8
