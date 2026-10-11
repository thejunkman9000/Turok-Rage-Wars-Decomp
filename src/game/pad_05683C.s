.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5683C */
glabel pad_05683C
    /* 5683C */  .word      0x24062800
endlabel pad_05683C
