.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAF94C */
glabel pad_0AF94C
    /* AF94C */  .word      0x00021C03
endlabel pad_0AF94C
