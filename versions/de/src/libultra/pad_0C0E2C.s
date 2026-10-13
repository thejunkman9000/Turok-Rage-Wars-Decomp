.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0E2C */
glabel pad_0C0E2C
    /* C0E2C */  .word      0x00054823
endlabel pad_0C0E2C
