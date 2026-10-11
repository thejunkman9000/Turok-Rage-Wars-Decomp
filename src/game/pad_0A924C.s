.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xA924C */
glabel pad_0A924C
    /* A924C */  .word      0xACCA0004
endlabel pad_0A924C
