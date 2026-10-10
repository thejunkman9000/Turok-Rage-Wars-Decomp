.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x187B8C */
glabel pad_187B8C
    /* 187B8C */  .word      0x24020002
endlabel pad_187B8C
