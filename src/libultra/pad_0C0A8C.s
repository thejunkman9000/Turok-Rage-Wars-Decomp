.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0A8C */
glabel pad_0C0A8C
    /* C0A8C */  .word      0x03615824
endlabel pad_0C0A8C
