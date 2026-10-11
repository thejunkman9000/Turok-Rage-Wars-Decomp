.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B0BFC */
glabel pad_1B0BFC
    /* 1B0BFC */  .word      0x308200FF
endlabel pad_1B0BFC
