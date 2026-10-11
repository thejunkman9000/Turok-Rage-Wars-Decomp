.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA41BC */
glabel pad_0A41BC
    /* A41BC */  .word      0xAC4A0008
endlabel pad_0A41BC
