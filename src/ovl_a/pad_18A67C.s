.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x18A67C */
glabel pad_18A67C
    /* 18A67C */  .word      0x081075A5
endlabel pad_18A67C
