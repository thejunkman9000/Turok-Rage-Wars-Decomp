.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x548C */
glabel pad_00548C
    /* 548C */  .word      0x00000000
endlabel pad_00548C
