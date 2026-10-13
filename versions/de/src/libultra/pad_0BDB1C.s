.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBDB1C */
glabel pad_0BDB1C
    /* BDB1C */  .word      0xF7BA0070
endlabel pad_0BDB1C
