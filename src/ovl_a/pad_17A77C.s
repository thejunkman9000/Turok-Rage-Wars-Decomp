.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17A77C */
glabel pad_17A77C
    /* 17A77C */  .word      0x4601A501
endlabel pad_17A77C
