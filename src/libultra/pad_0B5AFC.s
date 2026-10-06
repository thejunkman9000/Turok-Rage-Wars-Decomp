.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB5AFC */
glabel pad_0B5AFC
    /* B5AFC */  .word      0xA2200035
endlabel pad_0B5AFC
