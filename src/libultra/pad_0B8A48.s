.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8A48 */
glabel pad_0B8A48
    /* B8A48 */  .word      0x00000000
    /* B8A4C */  .word      0xAE440000
endlabel pad_0B8A48
