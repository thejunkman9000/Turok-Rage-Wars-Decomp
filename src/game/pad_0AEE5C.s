.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAEE5C */
glabel pad_0AEE5C
    /* AEE5C */  .word      0x00108200
endlabel pad_0AEE5C
