.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x4253C */
glabel pad_04253C
    /* 4253C */  .word      0x4480A000
endlabel pad_04253C
