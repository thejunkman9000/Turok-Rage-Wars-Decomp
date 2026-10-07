.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x57308 */
glabel pad_057308
    /* 57308 */  .word      0x24050001
    /* 5730C */  .word      0x8E442B48
endlabel pad_057308
