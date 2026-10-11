.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x63C7C */
glabel pad_063C7C
    /* 63C7C */  .word      0x20504152
endlabel pad_063C7C
