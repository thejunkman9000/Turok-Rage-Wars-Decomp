.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x7987C */
glabel pad_07987C
    /* 7987C */  .word      0x45000009
endlabel pad_07987C
