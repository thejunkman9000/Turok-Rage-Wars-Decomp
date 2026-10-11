.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19D0EC */
glabel pad_19D0EC
    /* 19D0EC */  .word      0x6E746572
endlabel pad_19D0EC
