.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x8BFC */
glabel pad_008BFC
    /* 8BFC */  .word      0x4500000C
endlabel pad_008BFC
