.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA346C */
glabel pad_0A346C
    /* A346C */  .word      0x4600A002
endlabel pad_0A346C
