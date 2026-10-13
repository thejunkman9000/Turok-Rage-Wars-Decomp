.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19FD2C */
glabel pad_19FD2C
    /* 19FD2C */  .word      0x46000802
endlabel pad_19FD2C
