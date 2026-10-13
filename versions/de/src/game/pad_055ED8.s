.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x55ED8 */
glabel pad_055ED8
    /* 55ED8 */  .word      0x00003021
    /* 55EDC */  .word      0x00C03821
endlabel pad_055ED8
