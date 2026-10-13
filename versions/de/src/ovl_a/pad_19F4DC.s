.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x19F4DC */
glabel pad_19F4DC
    /* 19F4DC */  .word      0x2624FFB8
endlabel pad_19F4DC
