.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8AFC */
glabel pad_0B8AFC
    /* B8AFC */  .word      0x34A50800
endlabel pad_0B8AFC
