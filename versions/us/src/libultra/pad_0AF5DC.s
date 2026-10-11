.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAF5DC */
glabel pad_0AF5DC
    /* AF5DC */  .word      0x4576656E
endlabel pad_0AF5DC
