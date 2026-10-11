.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x5A72C */
glabel pad_05A72C
    /* 5A72C */  .word      0x46000801
endlabel pad_05A72C
