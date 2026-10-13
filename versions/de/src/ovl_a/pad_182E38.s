.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x182E38 */
glabel pad_182E38
    /* 182E38 */  .word      0x24423834
    /* 182E3C */  .word      0x08102BBC
endlabel pad_182E38
