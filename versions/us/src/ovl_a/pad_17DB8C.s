.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x17DB8C */
glabel pad_17DB8C
    /* 17DB8C */  .word      0x554E445F
endlabel pad_17DB8C
