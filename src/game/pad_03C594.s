.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x3C594 */
glabel pad_03C594
    /* 3C594 */  .word      0x8FA40018
    /* 3C598 */  .word      0x84830000
    /* 3C59C */  .word      0x10720011
endlabel pad_03C594
