.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD918 */
glabel pad_0BD918
    /* BD918 */  .word      0x30A20010
    /* BD91C */  .word      0x10400002
endlabel pad_0BD918
