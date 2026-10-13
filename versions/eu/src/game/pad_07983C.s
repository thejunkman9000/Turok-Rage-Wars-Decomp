.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x7983C */
glabel pad_07983C
    /* 7983C */  .word      0xC60C0008
endlabel pad_07983C
