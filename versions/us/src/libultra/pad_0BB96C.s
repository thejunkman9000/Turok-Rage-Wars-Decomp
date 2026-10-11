.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBB96C */
glabel pad_0BB96C
    /* BB96C */  .word      0x536C6F77
endlabel pad_0BB96C
