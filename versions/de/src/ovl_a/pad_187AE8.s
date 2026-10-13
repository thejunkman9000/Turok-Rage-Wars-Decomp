.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x187AE8 */
glabel pad_187AE8
    /* 187AE8 */  .word      0x8C6303F0
    /* 187AEC */  .word      0x00402021
endlabel pad_187AE8
