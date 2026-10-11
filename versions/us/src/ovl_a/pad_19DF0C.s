.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19DF0C */
glabel pad_19DF0C
    /* 19DF0C */  .word      0x0D000800
endlabel pad_19DF0C
