.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x1BCD94 */
glabel pad_1BCD94
    /* 1BCD94 */  .word      0x00000000
    /* 1BCD98 */  .word      0x00024050
    /* 1BCD9C */  .word      0x00080000
endlabel pad_1BCD94
