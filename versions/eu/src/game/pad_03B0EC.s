.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3B0EC */
glabel pad_03B0EC
    /* 3B0EC */  .word      0x3C01800C
endlabel pad_03B0EC
