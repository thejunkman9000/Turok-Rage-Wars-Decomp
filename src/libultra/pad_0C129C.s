.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC129C */
glabel pad_0C129C
    /* C129C */  .word      0x3369FF00
endlabel pad_0C129C
