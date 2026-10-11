.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA32DC */
glabel pad_0A32DC
    /* A32DC */  .word      0x8C420000
endlabel pad_0A32DC
