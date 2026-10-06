.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC05A4 */
glabel pad_0C05A4
    /* C05A4 */  .word      0x8C6392B0
    /* C05A8 */  .word      0x27BDFFD8
    /* C05AC */  .word      0xAFBF0020
endlabel pad_0C05A4
