.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB913C */
glabel pad_0B913C
    /* B913C */  .word      0x00C08821
endlabel pad_0B913C
