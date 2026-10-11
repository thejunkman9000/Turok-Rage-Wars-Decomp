.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x6F1DC */
glabel pad_06F1DC
    /* 6F1DC */  .word      0xE6000014
endlabel pad_06F1DC
