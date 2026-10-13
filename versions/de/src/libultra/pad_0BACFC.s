.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xBACFC */
glabel pad_0BACFC
    /* BACFC */  .word      0x03E00008
endlabel pad_0BACFC
