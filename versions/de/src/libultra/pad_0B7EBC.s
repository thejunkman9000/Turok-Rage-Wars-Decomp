.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB7EBC */
glabel pad_0B7EBC
    /* B7EBC */  .word      0x03E00008
endlabel pad_0B7EBC
