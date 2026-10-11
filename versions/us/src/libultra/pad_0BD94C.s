.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBD94C */
glabel pad_0BD94C
    /* BD94C */  .word      0x42697473
endlabel pad_0BD94C
