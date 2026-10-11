.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B673C */
glabel pad_1B673C
    /* 1B673C */  .word      0x26100001
endlabel pad_1B673C
