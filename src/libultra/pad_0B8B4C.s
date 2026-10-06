.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8B4C */
glabel pad_0B8B4C
    /* B8B4C */  .word      0x8E020000
endlabel pad_0B8B4C
