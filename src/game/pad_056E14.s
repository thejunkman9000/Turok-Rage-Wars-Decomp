.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x56E14 */
glabel pad_056E14
    /* 56E14 */  .word      0x8C42B6A0
    /* 56E18 */  .word      0x27BDFFC8
    /* 56E1C */  .word      0xAFB10024
endlabel pad_056E14
