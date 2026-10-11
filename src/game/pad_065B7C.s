.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x65B7C */
glabel pad_065B7C
    /* 65B7C */  .word      0xAFA9003C
endlabel pad_065B7C
