.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A3ADC */
glabel pad_1A3ADC
    /* 1A3ADC */  .word      0x3C048012
endlabel pad_1A3ADC
