.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC3DA8 */
glabel pad_0C3DA8
    /* C3DA8 */  .word      0x00003821
    /* C3DAC */  .word      0xAFA80020
endlabel pad_0C3DA8
