.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xADE6C */
glabel pad_0ADE6C
    /* ADE6C */  .word      0x00000000
endlabel pad_0ADE6C
