.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x4F574 */
glabel pad_04F574
    /* 4F574 */  .word      0x00E09821
    /* 4F578 */  .word      0xA2200000
    /* 4F57C */  .word      0x96430008
endlabel pad_04F574
