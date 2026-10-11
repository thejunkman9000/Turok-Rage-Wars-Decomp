.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x171E88 */
glabel pad_171E88
    /* 171E88 */  .word      0x081013AC
    /* 171E8C */  .word      0x00001021
endlabel pad_171E88
