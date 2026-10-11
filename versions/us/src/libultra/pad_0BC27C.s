.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBC27C */
glabel pad_0BC27C
    /* BC27C */  .word      0x6C540000
endlabel pad_0BC27C
