.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1A76BC */
glabel pad_1A76BC
    /* 1A76BC */  .word      0x0C10E784
endlabel pad_1A76BC
