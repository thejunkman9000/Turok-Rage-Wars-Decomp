.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19D6BC */
glabel pad_19D6BC
    /* 19D6BC */  .word      0x00000007
endlabel pad_19D6BC
