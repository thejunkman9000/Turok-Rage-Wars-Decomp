.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xB600C */
glabel pad_0B600C
    /* B600C */  .word      0x24160002
endlabel pad_0B600C
