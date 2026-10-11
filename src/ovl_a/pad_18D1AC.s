.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18D1AC */
glabel pad_18D1AC
    /* 18D1AC */  .word      0x5450000A
endlabel pad_18D1AC
