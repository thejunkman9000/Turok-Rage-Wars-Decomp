.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x63CFC */
glabel pad_063CFC
    /* 63CFC */  .word      0xAC820028
endlabel pad_063CFC
