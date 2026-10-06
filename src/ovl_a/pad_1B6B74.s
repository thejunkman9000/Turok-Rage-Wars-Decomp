.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1B6B74 */
glabel pad_1B6B74
    /* 1B6B74 */  .word      0xAE3205D0
    /* 1B6B78 */  .word      0x1440000B
    /* 1B6B7C */  .word      0xAE3005E0
endlabel pad_1B6B74
