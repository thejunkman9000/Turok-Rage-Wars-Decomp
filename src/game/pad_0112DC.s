.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x112DC */
glabel pad_0112DC
    /* 112DC */  .word      0x00101080
endlabel pad_0112DC
