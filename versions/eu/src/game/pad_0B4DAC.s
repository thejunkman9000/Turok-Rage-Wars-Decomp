.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB4DAC */
glabel pad_0B4DAC
    /* B4DAC */  .word      0x8E42002C
endlabel pad_0B4DAC
