.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1973AC */
glabel pad_1973AC
    /* 1973AC */  .word      0x8C634F60
endlabel pad_1973AC
