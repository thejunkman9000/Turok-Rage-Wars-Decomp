.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x183D04 */
glabel pad_183D04
    /* 183D04 */  .word      0x34C60204
    /* 183D08 */  .word      0x3C050004
    /* 183D0C */  .word      0x3C048011
endlabel pad_183D04
