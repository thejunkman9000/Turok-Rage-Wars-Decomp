.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1398C */
glabel pad_01398C
    /* 1398C */  .word      0x03E00008
    /* 13990 */  .word      0x27BD0018
endlabel pad_01398C
