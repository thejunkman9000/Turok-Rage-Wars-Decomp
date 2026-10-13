.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBAF9C */
glabel pad_0BAF9C
    /* BAF9C */  .word      0x44021800
endlabel pad_0BAF9C
