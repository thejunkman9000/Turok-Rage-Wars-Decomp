.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC10CC */
glabel pad_0C10CC
    /* C10CC */  .word      0x00031880
endlabel pad_0C10CC
