.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB8C2C */
glabel pad_0B8C2C
    /* B8C2C */  .word      0x3C02002C
endlabel pad_0B8C2C
