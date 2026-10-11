.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x7A114 */
glabel pad_07A114
    /* 7A114 */  .word      0x8FB500EC
    /* 7A118 */  .word      0x8FB400E8
    /* 7A11C */  .word      0x8FB300E4
endlabel pad_07A114
