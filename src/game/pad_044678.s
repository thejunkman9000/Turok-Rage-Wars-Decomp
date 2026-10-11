.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x44678 */
glabel pad_044678
    /* 44678 */  .word      0xAE00001C
    /* 4467C */  .word      0x8FA2021C
endlabel pad_044678
