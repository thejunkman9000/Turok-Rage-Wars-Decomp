.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xAEF7C */
glabel pad_0AEF7C
    /* AEF7C */  .word      0x27BD0018
endlabel pad_0AEF7C
