.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18F1CC */
glabel pad_18F1CC
    /* 18F1CC */  .word      0x00000000
endlabel pad_18F1CC
