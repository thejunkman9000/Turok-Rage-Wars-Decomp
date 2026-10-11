.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x633B4 */
glabel pad_0633B4
    /* 633B4 */  .word      0x08098EBE
    /* 633B8 */  .word      0x00000000
    /* 633BC */  .word      0x3C048011
endlabel pad_0633B4
