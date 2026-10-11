.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0D5C */
glabel pad_0C0D5C
    /* C0D5C */  .word      0x57697065
endlabel pad_0C0D5C
