.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x179C2C */
glabel pad_179C2C
    /* 179C2C */  .word      0x00608821
endlabel pad_179C2C
